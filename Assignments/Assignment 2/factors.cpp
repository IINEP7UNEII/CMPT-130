#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//function prototypes
int validValue (int);
string isPerfectSquare (int);

int main()
{
    //initializes first and second value variables
    int firstValue = 0;
    int secondValue = 0;
    unsigned int factorCount = 0;

    //input first value and check whether its valid
    cout << "Enter a value between 1 and 999: ";
    cin >> firstValue;
    validValue(firstValue);

    //input second value and check whether its valid
    cout << "Enter a second value between 1 and 999: ";
    cin >> secondValue;
    validValue(secondValue);
    cout << '\n';

    //loop to list values from lowest to highest
    for (int currentNum = firstValue; currentNum <= secondValue; ++currentNum)
    {
        cout << setw(4) << currentNum << setw(4);

        for (int factorNum = 1; factorNum <= currentNum; ++factorNum)
        {
            if ((currentNum % factorNum) == 0)
            {
                cout << factorNum << setw(4);
                ++factorCount;
            }
        }
        cout << '(' << factorCount << ')' << isPerfectSquare(currentNum) << '\n';
        factorCount = 0;
    }

    system("pause");
}

//function checks whether input values are greater than 0 and less that 1000 and return input once appropriate value entered by user
int validValue(int input)
{
    //while loop to keep user to enter values until a valid value is entered
    while (input > 999 || input < 1)
    {
        cout << "The value must be greater than 0 and less than 1000: ";
        cin >> input;
    }
    return input;
}

string isPerfectSquare (int num) //continue here peter
{
    double square = 0.0;

}