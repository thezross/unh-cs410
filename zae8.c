#include <stdio.h>
#include <math.h>
/*******************************************************************************
*  NAME:  Zachary Ross                                                         *
*  ASSIGNMENT:  a7-c                                                           *
*  SECTION:  01 Summer                                                         *
*  DATE: July 14, 2008                                                         *
*  PURPOSE:                                                                    *
*    The scenario is a heat-flow simulation of the transfer of heat from two   *
*    sides of a metal plate across the entire plate.  A metal plate begins at a*
*    pair of fixed temperatures.  Heater/Cooler A is placed up against the top *
*    left (north and west) sides of the plate.  Heater/Cooler B is placed up   *
*    against the bottom and right (south and east) sides of the plate.  The    *
*    plate itself starts at two initial temperatures:  T1 and T2.  As the      *
*    simulation starts the sides of the plates will begin to heat up and thus  *
*    take on temperatures closer to the heaters.  This transfer of heat will   *
*    continue across the plate until it reaches a "stable" temperature, where  *
*    stable is defined, roughly, as "not changing significantly."              *
*  PROGRAM INPUT:                                                              *
*    All input will come from standard input.  The input includes 5 real       *
*    (double) values:  1. the first heater/cooler temperature;  2. the second  *
*    heater/cooler temperature (B);  3.  the first initial plate temperature,  *
*    T1;  4. the second initial plate temperature, (T2);  5. the stabilizing   *
*    criterion value.                                                          *
*  PROGRAM OUTPUT:                                                             *
*    The output will first echo the input data then display the heat-plate     *
*    temperatures.  Each plate temperature is displayed as they change until   *
*    the halt criterion is satisfied.                                          *
*******************************************************************************/
#define ROW 8
#define COL 6

void display_plate(double temps[][COL], double, double);
void init_array(double temps[][COL], double, double);
void init_newarray(double temps[][COL], double new[][COL], double, double);
void copy_func(double temps[][COL], double new[][COL]);
int check_data(double temps[][COL], double new[][COL], double);

int main (void)
{
  /*declares varaibles*/
  int row, col, count = 0, check = 0, okay = 0;
  double temps[ROW][COL], new[ROW][COL];
  double hca = 0.0, hcb = 0.0, iptone = 0.0, ipttwo = 0.0, stabcrit = 0.0;

  /*program into and requirements*/
  printf("Welcome to the Heat Plate Simulation \n \n");
  printf("Enter: Heat-A Heat-B Plate-1 Plate-2 Stab-Crit \n \n");

  /*scans froms standard input*/
  scanf("%lf%lf%lf%lf%lf", &hca, &hcb, &iptone, &ipttwo, &stabcrit);

  /*echos scan*/
  printf("    HEATER/COOLER A TEMPERATURE: %g \n", hca);
  printf("    HEATER/COOLER B TEMPERATURE: %g \n", hcb);
  printf("    INITIAL PLATE TEMPERATURE #1 %g \n", iptone);
  printf("    INITIAL PLATE TEMPERATURE #2 %g \n", ipttwo);
  printf("    STABALIZE CRITERION: %g \n", stabcrit);

  /*functions that carry data values and print initial plate*/
  init_array(temps, iptone, ipttwo);
  display_plate(temps, hca, hcb);
  init_newarray(temps, new, hca, hcb);
  check = check_data(temps, new, stabcrit);

  /*loops to print out to simulating plates*/
  while (check == 0)
  {
    count++;
    printf("\n \n    #### PLATE %d #### \n", count);
    printf("                                       %4.2f \n", hca);
    printf("        -----------------------------------------------------------\n");
    for (row = 0; row < ROW; row++)
    {
      for(col = 0; col < COL; col++)
      {
        okay = 0;
          if(col == 0 && row != 4)
            printf("        ");
          if (col == 0 && row == 4)
            printf("%6.2f    ", hca);
          printf("|  %4.2f  ", new[row][col]);
          if (col == 5 && row ==4)
            okay = 1;
      }
      if (okay == 1)
      {
        printf("|        ");
        printf("    %4.2f \n", hcb);
        printf("        -----------------------------------------------------------\n");
      }
      else
      {
        printf("|  \n");
        printf("        -----------------------------------------------------------\n");
      }
    }
    printf("                                     %4.2f", hcb);

    check = check_data(temps, new, stabcrit);
    copy_func(temps, new);
    init_newarray(temps, new, hca, hcb);
  }

  /*message for end of program*/
  printf("\n Goodbye \n");
  return 0;
}/******************END MAIN FUNCTION******************/

/*******************************************************************************
*  check_data function to make see if no element in the arraychanges by a      *
*  relative amount more than the stabalization indicating the simulation can   *
*  stop.  The stabalization criterion is a percent change, no a degree change  *
*  in comparison.                                                              *
*******************************************************************************/
int check_data(double temps[][COL], double new[][COL], double stabcrit)
{
  /*declares new variables*/
  int row, col, check;
  double change = 0.0, max = 0.0;

  /*loops for last change over criteria*/
  for(row = 0; row < ROW; row++)
    for(col = 0; col < COL; col++)
    {
      change = ((fabs(temps[row][col] - new[row][col]))/temps[row][col]);
      if (change > max)
        max = change;
    }
  if(max < stabcrit)
    check = 1;
  else
    check = 0;
return check;
}/******************END CHECK_DATA FUNCTION******************/

