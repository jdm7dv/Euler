 /*
============================================================================
 Name        : Euler.c
 Author      : Jonathan Moore
 Version     : 0.1
 Copyright   : Jonathan Moore
 Description : Project Euler OpenMP in C
 ===========================================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#include "euler.h"

void p001()
{
	int result = 0;

	#pragma omp parallel for
	for (int i = 1; i < 1000; i++)
	{
		if (((i % 3) == 0) || ((i % 5) == 0))
		{
        result += i;
		}
	}

	printf("result = %d", result);

}



void p003()
{

}

