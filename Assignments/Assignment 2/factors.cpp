#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
int validValue (int);
string isPerfectSquare (int);
string isPrime (int);

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
        cout << '(' << factorCount << ')' << isPerfectSquare(currentNum) << isPrime(factorCount) << '\n';
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

//function that determines whether a number is a perfect square
//the sqaure root of a perfect square is an integer, so if we sqrt the value and assign it to an integer and then multiply it to itself, then we should get the original number back
string isPerfectSquare (int num)
{
    for (int square = 1; square * square <= num; square++) 
    {
        if ((num % square == 0) && (num / square == square)) 
        {
            return "  **perfect square**";
        }
    }
    return {};
}

//function determines whether a number is prime by determening if the number of factors is has is equal to 2
string isPrime (int factors)
{
    if (factors == 2)
    {
        return "  **prime**";
    }
    else
    {
        return {};
    }
}

//continue interesting numbers function