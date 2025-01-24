/*******************************************************************************/
/**************************** declare.h ****************************************/
/*******************************************************************************/
/*******************************************************************************/
//declaration
int i;                          	  // declare the number of loops for sub-indexes of velocity files
int j;                          	  // declare the number of loops for the number of cells
const int nt = 51;              	  // declare the number of input velocity files (the number of times)
const int ncells = 2097152;  	          // declare the total number of cells
double uprime, vprime, wprime;		  // declare variables for three components of fluctuating velocity
double magUp2;		   		  // declare the sqare of magnitude of fluctuating velocity of local cells
double sumUp2;	  	  	 	  // declare the sum of magUp2
double *p;		  		  // declare a pointer to double
double ktAve[nt];       		  // declare the array to store the average turbulent kinetic energy for different times

