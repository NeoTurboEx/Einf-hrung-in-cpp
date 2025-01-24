/*******************************************************************************/
/**************************** evaporation.h ************************************/
/*******************************************************************************/
/* Functions to calculate droplet evaporation                                  */
/*******************************************************************************/
#include "includes.h"
/**************************** FUNCTION DECLARATIONS ****************************/
double calcTmp(const double , const double &,const double &, const double &,
				const double &, const double &,const int&, double [], double Z);     // TODO 4: calc T(r) [copy&paste from TODO 3 of part I]
double calcTmpGrd(double [], double[]);  // TODO 5: calc the (approximate) surface temperature gradient
double calcMDotNum(const double &, const double &, const double &); // TODO 6: calc the evaporation rate (numerically, approximate)
double calcMDotExa(const double &,const double &,const double&,const double &,
				   const double &,const double & ); // TODO 7: calc the evaporation rate (exact)


/**************************** FUNCTION IMPLEMENTATIONS *************************/
    
double calcTmp(const double mDot, const double &radSrf,const double &tmpSrf, 
				const double &tmpInf, const double &cpGas, const double &kGas,
				const int& i, double rad[], const double Z)  // TODO 3: calc T(r)
{

   cout << "TODO 4: Implement, declare and call function calcTmp()." << endl; 
	
   //call for arrays in the loop
   double calctemp = ((tmpInf - tmpSrf)*exp((-Z*mDot)/rad[i])-tmpInf*exp((-Z*mDot)
					/radSrf) + tmpSrf)/(1-exp((-Z*mDot)/radSrf));
					
}

double calcTmpGrd(double tmp[], double rad[])
{
    cout << "TODO 5: Implement, declare and call function calcTmpGrd()." << endl;
    
    double calctempgrd = (tmp[1]-tmp[0])/(rad[1]-rad[0]);
    
    //cout << calctempgrd;
}

double calcMDotNum(const double &radSrf,const double &grdSrf,const double &hVap)
{
    cout << "TODO 6: Implement, declare and call function calcMDotNum()." << endl;
    
    double calcmdotnum = (4*M_PI*radSrf*radSrf* grdSrf)/hVap;
    
    cout << calcmdotnum;
}

double calcMDotExa(const double &kGas,const double &cpGas,const double &radSrf,
				   const double &tmpInf,const double &tmpSrf,const double &hVap)
{
    cout << "TODO 7: Implement, declare and call function calcMDotExa()." << endl;
    
    double calcmdotexa = (4*M_PI*kGas*radSrf/cpGas)*log(((cpGas*(tmpInf-tmpSrf))/hVap)+1);
    
    cout << calcmdotexa;
}


