/*******************************************************************************/
/**************************** calcEk.h *****************************************/
/*******************************************************************************/
/* Functions for calculation of temperature fields                             */
/* in heat exchangers                                                          */
/*******************************************************************************/
//#include "init.h"
/**************************** FUNCTION DECLARATIONS ****************************/
void solveTFieldParallel();
void solveTFieldCountercurrent();

/**************************** FUNCTION IMPLEMENTATIONS *************************/
void solveTFieldParallel()                                              
{
 
    /* Local variables *********************************************************/
    int       i;                                                                     
    double    thetaM;
    /***************************************************************************/

    /* Calculation *************************************************************/
    // Explicit solution - loop over cells
    /*** TODO 3 ***/
    for (i =1; i<=nCells; i++ )
    {
        thetaM = theta1[i-1] - theta2[i-1];  // Eq. 11 in tutorial sheet
        
        theta1[i] = theta1[i-1] - kA/W1 * thetaM; // Eq. 9 in tutorial sheet
        theta2[i] = theta2[i-1] + kA/W2 * thetaM; // Eq. 10 in tutorial sheet ffssd
    }

}

void solveTFieldCountercurrent()                                              
{

    /* Local variables *******************************************************/
    int       i,j;                                                                     
    double    thetaM1,thetaM2;
    double    sumThetaMean;
    double    sumThetaMeanOld;
    double    RES;
    double    TOL=1.0e-5;
    /*************************************************************************/

    /* Calculation ***********************************************************/
    /*** TODO 5 ***/ 
    // For convergence check - sum Eq. 11 for all cells
   sumThetaMeanOld = 0.0;
   for (i = 0; i < nCells; ++i)
   {   
       sumThetaMeanOld += theta1[i] - theta2[i]; //rechnet Temperaturdifferenz aller Zellen aber hier wird nur der letzte Wert geschrieben also nCells =130°C
   }
    RES = 1.0e9;
    // Implicit solution - loop until solution is converged

        // Loop over cells
        while(RES >= TOL)  //solange Res >= Tol ist wird die schleife durchlaufen
        {
		for (i=1; i <= nCells; ++i) 
		{
			// eine i zelle berechnen alle j zellen und dann nächste i zelle
		
			j = nCells - i + 1;
			thetaM1 = theta1[i] - theta2[i]; // Eq. 11 in tutorial sheet	Temperaturdifferenz von vorne entspricht bei durchlauf 1 = +130°C
			thetaM2 = theta1[j] - theta2[j]; // Eq. 11 in tutorial sheet	Temperaturdifferenz von hinten entspricht bei durchlauf 1 = -130°C
			
			theta1[i] = theta1[i-1] - ((kA/W1) * thetaM1); // Eq. 9 in tutorial sheet    //rechnet Temperatur die übetragen wird 421,47°C
			theta2[j] = theta2[j+1] + ((kA/W2) * thetaM2); // Eq. 10 in tutorial sheet   //rechnet Temperatur die übetragen wird 
			            
        // Check for convergence
        sumThetaMean = thetaM1 - thetaM2; //Temperaturdifferenz zwischen abgegebener Temp und aufgenommener
	}
        RES = fabs((sumThetaMean - sumThetaMeanOld)/sumThetaMeanOld); //Absolutwert (... - 130)/130 >= 1.0e-5
        sumThetaMeanOld = sumThetaMean;
		}
        
}
