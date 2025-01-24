/*******************************************************************************/
/**************************** Output.h ******************************************/
/*******************************************************************************/
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/
void Output(const double[], const int);      			 

/**************************** FUNCTION IMPLEMENTATIONS *************************/

//implement the Output function to output ktAve to the file "/output/kt3.dat"
void Output(const double ktAve[], const int nt)
{
   // write the results to a file
   ofstream outfile ("../output/kt3.dat");

   for(int i = 0 ; i < nt; i++)
   {
      outfile << i << " " << ktAve[i] << " " ;
      outfile << "\n";
   }

   outfile.close();
}
