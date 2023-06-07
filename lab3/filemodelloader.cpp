#include "modelbuilder.h"
#include <error.h>
#include "error.h"
#include "filemodelloader.h"

FileModelLoader::FileModelLoader() : file(std::make_shared<std::ifstream>()) {}

FileModelLoader::FileModelLoader(std::shared_ptr<std::ifstream> &fin)
{
	file = fin;
}

FileModelLoader::FileModelLoader(std::string &fname) : file(std::make_shared<std::ifstream>())
{
	this->fname = fname;
}

std::size_t FileModelLoader::loadCount()
{
	int count;

	*file >> count;

	return count;
}

Point FileModelLoader::loadPoint()
{
	double x, y, z;

	*file >> x >> y >> z;

	return Point(x, y, z);
}

std::vector<Point> FileModelLoader::loadPoints()
{
	std::vector<Point> vertexes;

	int vertexNum;
	*file >> vertexNum;

	if (vertexNum <= 0)
	{
		std::string msg = "wrong vertex num";
		throw SourceError(msg);
	}

	double x, y, z;

	for (int i = 0; i < vertexNum; i++)
	{
	   *file >> x >> y >> z;
	   vertexes.push_back(Point(x, y, z));
	}

	return vertexes;
}

std::vector<Edge> FileModelLoader::loadEdges(int &vertexNum)
{
	std::vector<Edge> links;

	int linksNum;
	*file >> linksNum;

	if (linksNum <= 0)
	{
		std::string msg = "Wrong edges num.";
		throw SourceError(msg);
	}

	int vertex1Index, vertex2Index;

	for (int i = 0; i < linksNum; i++)
	{
		*file >> vertex1Index >> vertex2Index;

		if (vertex1Index < 0 or vertex2Index < 0 or
			vertex1Index > vertexNum or vertex2Index > vertexNum)
		{
			std::string msg = "Wrong link data.";
			throw SourceError(msg);
		}

		links.push_back(Edge(vertex1Index, vertex2Index));
	}

	return links;
}

void FileModelLoader::open(std::string &fname)
{
	if (!file) {
		std::string message = "Error while open file.";
		throw FileError(message);
	}

	file->open(fname);

	if (!file) {
		std::string message = "Error while open file.";
		throw FileError(message);
	}
}

void FileModelLoader::close()
{
	if (!file) {
		std::string message = "Error while open file.";
		throw FileError(message);
	}

	try {
		file->close();
	} catch (std::ifstream::failure &error) {
		error.what();
	}
}

std::string &FileModelLoader::getFileName()
{
	return fname;
}

