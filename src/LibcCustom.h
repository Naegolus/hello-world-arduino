
#ifndef LIBCCUSTOM_H
#define LIBCCUSTOM_H

namespace std
{
struct nothrow_t {};
extern const nothrow_t nothrow;
}

void *operator new(unsigned int size);
void *operator new[](unsigned int size);

#endif

