/*******************************************************************************/
/********************************* initialize.h ********************************/
/*******************************************************************************/
/* Initialization of the number of bodies, initial conditions,                 */
/* time integration paramenters, etc.                                          */
/*******************************************************************************/
        system("clear");
    
    /***************************************************************************/
    /* Read and store body descriptions ****************************************/
    /***************************************************************************/
     // Read INPUT
        int n;
        double inpx; 
        double inpy;
        double inpVx; 
        double inpVy;
        double inpmass;

        cin >> n;
        vector<body> bodies(n);                                                // Declare a vector with n elements
	for (int i=0; i<n; ++i)                                               
        {
        cin >> inpx 
            >> inpy
            >> inpVx 
            >> inpVy
            >> inpmass;

        bodies[i].setx(inpx);
        bodies[i].sety(inpy);
        bodies[i].setVx(inpVx);
        bodies[i].setVy(inpVy);
        bodies[i].setmass(inpmass);
        }

     // Prepare OUTPUT
        ofstream dataOutput("output/dataBodies.txt");                          // Prepare a file in which to write out the body status at each iteration
        dataOutput << "# Time" ;
        for (int i=0; i<n; ++i) 
        {  
        dataOutput << "," 
                   << "x"  << i+1 << "," << "y"  << i+1 << "," 
                   << "Vx" << i+1 << "," << "Vy" << i+1 << "," 
                   << "Ax" << i+1 << "," << "Ay" << i+1; 
        }
        dataOutput << "\n";

    /***************************************************************************/
    /* Prescribe Euler time integration parameters: ****************************/
    /***************************************************************************/
        double nIt=0.0;                                                        //number of iterations  
        double tini=0.0;                                                       //t0  
        double tmax=10.0;                                                      //integrate up to t=tmax  
        double dt=0.01;                                                        //time step  

        /*** TODO 5b ***/
        double theta_tol = 0.01;                                                        //Angular tolerance in radians

    /***************************************************************************/

