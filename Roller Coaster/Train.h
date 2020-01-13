#pragma once
#include "LoadObj\Model.h"
#include "ControlPoint.H"
#include <vector>
using namespace std;
class Train :
	public Model
{
public:
	Train(const QString& filePath, int s, Pnt3f p);

	//waypoints per frame
	float MAX_TRAIN_SPEED =5;
	float trainSpeed;

	vector<Pnt3f> waypoints;
	vector<Pnt3f> wayorients;
	typedef enum {
		spline_Linear = 0,
		spline_CardinalCubic = 1,
		spline_CubicB_Spline = 2
	} spline_t;
	typedef enum {
		DivideLine,
		ArcLength
	} interpolation_t;

	void interpolationLinear(interpolation_t type_interpolation, vector<ControlPoint> points, float stepArcLength=200.0, int DIVIDE_LINE=500);
	void interpolationCardinalCubic(interpolation_t type_interpolation, vector<ControlPoint> points, float CardinalMatrix[4][4], float stepArcLength = 200.0, int DIVIDE_LINE = 500);
	void interpolationCubicB_Spline(interpolation_t type_interpolation, vector<ControlPoint> points, float BSplineMatrix[4][4], float stepArcLength = 200.0, int DIVIDE_LINE = 500);
};

