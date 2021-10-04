#include <iostream>
using namespace std;

int main()
{
    //initializes the variables and sets them to zero
    int divident = 0;
    int divisor = 0;

    //prompt user to input divident and input it
    cout << "Enter the divident: ";
    cin >> divident;
    cout << '\n';

    //prompt user to input divisor and input it
    cout << "Enter the divisor: ";
    cin >> divisor;
    cout << '\n';

    //calculates the result and outputs it
    cout << divident << " divided by " << divisor << " = " << divident/divisor << " remainder " << divident%divisor << "\n";

    //pause window on screen to view result (would normally use "return 0;" to end program)
    system ("pause");
}