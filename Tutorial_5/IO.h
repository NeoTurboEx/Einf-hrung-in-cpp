/*******************************************************************************/
/**************************** IO.h *********************************************/
/*******************************************************************************/
/* Functions for data output (write ASCII data files containing the solution)  */
/*******************************************************************************/
//#include <cmath>   
//#include "includes.h"     // std::abs
/**************************** FUNCTION DECLARATIONS ****************************/

void writeSolutionsBasic(const int,double [], vector<double> , vector<double>);
void writeSolutions(const int,double [], vector<double>, vector<double>, vector<double>);

/**************************** FUNCTION IMPLEMENTATIONS *************************/


void writeSolutionsBasic(const int nCells, double x[],vector<double> phiDataVectorsANL, vector<double> phiDataVectorsCDS)
{
// Open file to write
ofstream of ("output/solutions.dat");
if (of.is_open())
    {
    int setwl = 12;
    cout << setprecision(4);
    of <<  setw(setwl-7) << "Node:"       <<
          setw(setwl)    << "Distance:"   <<
          setw(setwl)    << "ANL Soln:"   <<
          setw(setwl)    << "CDS Soln:"   << endl;
    for (int i = 0 ; i != nCells ; ++i)
    {
        of  << setw(setwl-7)  <<
        i+1 << setw(setwl) <<
        x[i] << setw(setwl) <<
        phiDataVectorsANL[i] << setw(setwl) <<
        phiDataVectorsCDS[i] << setw(setwl) << endl;
    }
    // Close written file
    of.close();
    }
else cout << "Unable to open solutions.dat file." << endl;
}



void writeSolutions(const int nCells, double x[],vector<double> phiDataVectorsANL, vector<double> phiDataVectorsCDS, vector<double> phiDataVectorsUDS)
{
// Open file to write
ofstream of ("output/solutions.dat");
if (of.is_open())
    {
    int setwl = 12;
    cout << setprecision(4);
    of << setw(setwl-7)  << "Node:"       <<
          setw(setwl)    << "Distance:"   <<
          setw(setwl)    << "ANL Soln:"   <<
          setw(setwl)    << "CDS Soln:"   <<
          setw(setwl)    << "UDS Soln:"   <<
          setw(setwl)    << "Difference:" <<
          setw(setwl)    << "Error:"      << endl;
    for (int i = 0 ; i != nCells ; ++i)
    {
        of  << setw(setwl-7)  <<
        i+1 << setw(setwl) <<
        x[i] << setw(setwl) <<
        phiDataVectorsANL[i] << setw(setwl) <<
        phiDataVectorsCDS[i] << setw(setwl) <<
        phiDataVectorsUDS[i] << setw(setwl) <<
    abs(phiDataVectorsUDS[i] - phiDataVectorsANL[i]) / (phiDataVectorsANL[i])*100.0 << setw(setwl) <<
    abs(phiDataVectorsCDS[i] - phiDataVectorsANL[i]) / (phiDataVectorsANL[i])*100.0 << setw(setwl) << endl;
    }
    // Close written file
    of.close();
    }
else cout << "Unable to open solutions.dat file." << endl;
}
