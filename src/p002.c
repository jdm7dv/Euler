#include "euler.h"
/*
	 * Computers are fast, so we can implement this solution directly without any clever math.
	 * Because the Fibonacci sequence grows exponentially by a factor of 1.618, the sum is
	 * bounded above by a small multiple of 4 million. Thus the answer fits in a Java int type.
*/
void p002()
{
	int sum = 0;
	int x = 1;  // Represents the current Fibonacci number being processed
	int y = 2;  // Represents the next Fibonacci number in the sequence
	char result [50];

	while (x <= 4000000)
	{
		if (x % 2 == 0)
		{
			sum += x;
		}

		int z = x + y;
		x = y;
		y = z;
	}
			printf(result, "%f", sum);
			printf("\n The string for the number is %s", result);
			getchar();

}
