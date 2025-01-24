/*******************************************************************************/
/*************************** printOnTheScreenBasic.h ***************************/
/*******************************************************************************/
/* Standard input/output on the terminal                                       */
/*******************************************************************************/


/**************************** FUNCTION DECLARATIONS ****************************/

void printOnTheScreenBasic();

/**************************** FUNCTION IMPLEMENTATIONS *************************/

void printOnTheScreenBasic(){
    
cout << "\n\n";
cout << "*****************************************************************************\n";
cout << "*                     ***** Begin of the Solution *****                     *\n";
cout << "*****************************************************************************\n";
cout << "\n";
 
cout << "Program has calculated fluid concentration for" << " " << nCells << "points."<<endl; 
cout << "The results from different methods are:" << endl;
cout << "\n";
cout << "x[i]:  "<<"analytical:  "<<"central: " << endl;
//cout << "x[i]:  "<<"analytical:  "<<"central: "<<"num.upwind:" << endl;
cout << "----------------------------"<< endl;
//cout << "-----------------------------------------"<< endl;
for (int i = 0; i != nCells; ++i)
    cout<< x[i] <<  "   |  " <<setprecision(4)<<phiDataVectorsANL[i]<< "  | "<<setprecision(4) << phiDataVectorsCDS[i] << "  |  " << setprecision(4)<< endl;

cout << "\n\n";
cout << "*****************************************************************************\n";
cout << "*                       ***** End of the Solution *****                     *\n";
cout << "*****************************************************************************\n";
cout << "\n";
 
}
