#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//function definitions to display mayan numbers
void printMayanNumber(int);
int powOfTwenty(int);
void printOnes(int);
int numberOfOnes(int);
void printFives(int);
int numberOfFives(int);
void printZero(int);
void printSeparator();

//function definitions for the mayan number game
void mayaNumberGame();
int readNumber();
char readLetter();
int randomizerForNumbers(int, int);
char randomizerForABC();

const int MAYAN_NUMBER_BASE = 20; //vigesimal
const int MIN_INPUT_NUMBER = 10; //if value entered is below this, the game will end
const int MIN_CORRECT_NUMBER = 4; //MIN_CORRECT_NUMBER = 4 due to assignment requirements

int main() //main function that only calls printMayanNumber
{
    cout << "Mayan representation of the number 5212 as per assignment requirements:\n";
    printMayanNumber(5212); //print the maya representation of the number 5,212 as per assignment requirements
    cout << "\n\n"; //for formatting to make it look uncluttered

    mayaNumberGame();
    cout << '\n'; //for formatting to make it look uncluttered

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

void mayaNumberGame()
{
    int number = 0; //number user inputs
    char letter = ' '; //letter user inputs as answer (a, b, or c)
    char correctLetter = ' '; //stores the correct answer (a, b, or c)
    int correctNumber = 0; //stores the correct number
    int randomMax = 0; //maximum number that could be generated
    int randomMin = 0; //minimum number that could be generated
    int firstRand = 0; // these are used to check if the first and second randomly generated mayan numbers are the same
    int secondRand = 0; // |

    cout << "###MAYAN NUMBER GAME###\n=======================\n\n"
    << "Enter a number greater than 10. The game will choose a number less than or equal to what you entered.\n"
    << "You will then have to match the decimal number to it's Mayan equivalent."
    << "\nEnter a positive integer value greater or equal than 10 (enter a value less than 10 to exit): ";
    number = readNumber(); //calls read number function for input handling
    srand(time(NULL)); //random generator uses time as seed

    while (number >= MIN_INPUT_NUMBER) //game loop
    {
        correctLetter = randomizerForABC(); //uses randomizerForABC() to obtain the random letter where the correct answer is
        correctNumber = randomizerForNumbers(number, MIN_CORRECT_NUMBER); //finds a random value between the value entered by the user and 4 (for assignment requirements)

        randomMax = correctNumber * 1.5; //upper bounds of possible generated value
        randomMin = correctNumber * 0.5; //lower bounds of possible generated value
        firstRand = randomizerForNumbers(randomMax, randomMin); //stores the first random number
        secondRand = randomizerForNumbers(randomMax, randomMin); //stores the second random number

        while (firstRand == secondRand || firstRand == correctNumber || secondRand == correctNumber) //resets random numbers if any of the displayed numbers are the same
        {
            firstRand = randomizerForNumbers(randomMax, randomMin);
            secondRand = randomizerForNumbers(randomMax, randomMin);
        }

        cout << "Which of these Mayan numbers is equal to " << correctNumber << '?';

        cout << "\n\na.\n";
        if (correctLetter == 'a') //displays mayan number for a (could be correct or incorrect value)
        {
            printMayanNumber(correctNumber);
        }
        else
        {
            printMayanNumber(firstRand);
            firstRand = 0;
        }

        cout << "\nb.\n";
        if (correctLetter == 'b') //displays mayan number for b (could be correct or incorrect value)
        {
            printMayanNumber(correctNumber);
        }
        else
        {
            if (firstRand != 0)
            {
                printMayanNumber(firstRand);
            }
            else
            {
                printMayanNumber(secondRand);
                secondRand = 0;
            }
        }

        cout << "\nc.\n";
        if (correctLetter == 'c') //displays mayan number for c (could be correct or incorrect value)
        {
            printMayanNumber(correctNumber);
        }
        else
        {
            if(secondRand != 0)
            {
                printMayanNumber(secondRand);
            }
            else
            {
                printMayanNumber(firstRand);
            }
        }

        letter = readLetter(); //stores the answer letter entered by the user

        if (letter == correctLetter) //self explanatory
        {
            cout << "\n\nCORRECT! The Mayan representation of " << correctNumber << " is:\n";
            printMayanNumber(correctNumber);
        }
        else
        {
            cout << "\n\nINCORRECT! The Mayan representation of " << correctNumber << " is:\n";
            printMayanNumber(correctNumber);
        }

        cout << "\n\nEnter another number, or less than 10 to exit: ";
        number = readNumber(); //to continue game loop the game asks the user to enter another number value
        cout << '\n';
    }
}

int readNumber() //handles input for the number entered (handles input errors aswell)
{
    int input = 0;
	cin >> input;

	while (cin.fail()) 
	{
		cerr << "ERROR: Please enter an integer value: " << endl;
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cin >> input;
	}
	cin.ignore(10000, '\n');
	return input;
}

char readLetter() //handles input for the letter entered (handles input errors aswell)
{
    char input = ' ';
	cout << "\n\nPlease enter either 'a', 'b', or 'c': ";
	cin >> input;

	while (input != 'a' && input != 'b' && input != 'c') 
	{
		cerr << "ERROR: Please enter either 'a', 'b', or 'c': " << endl;
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
		cin >> input;
	}
	cin.ignore(10000, '\n');
	return input;
}

int randomizerForNumbers(int max, int min) //returns a random integer from minimum(min) to mnaximum(max)
{
    int random = rand() % (max - min) + min;
    return random;
}

char randomizerForABC() //returns a random char (a, b, or c) which is the correct choice 
{
    char choice = ' ';
    int max = 3; //max = 3 because 3 choices (a, b, c)
    int min = 1; //min = 1 so we have 3 choices not 4

    int random = (rand() % max) + min;

    if (random == 1)
    {
        choice = 'a';
    }
    else if (random == 2)
    {
        choice = 'b';
    }
    else
    {
        choice = 'c';
    }
    return choice;
}