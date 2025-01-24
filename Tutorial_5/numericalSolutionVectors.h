/*******************************************************************************/
/**************************** numericalSolutionVectors.h ***********************/
/*******************************************************************************/
/*  Function that cals the numerical solver based on vectors                   */
/*******************************************************************************/


/**************************** INCLUDES *****************************************/

#include "tdmSolverVectors.h"


/**************************** FUNCTION DECLARATION *****************************/

void numericalSolutionVectors(const double &,const double &,const double &,const double &,
							  const double &,const double &,const double &,vector<double> &, const int);

/**************************** FUNCTION IMPLEMENTAION ***************************/

void numericalSolutionVectors(const double &aW, const double &aP,const double &aE,const double &Sp0,const double &SpL,
							  const double &phi0,const double &phiL, vector<double> &phiDataVectorsCDS, const int nCells)
{
  // Declare the vectors a,b,c,d,f to store the matrix coefficients 
  // Write first and/or last elements of the vectors, which are changed due to 
  // the boundary conditions (look at the page 3, tutorial sheet) 
  /*** TODO 3 ***/

  vector<double> a(nCells, -aW);
  vector<double> b(nCells,  aP);
  vector<double> c(nCells, -aE);
  vector<double> d(nCells, 0.0);
  vector<double> f(nCells);

  a[0] = 0.0;
  a[nCells-1] = -aW;
  
  c[0] = -aE;
  c[nCells-1] = 0.0;
  
  b[0] = -(a[0]+c[0]+Sp0);
  b[nCells-1] = -(a[nCells-1]+c[nCells-1]+SpL);
  
  d[0] = -Sp0*phi0;
  d[nCells-1] = -SpL*phiL;

  // Call the TDM solver function for vectors 
  /*** TODO 5 ***/

  tdmSolverVectors(a,b,c,d,f);
  
  // Write elements to the global variable phiDataVectorsCDS
  for (int i=0; i != nCells; ++i) 
  {   

	phiDataVectorsCDS[i]= f[i];  

  }
 
  // Print relative error between analytical and CDS solution     
    for (int i=0; i != nCells; ++i) 
    {   
        cout.precision(4);
        cout << "difference between your numerical and analytical solution vector is: " << fixed 
             << (phiDataVectorsCDS[i]-phiDataVectorsANL[i])/phiDataVectorsANL[i]*100 << "%." <<endl; 
    }
     
}


