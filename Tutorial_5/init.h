/*******************************************************************************/
/********************************* init.h **************************************/
/*******************************************************************************/
/* Inititialization of flow properties, geometry, initial conditions etc.      */
/*******************************************************************************/

/**************************** FUNCTION DECLARATION *****************************/
void init();

/**************************** FUNCTION IMPLEMENTATION **************************/
void init()
{  
    /*** TODO 1 ***/
    // Flow properties
    rho = 1.0;                                                                  // density of the medium, [kg/(m3)]
    Gamma = 0.1;                                                                // diffusion coefficient, [kg/(m*s)]
    u = 2.5;                                                                    // flow velocity, [m/s]

    // Computational domain geometry
    L = 1.0;                                                                    // length of the computational domain, [m]
    // Cell coordinates
    dx = L/nCells;                                                                   // size of the computational cell, [m]
    for (int i = 0; i != nCells; ++i)
    {
        x[i] = 	dx*i + dx/2;
        
    }
    // Boundary conditions
    phi0 = 1.0;                                                                 // concetration of the transported property at x = 0
    phiL = 0.0;                                                                 // concetration of the transported property at x = L
    /***end of TODO 1 ***/

 
     // Derived coefficients of the discretized equation
    Fe    = rho * u;                                                            // diffusion coefficient at the east point
    Fw    = rho * u;                                                            // diffusion coefficient at the west point
    De    = Gamma / dx;                                                         // convection coefficient at the east point
    Dw    = Gamma / dx;                                                         // convection coefficient at the east point



    // Additional coefficients for discretized transport equation
    // for the Central Differencing Scheme
    aE_CDS    = De - Fe / 2.0;                                                  // coefficient of the convective contribution to the east point
    aW_CDS    = Dw + Fw / 2.0;                                                  // coefficient of the convective contribution to the west point
    Sp_CDS    = 0.0;                                                            // free-term coefficients for the central point
    Sp0_CDS   = - (2.0 * Dw + Fw);                                              // free-term coefficients for the central point from the begining of the domain
    SpL_CDS   = - (2.0 * Dw - Fw);                                              // free-term coefficients for the central point from the end of the domain
    Su_CDS    = 0.0;                                                            // free-term coefficients for the central point
    Su0_CDS   =   (2.0 * De + Fe) * phi0;                                       // free-term coefficients for the central point from the begining of the domain
    SuL_CDS   =   (2.0 * De - Fw) * phiL;                                       // free-term coefficients for the central point from the end of the domain
    aP_CDS    = aW_CDS + aE_CDS + (Fe - Fw) - Sp_CDS;                           // coefficient of the convective contribution to the central point

    // Additional coefficients for discretized transport equation
    // for the Upwind Scheme
    aE_UDS  =  De;                                                              // coefficient of the convective contribution to the east point, Upwind scheme
    aW_UDS  =  De + Fe;                                                         // coefficient of the convective contribution to the west point, Upwind scheme
    Sp_UDS  =  0.0;                                                             // free-term coefficients for the central point, Upwind scheme
    Sp0_UDS =  - (2.0 * Dw + Fw);                                               // free-term coefficients for the central point, from the begining, Upwind scheme
    SpL_UDS =  - (2.0 * Dw);                                                    // free-term coefficients for the central point, from the end,Upwind scheme
    Su_UDS  =  0.0;                                                             // free-term coefficients for the central point
    Su0_UDS =    (2.0 * De + Fe) * phi0;                                        // free-term coefficients for the central point, Upwind scheme
    SuL_UDS =    (2.0 * De) * phiL;                                             // free-term coefficients for the central point, Upwind scheme
    aP_UDS  = aW_UDS + aE_UDS + (Fe - Fw) - Sp_UDS;                             // coefficient of the convective contribution to the central point


}

