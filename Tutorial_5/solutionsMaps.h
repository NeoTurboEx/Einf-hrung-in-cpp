/*******************************************************************************/
/************************** solutionsMaps.h ************************************/
/*******************************************************************************/
/* Creating maps and multimaps                                                 */
/*******************************************************************************/
#include "includes.h"
/**************************** INCLUDES *****************************************/

#include <map>           
#include <iterator>    

/**************************** FUNCTION DECLARATIONS ****************************/

void defineMaps(vector<double> &,vector<double> &,vector<double> &,map<int,double> &, map<int,double> &, map<int,double> &);


/**************************** FUNCTION IMPLEMENTATIONS *************************/

// Define maps for the analytical and numerical solution
/*** TODO 8 ***/
void defineMaps(vector<double> &phiDataVectorsANL,vector<double> &phiDataVectorsCDS,vector<double> &phiDataVectorsUDS,
			    map<int,double> &phiDataANLMaps,map<int,double> &phiDataCDSMaps, map<int,double> &phiDataUDSMaps)
{
 
 phiDataANLMaps.insert(make_pair(1,phiDataVectorsANL[0]));
 phiDataANLMaps.insert(make_pair(2,phiDataVectorsANL[1]));
 phiDataANLMaps.insert(make_pair(3,phiDataVectorsANL[2]));
 phiDataANLMaps.insert(make_pair(3,phiDataVectorsANL[3]));
 phiDataANLMaps.insert(make_pair(5,phiDataVectorsANL[4]));
 
 phiDataCDSMaps.insert(make_pair(1,phiDataVectorsCDS[0]));
 phiDataCDSMaps.insert(make_pair(2,phiDataVectorsCDS[1]));
 phiDataCDSMaps.insert(make_pair(3,phiDataVectorsCDS[2]));
 phiDataCDSMaps.insert(make_pair(4,phiDataVectorsCDS[3]));
 phiDataCDSMaps.insert(make_pair(5,phiDataVectorsCDS[4]));
 
 phiDataUDSMaps.insert(make_pair(1,phiDataVectorsUDS[0]));
 phiDataUDSMaps.insert(make_pair(2,phiDataVectorsUDS[1]));
 phiDataUDSMaps.insert(make_pair(3,phiDataVectorsUDS[2]));
 phiDataUDSMaps.insert(make_pair(4,phiDataVectorsUDS[3]));
 phiDataUDSMaps.insert(make_pair(5,phiDataVectorsUDS[4]));

}
/*** end of TODO 8 ***/

