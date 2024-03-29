#ifndef MYERROR_H
#define MYERROR_H

#include <exception>
#include <string>

class BaseError : public std::exception {
public:
	BaseError() = default;
	explicit BaseError(std::string &message) : error_info(message){};

	const char *what() const noexcept override {
		return "Something wrong with viewer.";
	}

	const std::string &get_info() const noexcept {
		return error_info;
	}

protected:
	std::string error_info;
};

class CameraError : public BaseError {
public:
	CameraError() = default;
	explicit CameraError(std::string &message) : BaseError(message){};

	const char *what() const noexcept override {
		return "Camera doesn't set.";
	}
};

class SourceError : public BaseError {
public:
	SourceError() = default;
	explicit SourceError(std::string &message) : BaseError(message){};

	const char *what() const noexcept override {
		return "Load corrupt or does not exist.";
	}
};

class ModelError : public BaseError {
public:
	ModelError() = default;
	explicit ModelError(std::string &message) : BaseError(message){};

	const char *what() const noexcept override {
		return "Error while building model.";
	}
};

class FileError : public BaseError {
public:
	FileError() = default;
	explicit FileError(std::string &message) : BaseError(message){};

	const char *what() const noexcept override {
		return "Error while open file.";
	}
};

#endif // MYERROR_H
