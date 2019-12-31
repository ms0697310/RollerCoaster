#ifndef MODEL_H
#define MODEL_H

#include <QtCore/QString>
#include <QtCore/QVector>

#include <math.h>
#include "Utilities/Pnt3f.H"


class Model
{
public:
	Model() {}
	Model(const QString &filePath, int s, Pnt3f p);

	void render(bool wireframe = false, bool normals = false) const;

	QString fileName() const { return m_fileName; }
	int faces() const { return m_pointIndices.size() / 3; }
	int edges() const { return m_edgeIndices.size() / 2; }
	int points() const { return m_points.size(); }
	void rotateTo(Pnt3f orient) { this->orient = orient; }
	void moveTo(Pnt3f pos) { this->pos = pos; }
	const Pnt3f getPosition() { return pos; }
private:
	QString m_fileName;
	QVector<Pnt3f> m_points;
	QVector<Pnt3f> m_normals;
	QVector<int> m_edgeIndices;
	QVector<int> m_pointIndices;
	Pnt3f pos;
	Pnt3f orient;
};

#endif