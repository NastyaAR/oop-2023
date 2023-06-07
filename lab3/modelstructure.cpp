#include "modelstructure.h"

ModelStructure::ModelStructure(const std::vector <Point> &points, const std::vector <Edge> &edges) :
	points(points), edges(edges) { }

ModelStructure::ModelStructure(const std::vector<Point> &points, const std::vector<Edge> &edges,
							   Point &center):
	center(center), points(points), edges(edges) { }


void ModelStructure::addPoint(const Point &point)
{
	points.push_back(point);
}

void ModelStructure::addEdge(const Edge &edge)
{
	edges.push_back(edge);
}

const std::vector <Point> ModelStructure::getPoints(void) const
{
	return points;
}

const std::vector <Edge> ModelStructure::getEdges(void) const
{
	return edges;
}

const Point ModelStructure::getCenter() const
{
	return center;
}

void ModelStructure::updateCenter()
{
	center = Point(0, 0, 0);
	size_t count = 0;

	for (const auto &element : points)
	{
		center = center + element.getCenter();
		count++;
	}

	center = Point(center.getX() / count,
					 center.getY() / count,
					 center.getZ() / count);
}

void ModelStructure::movePointsToOrigin(const Point &center)
{
	Point diff = Point(0, 0, 0) - center;

	Matrix<double> mtr = {{    1,            0,            0,             0      },
						  {    0,            1,            0,             0      },
						  {    0,            0,            1,             0      },
						  {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

	transformPoints(mtr);
	updateCenter();
}

void ModelStructure::movePointsToCenter(const Point &center)
{
	Point diff = center - Point(0, 0, 0);

	Matrix<double> mtr = {{    1,            0,            0,             0      },
						  {    0,            1,            0,             0      },
						  {    0,            0,            1,             0      },
						  {diff.getX(),  diff.getY(),  diff.getZ(),       1      }};

	transformPoints(mtr);
	updateCenter();
}

void ModelStructure::transformPoints(const Matrix<double> &mtr)
{
	for (auto &edge : points)
		edge.transform(mtr);
}

void ModelStructure::transform(const Matrix<double> &mtr, const Point &center)
{
	updateCenter();

	movePointsToOrigin(center);
	transformPoints(mtr);
	movePointsToCenter(center);
}




