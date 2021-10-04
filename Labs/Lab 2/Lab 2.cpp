#include <iostream>
using namespace std;

double greatestScore(double player1, double player2, double player3);

int main()
{
    //initializes char variable to ask user to continye or not
    char next = ' ';

    //initializes string variables for player names
    string playerName1;
    string playerName2;
    string playerName3;

    //initializes double variable to hold player's score
    double playerScore1 = 0.0;
    double playerScore2 = 0.0;
    double playerScore3 = 0.0;

    //while loop will continue looping if player does not set next to 'n' or 'N' at the end of the loop
    while (next != 'n' && next != 'N')
    {
        //prompt user to input player1's name
        cout << "Enter name of player 1: ";
        cin >> playerName1;

        //prompt user to input player's score
        cout << "\tEnter " << playerName1 << "'s score: ";
        cin >> playerScore1;


        //prompt user to input player2's name
        cout << "\nEnter name of player 2: ";
        cin >> playerName2;

        //prompt user to input player2's score
        cout << "\tEnter " << playerName2 << "'s score: ";
        cin >> playerScore2;


        //prompt user to input player3's name
        cout << "\nEnter name of player 3: ";
        cin >> playerName3;

        //prompt user to input player3's score
        cout << "\tEnter " << playerName3 << "'s score: ";
        cin >> playerScore3;
        cout << '\n';


        //outputs winner and their score, or tie and their scores
        if (playerScore1 == greatestScore(playerScore1, playerScore2, playerScore3))
        {
            cout << playerName1 << ' ';
        }

        if (playerScore2 == greatestScore(playerScore1, playerScore2, playerScore3))
        {
            cout << playerName2 << ' ';
        }
        
        if (playerScore3 == greatestScore(playerScore1, playerScore2, playerScore3))
        {
            cout << playerName3 << ' ';
        }

        cout << "is/are" << " the winner(s)!";


        cout << "\n\nDo you want to continue? Enter n to stop, any other key to continue: ";
		cin >> next;
        cout << "\n\n";
    }
}

double greatestScore(double player1, double player2, double player3)
{
    double greatest = 0.0;

    if ((player1 >= player2) && (player1 >= player3))
    {
        greatest = player1;
    }
    else if ((player2 >= player1) && (player2 >= player3))
    {
        greatest = player2;
    }
    else
    {
        greatest = player3;
    }

    return greatest;
}