#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a7-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE: July 14, 2008                                                         *
*  PURPOSE:                                                                    *
*    An acoustical signal can be converted into an electrical signal by a      *
*    microphone and the electrical signal can then be converted into a series  *
*    of numbers representing the value of the electrical signal at discrete    *
*    time intervals. These values have been stored in a data file, and the     *
*    program analyzes the data to measure various aspects of the acoustical    *
*    signal.                                                                   *
*  PROGRAM INPUT:                                                              *
*    A series of floating point numbers representing the acoustical signal.    *
*    These values are read into array until end of file or until the array is  *
*    full.  The array double is size 1500.                                     *
*  PROGRAM OUTPUT:                                                             *
*    The output consists of a neat, well labeled message with the following    *
*    information in the following order:  1.  Number of sample points          *
*    2.  Maximum magnitude  3.  Average power  4.  Average magnitude           *
*    5.  Number of zero crossings                                              *
*******************************************************************************/
#define MAX 1500
int read_data(double arr[], int);
double avg_power(double arr[], int);
double avg_mag(double arr[], int);
int zero_cross(double arr[], int);
double max_mag(double arr[], int);

int main (void)
{
  /*defines variables*/
  int count = 0, cross = 0;
  double arr[MAX], avgpow = 0.0, avgmag = 0.0, thegreatest = 0.0;

  /*program intro*/
  printf("                 Sound Statistics\n");
  printf("                 ****************\n");

  /*runs through functions*/
  count = read_data(arr, MAX);
  thegreatest = max_mag(arr, count);
  avgpow = avg_power(arr, count);
  avgmag = avg_mag(arr, count);
  cross = zero_cross(arr, count);

  /*prints computer data*/
  printf("                 Number of sample points:  %d \n", count);
  printf("                 Maximum magnitude:  %g \n", thegreatest);
  printf("                 Average Power:  %f \n", avgpow);
  printf("                 Average Magnitude:  %f \n", avgmag);
  printf("                 Zero Crossings:  %d \n", cross);

return 0;
}/****************END OF MAIN FUNCTION****************/

/*******************************************************************************
*  read_data function read the data into the array until end of file or until  *
*  the array is full                                                           *
*******************************************************************************/
int read_data(double arr[], int size)
{
  /*defines variables*/
  int count = 0, status;
  double n = 0.0;

  /*prepares for end of file loop*/
  status = scanf("%lf", &n);

  /*data checking loop*/
  while (count < size && status != EOF)
  {
    arr[count] = n;
    count++;
    status = scanf("%lf", &n);
  }
  /*returns read data*/
  return count;
}/****************END OF READ_DATA FUNCTION****************/

/*******************************************************************************
*  avg_power function computes the average power (sum of all x^2 divided by    *
*  the amount in the array)                                                    *
*******************************************************************************/
double avg_power(double arr[], int count)
{
  /*defines variables*/
  int i = 0;
  double avgpow = 0.0, sum = 0.0;

  /*loops for sum with power to two*/
  for(i=0; i < count; i++)
  {
    sum+=pow(arr[i], 2);
  }

  /*sets to average power value*/
  avgpow = sum / i;

  /*returns value*/
  return avgpow;
}/****************END OF AVG_POWER FUNCTION****************/

/*******************************************************************************
*  avg_mag function computes the average magnitude (sum of all absolute values *
*  in array divided by the amount in the array)                                *
*******************************************************************************/
double avg_mag(double arr[], int count)
{
  /*defines variables*/
  int i = 0;
  double sum = 0.0, avgmag = 0.0;

  /*loops for absolute value sum*/
  for(i=0; i < count; i++)
  {
    sum+=fabs(arr[i]);
  }

  /*uses sum to compute average magnitude*/
  avgmag = sum/i;

  /*returns value*/
  return avgmag;
}/****************END OF AVG_MAG FUNCTION****************/

/*******************************************************************************
*  zero_cross function computes the number of zero crossings (the number times *
*  the signal changes from positive to negative).  A change from non-zero to   *
*  zero or zero to non-zero is not a zero crossing.                            *
*******************************************************************************/
int zero_cross(double arr[], int count)
{
  /*defines variables*/
  int i = 0, cross = 0;

  /*loops for number of zero crossings*/
  for(i=0; i < count; i++)
  {
    if ((arr[i]*arr[i+1]) < 0)
      cross++;
  }
  /*returns number of zero crossings*/
  return cross;
}/****************END OF ZERO_CROSSING FUNCTION****************/

/*******************************************************************************
*  max_mag function computers the maximum magnitude                            *
*  (the maximum absolute value)                                                *
*******************************************************************************/
double max_mag(double arr[], int count)
{
  /*defines variables*/
  int i=0, maxi;
  double thegreatest = 0.0;

  maxi = 0;

  /*loops for maximum magnitude*/
  for(i=0; i < count; i++)
  {
    if((fabs(arr[i])) > (fabs(arr[maxi])))
      maxi = i;
  }

  /*uses maxi (maximum magnitude) value in array set to new variable*/
  thegreatest = arr[maxi];
  thegreatest = fabs(thegreatest);

  /*returns value in array section*/
  return thegreatest;
}/****************END OF MAX_MAG FUNCTION****************/