/*******************************************************************************
*  copy_func takes old array and sets it to old so a new array can be changed  *
*******************************************************************************/
void copy_func(double temps[][COL], double new[][COL])
{
  /*declares new variables*/
  int row, col;

  /*copies using loop*/
  for(row = 0; row < ROW; row++)
    for(col = 0; col < COL; col++)
      temps[row][col] = new[row][col];
}/******************END COPY_FUNC FUNCTION******************/

/*******************************************************************************
*  display_plate function prints out the initial plate                         *
*******************************************************************************/
void display_plate(double temps[][COL], double hca, double hcb)
{
  /*declares new variable*/
  int row, col, okay = 0;

  /*sets up table printing format*/
  printf("\n \n    #### INITIAL PLATE #### \n");
  printf("                                     %4.2f \n", hca);
  printf("        -----------------------------------------------------------\n");
    for (row = 0; row < ROW; row++);
    {
      for(col = 0; col < COL; col++)
      {
      okay = 0;
        if (col == 0 && row != 4)
          printf("                ");
        if(col == 0 && row == 4)
          printf("%6.2f           ", hca);
        printf("|    %4.2f    ", temps[row][col]);
      if (col == 5 && row == 4)
        okay = 1;
      }
      if (okay == 1)
      {
        printf("|          ");
        printf("      %4.2f \n", hcb);
        printf("        -----------------------------------------------------------\n");
      }
      else
      {
        printf("|  \n");
        printf("        -----------------------------------------------------------\n");
      }
    }
  printf("                                       %4.2f \n", hcb);
}/******************END DISPLAY_PLATE FUNCTION******************/

/*******************************************************************************
*  init_array function intilizes the first array based upon scanned values     *
*******************************************************************************/
void init_array(double temps[][COL], double iptone, double ipttwo)
{
  /*declare new variables*/
  int i, j;

  /*initializing first array*/
  for(i=0; i < ROW; i++)
    for(j=0; j < COL; j++)
      /*top left fourth*/
      if(i>0 && i <=3 && j >= 0 && j <= 2)
      {
        temps[i][j]= iptone;
      }
      /*bottom left fourth*/
      else if(i >= 4 && i <= 7 && j >= 0 && j <= 2)
      {
        temps[i][j] = ipttwo;
      }
      /*top right fourth*/
      else if(i >= 0 && i <= 3 && j >= 3 && j <= 5)
      {
        temps[i][j] = ipttwo;
      }
      /*bottom right fourth*/
      else if(i >= 4 && i <= 7 && j >= 3 && j <= 5)
      {
        temps[i][j] = iptone;
      }
}/******************END INIT_ARRAY FUNCTION******************/

/*******************************************************************************
*  init_newarray function takes the old array and adjusts it's values in the   *
*  newer array
*******************************************************************************/
void init_newarray(double temps[][COL], double new[][COL], double hca, double hcb)
{
  /*declares new variables*/
  int i, j;

  /*adjusts values in arrays*/
  for(i=0; i < ROW; i++)
    for(j=0; j < COL; j++)
      /*top left*/
      if (i==0 && j==0)
      {
        new[i][j] = ((hca + temps[i][j+1] + temps[i+1][j] + hca)/4);
      }
      /*top right*/
      else if(i==0 && j==5)
      {
        new[i][j] = ((temps[i+1][j] + temps[i][j-1]+hca+hcb)/4);
      }
      /*bottom left*/
      else if(i==7 && j==0)
      {
        new[i][j] = ((hca+hcb+temps[i-1][j] + temps[i][j+1])/4);
      }
      /*bottom right*/
      else if(i==7 && j==5)
      {
        new[i][j] = ((temps[i-1][j]+hcb +hcb +temps[i][j-1])/4);
      }
      /*left side*/
      else if(i>=0 && i<=7 && j==0)
      {
        new[i][j] = ((temps[i+1][j]+temps[i][j+1]+temps[i-1][j]+hca)/4);
      }
      /*right side*/
      else if(i>=0 && i<=7 && j==5)
      {
        new[i][j] = ((temps[i+1][j]+hcb+temps[i-1][j]+temps[i][j-1])/4);
      }
      /*bottom side*/
      else if(j>=0 && j<=5 && i==7)
      {
        new[i][j] = ((hcb+temps[i][j+1]+temps[i-1][j]+temps[i][j-1])/4);
      }
      /*top side*/
      else if(j>=0 && j<=5 && i==0)
      {
        new[i][j] = ((temps[i+1][j] + temps[i][j+1] + hca + temps[i][j-1])/4);
      }
      else
      {
        /*general*/
        new[i][j] = ((temps[i+1][j] + temps[i][j+1] + temps[i-1][j] + temps[i][j-1])/4);
      }
}/******************END INIT_NEWARRAY FUNCTION******************/
