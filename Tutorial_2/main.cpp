/*******************************************************************************/
/**************************** main.cpp *****************************************/
/*******************************************************************************/
/* Compile to: heatExchanger.x                                                 */
/*******************************************************************************/
/* A C/C++ program to illustrate the efficiency of heat exchangers |           */
/* D. Dietzel 08/2016                                                          */
/*******************************************************************************/
/* The (final) program calculates the temperature fields in a double tube heat */
/* exchanger. You can chose between parallel flow and counter flow.            */
/*******************************************************************************/

/**************************** INCLUDES *****************************************/
#include "includes.h"                                                           // general C/C++ includes
#include "declaration.h"                                                        // global data declaration
#include "init.h"                                                               // initialize fields
#include "calcHE.h"                                                             // function implementation
#include "IO.h"                                                                 // functions 4 IO

/**************************** MAIN *********************************************/
int main()
{
	string heatchanger; 
    cout << endl << "*** Begin Tutorial heatExchanger ***" << endl << endl;
    
    // Initialise all variables
    init(); // Call the function 'init' implemented in init.h

    // Determine the temperature field for each cell - numerical solution
    // Call the function 'solveTFieldParallel' implemented in calcHE.h
    //solveTFieldParallel();     
 
    /*** TODO 4 ***/

	if (flowMode==1)
	{
		solveTFieldParallel(); 
		heatchanger="Parallel flow";
		
	}
	else 
	{
		solveTFieldCountercurrent();  
		heatchanger="Counter flow";
	}
	
	
	cout << endl << "*** " << heatchanger << " ***" << endl<< endl;

    // Write to ~.dat file
    writeOutput(); // Call the function 'writeOutput' implemented in IO.h

    cout << endl << "*** End Tutorial heatExchanger ***" << endl << endl;

    return 0;
}
