#include "Train.h"

Train::Train(const QString& filePath, int s, Pnt3f p):Model(filePath, s, p), trainSpeed(MAX_TRAIN_SPEED/2.0),up(0,1,0)
{

	 
}

Pnt3f Train::getUp()
{
	return Pnt3f(up);
}

void Train::interpolationLinear(interpolation_t type_interpolation, vector<ControlPoint> points, float stepArcLength, int DIVIDE_LINE)
{

	vector<Pnt3f> tempWaypoints;
	vector<Pnt3f> tempWayorients;
	Pnt3f qt0;
	Pnt3f qt, qt1, orient_t;
	float arcLengthCounter = 0.0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		// pos
		Pnt3f cp_pos_p1 = points[i].pos;
		Pnt3f cp_pos_p2 = points[(i + 1) % points.size()].pos;
		// orient
		Pnt3f cp_orient_p1 = points[i].orient;
		Pnt3f cp_orient_p2 = points[(i + 1) % points.size()].orient;
		// 微調角度 防止180度翻轉問題

		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		if (cp_orient_p2 == -cp_orient_p1)
		{
			//若點位置斜率與微調的角度相同，則效果不佳。
			//故做了斜率判斷以及不同的角度微調。
			Pnt3f temp = cp_pos_p2 - cp_pos_p1;
			temp.normalize();
			if (temp.x / temp.z > 0)
				cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, -0.1);
			else
				cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, 0.1);
		}
		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		// 微調角度END

		float percent = 1.0f / DIVIDE_LINE;
		float t = 0;
		qt0 = cp_pos_p1;
		for (size_t j = 0; j < DIVIDE_LINE; j++) {
			
			t += percent;
			qt = (1 - t) * cp_pos_p1 + t * cp_pos_p2;
			orient_t = (1 - t) * cp_orient_p1 + t * cp_orient_p2;
			switch (type_interpolation)
			{
			case DivideLine:
				tempWaypoints.push_back(qt);
				tempWayorients.push_back(orient_t);
				break;
			case ArcLength:
				arcLengthCounter += (qt - qt0).length();
				if (arcLengthCounter >= stepArcLength)
				{
					arcLengthCounter -= stepArcLength;
					tempWaypoints.push_back(qt);
					tempWayorients.push_back(orient_t);
				}
				break;
			default:
				tempWaypoints.push_back(qt);
				tempWayorients.push_back(orient_t);
				break;
			}
			qt0 = qt;
		}
	}
	waypoints = tempWaypoints;
	wayorients = tempWayorients;
}

void Train::interpolationCardinalCubic(interpolation_t type_interpolation, vector<ControlPoint> points, float CardinalMatrix[4][4], float stepArcLength, int DIVIDE_LINE)
{

	vector<Pnt3f> tempWaypoints;
	vector<Pnt3f> tempWayorients;
	Pnt3f qt0;
	Pnt3f qt, qt1, orient_t;
	float arcLengthCounter = 0.0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		// pos
		Pnt3f cp_pos_p0 = points[(i - 1 + points.size()) % points.size()].pos;
		Pnt3f cp_pos_p1 = points[i].pos;
		Pnt3f cp_pos_p2 = points[(i + 1) % points.size()].pos;
		Pnt3f cp_pos_p3 = points[(i + 2) % points.size()].pos;
		// orient
		Pnt3f cp_orient_p0 = points[(i - 1 + points.size()) % points.size()].orient;
		Pnt3f cp_orient_p1 = points[i].orient;
		Pnt3f cp_orient_p2 = points[(i + 1) % points.size()].orient;
		Pnt3f cp_orient_p3 = points[(i + 2) % points.size()].orient;
		// 微調角度 防止180度翻轉問題

		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		if (cp_orient_p2 == -cp_orient_p1)
		{
			//若點位置斜率與微調的角度相同，則效果不佳。
			//故做了斜率判斷以及不同的角度微調。
			Pnt3f temp = cp_pos_p2 - cp_pos_p1;
			temp.normalize();
			if (temp.x / temp.z > 0)
				cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, -0.1);
			else
				cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, 0.1);
		}
		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		// 微調角度END

		float percent = 1.0f / DIVIDE_LINE;
		float t = 0;
		qt0 = cp_pos_p1;
		for (size_t j = 0; j < DIVIDE_LINE; j++) {
			t += percent;
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
						MTMatrix[i][0] += CardinalMatrix[i][j] * tMatrix[j][0];
				}
			}
			qt = MTMatrix[0][0] * cp_pos_p0 +
					MTMatrix[1][0] * cp_pos_p1 +
					MTMatrix[2][0] * cp_pos_p2 +
					MTMatrix[3][0] * cp_pos_p3;
			orient_t = MTMatrix[0][0] * cp_orient_p0 +
					MTMatrix[1][0] * cp_orient_p1 +
					MTMatrix[2][0] * cp_orient_p2 +
					MTMatrix[3][0] * cp_orient_p3;
			switch (type_interpolation)
			{
			case DivideLine:
				tempWaypoints.push_back(qt);
				tempWayorients.push_back(orient_t);
				break;
			case ArcLength:
				arcLengthCounter += (qt - qt0).length();
				if (arcLengthCounter >= stepArcLength)
				{
					arcLengthCounter -= stepArcLength;
					tempWaypoints.push_back(qt);
					tempWayorients.push_back(orient_t);
				}
				break;
			default:
				tempWaypoints.push_back(qt);
				tempWayorients.push_back(orient_t);
				break;
			}
			qt0 = qt;
		}
	}
	waypoints = tempWaypoints;
	wayorients = tempWayorients;
}

