/*******************************************************************************/
/********************************* calcFg.h*************************************/
/*******************************************************************************/
/*Function to calculate the force between bodies and the resulting acceleration*/
/*******************************************************************************/
/**************************** FUNCTION DECLARATIONS ****************************/
#include <cmath>
/*** TODO 2a ***/
void calculateGravitationalForce(body &, body &,double &, double &);

/*** TODO 2b ***/
void calculateGravitationalAcceleration(
                                        const double,
                                        const double,
                                        body &,
                                        double &dAxout,
                                        double &dAyout);
/**************************** FUNCTION IMPLEMENTATIONS *************************/

/*** TODO 2a ***/
void calculateGravitationalForce(
                                 body &B1, body &B2,
								 double &Fxout,
								 double &Fyout)
{   
	
	double G = 1;
	  
	double rx = B1.getx() - B2.getx();
	double ry = B1.gety() - B2.gety();
	
	double r  = sqrt(pow(rx,2) + pow(ry,2));

    double m1 = B1.getmass();
    double m2 = B2.getmass();
    
    Fxout= -G * m1 * m2/pow(r,3)*rx;
    Fyout= -G * m1 * m2/pow(r,3)*ry;
    
}

/*** TODO 2b ***/
void calculateGravitationalAcceleration(
                                        const double Fxout,
                                        const double Fyout,
                                        body &B, 
                                        double &dAxout,
                                        double &dAyout)
{
	
	double m = B.getmass();
    dAxout= Fxout/m;
    dAyout= Fyout/m;
    
}
