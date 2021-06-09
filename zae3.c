#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a3-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE:  June 13, 2008                                                        *
*  PURPOSE:                                                                    *
*    This program repeadly prompts for and reads in a floating point number     *
*    (type double) followed by an integer (type int) until the entered integer *
*    is less than or equal to zero.  The first number is the value at which we *
*    are taking the approximation (a floating point(radians)).  The second     *
*    value is an integer indicating how many terms to use in the approximation.*
*    The program will end if the integer is not greater than zero.  If it is,  *
*    it is calculated.                                                         *
*  Program Input:                                                              *
*    Floating point number = number of radians                                 *
*    Integer - the number of terms in the series                               *
*  Program Output:                                                             *
*    Program ends or is calculated using the cos(radians) and integer as the   *
*    amount of terms used.  The per line will be:  the number of terms, the    *
*    term value, the approximate sum, and then the error (difference between   *
*    the system value and the current approximate value).
*******************************************************************************
/*******************************************************************************
*  This function is used to calculate the factorial to later help approximate  *
*  the cos(x).  It will be declared as "factorial()""                          *
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
}
/*******************************************************************************
*  This function (main) will repeaditly prompt the user for an integer until   *
*  the integer is not greater then zero, then the program ends.  The integer   *
*  determines the amount of terms and the floating point represents the radians*
*  in cos(x).  Thiis is calculated and printed on a table.  The user is then   *
*  again prompted to enter new values.                                         *
*  The followinig computations are used in their relative order to compute the *
*  cos(x):  (pow(-1, count))*((pow(radians,(2*count)))/(factorial(2*count)))   *
*  All user inputs define variable functions except:                           *
*  FUNCTION: factorial                                                         *
*    factorial is defined in the previous function to calculate the actual math*
*    factorial since it cannot be declared from math.h                         *
*  FUNCTION: all others declared in math.h                                     *
*  FUNCTION:  fabs()                                                           *
*    Computes the absolute value for a flaoting point                          *
*******************************************************************************/
int main(void)
{
  /*variable declarations*/
  int n=0, count;
  double radians = 0.0;
  double value = 0.0;
  double termvalue = 0.0;
  double apoxvalue = 0.0;
  double errvalue = 0.0;

  /*program title*/
  printf("\n********************************************\n");
  printf("**      Acme Partial Sum Approximator     **");
  printf("\n********************************************\n");

  /*user prompt and input*/
  printf("\nEnter radians and number of terms\n");
  scanf("%lf", &radians);
  scanf("%d", &n);

  /*loop*/
  while (n > 0)
  {
    /*echoes, scan, and computes cos(x) built in function for later accuracy*/
    printf("************************************************\n");
    printf("*   Approximating cos(%g) with %d terms \n", radians, n);
    value = cos(radians);
    printf("*   The systems value of cos(%g) is  %.8f \n", radians, value);
    printf("************************************************\n");

    /*table*/
    printf("\nn    Term    Approx Sum    ERROR\n");

    /*sets the count start to zero and makes number of terms accurate*/
    count = -1;
      /*interloop*/
      while (count < (n-1))
      {
      /*index for the term*/
      count = count + 1;

      /*value of the term*/
      termvalue = (pow(-1, count))*((pow(radians,(2*count)))/(factorial(2*count)));

      /*current approximate value*/
      apoxvalue = termvalue + apoxvalue;

      /*the error*/
      errvalue = value - apoxvalue;
      errvalue = fabs(errvalue);

      /*prints the table value*/
      printf("%02d %16.8f %16.8f %16.6g \n", count, termvalue, apoxvalue, errvalue);
      }

  /*done*/
  printf("\n Done! \n");

  /*menu for new set of input*/
  printf("\nEnter radians and number of terms\n");
  scanf("%lf", &radians);
  scanf("%d", &n);

  /*clears values for any previous input so they are not passed over*/
  termvalue = 0.0;
  apoxvalue = 0.0;
  errvalue = 0.0;
  }
/*end of program print*/
printf("\n Goodbye \n");
return 0;
}/*****************END OF PROGRAM*****************/
