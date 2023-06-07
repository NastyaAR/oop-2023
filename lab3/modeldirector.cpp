#include "modeldirector.h"

ModelDirector::ModelDirector()
{
	loader = std::make_shared<FileModelLoader>();
}

ModelDirector::ModelDirector(std::shared_ptr<FileModelLoader> &loader)
{
	this->loader = loader;
}

std::shared_ptr<Object> ModelDirector::create(std::shared_ptr<ModelBuilder> builder)
{
	loader->open(loader->getFileName());

	builder->build();

	vector<Point> points = loader->loadPoints();
	int amountPoints = points.size();

	std::vector<Edge> edges = loader->loadEdges(amountPoints);
	int amountEdges = edges.size();

	for (int i = 0; i < amountPoints; i++)
		builder->buildPoint(points[i].getX(), points[i].getY(), points[i].getZ());

	for (int i = 0; i < amountEdges; i++)
		builder->buildEdge(edges[i].getStartPoint(), edges[i].getFinishPoint());

	loader->close();

	return builder->getObject();
}

