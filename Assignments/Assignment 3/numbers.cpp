#include <iostream>
#include <string>
#include <cmath> //remove if not using
using namespace std;

//function prototypes
string intToString(int);
void printIntStrings(int, int, int);

string ones(int);
string teens(int);
string tens(int);
string hundreds(int);
string thousands(int);

int main() //only used for testing purposes, delete afterwards
{
    int start = 0;
    int end = 0;
    int interval = 0;

    cout << "Enter start: ";
    cin >> start;
    cout << "Enter end: ";
    cin >> end;
    cout << "Enter interval: ";
    cin >> interval;
    cout << "\n\n";

    printIntStrings(start, end, interval);
    cout << "\n\n";

    system("pause");
}

//intToString definition
string intToString(int number)
{
    string err = "error";
    string s = "";

    int digit = 0;
    int numSize = 0;
    int count = 1;

    if (number >= 0 || number <= 99999)
    {
        /*while (number > 0 && number < 10)
        {
            digit = number % 10;
            number = number / 10;
            cout << digit << " - " << ones(digit) << '\n';
        }*/
        int ones = number % 10;
        number /= 10;
        int tens = number % 10;
        if (tens == 1)
        {
            int teens = tens * 10 + ones;
        }
        number /= 10;
        int hundreds = number % 10;
        number /= 10;
        int thousands = number % 10;

        

    }
    else if (number == 0)
    {
        s = "zero";
    }
    else
    {
        cerr << err;
    }
    return s;
}

//printIntStrings definition
void printIntStrings(int start, int end, int interval)
{
    if (end > start) //ascending order
    {
        for (int count = start; count <= end; count += interval)
        {
            cout << intToString(count);
        }
    }
    else if (start > end) //descending order
    {
        for (int count = start; count >= end; count -= interval)
        {
            cout << intToString(count);
        }
    }
    else //if start = end
    {
        cout << start;
    }
}

string ones(int num) //returns strings for ones
{
    string word = "";

    switch (num)
    {
        case 0:
        {
            word = "zero"; // change
            break;
        }
        case 1:
        {
            word = "one";
            break;
        }
        case 2:
        {
            word = "two";
            break;
        }
        case 3:
        {
            word = "three";
            break;
        }
        case 4:
        {
            word = "four";
            break;
        }
        case 5:
        {
            word = "five";
            break;
        }
        case 6:
        {
            word = "six";
            break;
        }
        case 7:
        {
            word = "seven";
            break;
        }
        case 8:
        {
            word = "eight";
            break;
        }
        case 9:
        {
            word = "nine";
            break;
        }
        default:
        {
            word = "out of bound error in ones";
        }
    }
    return word;
}

string teens(int num) //returns strings for teens
{
    string word = "";

    switch (num)
    {
        case 10:
        {
            word = "ten";
            break;
        }
        case 11:
        {
            word = "eleven";
            break;
        }
        case 12:
        {
            word = "twelve";
            break;
        }
        case 13:
        {
            word = "thirteen";
            break;
        }
        case 14:
        {
            word = "fourteen";
            break;
        }
        case 15:
        {
            word = "fifteen";
            break;
        }
        case 16:
        {
            word = "sixteen";
            break;
        }
        case 17:
        {
            word = "seventeen";
            break;
        }
        case 18:
        {
            word = "eighteen";
            break;
        }
        case 19:
        {
            word = "nineteen";
            break;
        }
        default:
        {
            word = "out of bound error in teens";
        }
    }
    return word;
}

string tens(int num) //returns strings for tens, calls ones function
{
    string word = "";

    if (num >= 20 && num < 30)
    {
        word = "twenty";
    }
    else if (num >= 30 && num < 40)
    {
        word = "thirty";
    }
    else if (num >= 40 && num < 50)
    {
        word = "fourty";
    }
    else if (num >= 50 && num < 60)
    {
        word = "fifty";
    }
    else if (num >= 60 && num < 70)
    {
        word = "sixty";
    }
    else if (num >= 70 && num < 80)
    {
        word = "seventy";
    }
    else if (num >= 80 && num < 90)
    {
        word = "eighty";
    }
    else if (num >= 90 && num < 100)
    {
        word = "ninety";
    }
    else
    {
        word = "out of bound error in tens";
    }
    return word;
}

string hundreds(int num)
{
    string word = "";
    //calls other functions
    return word;
}

string thousands(int num)
{
    string word = "";
    //calls other functions
    return word;
}