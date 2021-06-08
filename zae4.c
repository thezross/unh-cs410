#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a4-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE:  June 13, 2008                                                        *
*  PURPOSE:                                                                    *
*    The program repeatedly reads in an integer (type int) and floating point  *
*    numbers (type double).  The integer selects the calculation type.  If a   *
*    delta is entered less then zero, then it is assigned .0001.  If an integer*                                              *
*    is anything other then one, two, or three, then it is not aknowledged for *
*    that loop.                                                                *
*  Program Input:                                                              *
*    Floating point number = number of x (terms), and d (delta estimation)     *                        *
*    Integer = the selection between cos, sin, and exp                         *                                                     *
*  Program Output:                                                             *
*    Program ends with no input or is calculated using the exp(x), cos(x),     *
*    or sine(x).  Also requires integer selection.  The d is the delta,        *
*    finishing the loop estimation.                                            *
*    The per line will be:  the number of terms, the term value,               *
*    the approximate sum, and then the error (difference between the system    *
*    value and the current approximate value.)                                 *
*    All other functions declared in math.h                                    *
*******************************************************************************/
double factorial (int);
void exp_approx(double, double);
void sine_approx(double, double);
void cos_approx(double, double);

int main(void)
{
  int c = 0;
  double x = 0.0;
  double d = 0.0;
  double status = 0.0;

  printf("****************************************\n");
  printf("    Welcome to the Exponential Evaluator\n");
  printf("****************************************\n");

  status = scanf("%d%lf%lf", &c, &x, &d);

  while(status != EOF)
  {
    if (d < 0.0)
    {
      printf("Invalid Criterion, using 0.0001\n\n");
      d = 0.001;
    }
    printf("Processing input: %d, %g, %g\n", c, x, d);

    if (c == 1)
      exp_approx(x, d);
    else if (c == 3)
      sine_approx(x, d);
    else if (c == 2)
      cos_approx(x, d);
    else
      printf("Invalid choice entered, ignoring input\n\n");

    status = scanf("%d%lf%lf", &c, &x, &d);
  }
printf("Goodbye\n");

return 0;
}/**************END OF MAIN PROGRAM**************/

/*******************************************************************************
*  This function is used to calculate the factorial to later help approximate  *
*  the cos(x).  It will be declared as "factorial()"                           *
*******************************************************************************/

double factorial (int n)
{
  double fact = 1;
  while (n > 0)
  {
    fact = fact * n;
    n = n - 1;
  }
  return fact;
}/**************END OF FACTORIAL FUNCTION**************/

/*******************************************************************************
*  This function handles the exponential approximation for                     *
*  one set of valid input values.  It should print out                         *
*  the table on the approximation of e^x with criterion d                      *
*  and thent he final estimate of e^x.                                         *
*******************************************************************************/
void exp_approx( double x, double d)
{
  int count = -1;
  double value = 0.0;
  double termvalue = 10.0;
  double aproxvalue = 0.0;
  double errvalue = 0.0;

  /*echos scan and computes exp(x) built in function for later accuracy*/
  printf("************************************************************\n");
  printf("  Approximating exp(%g) with criteria %g \n", x, d);
  printf("************************************************************\n");
  printf("\nn         Term n         Approxmation\n");

  while (fabs(termvalue) > d)
{
  /*index for the term*/
  count = count + 1;

  /*value of the term*/
  termvalue = ((pow(x, count))/(factorial(count)));

  /*current approximate value*/
  aproxvalue = termvalue + aproxvalue;

  /*the error*/
  errvalue = value - aproxvalue;

  /*prints the table value*/
  printf("%d  %16.7f  %16.7f\n", count, termvalue, aproxvalue);
}
  printf("-------------------------------------------------------------\n");

  printf("Final approximation of exp (%g) is %g\n", x, aproxvalue);
  value = exp(x);
  printf("System exp (%g) is %g \n", x, value);
  errvalue = value - aproxvalue;
  errvalue = fabs(errvalue);
  printf("Error is %g \n", errvalue);
  printf("-------------------------------------------------------------\n\n");
}/**************END OF EXP FUNCTION**************/

/*******************************************************************************
*  This function handles the sine approximation for                            *
*  one set of valid input values.  It should print out                         *
*  the table on the approximation of sin with criterion d                      *
*  and thent he final estimate of sin(x).                                      *
*******************************************************************************/
void sine_approx(double x, double d)
{
  int count = -1;
  double value = 0.0;
  double termvalue = 10.0;
  double aproxvalue = 0.0;
  double errvalue = 0.0;

  /*echos scan and computes sin(x) built in function fot later accuracy*/
  printf("************************************************************\n");
  printf("  Approximating sin(%g) with criteria %g \n", x, d);
  printf("************************************************************\n");
  /*table*/
  printf("\nn         Term n         Approxmation\n");

  while(fabs(termvalue) > d)
  {
    /*index for the term*/
    count = count + 1;

    /*value of the term*/
    termvalue = (pow(-1, count))*(((pow(x,((2*count)+1)))/(factorial((2*count)+1))));

    /*current approximate value*/
    aproxvalue = termvalue + aproxvalue;

    /*the error*/
    errvalue = value - aproxvalue;

    /*prints the table value*/
    printf("%d %16.7f  %16.7f \n", count, termvalue, aproxvalue);
  }
  printf("-------------------------------------------------------------\n");
  printf("Final approximation of sin (%g) is %g\n", x, aproxvalue);
  value = sin(x);
  printf("System sin (%g) is %g \n", x, value);
  errvalue = value - aproxvalue;
  errvalue = fabs(errvalue);
  printf("Error is %g \n", errvalue);
  printf("-------------------------------------------------------------\n");
}/********END OF SINE FUNCTION********/

/*******************************************************************************
*  This function handles the cosine approximation for                          *
*  one set of valid input values.  It should print out                         *
*  the table on the approximation of cos(x) with criterion d                   *
*  and thent he final estimate of cos(x).                                      *
*******************************************************************************/
void cos_approx(double x, double d)
{
  int count = -1;
  double value = 0.0;
  double termvalue = 10.0;
  double aproxvalue = 0.0;
  double errvalue = 0.0;

  /*echos scans and computes cos(x) built in functino for later accuracy*/
  printf("************************************************************\n");
  printf("  Approximating cos(%g) with criteria %g \n", x, d);
  printf("************************************************************\n");
  /*table*/
  printf("\nn         Term n         Approxmation\n");

  while(fabs(termvalue) > d)
  {
    /*index for the term*/
    count = count + 1;

    /*value of the term*/
    termvalue = (pow(-1, count))*((pow(x,(2*count)))/(factorial(2*count)));

    /*current approximate value*/
    aproxvalue = termvalue + aproxvalue;

    /*prints the table value*/
    printf("%d %16.7f  %16.7f \n", count, termvalue, aproxvalue);
  }
  printf("-------------------------------------------------------------\n");
  printf("Final approximation of exp (%g) is %g\n", x, aproxvalue);
  value = cos(x);
  printf("System cos (%g) is %g \n", x, value);
  errvalue = value - aproxvalue;
  errvalue = fabs(errvalue);
  printf("Error is %g \n", errvalue);
  printf("-------------------------------------------------------------\n\n");
}/********END OF COS FUNCTION********/
