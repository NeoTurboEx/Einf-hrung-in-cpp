/*******************************************************************************/
/**************************** main.cpp *****************************************/
/*******************************************************************************/
/* Compile to: rocketMove.x                                                    */
/*******************************************************************************/
/* A C/C++ program to illustrate rocket's motion           | C. Straub 08/2016 */
/*******************************************************************************/

/**************************** INCLUDES *****************************************/
#include "includes.h"                                                           // general C/C++ includes
#include "IO.h"                                                                 // reading experimental data
#include "sort.h"                                                               // sort data
#include "lagrange.h"                                                           // Lagrange polynomial
#include "analyticalSolution.h"                                                 // Lagrange polynomial

/**************************** MAIN *********************************************/
int main()
{
    cout << endl << "*** Begin Tutorial rocketMotion ***" << endl << endl;

    // initialisations *********************************************************
    int lines = 0;
    string fileName;
  
    // initialize vectors with the correct length and read input data***********
    fileName = "input/rocketMove.dat";
    getNumberOfLines(lines, fileName.c_str());
    cout << endl << "lines " << lines << endl << endl;
    vector<double> rocketMoveT(lines);
    vector<double> rocketMoveV(lines);
    readInput(rocketMoveT, rocketMoveV, fileName.c_str());

    lines = 0;
    fileName = "input/rocketMoveII.dat";
    getNumberOfLines(lines, fileName.c_str());
    cout << endl << "lines " << lines << endl << endl;
    vector<char>   rocketMoveCharT(lines);
    vector<double> rocketMoveCharV(lines);
    readInput(rocketMoveCharT, rocketMoveCharV, fileName.c_str());

    // sort data *************************************
    // TODO 4: apply sortVec() to the input data rocketMoveT and rocketMoveV and 
    //         display the two sorted vectors on the screen
    
    sortVec(rocketMoveT, rocketMoveV);
    
    display(rocketMoveT);
    display(rocketMoveV);
  

    // TODO 6: apply sortVec() the the new data and display the elements on the screen

    sortVec(rocketMoveCharT, rocketMoveCharV);
    
    display(rocketMoveCharT);
    display(rocketMoveCharV);

    // compute Lagrange polynomial *************************************
    // TODO 5: apply lagrange() at t=15 s and write the value to the screen
	
	double t= 15;
	double approxL = lagrange(rocketMoveV, rocketMoveT, t);
	
	display(approxL);
	
    // analytical solution and error analysis *********************************
    // TODO 7: uncomment the following lines to compute the analytical solution
    //         and the error analysis
    // Attention: t should represent the time instant (not declared yet)
    double aa = analyticalSolution(50.0, 2000.0, 7.0e03, t);
    cout << endl << "analytical solution at t=" << t << " is: " << aa 
         << endl << endl;
    double errL = abs((aa - approxL)/aa);
    cout << endl << "Lagrange interpolation results in an error of " << errL 
         << endl << endl;
    double errD = abs((aa - rocketMoveCharV[5])/aa);
    cout << endl << "Experimental data results in an error of " << errD
         << endl << endl;

    cout << endl << "*** End Tutorial rocketMotion ***" << endl << endl;

    return 0;
}
