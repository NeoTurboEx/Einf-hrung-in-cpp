/*******************************************************************************/
/**************************** declaration.h ************************************/
/*******************************************************************************/
/* Declaration of variable types for globally used variables                   */
/*******************************************************************************/

// Heat transfer coefficient * reference area
double    kA;

// Inflow conditions 
double    W1,W2;                                                                 // heat capacity flow of stream 1 and 2, [W/K]

/*******************************************************************************/
/* For tube heat exchanger                                                     */
/*******************************************************************************/

// Numerical resolution
const int nCells=100;                                                              // number of mesh cells
// Heat exchanger geometry
double    ARef;                                                                   // reference area, [m^2]
double    x[nCells+1];                                                            // coordinate position, [m]
// Temperature fields
double    theta1[nCells+1];                                                       // temperature stream 1, [K]
double    theta2[nCells+1];                                                       // temperature stream 2, [K]

// FlowMode

int flowMode;
