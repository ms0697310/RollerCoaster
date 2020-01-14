#ifndef TRAINVIEW_H  
#define TRAINVIEW_H

#include <QGLWidget> 
#include <QtGui>
#include <QtOpenGL>  
#include <GL/GLU.h>
#include <QtMultimedia/QMediaPlayer>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 
#include "Utilities/ArcBallCam.H"
#include "Utilities/3DUtils.H"
#include "Track.H"
#include "Human.h"
#include "Triangle.h"
#include "Square.h"
#include "Wave.h"
#include "Train.h"
#include "Hill.h"
#include "Stone.h"
#include <iostream>
#include <vector>

class AppMain;
class CTrack;

//#######################################################################
// TODO
// You might change the TrainView in order to add different objects to
// be drawn, or adjust the lighting, or ...
//#######################################################################


class TrainView : public QGLWidget, protected QOpenGLFunctions_4_3_Core
{  
	Q_OBJECT  
public:  
	explicit TrainView(QWidget *parent = 0);  
	~TrainView();  

public:
	// overrides of important window things
	//virtual int handle(int);
	virtual void paintGL();

	// all of the actual drawing happens in this routine
	// it has to be encapsulated, since we draw differently if
	// we're drawing shadows (no colors, for example)
	void drawStuff(bool doingShadows=false);
	void drawTrack(bool doingShadows);
	void drawTrain(float);
	void drawTrainObj(float);
	void drawTrainObj2(float, bool doingShadows);
	void drawStone();
	void interpolation();
	void insertCar();
	void deleteCar();
	//for human view change
	void frontHuman();
	void behindHuman();

	//void drawTrain();
	// setup the projection - assuming that the projection stack has been
	// cleared for you
	void setProjection();

	// Reset the Arc ball control
	void resetArcball();

	// pick a point (for when the mouse goes down)
	void doPick(int mx, int my);

	void initializeGL();
	void initializeTexture();
	void initSplineMatrix();

public:
	ArcBallCam		arcball;			// keep an ArcBall for the UI
	int				selectedCube;  // simple - just remember which cube is selected

	CTrack*			m_pTrack;		// The track of the entire scene

	QTime frameTime;
	int frameCount;
	float t_time;
	unsigned int DIVIDE_LINE;
	unsigned int BOARD_DISTANCE_LENGTH;
	unsigned int BOARD_LENGTH;
	typedef enum {
		spline_Linear = 0,
		spline_CardinalCubic = 1,
		spline_CubicB_Spline = 2
	} spline_t;
	typedef enum {
		DivideLine,
		ArcLength
	} interpolation_t;

	vector<Pnt3f>waypoints;
	Train* train;
	int carNum;
	int humanNum;
	int humanViewIndex;
	Model sampleCar;
	Human sampleHuman;
	vector<Model*> cars;
	vector<Human*> humans;
	QMediaPlayer* player;
	int camera;
	int curve;
	int track;
	bool isrun;
	Triangle* triangle;
	Square* square;
	Wave* wave;
	Hill* hill;
	std::vector<Stone*> stone;
	GLfloat ProjectionMatrex[16];
	GLfloat ModelViewMatrex[16];
	QVector<QOpenGLTexture*> Textures;

	spline_t type_spline;
	interpolation_t type_interpolation;

	int trainLineIndex;
	unsigned int trainLineILength;
	float BSplineMatrix[4][4];
	float CardinalMatrix[4][4];
};  
#endif // TRAINVIEW_H  