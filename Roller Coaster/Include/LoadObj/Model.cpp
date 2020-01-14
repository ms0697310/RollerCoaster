#include "model.h"

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QVarLengthArray>

#include <QtOpenGL/QtOpenGL>
#include "Utilities/3dUtils.h"
Model::Model(const QString &filePath, int s, Pnt3f p)
	: m_fileName(QFileInfo(filePath).fileName()), rotateDegree(0)
{
	QFile file(filePath);
	if (!file.open(QIODevice::ReadOnly))
		return;
	pos = p;
	Pnt3f boundsMin( 1e9, 1e9, 1e9);
	Pnt3f boundsMax(-1e9,-1e9,-1e9);

	QTextStream in(&file);
	while (!in.atEnd()) {
		QString input = in.readLine();
		if (input.isEmpty() || input[0] == '#')
			continue;

		QTextStream ts(&input);
		QString id;
		ts >> id;
		if (id == "v") {
			Pnt3f p;
			for (int i = 0; i < 3; ++i) {
				ts >> p[i];
				boundsMin[i] = qMin(boundsMin[i], p[i]);
				boundsMax[i] = qMax(boundsMax[i], p[i]);
			}
			m_points << p;
		} else if (id == "f" || id == "fo") {
			QVarLengthArray<int, 4> p;

			while (!ts.atEnd()) {
				QString vertex;
				ts >> vertex;
				const int vertexIndex = vertex.split('/').value(0).toInt();
				if (vertexIndex)
					p.append(vertexIndex > 0 ? vertexIndex - 1 : m_points.size() + vertexIndex);
			}

			for (int i = 0; i < p.size(); ++i) {
				const int edgeA = p[i];
				const int edgeB = p[(i + 1) % p.size()];

				if (edgeA < edgeB)
					m_edgeIndices << edgeA << edgeB;
			}

			for (int i = 0; i < 3; ++i)
				m_pointIndices << p[i];

			if (p.size() == 4)
				for (int i = 0; i < 3; ++i)
					m_pointIndices << p[(i + 2) % 4];
		}
	}

	const Pnt3f bounds = boundsMax - boundsMin;
	const qreal scale = s / qMax(bounds.x, qMax(bounds.y, bounds.z));
	for (int i = 0; i < m_points.size(); ++i)
		m_points[i] = (m_points[i] + p - (boundsMin + bounds * 0.5)) * scale;

	m_normals.resize(m_points.size());
	for (int i = 0; i < m_pointIndices.size(); i += 3) {
		const Pnt3f a = m_points.at(m_pointIndices.at(i));
		const Pnt3f b = m_points.at(m_pointIndices.at(i+1));
		const Pnt3f c = m_points.at(m_pointIndices.at(i+2));

		const Pnt3f normal = cross(b - a, c - a).normalize();

		for (int j = 0; j < 3; ++j)
			m_normals[m_pointIndices.at(i + j)] += normal;
	}

	for (int i = 0; i < m_normals.size(); ++i)
		m_normals[i] = m_normals[i].normalize();
}

void Model::render(bool wireframe, bool normals) const
{
	glPushMatrix();
	
	glTranslatef(pos.x, pos.y, pos.z);
	float theta1 = -radiansToDegrees(atan2(orient.z, orient.x));
	glRotatef(theta1, 0, 1, 0);
	float theta2 = -radiansToDegrees(acos(orient.y));
	glRotatef(theta2, 0, 0, 1);
	glRotatef(rotateDegree, 0,1, 0);
	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	if (wireframe) {
		glVertexPointer(3, GL_FLOAT, 0, (float *)m_points.data());
		glDrawElements(GL_LINES, m_edgeIndices.size(), GL_UNSIGNED_INT, m_edgeIndices.data());
	} else {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
		glShadeModel(GL_SMOOTH);

		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, (float *)m_points.data());
		glNormalPointer(GL_FLOAT, 0, (float *)m_normals.data());
		glDrawElements(GL_TRIANGLES, m_pointIndices.size(), GL_UNSIGNED_INT, m_pointIndices.data());

		glDisableClientState(GL_NORMAL_ARRAY);
		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
	}

	if (normals) {
		QVector<Pnt3f> normals;
		for (int i = 0; i < m_normals.size(); ++i)
			normals << m_points.at(i) << (m_points.at(i) + m_normals.at(i) * 0.02f);
		glVertexPointer(3, GL_FLOAT, 0, (float *)normals.data());
		glDrawArrays(GL_LINES, 0, normals.size());
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();
}


