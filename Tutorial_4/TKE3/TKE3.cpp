/*******************************************************************************/
/**************************** TKE3.cpp *****************************************/
/*******************************************************************************/
/* Compile to: TKE3.x                                                          */
/*******************************************************************************/
/* A C/C++ program to post-process the isotropic turbulent field               */
/* B. Wang 10/2016                                                             */
/*******************************************************************************/
/* The (final) program uses a pointer to an array on the heap and calculates   */
/* the average turbulent kinetic energy of the turbuent velocity fields for    */
/* different times and analyse the time evolution of the energy decay          */
/*******************************************************************************/


// C/C++ includes
#include <cmath>         		    // include to get: exp(), abs(), M_PI(), ...
#include <fstream>       		    // include to get: fopen(), fclose(), ...
#include <iostream>      		    // include to get: cout (unformatted stream output)
#include <sstream>       		    // include to get: stringstream
#include <string.h>      		    // include to get: strcpy
#include <stdio.h>       		    // include to get: printf(), scanf(),...

using namespace std;     		    // avoid std::<functionname>

#include "declare.h"			    // declare i,j,nt,ncells,ktAve[] and pointers
#include "Input.h"	 	   	    // include the function to read the velocity files
#include "calcmagUp2.h"	 	   	    // include the function to calculate magUp2
#include "calcktAve.h"	 		    // include the function to calculate ktAve for different times
#include "Output.h"	 		    // include the function to output ktAve for different times

int main()
{
   for (i=0; i<nt; i++)			    // start the loops for different times
   {

      //allocate memory for arrays uprime, vprime, wprime, magUp2 on the heap
      /**********TODO 7**************/

	  double *uprime = new double[ncells];
	  double *vprime = new double[ncells];
	  double *wprime = new double[ncells];
	  double *magUp2 = new double[ncells];
	  
      /*******************************/

      Input(uprime,vprime,wprime,i,ncells);  // read the velocity files into arrays on the heap

      /**********TODO 8**************/
      calcmagUp2(magUp2,uprime,vprime,wprime,ncells);     // calculate magUp2 for each cell
      /*******************************/ 

      /**********TODO 9**************/
      calcktAve(ktAve,magUp2,ncells,i);      // calculate the average turbulent kinetic energy ktAve for different time
      /*******************************/ 
	  delete uprime;
	  delete vprime;
	  delete wprime;
	  delete magUp2;
	  
	  cout << ktAve[i] << endl;
   }

   Output(ktAve, nt);			     // output ktAve for different times

   return 0; 				     // everything went right.
} 
