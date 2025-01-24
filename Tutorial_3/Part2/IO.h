/*******************************************************************************/
/**************************** IO.h *********************************************/
/*******************************************************************************/
/* Functions for data input/output (files/display)                             */
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/
void   readInput(double &mDot,   double &radSrf, double &radInf, double &tmpSrf,// read input
                 double &tmpInf, double &cpGas , double &kGas,   double &hVap  ,// read input     
                 const int nInp);                                               // read input  

void   dispInput(const double mDot,   const double radSrf, const double radInf, // disp input
                 const double tmpSrf, const double tmpInf, const double cpGas,  // disp input
                 const double kGas,   const double hVap,   const int    nInp);  // disp input             
                                                                           
void writeOutput(const double rad[],  const double tmp[],  const int nRad,      // write output
                 const int    it);                                              // write output


/**************************** FUNCTION IMPLEMENTATIONS *************************/
void   readInput(double &mDot,   double &radSrf, double &radInf, double &tmpSrf,// read input
                 double &tmpInf, double &cpGas , double &kGas,   double &hVap  ,// read input     
                 const int nInp)                                                // read input  
{
    cout << "readInput(): Reading inputs... \n" ;

    ifstream data("input/input.dat");                                           // init ifstream 4 input data file
    string   line;                                                              // init string for line by line extraction
    double   dummy, inputs[nInp];                                               // init double arrays 4 input 
    int      i = 0;                                                             // init counter 4 (valid) input

    while(getline(data,line))                                                   // parse through file
    {
        stringstream    str(line);
        string          text;
        getline(str,text,'=');                                                  // search for "="
        str >> dummy;                                                           // read str into (dummy) double
        // cout << " line: " << line;
        if(!str.fail())                                                         // data found?
        {
            inputs[i] = dummy;                                                  // store data in inputs array
            i++;                                                                // increase data counter
        }
    }

    if (i == nInp)
    {
        cout << "readInput(): Found " << nInp << " inputs." << endl;  
    }
    else
    {
        cout << "readInput(): FAILED to find the expected number of inputs." << endl;  
    }

    // assign input quantities to their intended names
    mDot   = inputs[0];
    radSrf = inputs[1];
    radInf = inputs[2];
    tmpSrf = inputs[3];
    tmpInf = inputs[4];
    cpGas  = inputs[5];
    kGas   = inputs[6];
    hVap   = inputs[7];
}


void dispInput(const double mDot,   const double radSrf, const double radInf,   // disp input
               const double tmpSrf, const double tmpInf, const double cpGas,    // disp input
               const double kGas,   const double hVap,   const int    nInp)     // disp input
{

    cout << "\n" << "*** " << nInp << " Inputs ***" << endl << endl;

    printf("mDot:   %10.2e kg/s     \n",mDot);
    printf("radSrf: %10.2e m        \n",radSrf);
    printf("radInf: %10.2e m        \n",radInf);
    printf("tmpSrf: %10.2f K        \n",tmpSrf);
    printf("tmpInf: %10.2f K        \n",tmpInf);
    printf("cpGas:  %10.2f J/(kg-K) \n",cpGas);
    printf("kGas:   %10.2e W/(m-K)  \n",kGas);
    printf("hVap:   %10.2e J/kg     \n",hVap);
}


void writeOutput(const double rad[], const double tmp[], const int nRad,        // write output
                 const int    it)                                               // write output
{
    FILE *pFile;                                                                // init file

    // assemble file path & open file
    char fpath[100];                                                            // create filename (array of char)
    strcpy(fpath,"output/output_");                                             // add basepath 2 filename
    string str = int2str(it);                                                   // convert iteration counter 2 string
    const char * itc = str.c_str();                                             // convert iteration string  2 const char *
    strcat(fpath,itc);                                                          // add iteration number 2 filename
    strcat(fpath,".dat");                                                       // add suffix 2 filename
    pFile = fopen(fpath,"w");                                                   // open file 4 writing

    // write radial temperature profile to file & close
    fprintf (pFile,"# rad [m]      tmp [K] \n");
    for (int i=0 ; i < nRad ; i++)
    {
      fprintf(pFile,"%10.2e %8.2f \n",rad[i],tmp[i]);
    }
    fclose(pFile);
}
