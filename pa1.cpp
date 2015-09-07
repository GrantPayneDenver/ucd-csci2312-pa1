//
// Created by Ivo Georgiev on 8/25/15.
//

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
    double leg1, leg2, leg3 = 0;                         // triangle distances
    double s = 0;                                        // heron's formula s
    leg1 = a.distanceTo(b);
    cout << leg1 << " is triangle length 1" << endl;
    leg2 = a.distanceTo(c);
    cout << leg2 << " is triangle length 2" << endl;
    leg3 = b.distanceTo(c);
    cout << leg3 << " is triangle length 3" <<endl;
    s = (leg1 + leg2 + leg3)/2;                          // heron's formula
    area = sqrt(s*(s - leg1)*(s - leg2)*(s - leg3));     // ^^^^

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

