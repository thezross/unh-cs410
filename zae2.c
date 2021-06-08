#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a2-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE:  June 7, 2008                                                         *
*  PURPOSE:                                                                    *
*    Prompt with program menu then calculate frustum input,                    *
*    icosahedron input, or quit.                                               *
*  Program Input:                                                              *
*    Frustum = small radius, large radius, and height;                         *
*    Icosahedron = edge;                                                       *
*  Program Output:                                                             *
*    Quit program, frustrum or icosahedron volume in cm-cubed and in-cubed     *
*******************************************************************************/

/*******************************************************************************
*  This function (main) will prompt the user with a menu choice to quit the    *
*  program, compute a frustrum, or compute an icosahedron.  Upon input         *
*  selection, the program will ask for required input information upon the     *
*  relative selection.  The program will continue to prompt the menu until     *
*  quit is selected.                                                           *
*  The following computations are used in their relative order to compute the  *
*  volumer in cm-cubed:                                                        *
*    Frustum = (pi*height/3)(a^2+ab+b^2)                                       *
*    Icosahedron = (5/12)(3+sqrt(5)a^3)                                        *
*  All user unputs define variable functions except:                           *
*    FUNCTION:  PI                                                             *
*      Pi is defined as 3.14159                                                *
*    FUNCTION:  CMTOINCH                                                       *
*      Converts cm-cubed to in-cubed                                           *
*******************************************************************************/
#define PI 3.14159
#define CMTOINCH 0.3937
int main(void)
{
  /* variable declarations */
  double smallradius = 0.0;
  double largeradius = 0.0;
  double height = 0.0;
  double edge = 0.0;
  double volume = 0.0;
  int answer = 1;

  /* program title */
  printf( "\n Solid Volume Computational Program \n");
  printf( "\n ================================== \n");

  /* MENU CHOICE PROMPT */
  printf( "\n Choose one of the following options:\n");
  printf( "\n ====================================\n");
  printf( "      0 Quit\n");
  printf( "      1 Frustum\n");
  printf( "      2 Icosahedron\n");
  scanf("%d", &answer);
  while (answer != 0)
  {
    if(answer==1)
  {
  /*WHEN 1, FRUSTUM, IS SELECTED FROM THE MENU*/
  /*prompt for frustum*/
  printf("\nEnter the small radius, large radius and height for the frustum  >\n");
  scanf( "%lf", &smallradius);
  scanf( "%lf", &largeradius);
  scanf( "%lf", &height);

  /*echo frustum entered*/
  printf("The 2 radii and height entered are %.4f, %.4f, %.4f cm \n", smallradius, largeradius, height);
  printf("------------------------------------------------------------\n");

  /*process*/
  volume = ((PI * height)/3) * (pow(smallradius, 2) + (smallradius*largeradius) + pow(largeradius, 2));

  /*output*/
  printf("The volume of the frustum is\n%.6f cm-cubed\n", volume);
  volume = volume * pow(CMTOINCH, 3);
  printf("%.5e in-cubed\n", volume);
  printf("------------------------------------------------------------\n");

  /*END OF FRUSTUM - MENU SELECTION 1*/
  }
  else
  {
  /*WHEN 2 OR OTHER NUMBER, ICOSAHEDRON, IS SELECTED FROM THE MENU*/

  /*prompt for icosahedron*/
  printf("\nEnter edge length for a icosahedron >\n");
  scanf( "%lf", &edge);

  /*echo frustum entered*/
  printf("The edge length entered is %.4f cm\n", edge);
  printf("------------------------------------------------------------\n");

  /*process*/
  volume = (5.0/12.0) * ((3.0 + sqrt(5.0)) * pow(edge, 3.0));

  /*output*/
  printf("The volume of the icosahedron is\n%.6f cm-cubed\n", volume);
  volume = volume * pow(CMTOINCH, 3);
  printf("%.5e in-cubed \n", volume);
  printf("------------------------------------------------------------\n");

  /*END OF ICOSAHEDRON - MENU SELECTION 2 OR OTHER NUMBER*/
  }
  /*MENU CHOICE PROMPT*/
  printf( "\nChoose one of the following options:\n");
  printf( "\n ====================================\n");
  printf( "      0 Quit\n");
  printf( "      1 Frustum\n");
  printf( "      2 Icosahedron\n");
  printf( "\n ====================================\n");
  scanf("%d", &answer);
  }
  /*WHEN 0, QUIT, IS SELECTED FROM THE MENU*/
  printf("You chose 0 (Quit) Goodbye\n");

  return 0;
}/************END OF PROGRAM************/
