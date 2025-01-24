/*******************************************************************************/
/**************************** auxiliary.h **************************************/
/*******************************************************************************/
/* Auxiliary functions                                                         */
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/
string int2str(const int);                                                      // convert integer 2 string
void   calcRad(double [], const double, const double, const int);               // calc array of radial positions

/**************************** FUNCTION IMPLEMENTATIONS *************************/
string int2str(const int intNum)                                                // convert integer 2 string
{
    stringstream ss;                                                            // create a stringstream
   
    ss << intNum;                                                               // add integer number to the stream
   
    return ss.str();                                                            // return string w/ contents of stream
}


void calcRad(double rad[], const double radMin, const double radMax, const int nRad) // calc array of radial positions
{
    const double radStp = (radMax-radMin)/(double(nRad)-1.0);                   // calc step size   
    
    rad[0] = radMin;                                                            // set  first array element to radMin
    
    for (int i = 1; i < nRad; i++)                                              // loop over elements of rad
    {
        rad[i] = rad[i-1] + radStp;                                             // calc rad[i]
    }
}
