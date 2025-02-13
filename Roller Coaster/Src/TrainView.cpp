#include "TrainView.h"  
#include "AppMain.h"
#include <QtMultimedia/QMediaPlaylist>
#include "Particle.h"
#include<QDebug>
#include<string>
TrainView::TrainView(QWidget *parent) :  
QGLWidget(parent)  
{  
	resetArcball();
	DIVIDE_LINE = 500;
	BOARD_LENGTH = 3;
	BOARD_DISTANCE_LENGTH = 3;
	trainLineIndex = 0;
	trainLineILength = 0;
	t_time = 0;
	type_interpolation = ArcLength;
	initSplineMatrix();
	frameCount = 0;
	carNum = 3;
	humanNum = 1;
	humanViewIndex = 1;
	CardinalTao = 0.5;
	train = new Train("./Models/train.obj", 20, Pnt3f(0, 0, 0));
	
	sampleCar = Model("./Models/opencar.obj", 20, Pnt3f(0, 0, 0));
	sampleHuman = Human("./Models/human.obj", 5, Pnt3f(0, 0, 0));
	for (size_t i = 0; i < carNum; i++)
	{
		cars.push_back(new Model(sampleCar));
		for (size_t j = 0; j < humanNum; j++)
		{
			humans.push_back(new Human(sampleHuman));
		}
	}
	buildings.push_back(new Model("./Models/247_House 15_obj.obj", 20, Pnt3f(-55, 5, 10)));
	buildings[0]->rotateTo(Pnt3f(0, 1, 0));
	buildings.push_back(new Model("./Models/3d we.obj", 10, Pnt3f(14, 16, 27)));
	buildings[1]->rotateTo(Pnt3f(0, 1, 0));
	buildings.push_back(new Model("./Models/Old House 2 3D Models.obj", 20, Pnt3f(30, 20, 15)));
	buildings[2]->rotateTo(Pnt3f(0, 1, 0.2));
}  

TrainView::~TrainView()  
{}  

void TrainView::initializeGL()
{
	initializeOpenGLFunctions();
	//Create a triangle object
	triangle = new Triangle();
	//Initialize the triangle object
	triangle->Init();
	//Create a square object
	square = new Square();
	//Initialize the square object
	square->Init();
	//Initialize texture 
	initializeTexture();

	wave = new Wave();
	wave->Init();

	hill = new Hill();
	hill->Init();

	bg = new BackGround();
	bg->Init();

	tunnel = new Tunnel();
	tunnel->Init();

	//初始化石頭
	GLfloat centerX = -30, centerZ = -30, r = 30;
	for (float deta = 0; deta < 6.28; deta += 6.28 / 20){
		GLfloat x = r * cos(deta), z = r * sin(deta);
		Stone* newStone = new Stone(x + centerX, z + centerZ);
		newStone->Init();
		stone.push_back(newStone);
	}
	frameTime.start();
	QMediaPlaylist* playlist = new QMediaPlaylist();
	playlist->addMedia(QUrl("./Music/bgm.mp3"));
	playlist->setPlaybackMode(QMediaPlaylist::Loop);

	player = new QMediaPlayer;
	//player->setMedia(QUrl(QUrl::fromLocalFile("./Music/bgm.mp3")));
	player->setPlaylist(playlist);
	player->setVolume(50);
	player->play();
}

void TrainView::initializeTexture()
{
	//Load and create a texture for square;'stexture
	QOpenGLTexture* texture = new QOpenGLTexture(QImage("./Textures/Tupi.bmp"));
	Textures.push_back(texture);
}

void TrainView::initSplineMatrix(float CardinalScale)
{
	float BSplineScale = 1.0 / 6.0;
	float tempBSplineMatrix[][4] =
	{
		{-1,3,-3,1},
		{3,-6,0,4},
		{-3,3,3,1},
		{1,0,0,0}
	};
	float tempCardinalMatrix[][4]=
	{
		{-1,2,-1,0},
		{-1,1,0,0},
		{1,-2,1,0},
		{1,-1,0,0}
	};
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			CardinalMatrix[i][j] = tempCardinalMatrix[i][j];
			BSplineMatrix[i][j] = tempBSplineMatrix[i][j];
		}
	}
	float CardinalMatrix2[][4] =
	{
		{0,0,0,0},
		{2,-3,0,1},
		{-2,3,0,0},
		{0,0,0,0}
	};
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			BSplineMatrix[i][j] *= BSplineScale;
			CardinalMatrix[i][j] *= CardinalScale;
			CardinalMatrix[i][j] += CardinalMatrix2[i][j];
		}
	}
}

