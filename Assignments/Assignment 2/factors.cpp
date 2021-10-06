#include <iostream>
#include <iomanip>
using namespace std;

//function prototypes
int validValue (int);
int sumOfDigits (int);
int productOfDigits (int);
string isPerfectSquare (int);
string isPrime (int);
string isInteresting (int, int, int);

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

        //for loop that displays the factors of a number and count how many there are
        for (int factorNum = 1; factorNum <= currentNum; ++factorNum)
        {
            if ((currentNum % factorNum) == 0)
            {
                cout << factorNum << setw(4);
                ++factorCount;
            }
        }
        //output whether a number is perfect or prime
        cout << '(' << factorCount << ')' << isPerfectSquare(currentNum) << isPrime(factorCount) << '\n';
        factorCount = 0;
    }
    cout << '\n' << firstValue << ": sum of digits = " << sumOfDigits(firstValue) << ' ' << isInteresting(firstValue, sumOfDigits(firstValue), productOfDigits(firstValue));
    cout << '\n' << secondValue << ": sum of digits = " << sumOfDigits(secondValue) << ' ' << isInteresting(secondValue, sumOfDigits(secondValue), productOfDigits(secondValue));

    //end program, normally we put "return 0;" here but the window closes right away for me
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

//function determines the sum of a number's digits using modulus to retreive induvidual digits
int sumOfDigits (int num)
{
    int sum = 0;

    while (num != 0) 
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

//function determines the product of digits using a similar method to the one above
int productOfDigits (int num)
{
    int product = 1;
    int remainder = 0;

    while (num > 0)
	{
    	remainder = num % 10;
    	product = product * remainder;
    	num = num / 10;
	}
    return product;
}

//function determines if a number is interesting by using the formula provided in assignemnt description
string isInteresting (int num, int sum, int product)
{
    if ((sum + product) == num)
    {
        return "--interesting--";
    }
    else
    {
        return {};
    }
}