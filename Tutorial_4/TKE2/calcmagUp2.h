/*******************************************************************************/
/**************************** calcmagUp2.h ****************************************/
/*******************************************************************************/
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/
void   calcmagUp2(double[], const double[], const double [], const double [], const int); 

/**************************** FUNCTION IMPLEMENTATIONS *************************/

// implement the function calcmagUp2() to calculate magUp2 for each cell and store them into an array 
/**********TODO 5***************/

void calcmagUp2(double magUp2[],const double uprime[],const double vprime[],
				const double wprime[],const int ncells)
{
	
	for(int i =0; i < ncells; i++)
	{
	magUp2[i+1] = uprime[i]*uprime[i] + vprime[i]*vprime[i]+wprime[i]*wprime[i]
				+  magUp2[i];
	
	magUp2[i] = 0;
	
	}
	
}
/******************************/
