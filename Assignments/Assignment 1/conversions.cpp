#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //declares and initializes constant variables
    const double inchesInMeters = 39.37008;
    const unsigned int inchesInFoot = 12;
    const double furlongsInMeters = 0.0049709695378987;
    const unsigned int speedOfLight = 299792000; // m/s

    //declares variables and initializes them to 0 (or 0.0 for double)
    double radius = 0.0;
    double area = 0.0;
    double meters = 0.0;
    unsigned int feet = 0;
    double inches = 0.0;
    double furlong = 0.0;
    double seconds = 0.0;

    //output circle area title
    cout << "CIRCLE AREA\n-----------\n";

    //prtomt user input and input radius
    cout << "Enter radius: ";
    cin >> radius;

    //calculate area of circle
    area = radius * radius * M_PI;

    //output radius and the area
    cout << setprecision(2) << fixed << "\na circle with radius = " << radius <<" has an area = " << area << "\n\n";

    //output distance title
    cout << "DISTANCE" << "\n--------\n";

    //promt user to input distance and input it
    cout << "Enter distance in meters: ";
    cin >> meters;

    //calculating inches and feet from meters
    inches = meters * inchesInMeters;
    feet = inches / inchesInFoot;
    inches = fmod(inches, inchesInFoot);

    //output of meters to feet and inches conversion
    cout << '\n' << setprecision(1) << fixed << meters << " meters = " << feet << "\' " << setprecision(5) << fixed << inches << '\"';

    //calculating meters to furlongs conversion
    furlong = meters * furlongsInMeters;

    //output of meters to furlong conversion
    cout << '\n' << setprecision(1) << fixed << meters << " meters = " << setprecision(4) << fixed << furlong << " furlongs\n";

    //calculates time light needs to travel in amount of meters
    seconds = meters / speedOfLight;

    //outputs the time needed for light to travel a certain amout of meters
    cout << "It takes " << scientific << setprecision(4) << seconds << "s for light to travel "  << setprecision(1) << fixed << meters << "m in a vacuum\n\n";

    //pauses terminal window on screen so we could see the result (normally would end with "return 0;"")
    system("pause");
}