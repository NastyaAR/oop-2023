#include "edge.h"

Edge::Edge(const std::size_t startPoint, const std::size_t finishPoint)
{
	start = startPoint;
	finish = finishPoint;
}

std::size_t Edge::getStartPoint() const
{
	return start;
}

std::size_t Edge::getFinishPoint() const
{
	return finish;
}

void Edge::setStartPoint(const std::size_t index)
{
	start = index;
}

void Edge::setFinishPoint(const std::size_t index)
{
	finish = index;
}
