/*******************************************************************************/
/**************************** Input.h ******************************************/
/*******************************************************************************/
/*******************************************************************************/

/**************************** FUNCTION DECLARATIONS ****************************/
void Input(double[], double[], double[], const int, const int); 

/**************************** FUNCTION IMPLEMENTATIONS *************************/

//implement the Input function to read the velocity files into arrays on the heap
void Input(double uprime[], double vprime[], double wprime[], const int i, const int ncells)
{
      char st1[20] = "../input/U";    	  // declare the string of common part of the file name 
      char filename[20] = {'\0'};     	  // declare the string of full filename.  
      ifstream infile;
      sprintf(filename, "%s%d", st1, i);  // the filename is composed by the common parts 'U' and the loop i
      infile.open(filename);              // open the velocity files

      if(infile.fail())                   // check to see if files are opened 
      { 
         cout << "input error" << endl;
      }

      for (j=0; j<ncells; j++)            // loop all the cells in the domain
      {
         infile >> uprime[j];             // read u' into an array on the heap
         infile >> vprime[j];             // read v' into an array on the heap
         infile >> wprime[j];             // read w' into an array on the heap
      }
}
