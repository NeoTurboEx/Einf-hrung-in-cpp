/*******************************************************************************/
/**************************** IO.h *********************************************/
/*******************************************************************************/
/* Functions for data input/output (files/display)                             */
/*******************************************************************************/

/**************************** FUNCTION DEFINITIONS *************************/
void   getNumberOfLines(int &lines, const char* fileName)
{
    string line;
    ifstream fileExp(fileName);                                           // init ifstream 4 input data file
    while (getline(fileExp,line))
        ++lines;

    // For debugging: display number of lines in file
    cout << "Nr. of lines in input data: " << lines << endl;
}

template<class T, class U>
void   readInput(vector<T>& vec1, vector<U>& vec2, const char* fileName)
{
    ifstream data(fileName);                                              // init ifstream for input data file
    string   line;                                                        // init string for line by line extraction
    T        val1;                                                        // init object of type T for input 
    U        val2;                                                        // init object of type U for input 
    int      i = 0;                                                       // count valid lines
    while(getline(data,line))                                             // parse through file
    {
        stringstream    str(line);
        string          text;
        str >> val1 >> val2;                                              // read str into val1 and val2
        if(!str.fail())                                                   // data found?
        {
            vec1[i] = val1;                                                 // store data in input vector
            vec2[i] = val2;                                                 // store data in input vector
            i++;                                                          // increase data counter
        }
    }
}

// TODO 3: write a function display() which displays a vector independent of the type; 
// hint: get the size of the vector vec with: int n = vec.size();
template <class D>

void display(vector<D>& vec )
{
	int n = vec.size();
	for (int i = 0; i < n ;++i)
	{
		cout << i << ". Eintrag: " << vec[i] << endl;
	}
}
