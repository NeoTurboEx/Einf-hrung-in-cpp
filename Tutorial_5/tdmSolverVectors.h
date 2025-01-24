/*******************************************************************************/
/**************************** tdmSolverVectors.h *******************************/
/*******************************************************************************/
/*  Implementation of the Thomas algorithm for solving tridiagonal matrix      */
/*******************************************************************************/
/**************************** FUNCTION DECLARATION *****************************/

/*** TODO 4 ***/

void tdmSolverVectors(const vector<double> &,const vector<double> &,const vector<double> &,const vector<double> &,vector<double>&);
 
/**************************** FUNCTION IMPLEMENTATION **************************/

void tdmSolverVectors(const vector<double> &a, const vector<double> &b,const vector<double> &c,const vector<double> &d,vector<double> &f) 
{
    size_t N = d.size();

    // Create the temporary vectors
    std::vector<double> c_star(N, 0.0);
    std::vector<double> d_star(N, 0.0);
  
    // This updates the coefficients in the first row
    // Note that we should be checking for division by zero here
    c_star[0] = c[0] / b[0];
    d_star[0] = d[0] / b[0];
	
    // Calculate values of the c_star and d_star coefficients in the forward sweep
    for (int i=1; i<N; i++) 
    {
        double m = 1.0 / (b[i] - a[i] * c_star[i-1]);
        c_star[i] = c[i] * m;
        d_star[i] = (d[i] - a[i] * d_star[i-1]) * m;

    }
  
    // This is the reverse sweep, used to update the solution vector f
    f[N - 1] = d_star[N - 1];
    for (int i=N-1; i-- > 0;) 
    {
        f[i] = d_star[i] - c_star[i] * f[i+1];

    }
}
