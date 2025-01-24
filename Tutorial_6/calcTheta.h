/********************************************************************************/
/********************************* calcTheta.h***********************************/
/********************************************************************************/
/*Function to calculate the angle between the direction of the first two bodies */
/*and a third body                                                              */
/********************************************************************************/
/**************************** FUNCTION DECLARATIONS *****************************/

/*** TODO 5a ***/
double calculateTheta(body &, body &, body &, double &);

/**************************** FUNCTION IMPLEMENTATIONS *************************/
double calculateTheta(body &B1, body &B2, body &B3, double &cosTheta)
{
	
	double r1x = B2.getx() - B1.getx();
	double r1y = B2.gety() - B1.gety();
	double c  = sqrt(pow(r1x,2) + pow(r1y,2));
	
	double r2x = B3.getx() - B1.getx();
	double r2y = B3.gety() - B1.gety();
	double b  = sqrt(pow(r2x,2) + pow(r2y,2));      

    cosTheta = abs((r1x*r2x+r1y*r2y)/(b*c));
  
    cout << "Calculating the angle between bodies...\n";

    return cosTheta;
}
