
#include <stdlib.h>

#include "LibcCustom.h"

// http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/memory/new/nothrow_t.html
const std::nothrow_t std::nothrow;

void *operator new(unsigned int size)
{
	return malloc(size);
}

void *operator new[](unsigned int size)
{
	return malloc(size);
}

// https://bitbashing.io/embedded-cpp.html
void operator delete(void *p)
{
	free(p);
}

void operator delete[](void *p)
{
	free(p);
}

// https://stackoverflow.com/questions/920500/what-is-the-purpose-of-cxa-pure-virtual
extern "C" void __cxa_pure_virtual()
{
	while (1);
}

