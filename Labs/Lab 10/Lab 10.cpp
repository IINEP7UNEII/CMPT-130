#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

// Circle struct goes here
struct Circle
{
    int x;
    int y;
    double radius;
};

// Function prototypes
bool intersect(Circle c1, Circle c2);
double area(Circle c);

int main()
{
    Circle c1 = { 5, 6, 3.2 };
    Circle c2 = { 6, 8, 1.2 };

    // Intersect test 1
    if (intersect(c1, c2)) 
    {
        cout << "The circles intersect" << endl;
    }
    else 
    {
        cout << "The circles do NOT intersect" << endl;
    }

    // Intersect test 2  
    Circle c3 = { 12, 2, 3.2 };
    Circle c4 = { 2, 12, 5.7 };

    if (intersect(c3, c4)) 
    {
        cout << "The circles intersect" << endl;;
    }
    else 
    {
        cout << "The circles do NOT intersect" << endl;
    }

    // Area test
    cout << endl << "Area of c1 = " << area(c1) << endl << endl;

    system("pause");
}

bool intersect(Circle c1, Circle c2)
{
    int distance = sqrt(pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2));
    int sum = c1.radius + c2.radius;
    
    if (sum > distance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double area(Circle c1)
{
    int area = PI * pow(c1.radius, 2);
    return area;
}