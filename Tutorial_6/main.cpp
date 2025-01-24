/*******************************************************************************/
/**************************** main.cpp *****************************************/
/*******************************************************************************/
/* Compile to: gravitationalOrbits.x                                           */
/*******************************************************************************/
/* A C/C++ program to compute the two-dimensional orbits of multiple bodies    */
/* under the force of gravity                                                  */
/* G.L. Tufano 09/2016                                                         */
/*******************************************************************************/
/* The program computes two-dimensional orbits that multiple bodies describe   */
/* under the force of gravity. The Euler method is used for numerical          */
/* integration. From the estimated trajectories, the code is able to determine */
/* when the bodies are aligned.                                                */
/*******************************************************************************/

/********************************* INCLUDES ************************************/
#include "includes.h"                                 // general C/C++ includes*/
#include "body.h"                                      // body class definition*/
#include "globVar.h"                  // variables available in the whole scope*/
#include "calcFg.h"           // calculate gravitational force and acceleration*/
#include "calcTheta.h"        // calculate angle between two bodies and a third*/
/*********************************** MAIN **************************************/

int main() 
{
 cout<< "\n\n|************************************************************************************|\n";
 cout<< "|Start computing two-dimensional orbits of multiple bodies under the force of gravity|\n";  
 cout<< "\n\n|************************************************************************************|\n";
 #include "initialize.h"// read and store body descriptions, 
                        // prepare a file in which to write out the body status at each iteration, 
                        // set Euler time integration parameters.


double Fxout=0, Fyout=0, dAxout, dAyout;

// for each time step 
 for ( double tt=tini ; tt<=tmax ; tt=tt+dt)
     {
      nIt++;
      cout<< "\n\n|************ Time = " <<tt<< " |****************| Iteration N° "<<nIt<<" |****************|\n";
      dataOutput << tt ;
		
      for (int i=0; i<n; ++i) 
          {
           bodies[i].initAcceleration();  //   set the acceleration for each body to zero
           for (int j=0; j<n; ++j) 
               {
// For each pair of bodies compute the gravitational force between them according to their 
// positions and the equation of gravity. Add to the running total accelearation for each body.
                if (i!=j)
                   {
					
                    /*** TODO 3 ***/
                    cout << "Calculating Gravitational Force between Body N° "<<i+1<<" and Body N° "<<j+1;
                    calculateGravitationalForce(
                                                bodies[i], bodies[j],
												Fxout,Fyout);
					
                    cout << " ---> Converting to acceleration... \n";
                    calculateGravitationalAcceleration(
                                                       Fxout, Fyout,
                                                       bodies[i],
                                                       dAxout,dAyout);
                    
                    
                    bodies[i].modAcceleration(dAxout,dAyout);
                   }
               }
          }

// * Euler time integration:
//   For each body update its position according to its velocity and the time step deltat
//   update its velocity according to its acceleration and the time step deltat

      cout << " Updating Body status...\n";
      for (int i=0; i<n; ++i) 
          {
           /*** TODO 4 ***/

           dx=  dt * bodies[i].getVx();
           dy=  dt * bodies[i].getVy();
           dVx= dt * bodies[i].getAx();
           dVy= dt * bodies[i].getAy();
           

           bodies[i].move(dx,dy);
           bodies[i].accelerate(dVx,dVy);

           cout << "Body N° " << i+1 << " ---> position: ("<< bodies[i].getx()   << ", " << bodies[i].gety()   << ")\t "
                                     <<         " speed: ("<< bodies[i].getVx()  << ", " << bodies[i].getVy()  << ")\t "
                                     <<  " acceleration: ("<< bodies[i].getAx()  << ", " << bodies[i].getAy()  << ")\t" << endl;
            
           bodies[i].printBody(dataOutput); //   Write out each body status
          }
      dataOutput << "\n";

// Check whether the bodies are aligned. If they are, stop calculation. If not keep going to the next time iteration
     /*** TODO 5c ***/
     
     calculateTheta(bodies[0], bodies[1], bodies[2],cosTheta);

      if (cosTheta > cos(theta_tol))
         {
          cout<<"\n";
          cout<<"\t\t\t\t*\t*\t*\n";
          cout<<"\t\t\t\t**\t**\t**\n";
          cout<<"\t\t\t\t***\t***\t***\n";
          cout<<"\t\t\t\t****\t****\t****\n";
          cout<<"\t\t\t\t*****\t*****\t*****\n";
          cout<<"\t\t\t\t******\t******\t******\n";
          cout<<"\t\t\t\t*******\t*******\t*******\n";
          cout<<"\t\t\t For t=" << tt << "s the 3 bodies are aligned! \n";     
          cout<<"\t\t\t\t*******\t*******\t*******\n";
          cout<<"\t\t\t\t******\t******\t******\n";
          cout<<"\t\t\t\t*****\t*****\t*****\n";
          cout<<"\t\t\t\t****\t****\t****\n";
          cout<<"\t\t\t\t***\t***\t***\n";
          cout<<"\t\t\t\t**\t**\t**\n";
          cout<<"\t\t\t\t*\t*\t*\n";
          break;           
         }
      cout << "Bodies not aligned! (Theta = " << 360/6.28*acos(abs(cosTheta)) << "°) ---> Moving to the next iteration! \n";
     
     }
}
