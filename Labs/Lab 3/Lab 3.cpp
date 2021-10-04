#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int end = 0;

    cout << "Enter end of sequence: ";
    cin >> end;

    while (end < 1 || end > 214)
    {
        cout << "Please submit another value greater than 0 and less than 215";
        cout << "\nEnter end of sequence: ";
        cin >> end;
        cout << "\n\n";
    }
    cout << '\n';

    // Print Titles
    cout << setw(3) << "x" << setw(8) << "sqrt(x)" << setw(8) << "x^2" << setw(8) << "x^3" << fixed << endl;
    
    // Print square root, square and cube of numbers 1 to 10
    for (int x = 1; x <= end; ++x)
    {
        cout << setw(3) << x;
        cout.precision(3);
        cout << setw(8) << sqrt(x);
        cout.precision(0);
        cout << setw(8) << pow(x, 2);
        cout << setw(8) << pow(x, 3);
        cout << endl;
    }
    system ("pause");
}