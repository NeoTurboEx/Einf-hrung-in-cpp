/*******************************************************************************/
/**************************** IO.h *********************************************/
/*******************************************************************************/
/* Functions for data input/output (files/display)                             */
/*******************************************************************************/
//#include "includes.h"

/**************************** FUNCTION DECLARATIONS ****************************/
void readInput(const int,double& ,double& , double& , double& ,
			   double& ,double& ,double& ,double&, double&); 		// TODO 1: read input darf nicht const sein da ich sonst die variable nicht überschreiben kann
void dispInput(const int ,const double , const double ,const double,
			   const double ,const double ,const double ,const double , double); // TODO 2: display input          
                                                                           
void writeOutput(const double rad[],  const double tmp[],  const int nRad,      // write output
                 const int  it);                                                // write output


/**************************** FUNCTION IMPLEMENTATIONS *************************/
void readInput(const int nInp,double &mDot,double &radSrf,double &radInf,
			   double &tmpSrf,double &tmpInf,double &cpGas,double &kGas,double &hVap) 	// TODO 1: read input
{

    cout << "TODO 1: Implement (complete) header, declaration and call of function readInput()." << endl;

    

    cout << "readInput(): Reading inputs... \n" ;

    ifstream data("input/input.dat");                                           // init ifstream 4 input data file
    string line;                                                              // init string for line by line extraction
    double   dummy, inputs[nInp];                                               // init double arrays 4 input 
    int      i = 0;                                                             // init counter 4 (valid) input

    while(getline(data,line))                                                   // parse through file
    {
        stringstream str(line);
        string text;
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
      
      cout << mDot;
}


void dispInput(const int nInp,double mDot,const double radSrf,const double radInf,
			   const double tmpSrf,const double tmpInf,const double cpGas,
			   const double kGas,const double hVap) // TODO 2: display input  
{

    cout << "TODO 2: Implement (complete) header, declaration and call of function dispInput()." << endl;

    
    cout << "\n" << "*** " << nInp << " Inputs ***" << endl << endl;

    printf("mDot:   %10.2e kg/s     \n",mDot);
    printf("radSrf: %10.2e m        \n",radSrf);
    printf("radInf: %10.2e m        \n",radInf);
    printf("tmpSrf: %10.2f K        \n",tmpSrf);
    printf("tmpInf: %10.2f K        \n",tmpInf);
    printf("cpGas:  %10.2f J/(kg-K) \n",cpGas);
    printf("kGas:   %10.2e W/(m-K)  \n",kGas);
    printf("hVap:   %10.2e J/kg     \n",hVap);
 
    cout << endl;
    
}


void writeOutput(const double rad[], const double tmp[], const int nRad,        // write output
                 const int it)                                               // write output
{
    // assemble file path & open file
    char fpath[100];                                                            // create filename (array of char)
    strcpy(fpath,"output/output_");                                             // add basepath 2 filename
    string str = int2str(it);                                                   // convert iteration counter 2 string
    const char * itc = str.c_str();                                             // convert iteration string  2 const char *
    strcat(fpath,itc);                                                          // add iteration number 2 filename
    strcat(fpath,".dat");                                                       // add suffix 2 filename
    
    // Using C file I/O
    FILE *pFile;                                                                // init file
    pFile = fopen(fpath,"w");                                                   // open file 4 writing

    // write radial temperature profile to file & close
    fprintf (pFile,"# rad [m]      tmp [K] \n");
    for (int i=0 ; i < nRad ; i++)
    {
      fprintf(pFile,"%10.2e %8.2f \n",rad[i],tmp[i]);
    }
    fclose(pFile);
    
    
    //Using C++ file I/O;
	ofstream myFile;                                                            // create fstream object for output
    myFile.open(fpath);                                                         // open file 
    myFile << "# rad [m]      tmp [K] \n";                                      // write header
    for (int i=0 ; i < nRad ; i++)                                              // loop over nRad
    {
        myFile << setw(10) << scientific << setprecision(2) << rad[i]<< " "     // set field width and precision for rad; also set notation to scientific
              << setw(8) << fixed << setprecision(2) << tmp[i] <<endl;         // set field width and percision for temperature; set notation back to fixed point
    }
    myFile.close();
}
