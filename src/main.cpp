
#include "AvrSupervising.h"

AvrSupervising *pApp = NULL;

int main()
{
	AvrSupervising *pApp = AvrSupervising::create();
	if (!pApp)
		return -1;

	while (1)
		pApp->treeTick();

	return 0;
}

