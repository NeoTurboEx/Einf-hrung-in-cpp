/*******************************************************************************/
/**************************** evaporation.h ************************************/
/*******************************************************************************/
/* Functions to calculate droplet evaporation                                  */
/*******************************************************************************/
#include "includes.h"
/**************************** FUNCTION DECLARATIONS ****************************/

double calcTmp(const double &, const double &,const double &, const double &,
				const double &, const double &,const int&, double [], double Z); // TODO 3: calc T(r)

/**************************** FUNCTION IMPLEMENTATIONS *************************/
double calcTmp(const double &mDot, const double &radSrf,const double &tmpSrf, 
				const double &tmpInf, const double &cpGas, const double &kGas,
				const int& i, double rad[], const double Z)  // TODO 3: calc T(r)
{
   cout << "TODO 3: Implement, declare and call function calcTmp()." << endl;
    
	
   //call for arrays in the loop
   double calctemp = ((tmpInf - tmpSrf)*exp((-Z*mDot)/rad[i])-tmpInf*exp((-Z*mDot)
					/radSrf) + tmpSrf)/(1-exp((-Z*mDot)/radSrf));
					
 
} 