void TrainView:: resetArcball()
	//========================================================================
{
	// Set up the camera to look at the world
	// these parameters might seem magical, and they kindof are
	// a little trial and error goes a long way
	arcball.setup(this, 40, 250, .2f, .4f, 0);
}

void TrainView::paintGL()
{

	//*********************************************************************
	//
	// * Set up basic opengl informaiton
	//
	//**********************************************************************
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	// Set up the view port
	glViewport(0,0,width(),height());
	// clear the window, be sure to clear the Z-Buffer too
	glClearColor(0,0,0.3f,0);
	
	// we need to clear out the stencil buffer since we'll use
	// it for shadows
	glClearStencil(0);
	glEnable(GL_DEPTH);

	// Blayne prefers GL_DIFFUSE
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// prepare for projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	setProjection();		// put the code to set up matrices here

	//######################################################################
	// TODO: 
	// you might want to set the lighting up differently. if you do, 
	// we need to set up the lights AFTER setting up the projection
	//######################################################################
	// enable the lighting
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// top view only needs one light
	if (this->camera == 1) {
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
	} else {
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
	}

	//*********************************************************************
	//
	// * set the light parameters
	//
	//**********************************************************************
	GLfloat lightPosition1[]	= {0,1,1,0}; // {50, 200.0, 50, 1.0};
	GLfloat lightPosition2[]	= {1, 0, 0, 0};
	GLfloat lightPosition3[]	= {0, -1, 0, 0};
	GLfloat yellowLight[]		= {0.5f, 0.5f, .1f, 1.0};
	GLfloat whiteLight[]		= {1.0f, 1.0f, 1.0f, 1.0};
	GLfloat blueLight[]			= {.1f,.1f,.3f,1.0};
	GLfloat grayLight[]			= {.3f, .3f, .3f, 1.0};

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, grayLight);

	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, yellowLight);

	glLightfv(GL_LIGHT2, GL_POSITION, lightPosition3);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, blueLight);

	//draw background
	bg->Begin(ProjectionMatrex, ModelViewMatrex);
		glActiveTexture(GL_TEXTURE0);
		bg->PaintObject();
	bg->End();

	//*********************************************************************
	// now draw the ground plane
	//*********************************************************************
	// setupFloor();
	// glDisable(GL_LIGHTING);
	// drawFloor(200,10);
	hill->Paint(ProjectionMatrex, ModelViewMatrex);

	//*********************************************************************
	// now draw the object and we need to do it twice
	// once for real, and then once for shadows
	//*********************************************************************
	glEnable(GL_LIGHTING);
	setupObjects();

	drawStuff();

	// this time drawing is for shadows (except for top view)
	if (this->camera != 1) {
		setupShadows();
		drawStuff(true);
		unsetupShadows();
	}

	//Get modelview matrix
 	glGetFloatv(GL_MODELVIEW_MATRIX,ModelViewMatrex);
	//Get projection matrix
 	glGetFloatv(GL_PROJECTION_MATRIX,ProjectionMatrex);

	//Call triangle's render function, pass ModelViewMatrex and ProjectionMatrex
 	//triangle->Paint(ProjectionMatrex,ModelViewMatrex);
    
	//we manage textures by Trainview class, so we modify square's render function
	//square->Begin();
	//	//Active Texture
	//	glActiveTexture(GL_TEXTURE0);
	//	//Bind square's texture
	//	Textures[0]->bind();
	//	//pass texture to shader
	//	square->shaderProgram->setUniformValue("Texture",0);
	//	//Call square's render function, pass ModelViewMatrex and ProjectionMatrex
	//	square->Paint(ProjectionMatrex,ModelViewMatrex);
	//square->End();

	//水面
	wave->updateTime(t_time);

	wave->Begin(ProjectionMatrex, ModelViewMatrex);
		glActiveTexture(GL_TEXTURE0);
		wave->PaintObject();
	wave->End();

	//石頭
	drawStone();

	//煙火
	ProcessParticles(t_time);
	DrawParticles();

	//隧道
	tunnel->Paint(ProjectionMatrex, ModelViewMatrex);

	//fps計算
	++frameCount;
	if (frameTime.elapsed() >= 1000)
	{

		double fps = frameCount / ((double)frameTime.elapsed() / 1000.0);
		
		qInfo("FPS: %s",std::to_string(fps).c_str());
		frameTime.restart();
		frameCount = 0;
	}
}

