/*******************************************************************************/
/**************************** IO.h *********************************************/
/*******************************************************************************/
/* Functions for data output (write ASCII data files containing the solution)  */
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/

void writeOutput();                                                             

/**************************** FUNCTION IMPLEMENTATIONS *************************/

void writeOutput()                                                             
{

    /* Local variables *********************************************************/
    int       i;                                                                     
    /***************************************************************************/

    // Open file to write
    /*** TODO 6b ***/
    if (flowMode==1)
	{
		ofstream outfile1 ("output/thetaOfXParallel.dat");
		// Write to file
		for (i=0 ; i <= nCells ; ++i)
		{
			outfile1 << x[i] <<" "<< theta1[i] <<" "<< theta2[i] << "\n";
		}
		// Close written file
		outfile1.close();
		
	}
	else 
	{
		ofstream outfile1 ("output/thetaOfXCounter.dat");
		// Write to file
		for (i=0 ; i <= nCells ; ++i)
		{
			outfile1 << x[i] <<" "<< theta1[i] <<" "<< theta2[i] << "\n";
		}
		// Close written file
		outfile1.close();
	}
     
}
