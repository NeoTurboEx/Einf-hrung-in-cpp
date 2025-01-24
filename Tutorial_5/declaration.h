/*******************************************************************************/
/**************************** declaration.h ************************************/
/*******************************************************************************/
/* Declaration of variable types                                               */
/*******************************************************************************/
#include "includes.h"

// Flow properties
double          rho;                                                            // density of the medium, [kg/(m3)]
double          Gamma;                                                          // diffusion coefficient, [kg/(m*s)]
double          u;                                                              // flow velocity, [m/s]

// Computational domain geometry
const int       nCells = 25;                                                     // number of the mesh cells, [-]
double          L;                                                              // length of the computational domain, [m]
double          dx;                                                             // size of the computational cell, [m]
double          x[nCells];                                                      // coordinate position, [m]

// Vector declaration
vector<double>  phiDataVectorsANL(nCells);                                      // numericaly calculated concentration, [parts of 1]                         
vector<double>  phiDataVectorsCDS(nCells);                                      // numericaly calculated concentration using central diferencing scheme, [parts of 1]
vector<double>  phiDataVectorsUDS(nCells);                                      // numericaly calculated concentration using upwind scheme, [parts of 1]

// Declare maps for the analytical and numerical solution
/*** TODO 7 ***/
map<int,double> phiDataANLMaps;                                              // map for the analytical calculated concentration - phiDataANLMaps
map<int,double> phiDataCDSMaps;                                              // map for the numerical concentration calculated with the central scheme - phiDataCDSMaps
map<int,double> phiDataUDSMaps;                                              // map for the numerical concentration calculated with the upwind scheme - phiDataUDSMaps

map<int,double>::iterator it;                           	                        // iterator for a map of int-double pairs
/*** end of TODO 7 ***/

// Boundary conditions
double    phi0;                                                                 // concetration of the transported property at x = 0
double    phiL;                                                                 // concetration of the transported property at x = L

// Discretizing scheme coefficients
double    Fe;                                                                   // diffusion coefficient at the east point
double    Fw;                                                                   // diffusion coefficient at the west point
double    De;                                                                   // convection coefficient at the east point
double    Dw;                                                                   // convection coefficient at the west point
// internal coefficients of discretized scalar equation
double    aE_CDS;                                                               // coefficient of the convective contribution to the east point
double    aP_CDS;                                                               // coefficient of the convective contribution to the middle point
double    aW_CDS;                                                               // coefficient of the convective contribution to the west point
// internal free-term coefficients of the discretized equation
double    Sp_CDS, Sp0_CDS, SpL_CDS;                                             // free-term coefficients for the central point, at the begining and at the end of domain
double    Su_CDS, Su0_CDS, SuL_CDS;                                             // free-term coefficients for the central point, at the begining and at the end of domain

// Additional coefficients for discretized transport equation
// for the Upwind Scheme
double    aW_UDS, aP_UDS,   aE_UDS;                                               // coefficient of the convective contribution to the west, central and east point
double    Sp_UDS, Sp0_UDS, SpL_UDS;                                             // free-term coefficients for the west, central and east point
double    Su_UDS, Su0_UDS, SuL_UDS;                                             // free-term coefficients for the west, central and east point

