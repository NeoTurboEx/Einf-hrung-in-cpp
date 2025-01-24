/*******************************************************************************/
/**************************** main.cpp *****************************************/
/*******************************************************************************/
/* Compile to: dropletEvaporation.x                                            */
/*******************************************************************************/
/* A C/C++ program to illustrate simple droplet evaporation | O. Stein 07/2016 */
/*******************************************************************************/
/* The (final) program calculates the droplet evaporation rate (mDot) and the  */
/* radial gas temperature profile T(r) iteratively. The required surface       */
/* temperature gradient is approximated numerically and the mDot obtained by   */
/* iteration is compared to an analytical solution.                            */
/*******************************************************************************/

/**************************** INCLUDES *****************************************/
#include "includes.h"                                                           // general C/C++ includes
#include "auxiliary.h"                                                          // auxiliary functions
#include "IO.h"                                                                 // functions 4 IO
#include "evaporation.h"                                                        // functions 4 droplet evaporation

/**************************** MAIN *********************************************/
int main()
{
    cout << endl << "*** Begin Tutorial dropletEvaporation ***" << endl << endl;

    /* initialisations *********************************************************/
    // physical variables
    const int nRad =  10;                                                       // set # of radial positions
    const int nInp =   8;                                                       // set # of input variables
    double mDotNew = 0.0, grdSrf = 0.0;                                         // decl mdot & surface gradient (4 iterating)
    double rad[nRad]; fill_n(rad,nRad,0.0);                                     // decl & init array of radii
    double tmp[nRad]; fill_n(tmp,nRad,0.0);                                     // decl & init array of temperature
    double mDot, radSrf, radInf, tmpSrf, tmpInf, cpGas, kGas, hVap;            // decl input variables (read from file next, otherwise init to 0!)
  
    /* read inputs & calc radial positions *************************************/
    /*** TODO 1 ***/
    readInput(nInp, mDot, radSrf, radInf, tmpSrf, tmpInf, cpGas, kGas, hVap); //skript zum input lesen
	
    /*** TODO 2 ***/
    dispInput(nInp,mDot, radSrf, radInf, tmpSrf, tmpInf, cpGas, kGas, hVap);

    /*** TODO 3 ***/
	//calcTmp(mDot, radSrf, radInf, tmpSrf, tmpInf, cpGas, kGas);

    // NOTE: Once calcTmp() is properly implemented and working, uncomment the code
             right below and call it within the loop to calculate T(r). */

   
    //const double Z = cpGas/(4*M_PI*kGas);                                       // calc Z
    calcRad(rad,radSrf,radInf,nRad);                                            // calc array of radial positions

	cout << "radius o:" <<rad[0] << endl;
     //loop over radius, calc T(r) *********************************************/
   
    for (int i = 0; i < nRad; i++)
    {
        tmp[i] = calcTmp(mDot, radSrf, tmpSrf, tmpInf, cpGas, kGas,i,rad, Z);      // calc T(r)
        printf("i: %4i, rad: %10.2e m, tmp: %8.2f K \n",i,rad[i],tmp[i]);
    }
    
            
    writeOutput(rad,tmp,nRad,1);                                                // write T(r) to a file (4 plotting)

	
    cout << endl << "*** End Tutorial dropletEvaporation ***" << endl << endl;

    return 0;
}
