/*******************************************************************************/
/**********************************body.h **************************************/
/*******************************************************************************/
/* Body class                                                                  */
/*******************************************************************************/
#include "includes.h"
/*********************** CLASS & FUNCTION DECLARATION **************************/

// Declare a data type
class body
{
    /*** TODO 1a ***/
public:
    body() ; //  body() {};                                                              // constructor
    ~body();                                                                   // destructor

// Member functions
    void initAcceleration();
    void modAcceleration(double newAx,double newAy);
    void move(double newx, double newy);
    void accelerate(double dVx,double dVy);
    void printBody(ofstream &dataOutput);

    double getx();
    double gety();
    double getVx();
    double getVy();
    double getAx();
    double getAy();
    double getmass();

    void setx(double newx);
    void sety(double newy);
    void setVx(double newVx);
    void setVy(double newVy);
    void setAx(double newAx);
    void setAy(double newAy);
    void setmass(double newMass);

// Member data
private:
    double x, y;                                                                // position: x,y
    double Vx,Vy;                                                               // velocity     components
    double Ax, Ay;                                                              // acceleration components
    double m;                                    			                    // mass
};

/**************************** CLASS & FUNCTION IMPLEMENTATION ******************/

/*** TODO 1b ***/
body::body()                                             //constructor
{
}

body::~body()                                                                  //destructor
{
}

void body::initAcceleration()                                                   //zerolize the acceleration
{
    Ax=0.0;
    Ay=0.0;    
}

void body::modAcceleration(double newAx,double newAy)                 //modify the acceleration of a body
{
    Ax = Ax + newAx;
    Ay = Ay + newAy;
}

void body::move(double newx,double newy)                               //move a body
{
    x = x + newx;
    y = y + newy;
}

void body::accelerate(double dVx,double dVy)                       //accelerate a body
{
    Vx = Vx + dVx;
    Vy = Vy + dVy;
}

void body::printBody(ofstream &dataOutput)                                      //write body status out
{
    dataOutput << "," << x << "," << y << "," << Vx << "," << Vy << "," << Ax << "," << Ay; 
}

double body::getx()                                                             //return body state (x,y,Vx,Vy,Ax,Ay,m)
{
    return x;
}

double body::gety()
{
    return y;
}

double body::getVx()
{
    return Vx;
}

double body::getVy()
{
    return Vy;
}

double body::getAx()
{
    return Ax;
}

double body::getAy()
{
    return Ay;
}

double body::getmass()
{
    return m;
}

void body::setx(double newx)                                                                    //set body state (x,y,Vx,Vy,Ax,Ay,m)
{
    x = newx;
}

void body::sety(double newy) 
{
    y = newy;
}

void body::setVx(double newVx) 
{
    Vx = newVx;
}

void body::setVy(double newVy) 
{
    Vy = newVy;
}

void body::setAx(double newAx) 
{
    Ax = newAx;
}

void body::setAy(double newAy) 
{
    Ay = newAy;
}

void body::setmass(double newmass) 
{
    m = newmass;
}

