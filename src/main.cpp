
#include "AvrSupervising.h"

AvrSupervising *pApp = NULL;

void setup()
{
	pApp = AvrSupervising::create();
}

void loop()
{
	pApp->treeTick();
}