//************************************************************************
//
// * This sets up both the Projection and the ModelView matrices
//   HOWEVER: it doesn't clear the projection first (the caller handles
//   that) - its important for picking
//========================================================================
void TrainView::
setProjection()
//========================================================================
{
	// Compute the aspect ratio (we'll need it)
	float aspect = static_cast<float>(width()) / static_cast<float>(height());

	// Check whether we use the world camp
	if (this->camera == 0){
		arcball.setProjection(false);
		update();
	// Or we use the top cam
	}else if (this->camera == 1) {
		float wi, he;
		if (aspect >= 1) {
			wi = 110;
			he = wi / aspect;
		} 
		else {
			he = 110;
			wi = he * aspect;
		}

		// Set up the top camera drop mode to be orthogonal and set
		// up proper projection matrix
		glMatrixMode(GL_PROJECTION);
		glOrtho(-wi, wi, -he, he, 200, -200);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glRotatef(-90,1,0,0);
		update();
	} 
	// Or do the train view or other view here
	//####################################################################
	// TODO: 
	// put code for train view projection here!	
	//####################################################################
	else if (this->camera == 2) {
		//
		Pnt3f direction = train->getOrient();
		direction.normalize();
		Pnt3f eye = train->getPosition() + direction * 1;
		Pnt3f up=train->getUp();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(50.0, aspect, 0.1, 512);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye.x , eye.y , eye.z ,
			eye.x+ direction.x , eye.y+ direction.y , eye.z+ direction.z , up.x, up.y, up.z);
		update();
	}
	else if (this->camera == 3) {
		//
		if (humanViewIndex >= humans.size())return;
		Pnt3f up  = humans[humanViewIndex]->getUp();
		up.normalize();
		Pnt3f direction = humans[humanViewIndex]->getOrient();
		direction.normalize();
		Pnt3f eye = humans[humanViewIndex]->getPosition() + up * 3 + direction * (3);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(50.0, aspect, 0.1, 512);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(eye.x , eye.y , eye.z ,
			eye.x + direction.x , eye.y + direction.y , eye.z + direction.z , up.x, up.y, up.z);

		//glLoadIdentity();
		update();
	}
	else {
#ifdef EXAMPLE_SOLUTION
		trainCamView(this,aspect);
#endif
		update();
	}
}


//************************************************************************
//
// * this draws all of the stuff in the world
//
//	NOTE: if you're drawing shadows, DO NOT set colors (otherwise, you get 
//       colored shadows). this gets called twice per draw 
//       -- once for the objects, once for the shadows
//########################################################################
// TODO: 
// if you have other objects in the world, make sure to draw them
//########################################################################
//========================================================================
void TrainView::drawStuff(bool doingShadows)
{
	// Draw the control points
	// don't draw the control points if you're driving 
	// (otherwise you get sea-sick as you drive through them)
	if (this->camera != 2) {
		for(size_t i = 0; i < this->m_pTrack->points.size(); ++i) {
			if (!doingShadows) {
				if ( ((int) i) != selectedCube)
					glColor3ub(240, 60, 60);
				else
					glColor3ub(240, 240, 30);
			}
			this->m_pTrack->points[i].draw();
		}
		update();
	}
	// draw the track
	//####################################################################
	// TODO: 
	// call your own track drawing code
	//####################################################################
	drawTrack(doingShadows);
#ifdef EXAMPLE_SOLUTION
	drawTrack(this, doingShadows);
#endif

	// draw the train
	//####################################################################
	// TODO: 
	//	call your own train drawing code
	//####################################################################
	if (isrun) AppMain::getInstance()->advanceTrain();
	//drawTrain(t_time);
	drawTrainObj2(t_time, doingShadows);
#ifdef EXAMPLE_SOLUTION
	// don't draw the train if you're looking out the front window
	if (!tw->trainCam->value())
		drawTrain(this, doingShadows);
#endif
	drawBuilding(doingShadows);
}