void Train::interpolationCubicB_Spline(interpolation_t type_interpolation, vector<ControlPoint> points, float BSplineMatrix[4][4], float stepArcLength, int DIVIDE_LINE)
{

	vector<Pnt3f> tempWaypoints;
	vector<Pnt3f> tempWayorients;
	Pnt3f qt0;
	Pnt3f qt, qt1, orient_t;
	float arcLengthCounter = 0.0;
	for (size_t i = 0; i < points.size(); ++i)
	{
		// pos
		Pnt3f cp_pos_p0 = points[(i - 1 + points.size()) % points.size()].pos;
		Pnt3f cp_pos_p1 = points[i].pos;
		Pnt3f cp_pos_p2 = points[(i + 1) % points.size()].pos;
		Pnt3f cp_pos_p3 = points[(i + 2) % points.size()].pos;
		// orient
		Pnt3f cp_orient_p0 = points[(i - 1 + points.size()) % points.size()].orient;
		Pnt3f cp_orient_p1 = points[i].orient;
		Pnt3f cp_orient_p2 = points[(i + 1) % points.size()].orient;
		Pnt3f cp_orient_p3 = points[(i + 2) % points.size()].orient;

		// 微調角度 防止180度翻轉問題
		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		if (cp_orient_p2 == -cp_orient_p1)
		{
			//若點位置斜率與微調的角度相同，則效果不佳。
			//故做了斜率判斷以及不同的角度微調。
			Pnt3f temp = cp_pos_p2 - cp_pos_p1;
			temp.normalize();
			if (temp.x / temp.z > 0)
				cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, -0.1);
			else
				cp_orient_p2 = cp_orient_p2 + Pnt3f(0.1, 0.1, 0.1);
		}
		cp_orient_p1.normalize();
		cp_orient_p2.normalize();
		// 微調角度END
		
		float percent = 1.0f / DIVIDE_LINE;
		float t = 0;
		qt0 = cp_pos_p1;
		for (size_t j = 0; j < DIVIDE_LINE; j++) {
			t += percent;
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
					MTMatrix[i][0] += BSplineMatrix[i][j] * tMatrix[j][0];
				}
			}
			qt = MTMatrix[0][0] * cp_pos_p0 +
					MTMatrix[1][0] * cp_pos_p1 +
					MTMatrix[2][0] * cp_pos_p2 +
					MTMatrix[3][0] * cp_pos_p3;
			orient_t = MTMatrix[0][0] * cp_orient_p0 +
					MTMatrix[1][0] * cp_orient_p1 +
					MTMatrix[2][0] * cp_orient_p2 +
					MTMatrix[3][0] * cp_orient_p3;
			switch (type_interpolation)
			{
			case DivideLine:
				tempWaypoints.push_back(qt);
				tempWayorients.push_back(orient_t);
				break;
			case ArcLength:
				arcLengthCounter += (qt - qt0).length();
				if (arcLengthCounter >= stepArcLength)
				{
					arcLengthCounter -= stepArcLength;
					if (tempWaypoints.size() == 0 || !(qt == tempWaypoints[tempWaypoints.size() - 1]))
					{
						//orient_t = qt0.getOrient(qt);
						tempWaypoints.push_back(qt);
						tempWayorients.push_back(orient_t);
					}
				}
				break;
			default:
				tempWaypoints.push_back(qt);
				tempWayorients.push_back(orient_t);
				break;
			}
			qt0 = qt;
		}
	}
	waypoints = tempWaypoints;
	wayorients = tempWayorients;
}
