#include "facade.h"

void Facade::execute(BaseCommand &cmd)
{
	cmd.execute();
}