void TrainView::drawTrack(bool doingShadows)
{


	type_spline = (spline_t)curve;
	Pnt3f qt0, qt00, qt01, board0, board1;
	Pnt3f qt, orient_t;
	bool started = false;
	float boardLen = 0;
	const bool BOARD_MODE = true, TRACK_MODE = false;
	bool BoardMode = TRACK_MODE;
	for (size_t i = 0; i < m_pTrack->points.size(); ++i)
	{
		// pos
		Pnt3f cp_pos_p0 = m_pTrack->points[(i - 1+ m_pTrack->points.size()) % m_pTrack->points.size()].pos;
		Pnt3f cp_pos_p1 = m_pTrack->points[i].pos;
		Pnt3f cp_pos_p2 = m_pTrack->points[(i + 1) % m_pTrack->points.size()].pos;
		Pnt3f cp_pos_p3 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].pos;
		// orient
		Pnt3f cp_orient_p0 = m_pTrack->points[(i - 1+ m_pTrack->points.size()) % m_pTrack->points.size()].orient;
		Pnt3f cp_orient_p1 = m_pTrack->points[i].orient;
		Pnt3f cp_orient_p2 = m_pTrack->points[(i + 1) % m_pTrack->points.size()].orient;
		Pnt3f cp_orient_p3 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].orient;
		// �L�ը��� ����180��½����D
		
		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		if (cp_orient_p2 == -cp_orient_p1)
		{
			
			//�Y�I��m�ײv�P�L�ժ����׬ۦP�A�h�ĪG���ΡC
			//�G���F�ײv�P�_�H�Τ��P�����׷L�աC
			
			Pnt3f temp = cp_pos_p2 - cp_pos_p1;
			temp.normalize();
			if( temp.x / temp.z > 0 )
			cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1,-0.1);
			else
			cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, 0.1);
		}
		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		// �L�ը���END
		float percent = 1.0f / DIVIDE_LINE;
		float t = 0;
		if (!started) qt00 = qt01 = qt;
		for (size_t j = 0; j < DIVIDE_LINE; j++) {
			qt0 = qt;
			t += percent; 
			float tMatrix[][1] =
			{
				{t * t * t},
				{t * t},
				{t},
				{1}
			};
			float MTMatrix[4][1] = { {0},{0},{0},{0} };
			switch (type_spline) {
			case spline_CardinalCubic:
				for (size_t i = 0; i < 4; i++)
				{
					for (size_t j = 0; j < 4; j++)
					{
						MTMatrix[i][0] += CardinalMatrix[i][j] * tMatrix[j][0];
					}
				}
				break;
			case spline_CubicB_Spline:
				for (size_t i = 0; i < 4; i++)
				{
					for (size_t j = 0; j < 4; j++)
					{
						MTMatrix[i][0] += BSplineMatrix[i][j] * tMatrix[j][0];
					}
				}
				break;
			}
			switch (type_spline) {
			case spline_Linear:
				qt = (1 - t) * cp_pos_p1 + t * cp_pos_p2;
				orient_t = (1 - t) * cp_orient_p1 + t * cp_orient_p2;
				break;
			case spline_CardinalCubic:
			case spline_CubicB_Spline:
				qt = MTMatrix[0][0] * cp_pos_p0+
					 MTMatrix[1][0] * cp_pos_p1+
					 MTMatrix[2][0] * cp_pos_p2+
					 MTMatrix[3][0] * cp_pos_p3;
				orient_t = MTMatrix[0][0] * cp_orient_p0 +
					MTMatrix[1][0] * cp_orient_p1 +
					MTMatrix[2][0] * cp_orient_p2 +
					MTMatrix[3][0] * cp_orient_p3;
				break;
			}

			Pnt3f qt1 = qt;

			orient_t.normalize();
			Pnt3f diff = (qt1 - qt0);

			Pnt3f cross_t = diff * orient_t;
			cross_t.normalize();
			cross_t = cross_t * 2.5f;
			
			if (started) {

				float len = sqrt((diff.x * diff.x) + (diff.y * diff.y) + (diff.z * diff.z));
				boardLen += len;

				// �y�D
				glLineWidth(4);
				glBegin(GL_LINES);
				if (!doingShadows) {
					glColor3ub(32, 32, 64);
				}
				
				glVertex3f(qt00.x, qt00.y, qt00.z);
				glVertex3f(qt1.x + cross_t.x, qt1.y + cross_t.y, qt1.z + cross_t.z);
				
				glVertex3f(qt01.x, qt01.y, qt01.z);
				glVertex3f(qt1.x - cross_t.x, qt1.y - cross_t.y, qt1.z - cross_t.z);
				
				glEnd();

				// ���
				Pnt3f cross_b = diff * orient_t;
				cross_b.normalize();
				cross_b = cross_b * 3.5f;

				Pnt3f newBoard0 = qt1 + cross_b, newBoard1 = qt1 - cross_b;
				Pnt3f center0 = (newBoard0 - board0) * 0.5f + board0, center1 = (newBoard1 - board1) * 0.5f + board1;
				Pnt3f parallel = (newBoard0 - board0);
				parallel.normalize();
				parallel = parallel * (BOARD_LENGTH / 2);
				
				if (BoardMode == TRACK_MODE && boardLen >= BOARD_LENGTH) {
					BoardMode = BOARD_MODE;
					boardLen -= BOARD_LENGTH;
					board0 = qt1 + cross_b;
					board1 = qt1 - cross_b;
				}
				else if (BoardMode == BOARD_MODE && boardLen >= BOARD_DISTANCE_LENGTH) {
					BoardMode = TRACK_MODE;
					boardLen -= BOARD_DISTANCE_LENGTH;
					glBegin(GL_QUADS);
					if (!doingShadows) {
						glColor3ub(255, 255, 255);
					}
					// glVertex3f(board0.x, board0.y - 0.1f, board0.z);
					// glVertex3f(board1.x, board1.y - 0.1f, board1.z);
					// glVertex3f(qt1.x - cross_b.x, qt1.y - cross_b.y - 0.1f, qt1.z - cross_b.z);
					// glVertex3f(qt1.x + cross_b.x, qt1.y + cross_b.y - 0.1f, qt1.z + cross_b.z);
					glVertex3f(center0.x + parallel.x, center0.y + parallel.y - 0.1f, center0.z + parallel.z);
					glVertex3f(center1.x + parallel.x, center1.y + parallel.y - 0.1f, center1.z + parallel.z);
					glVertex3f(center1.x - parallel.x, center1.y - parallel.y - 0.1f, center1.z - parallel.z);
					glVertex3f(center0.x - parallel.x, center0.y - parallel.y - 0.1f, center0.z - parallel.z);
					glEnd();
				}
			}
			started = true;
			qt00 = qt1 + cross_t;
			qt01 = qt1 - cross_t;
		}


	}
}
void TrainView::drawTrainObj(float t)
{
	t *= m_pTrack->points.size();
	size_t i = t;
	t -= i;
	Pnt3f cp_pos_p0 = m_pTrack->points[(i - 1 + m_pTrack->points.size()) % m_pTrack->points.size()].pos;
	Pnt3f cp_pos_p1 = m_pTrack->points[i].pos;
	Pnt3f cp_pos_p2 = m_pTrack->points[(i + 1) % m_pTrack->points.size()].pos;
	Pnt3f cp_pos_p3 = m_pTrack->points[(i + 2) % m_pTrack->points.size()].pos;
	Pnt3f qt, orient_t;

	float tMatrix[][1] =
	{
		{t * t * t},
		{t * t},
		{t},
		{1}
	};
	float MTMatrix[4][1] = { {0},{0},{0},{0} };
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (type_spline == spline_CardinalCubic)
				MTMatrix[i][0] += CardinalMatrix[i][j] * tMatrix[j][0];
			else if (type_spline == spline_CubicB_Spline)
				MTMatrix[i][0] += BSplineMatrix[i][j] * tMatrix[j][0];
		}
	}


	switch (type_spline) {
	case spline_Linear:
		// Linear
		qt = (1 - t) * cp_pos_p1 + t * cp_pos_p2;
		break;
	case spline_CardinalCubic:
	case spline_CubicB_Spline:
		qt = MTMatrix[0][0] * cp_pos_p0 +
			MTMatrix[1][0] * cp_pos_p1 +
			MTMatrix[2][0] * cp_pos_p2 +
			MTMatrix[3][0] * cp_pos_p3;
		break;
	}

	orient_t = train->getPosition().getOrient(qt);
	train->rotateTo(orient_t);
	train->moveTo(qt);
	glColor3ub(255, 255, 255);
	train->render(false, false);

}
void TrainView::drawTrainObj2(float t, bool doingShadows)
{
	if (train->waypoints.size() == 0)return;
	int index = t * train->waypoints.size();
	Pnt3f qt = train->waypoints[index];
	Pnt3f diff = train->waypoints[index].getOrient(train->waypoints[(index + 1) % train->waypoints.size()]);
	Pnt3f orient_t = train->wayorients[index];
	orient_t.normalize(); 
	train->up = orient_t;

	Pnt3f cross_t = diff * Pnt3f(0, 1, 0);
	cross_t.normalize();
	float x = cross_t.x * orient_t.x +
		cross_t.y * orient_t.y +
		cross_t.z * orient_t.z;
	float theta = radiansToDegrees(atan2(x, orient_t.y));

	train->rotateDegree = theta;
	train->rotateTo(diff);
	qt = qt + 4 * orient_t;
	train->moveTo(qt);

	if(!doingShadows)
	glColor3ub(50, 50, 50);
	if(camera!=2)
	train->render(false, false);

	
	int distance = 10;
	for (size_t i = 0; i < carNum; i++)
	{
		int tempIndex = (index - (i+1) * distance + train->waypoints.size()) % train->waypoints.size();
		Pnt3f qt = train->waypoints[tempIndex];
		
		Pnt3f diff = train->waypoints[tempIndex].getOrient(train->waypoints[(tempIndex + 1) % train->waypoints.size()]);
		Pnt3f orient_t = train->wayorients[tempIndex];
		orient_t.normalize();
		cars[i]->up = orient_t;
		Pnt3f cross_t = diff * Pnt3f(0,1,0);
		cross_t.normalize();
		float x = cross_t.x * orient_t.x +
			cross_t.y * orient_t.y +
			cross_t.z * orient_t.z ;
		float theta = radiansToDegrees(atan2(x, orient_t.y));

		cars[i]->rotateDegree = theta;
		cars[i]->rotateTo(diff);
		cars[i]->moveTo(qt + 2 * orient_t);


		if (!doingShadows)
			glColor3ub(50, 50, 50);
		cars[i]->render(false, false);

		for (size_t j = 0; j < humanNum; j++)
		{
			Pnt3f displace = humans[i * humanNum + j]->getDisplace();
			Pnt3f right = diff * orient_t;
			right.normalize();
			humans[i * humanNum + j]->up = orient_t;
			humans[i * humanNum + j]->rotateDegree = theta;
			humans[i * humanNum + j]->rotateTo(diff);
			humans[i * humanNum + j]->moveTo(qt+ orient_t*5+ diff* (j+ displace.x)+ right * displace.z);
			if (!doingShadows)
				glColor3ub(254, 225, 185);
			if(!(camera==3&& i * humanNum + j==humanViewIndex))
			humans[i * humanNum + j]->render(false, false);
		}
	}
}

