
#include "AvrSupervising.h"

int main()
{
	AvrSupervising *pApp;

	pApp = AvrSupervising::create();
	if (!pApp)
		return -1;

	while (1)
		pApp->treeTick();

	return 0;
}

