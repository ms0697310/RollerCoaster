/************************************************************************
     File:        Track.cpp

     Author:     
                  Michael Gleicher, gleicher@cs.wisc.edu
     Modifier
                  Yu-Chi Lai, yu-chi@cs.wisc.edu
     
     Comment:     Container for the "World"

						This provides a container for all of the "stuff" 
						in the world.

						It could have been all global variables, or it could 
						have just been
						contained in the window. The advantage of doing it 
						this way is that
						we might have multiple windows looking at the same 
						world. But, I don't	think we'll actually do that.

						See the readme for commentary on code style

     Platform:    Visio Studio.Net 2003/2005

*************************************************************************/

#include "Track.H"

//****************************************************************************
//
// * Constructor
//============================================================================
CTrack::
CTrack() : trainU(0)
//============================================================================
{
	resetPoints();
	
}

//****************************************************************************
//
// * provide a default set of points
//============================================================================
void CTrack::
resetPoints()
//============================================================================
{

	points.clear();
	points.push_back(ControlPoint(Pnt3f(50,5,0 )));
	points.push_back(ControlPoint(Pnt3f(0,5,50 )));
	points.push_back(ControlPoint(Pnt3f(-50,5,0)));
	points.push_back(ControlPoint(Pnt3f(0,5,-50)));

	// we had better put the train back at the start of the track...
	trainU = 0.0;
}

//****************************************************************************
//
// * Handy utility to break a string into a list of words
//============================================================================
void breakString(char* str, std::vector<const char*>& words) 
//============================================================================
{
	// start with no words
	words.clear();

	// scan through the string, starting at the beginning
	char* p = str;

	// stop when we hit the end of the string
	while(*p) {
		// skip over leading whitespace - stop at the first character or end of string
		while (*p && *p<=' ') p++;

		// now we're pointing at the first thing after the spaces
		// make sure its not a comment, and that we're not at the end of the string
		// (that's actually the same thing)
		if (! (*p) || *p == '#')
		break;

		// so we're pointing at a word! add it to the word list
		words.push_back(p);

		// now find the end of the word
		while(*p > ' ') p++;	// stop at space or end of string

		// if its ethe end of the string, we're done
		if (! *p) break;

		// otherwise, turn this space into and end of string (to end the word)
		// and keep going
		*p = 0;
		p++;
	}
}

//****************************************************************************
//
// * The file format is simple
//   first line: an integer with the number of control points
//	  other lines: one line per control point
//   either 3 (X,Y,Z) numbers on the line, or 6 numbers (X,Y,Z, orientation)
//============================================================================
void CTrack::
readPoints(const char* filename)
//============================================================================
{
	FILE* fp = fopen(filename,"r");
	if (!fp) {
		printf("Can't Open File!\n");
	} 
	else {
		char buf[512];

		// first line = number of points
		fgets(buf,512,fp);
		size_t npts = (size_t) atoi(buf);

		if( (npts<4) || (npts>65535)) {
			printf("Illegal Number of Points Specified in File");
		} else {
			points.clear();
			// get lines until EOF or we have enough points
			while( (points.size() < npts) && fgets(buf,512,fp) ) {
				Pnt3f pos,orient;
				vector<const char*> words;
				breakString(buf,words);
				if (words.size() >= 3) {
					pos.x = (float) strtod(words[0],0);
					pos.y = (float) strtod(words[1],0);
					pos.z = (float) strtod(words[2],0);
				} else {
					pos.x=0;
					pos.y=0;
					pos.z=0;
				}
				if (words.size() >= 6) {
					orient.x = (float) strtod(words[3],0);
					orient.y = (float) strtod(words[4],0);
					orient.z = (float) strtod(words[5],0);
				} else {
					orient.x = 0;
					orient.y = 1;
					orient.z = 0;
				}
				orient.normalize();
				points.push_back(ControlPoint(pos,orient));
			}
		}
		fclose(fp);
	}
	trainU = 0;
}