void TrainView::drawStone() {
	for (auto iter = stone.begin(); iter < stone.end(); iter++) {
		(*iter)->Paint(ProjectionMatrex, ModelViewMatrex);
	}
}

void TrainView::drawBuilding(bool doingShadows)
{

		if (!doingShadows) {
			glColor3ub(140, 95, 40);
		}
		buildings[0]->render(false, false);
		if (!doingShadows) {
			glColor3ub(139, 139, 122);
		}
		buildings[1]->render(false, false);
		if (!doingShadows) {
			glColor3ub(79, 34, 1);
		}
		buildings[2]->render(false, false);
}

void TrainView::interpolation()
{
	if (m_pTrack->points.size() == 0)return;
	type_spline = (spline_t)curve;
	float stepArcLength = 2;
	switch (type_spline) {
	case spline_Linear:
		train->interpolationLinear((Train::interpolation_t)type_interpolation, m_pTrack->points, stepArcLength, 500);
		break;
	case spline_CardinalCubic:
		train->interpolationCardinalCubic((Train::interpolation_t)type_interpolation, m_pTrack->points,CardinalMatrix, stepArcLength, 500);
		break;
	case spline_CubicB_Spline:
		train->interpolationCubicB_Spline((Train::interpolation_t)type_interpolation, m_pTrack->points, BSplineMatrix, stepArcLength,5000);
		break;
	default:
		train->interpolationLinear((Train::interpolation_t)type_interpolation, m_pTrack->points, stepArcLength, 500);
		break;
	}
}
void TrainView::insertCar()
{
	carNum++;
	cars.push_back(new Model(sampleCar));
	humans.push_back(new Human(sampleHuman));
}
void TrainView::deleteCar()
{
	if (carNum == 0)return;
	carNum--;
	cars.erase(cars.begin() + cars.size() - 1);
	humans.erase(humans.begin() + humans.size() - 1);
	if (humanViewIndex == humans.size()) frontHuman();
}
void TrainView::frontHuman()
{
	humanViewIndex--;
	if (humanViewIndex < 0)humanViewIndex = 0;
}
void TrainView::behindHuman()
{
	humanViewIndex++;
	if (humanViewIndex >= humans.size())humanViewIndex = humans.size()-1;
	if (humanViewIndex < 0)humanViewIndex = 0;
}
void TrainView::drawTrain(float t)
{
	t *= m_pTrack->points.size();
	size_t i = t;
	t -= i;
	// for (i = 0; t > 1; t -= 1, i++) i++;
	Pnt3f cp_pos_p1 = m_pTrack->points[i].pos;
	Pnt3f cp_pos_p2 = m_pTrack->points[(i + 1) % m_pTrack->points.size()].pos;

	// orient
	Pnt3f cp_orient_p1 = m_pTrack->points[i].orient;
	Pnt3f cp_orient_p2 = m_pTrack->points[(i + 1) % m_pTrack->points.size()].orient;
	Pnt3f qt, orient_t;
	switch (type_spline) {
	case spline_Linear:
		// Linear
		qt = (1 - t) * cp_pos_p1 + t * cp_pos_p2;
		orient_t = (1 - t) * cp_orient_p1 + t * cp_orient_p2;
		break;
	}
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(qt.x - 5, qt.y - 5, qt.z - 5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(qt.x + 5, qt.y - 5, qt.z - 5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(qt.x + 5, qt.y + 5, qt.z - 5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(qt.x - 5, qt.y + 5, qt.z - 5);
	glEnd();
}

void TrainView::
	doPick(int mx, int my)
	//========================================================================
{
	// since we'll need to do some GL stuff so we make this window as 
	// active window
	makeCurrent();

	// get the viewport - most reliable way to turn mouse coords into GL coords
	int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity ();

	gluPickMatrix((double)mx, (double)(viewport[3]-my), 
		5, 5, viewport);

	// now set up the projection
	setProjection();

	// now draw the objects - but really only see what we hit
	GLuint buf[100];
	glSelectBuffer(100,buf);
	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);


	// draw the cubes, loading the names as we go
	for(size_t i=0; i<m_pTrack->points.size(); ++i) {
		glLoadName((GLuint) (i+1));
		m_pTrack->points[i].draw();
	}

	// go back to drawing mode, and see how picking did
	int hits = glRenderMode(GL_RENDER);
	if (hits) {
		// warning; this just grabs the first object hit - if there
		// are multiple objects, you really want to pick the closest
		// one - see the OpenGL manual 
		// remember: we load names that are one more than the index
		selectedCube = buf[3]-1;
	} else // nothing hit, nothing selected
		selectedCube = -1;
}
