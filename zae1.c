#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a4-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE:  May 31, 2008                                                         *
*  PURPOSE:                                                                    *
*    This program will print out the volume of a box, cylinder, and a frustum. *                                             *                                                               *
*  Program Input:                                                              *
*    Box = three lengths of sides of the box;                                  *
*    Cylinder = radius of base and height;                                     *
*    Frustum = small radius, large radius, and height;                         *                                                     *
*  Program Output:                                                             *
*    The volume of all three individual shapes                                 *
*******************************************************************************/
/*******************************************************************************
*  This function (main) will ask for the required input for a box then each    *                                                      *
*  back the input and compute the volume.  It will then proceed to a cylinder  *                                                         *
*  and frustum, repeating the same steps but with relative answers to it's     *                                                      *
*  it's shape;                                                                 *
*  The following computations are used in their relative order to compute the  *                                                                    *
*  volume in cm-cubed:                                                         *                                                               *
*  Box = side1 * side2 * side3                                                 *                                                             *
*  Cylinder = (pi * height)(a^2+ab+b^2)                                        *
*  Frustum = (pi*height/3)(a^2+ab_b^2)                                         *
*  All user inputs define variable functions except:                           *                                                     *
*  FUNCTION: M_PI                                                              *
*    Is the equivilency of pi                                                  *
*******************************************************************************/
int main(void)
{
  /*variable declarations*/
  double sone = 0.0;
  double stwo = 0.0;
  double sthree = 0.0;
  double radius = 0.0;
  double height = 0.0;
  double smallradius = 0.0;
  double largeradius = 0.0;
  double hght = 0.0;
  double volume = 0.0;

  /*title*/
  printf("/n       Solid Volume Computational Program       \n");
  printf("        ==================================        \n");

  /*This will prompt the user for the orrect number and type of parameters
  needed for a box, echo, and compute volume*/

  /*input*/
  printf("\nEnter three lengths for the sides of a box >>\n");
  scanf( "%lf", &sone);
  scanf( "%lf", &stwo);
  scanf( "%lf", &sthree);

  /*echos input*/
  printf("The lengths for the sides of the box are >> %f, %f, %f cm\n", sone, stwo, sthree);
  printf("\n------------------------------------------\n");

  /*process*/
  volume = sone * stwo * sthree;

  /*output*/
  printf("The volume of the box is \n %f cm-cubed", volume);
  printf("\n------------------------------------------\n");

  /*This will prompt the user for the correct number and type of paramteres
  needed for a cylinder, echo, and compute the volune*/

  /*input*/
  printf("\nEnter radius and height for a cylinder >>\n");
  scanf("%lf", &radius);
  scanf("%lf", &height);

  /*echos input*/
  printf("The height and the radius entered are >> %f, %f cm\n", radius, height);
  printf("\n------------------------------------------\n");

  /*process*/
  volume = M_PI *(radius*radius)*height;

  /*output*/
  printf("The volume of the cylinder is\n %f cm-cubed", volume);
  printf("\n------------------------------------------\n");

  /*This will prompt the user for the correct number and type of parameters
  needed for a frustum, echo, and compute the volume*/

  /*input*/
  printf("\nEnter the small radius, large radius, and height for the frustum >>\n");
  scanf("%lf", &smallradius);
  scanf("%lf", &largeradius);
  scanf("%lf", &hght);

  /*echos input*/
  printf("The 2 radii and height entered are >> %f, %f, %f cm\n", smallradius, largeradius, hght);
  printf("\n------------------------------------------\n");

  /*process*/
  volume = ((M_PI * hght)/3) * ((smallradius) + (smallradius *largeradius) + (largeradius * largeradius));

  /*output*/
  printf("The volume of the frustum is \n %f cm-cubed", volume);
  printf("\n------------------------------------------\n");
  printf("\nGoodbye\n");
  return 0;
}/************END OF PROGRAM************/
