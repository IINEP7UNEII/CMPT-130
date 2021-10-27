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

    if (number > 0 && number <= 99999)
    {
        s += tens(number);
        s += teens(number);
        s += ones(number);
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
void printIntStrings(int start, int end, int interval) //change to include commas if number is greater than one-thousand. Ex: "1,000" or " 36,000"
{
    if (end > start) //ascending order
    {
        for (int count = start; count <= end; count += interval)
        {
            cout << count << " - " << intToString(count) << '\n';
        }
    }
    else if (start > end) //descending order
    {
        for (int count = start; count >= end; count -= interval)
        {
            cout << count << " - " << intToString(count) << '\n';
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
    int range = num / 10;

    if (range % 10 != 1)
    {
        switch (num % 10)
        {
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
                break;
            }
        }
    }
    return word;
}

string teens(int num) //returns strings for teens
{
    string word = "";
    int range = num / 10;

    if (range % 10 == 1)
    {
        switch (num % 20)
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
                break;
            }
        }
    }
    return word;
}

string tens(int num) //returns strings for tens, calls ones function
{
    string word = "";
    int range = num / 10;

    switch (range % 10)
    {
        case 2:
        {
            word = "twenty";
            break;
        }
        case 3:
        {
            word = "thirty";
            break;
        }
        case 4:
        {
            word = "fourty";
            break;
        }
        case 5:
        {
            word = "fifty";
            break;
        }
        case 6:
        {
            word = "sixty";
            break;
        }
        case 7:
        {
            word = "seventy";
            break;
        }
        case 8:
        {
            word = "eighty";
            break;
        }
        case 9:
        {
            word = "ninety";
            break;
        }
        default:
        {
            break;
        }
    }
    
    if (range % 10 >= 2 && num % 10 != 0)
    {
        word += "-";
    }

    ones(num);
    return word;
}

string hundreds(int num)
{
    string word = "";
    //calls some preceding functions
    return word;
}

string thousands(int num)
{
    string word = "";
    //calls some preceding functions
    return word;
}