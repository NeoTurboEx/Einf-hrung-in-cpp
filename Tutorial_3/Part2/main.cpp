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
    // iteration variables
          int    it    = 0;                                                     // init iteration counter
    const int    itMax = 1;                                                     // set max. # of iterations
          double dlm   = 1.0E+15;                                               // init delta_mdot (difference of mdots)
    const double eps   = 1.0E-15;                                               // set tolerance 4 iteration

    // physical variables
    const int nRad =  10;                                                       // set # of radial positions
    const int nInp =   8;                                                       // set # of input variables
    double mDotNew = 0.0, grdSrf = 0.0;                                         // decl mdot & surface gradient (4 iterating)
    double rad[nRad]; fill_n(rad,nRad,0.0);                                     // decl & init array of radii
    double tmp[nRad]; fill_n(tmp,nRad,0.0);                                     // decl & init array of temperature
    double mDot, radSrf, radInf, tmpSrf, tmpInf, cpGas, kGas, hVap;             // decl input variables (read from file next, otherwise init to 0!)
  
    /* read inputs & calc radial positions *************************************/
    readInput(mDot,radSrf,radInf,tmpSrf,tmpInf,cpGas,kGas,hVap,nInp);           // read input
    dispInput(mDot,radSrf,radInf,tmpSrf,tmpInf,cpGas,kGas,hVap,nInp);           // disp input
    const double Z = cpGas/(4*M_PI*kGas);                                       // calc Z
    calcRad(rad,radSrf,radInf,nRad);                                            // calc array of radial positions

    /* iterate to find mdot ****************************************************/
    cout << endl << "*** Starting to iterate ***" << endl << endl;

    while ((dlm > eps) && (it < itMax))                                         // loop until converged or max iteration #
    {   
        it++;                                                                   // increment iteration counter

        /* loop over radial positions, calculate T(r) **************************/
        for (int i = 0; i < nRad; i++)
        {  
            /*** TODO 4 ***/    
            tmp[i] = calcTmp(mDot, radSrf, tmpSrf, tmpInf, cpGas, kGas,i,rad, Z);                                                 // calc T(r)

          printf("i: %4i, rad: %10.2e m, tmp: %8.2f K \n",i,rad[i],tmp[i]);
        }
  
        /*** TODO 5 ***/      
        grdSrf  = calcTmpGrd(tmp,rad);                                                 // calc surface gradient (numerically)
  
        /*** TODO 6 ***/       
        mDotNew = calcMDotNum(radSrf, grdSrf, hVap);                            // calc mDot (numerically)

        dlm = abs(mDotNew - mDot);                                              // calc deltaMDot
      
        printf("it: %5i, grdSrf: %10.4e, mDot: %10.4e, mDotNew: %10.4e, dlm: %10.4e\n",it,grdSrf,mDot,mDotNew,dlm); // disp iteration progress

        mDot = mDotNew;                                                         // update mDot (w/ new value)

        writeOutput(rad,tmp,nRad,it);                                           // write T(r,it) to a file
    }
    cout << endl << "*** Iteration finished ***" << endl << endl;

    /* final outputs ***********************************************************/
            
    /*** TODO 7 ***/
    const double mDotExa = calcMDotExa(kGas,cpGas,radSrf,tmpInf,tmpSrf,hVap);   // calc mDot (exact)
    
    printf("mDotExa: %10.2e kg/s \n",mDotExa);                                  // disp mDot (exact)
    printf("mDotNum: %10.2e kg/s \n",mDotNew);                                  // disp mDot (approx)

    cout << endl << "*** End Tutorial dropletEvaporation ***" << endl << endl;

    return 0;
}
