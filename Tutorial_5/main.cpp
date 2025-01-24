/*******************************************************************************/
/**************************** main.cpp *****************************************/
/*******************************************************************************/
/* Compile to: transportEquation.x                                             */
/*******************************************************************************/
/* C++ program to illustrate use of FVM central and upwind differencing scheme */
/* M. Smiljanic 09/2016                                                        */
/**************************** INCLUDES *****************************************/
#include "includes.h"                                                           // general C/C++ includes
#include "declaration.h"                                                      // global data declaration
#include "init.h"                                                             // initialize phields
#include "analyticalSolution.h"                                               // function implementation
#include "numericalSolutionVectors.h"                                         // function implementation
#include "IO.h"                                                               // functions 4 IO
#include "printOnTheScreenBasic.h"                                            // standard cin/cout 
#include "printOnTheScreenMaps.h"                                             // map,find, and cin/cout 

/**************************** MAIN *********************************************/
int main()
{
    cout << endl << ">>> Begin Tutorial transportEquation <<<" << endl << endl;

init();                                                                     // call the function 'init' from init.h
analyticalSolution(phiDataVectorsANL, phi0, phiL, rho,u, L, Gamma, x, nCells);

/**************************** Use of Vectors **********************************/
// calculate phiDataVectorsCDS
numericalSolutionVectors(aW_CDS,aP_CDS, aE_CDS, Sp0_CDS,SpL_CDS,phi0,phiL,phiDataVectorsCDS, nCells);  // call the function 'numericalSolutionVectors' from numericalSolutionVectors.h

/*** TODO 6 ***/
// calculate phiDataVectorsUDS
numericalSolutionVectors(aW_UDS,aP_UDS,aE_UDS, Sp0_UDS,SpL_UDS,phi0,phiL, phiDataVectorsUDS, nCells);

/*** end of TODO 6 ***/

//writeSolutionsBasic(nCells, x, phiDataVectorsANL,phiDataVectorsCDS);                                                      // call the function 'writeSolutionsBasic' to write output file for phiDataVectorsANL and phiDataVectorsCDS solutions only
writeSolutions(nCells, x, phiDataVectorsANL,phiDataVectorsCDS,phiDataVectorsUDS);                                          // call the function 'writeSolutions' from 'IO.dat' to write output file for phiDataVectorsANL, phiDataVectorsCDS and phiDataVectorsUDS

/**************************** Use of Maps/Multimaps ***************************/
printOnTheScreenMaps(phiDataVectorsANL,phiDataVectorsCDS,phiDataVectorsUDS,phiDataANLMaps,phiDataCDSMaps,phiDataUDSMaps,it,x);                                                     // call the function 'printOnTheScreenMaps' from printOnTheScreenMaps.h

    cout << endl << ">>> End of Tutorial Transport Equation <<<" << endl << endl;

    return 0;
}
