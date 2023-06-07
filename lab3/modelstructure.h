#ifndef MODELSTRUCTURE_H
#define MODELSTRUCTURE_H

#include <vector>

#include "point.h"
#include "edge.h"

class ModelStructure
{
public:
	ModelStructure() = default;
	ModelStructure(const std::vector <Point> &points, const std::vector <Edge> &edges);
	ModelStructure(const std::vector<Point> &points,  const std::vector<Edge> &edges, Point &center);

	void addPoint(const Point &point);
	void addEdge(const Edge &edge);

	const std::vector <Point> getPoints(void) const;
	const std::vector <Edge> getEdges(void) const;
	const Point getCenter() const;
	void updateCenter();

	void movePointsToOrigin(const Point &center);
	void movePointsToCenter(const Point &center);
	void transformPoints(const Matrix<double> &mtr);

	void transform(const Matrix<double> &mtr, const Point &center);

private:
	Point center;
	std::vector <Point> points;
	std::vector <Edge> edges;
};

#endif // MODELSTRUCTURE_H
