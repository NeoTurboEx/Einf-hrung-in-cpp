/*******************************************************************************/
/**************************** calcktAve.h **************************************/
/*******************************************************************************/
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/
void  calcktAve(double[], const double[], const int, const int);

/**************************** FUNCTION IMPLEMENTATIONS *************************/

// implement the function calcktAve() to calculate ktAve for different times and store them into an array
/**********TODO 6***************/
void calcktAve(double ktAve[],const double magUp2[],const int ncells,const int i)
{
	
     ktAve[i] = 0.5 * magUp2[ncells]/ncells;
	
}
/******************************/