//****************************************************************************
//
// * write the control points to our simple format
//============================================================================
void CTrack::
writePoints(const char* filename)
//============================================================================
{
	FILE* fp = fopen(filename,"w");
	if (!fp) {
		printf("Can't open file for writing");
	} else {
		fprintf(fp,"%d\n",points.size());
		for(size_t i=0; i<points.size(); ++i)
			fprintf(fp,"%g %g %g %g %g %g\n",
				points[i].pos.x, points[i].pos.y, points[i].pos.z, 
				points[i].orient.x, points[i].orient.y, points[i].orient.z);
		fclose(fp);
	}
}

void CTrack::DimensionTransformation(GLfloat source[], GLfloat target[][4])
{
	//for uniform value, transfer 1 dimension to 2 dimension
	int i = 0;
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		{
			target[j][k] = source[i];
			i++;
		}
}

void CTrack::drawTrack(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix)
{
	GLfloat P[4][4];
	GLfloat MV[4][4];
	DimensionTransformation(ProjectionMatrix, P);
	DimensionTransformation(ModelViewMatrix, MV);

	//Bind the shader we want to draw with
	shaderProgram->bind();
	//Bind the VAO we want to draw
	vao.bind();

	//pass projection matrix to shader
	shaderProgram->setUniformValue("ProjectionMatrix", P);
	//pass modelview matrix to shader
	shaderProgram->setUniformValue("ModelViewMatrix", MV);

	// Bind the buffer so that it is the current active buffer.
	vvbo.bind();
	// Enable Attribute 0
	shaderProgram->enableAttributeArray(0);
	// Set Attribute 0 to be position
	shaderProgram->setAttributeArray(0, GL_FLOAT, 0, 3, NULL);
	//unbind buffer
	vvbo.release();

	// Bind the buffer so that it is the current active buffer
	cvbo.bind();
	// Enable Attribute 1
	shaderProgram->enableAttributeArray(1);
	// Set Attribute 0 to be color
	shaderProgram->setAttributeArray(1, GL_FLOAT, 0, 3, NULL);
	//unbind buffer
	cvbo.release();

	//Draw a triangle with 3 indices starting from the 0th index
	glDrawArrays(GL_LINE_STRIP, 0, vertices.size());
	//Disable Attribute 0&1
	shaderProgram->disableAttributeArray(0);
	shaderProgram->disableAttributeArray(1);

	//unbind vao
	vao.release();
	//unbind vao
	shaderProgram->release();
}

void CTrack::InitShader(QString vertexShaderPath, QString fragmentShaderPath)
{
	// Create Shader
	shaderProgram = new QOpenGLShaderProgram();
	QFileInfo  vertexShaderFile(vertexShaderPath);
	if (vertexShaderFile.exists())
	{
		vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
		if (vertexShader->compileSourceFile(vertexShaderPath))
			shaderProgram->addShader(vertexShader);
		else
			qWarning() << "Vertex Shader Error " << vertexShader->log();
	}
	else
		qDebug() << vertexShaderFile.filePath() << " can't be found";

	QFileInfo  fragmentShaderFile(fragmentShaderPath);
	if (fragmentShaderFile.exists())
	{
		fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
		if (fragmentShader->compileSourceFile(fragmentShaderPath))
			shaderProgram->addShader(fragmentShader);
		else
			qWarning() << "fragment Shader Error " << fragmentShader->log();
	}
	else
		qDebug() << fragmentShaderFile.filePath() << " can't be found";
	shaderProgram->link();
}

void CTrack::drawInit()
{
	InitShader("./Shader/CTrack.vs", "./Shader/CTrack.fs");
	vao.create();
	cvbo.create();
	vvbo.create();
	//vao.bind();
}

void CTrack::drawLinear(GLfloat* ProjectionMatrix, GLfloat* ModelViewMatrix)
{
	vertices.clear();
	colors.clear();
	vao.bind();
	for (int i = 0; i <= points.size(); i++) {
		Pnt3f p = points[i % points.size()].pos;
		vertices << QVector3D(p.x, p.y, p.z);
	}
	vvbo.bind();
	vvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	vvbo.allocate(vertices.constData(), vertices.size() * sizeof(QVector3D));
	vvbo.release();
	for (int i = 0; i <= points.size(); i++) {
		colors << QVector3D(1, 0, 0);
	}
	cvbo.bind();
	cvbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
	cvbo.allocate(colors.constData(), colors.size() * sizeof(QVector3D));
	cvbo.release();
	drawTrack(ProjectionMatrix, ModelViewMatrix);
}
