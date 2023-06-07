#ifndef BASECOMMAND_H
#define BASECOMMAND_H

class BaseCommand {
public:
	BaseCommand() = default;
	~BaseCommand() = default;
	virtual void execute() = 0;
};

#endif // BASECOMMAND_H
