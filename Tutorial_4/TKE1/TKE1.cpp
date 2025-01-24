/*******************************************************************************/
/**************************** TKE1.cpp *****************************************/
/*******************************************************************************/
/* Compile to: TKE1.x                                                          */
/*******************************************************************************/
/* A C/C++ program to post-process the isotropic turbulent field               */
/* B. Wang 10/2016                                                             */
/*******************************************************************************/
/* The (final) program postprocesses the velocity data of each cell to	       */
/* calculate kinetic energy of the turbuent velocity fields for different times*/   
/* (no large arrays) and analyse the time evolution of the energy decay	       */
/*******************************************************************************/

// C/C++ includes
#include <cmath>         		  // include to get: exp(), abs(), M_PI(), ...
#include <fstream>       		  // include to get: fopen(), fclose(), ...
#include <iostream>      		  // include to get: cout (unformatted stream output)
#include <sstream>       		  // include to get: stringstream
#include <string.h>     		  // include to get: strcpy
#include <stdio.h>       		  // include to get: printf(), scanf(),...

using namespace std;     		  // avoid std::<functionname>

#include "declare.h"	 		  // declare i,j,sumk,nt,ncells,u',v',w',magUp2,ktAve[]
#include "Output.h"	 		  // include the function to output ktAve for different times

int main()
{ 
   for (i=0; i<nt; i++)      		  // start the loops for different times
   {
      double sumUp2 = 0;                  // initialize the sum of square of magnitude of fluctuating velocity

      //read the velocity file
      char st1[20] = "../input/U";    	  // declare the string of common part of the file name 
      char filename[20] = {'\0'};     	  // declare the string of full filename.  
      ifstream infile;
      sprintf(filename, "%s%d", st1, i);  // the filename is composed of the common part 'U' and the loop i
      infile.open(filename);              // open the velocity files

      if(infile.fail())                   // check to see if files are opened 
      { 
         cout << "input error" << endl;
      }

		
      for (j=0; j<ncells; j++)            // loop all the cells in the domain
      {
         //infile >> uprime >> vprime >> wprime;    // either like this or:
         infile >> uprime;                // read u' line by line
         infile >> vprime;                // read v' line by line
         infile >> wprime;             	// read w' line by line

         //calculate the square of magnitude of fluctuating velocity of local cells
         /**********TODO 1***************/
          
          magUp2 = uprime* uprime + vprime * vprime + wprime*wprime;
          
          //cout << magUp2 << endl;
         /*******************************/

	 //declare a pointer to memory on the heap which is assigned the value of magUp2 and use it to calculate sumUp2
         /**********TODO 2***************/
		   double *pointer= new double;
		   *pointer = magUp2;
		  
		   sumUp2 += *pointer;
           delete pointer;
           
          // cout << sumUp2 <<endl;
         /*******************************/

      }
	
      //assign the address of sumUp2 to pointer p and use it to calculate ktAve[]. Print ktAve[] to terminal.
      /**********TODO 3***************/   
		 p = &sumUp2;
		 cout << "sumUp2 Adresse: " << &sumUp2 << endl;
		 cout << "sumUp2 Wert " << sumUp2 <<endl;
		 cout << "p Adresse: " << &p << endl;
		 cout << "p Wert " << *p <<endl;
		 cout << " Iteration i: " <<i<<endl;
      
         ktAve[i] = (*p) * 0.5/ncells;
         
         cout << "ktAve: " << ktAve[i] << endl;
      /*******************************/

   }

   Output(ktAve,nt);			  // output ktAve for different times
 
   return 0; 				  // everything went right.
} 
