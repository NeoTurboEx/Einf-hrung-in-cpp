/*******************************************************************************/
/************************** printOnTheScreenMaps.h *****************************/
/*******************************************************************************/
/* Creating maps and printing output on the screen                             */
/*******************************************************************************/

/**************************** INCLUDES *****************************************/

#include "includes.h"
//#include "declaration.h"
#include <map>           
#include <iterator>  
#include "solutionsMaps.h"


/**************************** FUNCTION DECLARATIONS ****************************/

void printOnTheScreenMaps(const vector<double> &,const vector<double> &,const vector<double> &,
                  map<int,double> &, map<int,double> &, map<int,double> &,map<int,double> &, double  );

/**************************** FUNCTION IMPLEMENTATIONS *************************/

void printOnTheScreenMaps( const vector<double> &phiDataVectorsANL,const vector<double> &phiDataVectorsCDS,const vector<double> &phiDataVectorsUDS,
			    map<int,double> &phiDataANLMaps , map<int,double> &phiDataCDSMaps, map<int,double> &phiDataUDSMap, map<int,double>::iterator &it, double x[])
{
/*** TODO 9a ***/
// call the defineMaps() to write the solutions vectors into the maps


defineMaps(phiDataVectorsANL,phiDataVectorsCDS,phiDataVectorsUDS,phiDataANLMaps,phiDataCDSMaps,phiDataUDSMaps);




cout << "\n";
cout << "*****************************************************************************\n";
cout << "*                     ***** Begin of the Solution *****                     *\n";
cout << "*****************************************************************************\n";
cout << "\n";
cout << "Program has calculated fluid concentration for" << " " 
     <<  nCells << " " << "points, namely:"<<endl;
for (int i = 0; i != nCells; ++i)
    cout<<x[i]<< ",";
cout << " which are indexed as:"<<endl;

/*** TODO 9b ***/ 
for (it = phiDataCDSMaps.begin(); it != phiDataCDSMaps.end(); ++it )
{
cout<< it->first <<" , ";
    
}

cout << "\n";
cout << "Which point (index) is of your interest?" << endl;
cout << "\n";
	cout << "                         ***** Program input *****                           \n";
double number;
cin >> number;
if (number<=nCells and number != 0)
{
    double a = phiDataANLMaps.find(number)-> second;
    double b = phiDataCDSMaps.find(number)-> second;
    double c = phiDataUDSMaps.find(number)-> second;
    cout << "\n";
    cout << "\n";
    cout << "                        ***** Program output *****                         \n";
    cout << "\n";
	
    cout << "At the point" << " " << number << " " 
		  	   << " analyticaly calculated concentration has value:" << a
    
 			   << "numerically calculated concentration using central scheme is:" << b

 		           << "while numerically calculated concentration using upwind scheme is: " << c ; 
	
	double rab = (a-b)/(a*100);
	double rbc = (a-c)/(c*100);
    cout << "\n";
  
    cout << "Relative error between"
    
	 << " numerical CDS and analyical solution is" << rab<< endl;
	 
	 cout << "Relative error between"
	 << " numerical UDS and analytical solution is" << rbc << endl;
	cout << "\n";
    cout << "*****************************************************************************\n";
    cout << "*                       ***** End of the Solution *****                     *\n";
    cout << "*****************************************************************************\n";
    cout << "\n";

}
else
{    
    cout << "\n";
    cout << "\n";
    cout << "There is no such a point." <<endl;
    cout << "\n";
    cout << "\n";
}
   /*** end of TODO 9b ***/


}
