/*******************************************************************************/
/**************************** declare.h ****************************************/
/*******************************************************************************/
/*******************************************************************************/
int i;                          //declare the number of loops for sub-indexes of velocity files
int j;                          //declare the number of loops for the number of cells
const int nt = 51;              //declare the number of velocity files (the number of times)
const int ncells = 2097152;     //declare the total number of cells

//declare the arrays to store ktAve for different times and uprime, vprime, wprime, magUp2 for different cells
/**********TODO 4***************/

double uprime[ncells] = {}, vprime[ncells] ={},wprime[ncells]={};
double magUp2[ncells]= {}, sumUp2[ncells] = {};
double ktAve[nt] = {};
/*******************************/ 
