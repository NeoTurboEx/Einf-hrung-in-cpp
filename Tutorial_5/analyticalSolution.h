/*******************************************************************************/
/********************************* analyticalSolution.h ************************/
/*******************************************************************************/
/* Analytical solver for transport equation                                    */
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/

/*** TODO 2 ***/
void analyticalSolution(vector<double> &, const double&, const double&, const double&,
						const double&, const double&, const double&,double [],const int& );

/**************************** FUNCTION IMPLEMENTATIONS *************************/

void analyticalSolution(vector<double> &phiDataVectorsANL, const double &phi0, 
						const double &phiL, const double &rho,const double &u,
						const double &L, const double &Gamma, double x[],const int &nCells)
{
    // imlementation of Eq. 3  
    for(int i = 0; i<nCells; ++i)
    {    
    phiDataVectorsANL[i] = phi0 +(phiL-phi0)*(exp(rho*u*x[i]/Gamma)-1)/(exp(rho*u*L/Gamma)-1); 
    
	}

}
/***end of TODO 2 ***/
