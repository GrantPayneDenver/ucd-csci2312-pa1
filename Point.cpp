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

