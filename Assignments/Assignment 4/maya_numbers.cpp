#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//function definitions
void printMayanNumber(int);
int powOfTwenty(int);
void printOnes(int);
int numberOfOnes(int);
void printFives(int);
int numberOfFives(int);
void printZero(int);
void printSeparator();

const int MAYAN_NUMBER_BASE = 20; //vigesimal

int main() //main function that only calls printMayanNumber
{
    int num = 0;

    cout << "Enter number to convert into Mayan number: ";
    cin >> num;
    cout << "\n\n";

    printMayanNumber(num);
    cout << '\n';

    system("pause");
}

void printMayanNumber (int num) //prints mayan numbers by calling other functions
{
    int result = num;
    int remainder = 0;
    int* mayanArray = new int[powOfTwenty(num)]; //dynamic array who's size is determined by powOfTwenty funciton

    for (int count = powOfTwenty(num) - 1; count >= 0; --count) //assigning numbers to the dynamic array in base 20 (72 would be [3, 12])
    {
        remainder = result % MAYAN_NUMBER_BASE;
        result = result / MAYAN_NUMBER_BASE;
        mayanArray[count] = remainder;
    }

    for (int count = 0; count < powOfTwenty(num); ++count)  //printing ones, fives, and the separator
    {   
        if (numberOfOnes(mayanArray[count]) > 0) // if statement for formatting so we dont get an extra \n in output
        {
            printOnes(mayanArray[count]);
        }
        printFives(mayanArray[count]);
        printZero(mayanArray[count]);

        if (count != powOfTwenty(num) - 1) // for formatting so we do not get an extra separator
        {
            printSeparator();
        }
    }

    delete[] mayanArray; //delete dynamic array
}


int powOfTwenty(int num) //to determine the number of digits in the a base 20 version of the number
{
    int count = 0;

    while (pow(MAYAN_NUMBER_BASE, count) <= num)
    {
        ++count;
    }
    return count;
}

void printOnes(int rem) //function is responsible for printing ones
{
    int maxNumberOfOnes = 4; //there could only be 4 ones in one line
    int numSpaces = maxNumberOfOnes - numberOfOnes(rem);
    char one = 'o';
    char space = ' ';

    cout << space; //for formatting

    for (int count = 0; count < maxNumberOfOnes; ++count) //for loops goes through all the possible ones if could print and prints either a space or a one
    {
        if (count < numSpaces)
        {
            cout << space;
        }
        else
        {
            cout << one;
        }
    }
    cout << '\n';
}

int numberOfOnes(int num) //funciton determines the number of ones to print
{
    int lineValue = 5; //one line of ones = 5
    int ones = 0;

    ones = num % lineValue;
    return ones;
}

void printFives(int rem) //funciton is resonsible to print fives
{
    int maxNumberOfFives = 4; //there could only be 4 fives in one line
    string five = "====";

    for (int count = 0; count < numberOfFives(rem); ++count)
    {
        cout << ' ' << five << '\n';
    }
}

int numberOfFives(int num) //function determines the number of fives to print
{
    int lineValue = 5; //one line = 5
    int fives = 0;

    fives = num / lineValue;
    return fives;
}

void printZero(int num) //function is responsible for printing zero
{
    if (num == 0)
    {
        cout << "  00\n";
    }
}

void printSeparator() //funciton prints seperator between base 20s
{
    const string split = "______";
    cout << split << "\n";
}