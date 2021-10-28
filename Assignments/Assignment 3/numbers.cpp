#include <iostream>
#include <string>
using namespace std;

//function prototypes
string intToString(int);
void printIntStrings(int, int, int);
string addWordsToString(int);
string ones(int);
string teens(int);
string tens(int);
string hundreds(int);
string thousands(int);

//global variable used to set max and min values of numbers
const unsigned int MIN_VALUE = 0;
const unsigned int MAX_VALUE = 99'999;

/*int main() //only used for testing purposes, comment out afterwards
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
}*/

//intToString definition
string intToString(int number)
{
    string err = "error"; //error message
    string numberWord = "";

    if (number > MIN_VALUE && number <= MAX_VALUE) //test if number is valid (in max and min bounds)
    {
        numberWord += addWordsToString(number);
    }
    else if (number == 0) //test if number == 0, then exception
    {
        numberWord = "zero";
    }
    else //error message if number is out of bounds
    {
        cerr << err;
    }
    return numberWord;
}

//printIntStrings definition
void printIntStrings(int start, int end, int interval)
{
    if (end > start) //ascending order
    {
        for (int count = start; count <= end; count += interval)
        {
            cout << intToString(count) << '\n';
        }
    }
    else if (start > end) //descending order
    {
        for (int count = start; count >= end; count -= interval)
        {
            cout << intToString(count) << '\n';
        }
    }
    else //if start = end
    {
        cout << intToString(start) << '\n';
    }
}

string addWordsToString(int num) //function that adds all number cases to a single string
{
    string numberWord = "";

    numberWord += thousands(num);
    numberWord += hundreds(num);
    numberWord += tens(num);
    numberWord += teens(num);

    return numberWord;
}

string ones(int num) //returns strings for ones
{
    string word = "";
    int range = num / 10; //set range so we are only looking at the ones digits of the number

    if (range % 10 != 1) //checks if the ones number is related to teens (if 21 - twenty one, or 11 - eleven)
    {
        switch (num % 10) //switch ignore case 0 as that is an exception handled in the intToString function
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
    int range = num / 10; //sets range for teens

    if (range % 10 == 1) //if range % 10 == 1 then we do the switch function, because if it is greater or less than that we call the tens funciton
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
    int range = num / 10; //range used to count digits of tens

    switch (range % 10) //swtich from tens = 2 to tens = 9 (not including tens = 1 as the teens funciton handles those numbers; also not including tens = 0 as we ignore that in writing) 
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
    
    if (range % 10 >= 2 && num % 10 != 0) //adds a dash if there is a ones number afterwards that is not teens
    {
        word += "-";
    }

    word += ones(num); //call ones function
    return word;
}

string hundreds(int num)
{
    string word = "";
    int range = num / 100; //range used to count digits of hundreds

    if (range % 10 != 0) //checks if hundreds is not 0
    {
        word += ones(range % 10); //calls ones function to determine how many hundreds ("two" hundred or "three" hundred...)
        word += " hundred";

        if (num % 100 != 0) //adds "and" if numbers below hundreds are not all zero (one hunred "and" one, opposed to one hundred "")
        {
            word += " and ";
        }
    }
    return word;
}

string thousands(int num)
{
    string word = "";
    int range = num / 1000; //range used to count digits of tousands
    int rangeForComma = num / 100; //range used in the if statement below that determines whether a commma is appropriate at the number

    if (range > 0) //checks if thousands is not 0
    {
        if (range >= 20)
        {
            word += tens(range); //calls tens function to determine how many thousands ("twenty" thousand or "thirty" thousand...)
        }
        else if (range >= 10 && range < 20)
        {
            word += teens(range); //calls teens function to determine how many thousands ("twelve" thousand or "thirteen" thousand...)
        }
        else
        {
            word += ones(range % 10); //calls ones function to determine how many thousands ("two" thousand or "three" thousand...)
        }
        word += " thousand";

        if (rangeForComma % 10 != 0) //used to determine if a comma is necessary for this number
        {
            word += ", ";
        }
        else if (num % 100 != 0) //adds "and" if numbers below hundreds are not all zero (one hunred "and" one, opposed to one hundred "")
        {
            word += " and ";
        }
    }
    return word;
}