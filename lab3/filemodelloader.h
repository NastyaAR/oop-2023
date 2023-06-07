#ifndef FILEMODELLOADER_H
#define FILEMODELLOADER_H

#include "basemodelloader.h"

class FileModelLoader : public BaseModelLoader {
public:
	FileModelLoader();
	explicit FileModelLoader(std::shared_ptr<std::ifstream> &fin);
	explicit FileModelLoader(std::string &fname);
	~FileModelLoader() override = default;

	std::size_t loadCount();
	Point loadPoint();
	std::vector<Point> loadPoints();
	std::vector<Edge> loadEdges(int &amountPoints);

	void open(std::string &fname) override;
	void close() override;

	std::string &getFileName();

protected:
	std::shared_ptr<std::ifstream> file;

private:
	std::string fname;
};

#endif // FILEMODELLOADER_H
