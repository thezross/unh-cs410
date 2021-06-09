#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a6-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE:  July 8, 2008                                                         *
*  PURPOSE:                                                                    *
*    Reads floating point numbers into an array and performs some simple       *
*    statistics on the array (mean, variance, standard deviation).             *
*  PROGRAM INPUT:                                                              *
*    An unknown number of values (could be none) that are read into an array   *
*    until end-of-file.  Stops reading if array is full.  Also handles empty   *
*    input files.                                                              *
*  PROGRAM OUTPUT:                                                             *
*    The output is the mean, variance, and standard deviation.                 *
*All other functions declared in math.h                                        *
*******************************************************************************/
/*sets size of array*/
#define MAX 256

int main (void)
{
  int status = 0, count = 0, i = 0, count_extra = 0;
  double arr[MAX], n=0.0, mean = 0.0, sum = 0.0, variance = 0.0;

  /*program intro*/
  printf("*****************************");
  printf("\n Array Statistics \n");
  printf("*****************************\n");

  /*reads input and sets as variable*/
  status = scanf("%lf", &n);

  /*fills size*/
  while(count < MAX && status != EOF)
  {
    arr[count] = n;
    count++;
    status = scanf("%lf", &n);
  }

  /*displays the number of unused variables*/
  while (status != EOF)
  {
    count_extra ++;
    status = scanf("%lf", &n);
  }

  if (count_extra > 0)
  {
    printf("*****Warning: there are %d unused values in the input file \n", count_extra);
  }

  /*if there is no data in the file it displays likewise*/
  if(count == 0)
    printf("*****Error: No data in file \n");
  else
  {
    /*reports statistics*/
    printf("         Statistics Report:\n");
    printf("         Number of values: %d \n", count);

    /*for mean*/
    for(i=0; i < count; i++)
    {
      sum+=arr[i];
    }
    mean = sum/i;
    printf("         Mean Value: %g\n", mean);

    /*for variance*/
    sum = 0.0;
    for(i=0; i < count; i++)
    {
      arr[i] = pow((arr[i]-mean), 2);
      sum+=arr[i];
    }
    variance=sum/(i-1);
    printf("         Variance %g\n", variance);

    /*for standard deviation*/
    printf("         Standard deviation: %g \n", sqrt(variance));
  }
  /*ending message*/
  printf("Goodbye \n");
  return 0;
}/********END OF PROGRAM********/
