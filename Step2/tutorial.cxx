// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "教學設定.h"
#ifdef USE_MYMATH
	#include "MathFunctions/MathFunctions.h"
#endif
int main (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout,"%s 版本 %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);
    fprintf(stdout,"使用方式： %s 數字\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
	
#ifdef USE_MYMATH
  double outputValue = mysqrt(inputValue);
#else
  double outputValue = sqrt(inputValue);
#endif
	
  fprintf(stdout,"%g 的平方根為 %g\n",
          inputValue, outputValue);
  return 0;
}
