#ifndef __EULER_H__
#define __EULER_H__

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

struct
{
	void (*p001)(struct eulersolution*);
	void (*p002)(struct eulersolution*);

} eulersolution;

#endif
