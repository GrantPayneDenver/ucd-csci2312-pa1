# Intermediate-PA1

This program takes in user inputs that create 3 points on a 3-D plane which form a triangle.
The triangle's area is then calculated using Heron's Formula. 
### Point.h
```
// A 3-dimensional point class!
// Coordinates are double-precision floating point.
class Point {

private:
double x;
double y;
double z;

public:
// Constructors
Point();                      // default constructor
Point(double x, double y);    // two-argument constructor

// Destructor
~Point();

// Mutator methods
void setX(double newX);
void setY(double newY);
void setZ(double newZ);

// Accessor methods
double getX();
double getY();
double getZ();
};

```
### Point.cpp
```
#include "Point.h"
#include <cmath>

// Default constructor
// Initializes the point to (0.0, 0.0, 0.0)
Point::Point() {
  x = 0.0;
  y = 0.0;
  z = 0.0;
}

// Constructor
// Initializes the point to (initX, initY, initZ)
Point::Point(double initX, double initY, double initZ) {
  x = initX;
  y = initY;
  z = initZ;
}

// Destructor
// No dynamic allocation, so nothing to do; if omitted, generated automatically
Point::~Point() {
  // no-op
}

// Mutator methods
// Change the values of private member variables

void Point::setX(double newX) {
  x = newX;
}

void Point::setY(double newY) {
  y = newY;
}

void Point::setZ(double newZ) {
  z = newZ;
}

// Accessors
// Return the current values of private member variables

double Point::getX() {
  return x;
}

double Point::getY() {
  return y;
}

double Point::getZ(){
  return z;
}

// Accessing
// Compute and return distance between points

double Point::distanceTo(Point& pointIn){
  double distance;          // the end distance to be returned
  double hypotenuse1;       // first part is computing the x and y plane distance between the two points
  double x2 = pointIn.x;    // hypotenuse1 holds that distance
  double y2 = pointIn.y;
  double z2 = pointIn.z;    // assignment of points from Point object passed in
  double deltax;
  double deltay;
  double deltaz;            // variables to hold the differences of x, y, and z coordianates
  deltax = x - x2;
  deltay = y - y2;
  deltaz = z - z2;

  hypotenuse1 = sqrt( pow(deltax, 2) + pow(deltay, 2));
  distance = sqrt( pow(hypotenuse1, 2) + pow(deltaz, 2));

  return distance;
} // end distanceTo
```
### main, pa1.cpp
```
#include "Point.h"
#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

double computeArea(Point&, Point&, Point&);          // prototype

// computeArea, takes in 3 point objects
// outputs the area of a triangle
double computeArea(Point &a, Point &b, Point &c)     // definition
{
    double area = 0;
    double leg1, leg2, leg3 = 0;
    double s = 0;
    leg1 = a.distanceTo(b);
    cout << leg1 << " is triangle length 1" << endl;
    leg2 = a.distanceTo(c);
    cout << leg2 << " is triangle length 2" << endl;
    leg3 = b.distanceTo(c);
    cout << leg3 << " is triangle length 3" <<endl;
    s = (leg1 + leg2 + leg3)/2;
    area = sqrt(s*(s - leg1)*(s - leg2)*(s - leg3));

    return area;
} // end computeArea()

int main(void) {
    cout << setprecision(2) << setw(2);
    Point p(0,0,0);         // Point objects, each initialized with three zeros for their coordinates
    Point q(0,0,0);
    Point r(0,0,0);
    double area = 0;        // Variable to hold the triangle area
    double num;             // variable that will take in user entered coordinate numbers

    cout << "Welcome to the triangle program, designed to find the area of a triangle using Heron's Formula." << endl;
    cout << "Please enter 3 points, 3 digits each." << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Please enter coordinate " << j << " for Point " << i << endl;
            cin >> num;
            if(i == 0 && j == 0)
            {
                p.setX(num);             // point p
            }
            else if(i == 0 && j == 1)
            {
                p.setY(num);              // point p
            }
            else if(i == 0 && j == 2)
            {
                p.setZ(num);              // point p
            }
            else if(i == 1 && j == 0)
            {
                q.setX(num);              //  point q
            }
            else if(i == 1 && j == 1)
            {
                q.setY(num);              //  point q
            }
            else if(i == 1 && j == 2)
            {
                q.setZ(num);              // point q
            }
            else if(i == 2 && j == 0)
            {
                r.setX(num);              // point r
            }
            else if(i == 2 && j == 1)
            {
                r.setY(num);              // point r
            }
            else if(i == 2 && j == 2)
            {
                r.setZ(num);              // point r
            }
        } // nested for

    }   // outer for



    area = computeArea(p,q,r);
    cout << "The area of your triangle is " <<  area << endl;


    return 0;
} // end main

``
