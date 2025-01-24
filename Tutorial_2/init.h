/*******************************************************************************/
/********************************* init.h **************************************/
/*******************************************************************************/
/* Inititialization of material properties, initial conditions etc.            */
/*******************************************************************************/
//#include <iostream>
//#include "declaration.h" 
#include "math.h" 


/**************************** FUNCTION DECLARATIONS ****************************/
void init();  

/**************************** FUNCTION IMPLEMENTATIONS *************************/
void init() 
{
    
    /***************************************************************************/
    /* Local variables *********************************************************/
    /***************************************************************************/
    double    alpha1,alpha2;                                                    // heat transfer coeffiecient of streams 1 and 2, [W/(m^2*K)]
    double    cp1,cp2;                                                          // spec. heat capacity of streams 1 and 2, [J/(kg*K)]
    double    lambda;                                                           // heat conductivity of heat exchanger plates, [W/mK]
    double    k;                                                                // k = f(alpha1,alpha2,lambda,A,geometry)
    double    mDot1,mDot2;                                                      // mass flow rate of streams 1 and 2, [kg/s]
    double    thetaIn1,thetaIn2;                                                // temperature of incoming fluids, [K]
    double    length;                                                           // tube length, [m]
    double    rIn,rOut;                                                         // inner and outer radius of the tube, [m]
    double    dx;                                                               // size of the computational cell, [m]
    double    xStart;                                                           // coordinate origin, [m]
    /***************************************************************************/

    /***************************************************************************/
    /* Prescribe initial conditions: *******************************************/
    /***************************************************************************/
    /*** TODO 1 ***/
    /* 1. Material properties */
    alpha1 = 2000.0;        
    alpha2 = 2000.0;
    cp1    = 4305.335;
    cp2    = 4184.051;
    lambda = 236.0;

    /* 2. Inflow conditions */
    mDot1    = 1.0;
    mDot2    = 2.0;
    thetaIn1 = 423.15;
    thetaIn2 = 293.15;

    /* 3. Geometrical data */
    xStart  = 0.0;
    length  = 10.0;
    rIn     = 0.080;
    rOut    = 0.082;

    /***************************************************************************/

    /***************************************************************************/
    /* Derived quantities ******************************************************/
    /***************************************************************************/
    /*** TODO 2 ***/
    /* 1. Reference area and heat transfer coefficient - Eqs. 5 and 6          */
    /*    Note: Use the variable kA (declared in declaration.h) to specify     */
    /*          the product of k and ARef for one single computational cell!   */
    
    
       
    ARef=2*M_PI*rOut*(length/nCells); // = 0,0515221 m²
       
    k=1/(((rOut/rIn)*(1/alpha1))+rOut*(log(rOut/rIn)/lambda) + (1/alpha2)); //=1/0,0010210796 = 979,3556
    
    kA=k*ARef; //= 50,4685
    
    /* 2. Heat capacity flow */
    
    W1= mDot1*cp1; // = 4305.335
    W2= mDot2*cp2; // = 8368,102        
    
    /* 3. Initialise the temperature field */
    
    //Gleichstrom
    //theta1[0]=thetaIn1;
    //theta2[0]=thetaIn2;  
    
    /* 4. Cell locations */
    
    dx= length/nCells;
    
    for (int i=0; i<=nCells; ++i)
    {
		x[i]= xStart + i*dx;
		
	}
    
    /*** TODO 6a ***/
	
	bool PARALLELFLOW = true; //true= parallelflow; 
	
	if (PARALLELFLOW==true)
	{
		flowMode=1;
		
		//Gleichstrom
    theta1[0]=thetaIn1; //setzt Temperatur von 1 auf 423°C in Zelle 0
    theta2[0]=thetaIn2; //setzt Temperatur von 1 auf 293°C in Zelle 0
    

 
	}
	else 
	{
		flowMode=0;
    
		for (int i=0; i<=nCells; ++i) 
    
		{
			theta1[i]=thetaIn1;  //setzt Temperatur von 1 auf 423°C in jeder Zelle
			theta2[i]=thetaIn2;  //setzt Temperatur von 2 auf 293°C in jeder Zelle 
			//+ nCells+1 da Zelle 0 und Zelle nCells+1 die initialisierungszellen für beide Stromrichtungen sind
		}
	}
	
	
    /*** TODO 7 ***/


}
