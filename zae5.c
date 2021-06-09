#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a5-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE:  July 1, 2008                                                         *
*  PURPOSE:                                                                    *
*    This program find the roots of a function, that is, given a function to   *
*    find a value of x where f(x)=0.  The bisection method is the root-        *
*    finding algorithm used to find the roots of functions (approximating)     *
*    the root of a function.  Several functions will carry out these needs.    *
*  PROGRAM INPUT:                                                              *
*    The input consists of an unknown number (0 or more) of data sets.  Each   *                                                         *
*    set has seven items which are all floating point numbers, they are:       *
*    1.  d the constant term in the polynomial                                 *
*    2.  c the coefficient of the x term in the polynomial                     *
*    3.  b the coefficient of the x^2 term in the polynomial                   *
*    4.  a the coefficient of the x^3 term in the polynomial                   *
*    5.  x1 the lower (left) endpoint of the interval on which the root search *
*    6.  x2 the upper (right endpooint of the interval on which the root search*
*    7.  y_critical (critical) the tolerance value that estimates root         *
*        closeness                                                             *
*  PROGRAM OUTPUT:                                                             *
*    1.  Checks data validity: x1 must be greater than x2, f(x) and f(x2) must *                                                              *
*        have opposite signs, y_critical must be positive.  A specific data    *
*        error message is printed for each.                                    *
*    2.  A table of:  the iteration number, the left, and right current values,*
*        the midpoint (mid) of the current interval, and the functiional value *
*        of mid, fmid.                                                         *
*    3.  Final root estimate                                                   *
*All other functions declared in math.h                                        *
*******************************************************************************/
double ev_poly(double, double, double, double, double);
int verifyz(double, double, double, double, double, double, double);
void recallz(double, double, double, double, double, double, double);
void tablez(double, double, double, double, double, double, double);
int point_param(double *, double *, double *, double *, double *, double *, double *);

int main (void)
{
  int status = 0, flag = 0;
  double d = 0.0, c = 0.0, b = 0.0, a = 0.0, left = 0.0, right = 0.0,
  critical = 0.0, mid = 0.0;

  status = point_param( &d, &c, &b, &a, &left, &right, &critical);

  printf("======================================================\n");
  printf("    Welcome to the Bisection Cubic Root Finder\n");
  printf("\n  We will now process root searches\n");
  printf("======================================================\n");

  while (status != EOF)
  {
    ev_poly(d, c, b, a, mid);
    recallz(d, c, b, a, left, right, critical);
    flag = verifyz(d, c, b, a, left, right, critical);

    if (flag != 0)
      tablez(d, c, b, a, left, right, critical);

    status = point_param(&d, &c, &b, &a, &left, &right, &critical);
  }
printf("Goodbye\n");
return 0;
}/***************END OF MAIN FUNCTION***************/

/*******************************************************************************
*  Accepts fiive doubles as arguements and returns value of ax^3+bx^2+cx+d     *
*******************************************************************************/
double ev_poly(double d, double c, double b, double a, double x)
{
  double value = 0.0;
  value = (a*(pow(x,3)))+((b*(pow(x, 2)))+(c*x)+d);
  return value;
}/***************END of EV_POLY FUNCTION***************/

/*******************************************************************************
*  This is of type int(boolean) and accepts seven doubles as arguements.  It   *
*  checks the data and prints out any required error messages.  It will return *
*  true if data is valid and false if not.                                     *
*******************************************************************************/
int verifyz(double d, double c, double b, double a, double left, double right,
double critical)
{
  int flag = 1;

  /*loops for data errors*/
  if (critical < 0.0)
  {
    printf("Data error:  critical value must be greater than zero \n");
    flag = 0;
  }
  if (left > right)
  {
    printf("Data error: left must be less than right\n");
    flag = 0;
  }
  if ((ev_poly(d, c, b, a, left))*(ev_poly(d, c, b, a, right)) >= 0.0)
  {
    printf("Data error: function does not have opposite signs on endpoints\n");
    flag = 0;
  }
return flag;
}/***************END OF VERIFYZ FUNCTIION***************/

/*******************************************************************************
*  This is of type int(boolean) and accepts seven doubles as arguements.  It   *
*  echos the inpt in a nice format.                                            *
*******************************************************************************/
void recallz(double d, double c, double b, double a, double left, double right, double critical)
{
  printf("======================================================\n");
  printf("For polynomial %gx^3 + %gx^2 + %gx + %g\n", a, b, c, d);
  printf("with endpoints:  Left = %.2f  Right = %.2f \n", left, right);
  printf("with tolerance:  %g \n \n", critical);
}/***************END OF RECALLZ FUNCTION***************/

/*******************************************************************************
*  This is of type int(boolean) and accepts seven doubles as arguements.  It   *
*  prints out the table and final root estimate for one set of data.           *
*******************************************************************************/
void tabelz(double d, double c, double b, double a, double left, double right, double critical)
{
  int count = 1;

  double mid = 0.0, fmid = 0.0;

  /*sets up table for data*/
  printf("\n Root finder proceeds as follows:  \n");
  printf("\n Try#    left    right    mid    f(mid)\n");
  printf("\n=====    ====    ====    ====    ======\n");

  /*prints out the table with loop*/
  mid = (right+left)/2;
  fmid = (ev_poly(d, c, b, a, mid));
  printf("%2d  %16.5f  %16.5f  %16.5f  %16.5f\n", count, left, right, mid, fmid);
  while((fabs(fmid)) > critical)
  {
    count = count + 1;
    if  ((fmid * ev_poly(d, c, b, a, left)) < 0)
    {
      right = mid;
    }
    else
    {
      left = mid;
    }
    mid = (right + left)/2;
    fmid = (ev_poly(d, c, b, a, mid));
    printf("%2d  %16.5f  %16.5f  %16.5f  %16.5f\n", count, left, right, mid, fmid);
  }
  /*prints out where root is found at*/
  printf("  All done ---\n");
  printf("Root found at:  x = %.5f, F(x) = %g \n", mid, fmid);
  printf("====================================================== \n \n \n");
}/***************END OF TABLEZ FUNCTION***************/

/*******************************************************************************
*  This is of type int(boolean) and accepts seven doubles as arguements. The   *
*  function should read in the data and return the scanf value.                *
*******************************************************************************/
int point_param(double *d, double *c, double *b, double *a, double *left, double *right, double *critical)
{
  int status = 0;
  status = scanf("%lf%lf%lf%lf%lf%lf%lf", &*d, &*c, &*b, &*a, &*left, &*right, &*critical);
  return status;
}/***************END OF POINT_PARAM FUNCTION***************/
