#ifndef EDGE_H
#define EDGE_H

#include <cstddef>

class Edge
{
public:
	Edge() = default;
	Edge(const std::size_t startPoint, const std::size_t finishPoint);
	Edge(const Edge &Edge) = default;

	~Edge() = default;

	std::size_t getStartPoint() const;
	std::size_t getFinishPoint() const;

	void setStartPoint(const std::size_t index);
	void setFinishPoint(const std::size_t index);

private:
	std::size_t start;
	std::size_t finish;
};


#endif // EDGE_H
