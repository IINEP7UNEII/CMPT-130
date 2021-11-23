#include <iostream>
using namespace std;

struct Card
{
    string suit;
    string description;
    int rank;
    int value;

    Card()
    {
        suit = "";
        description = "";
        rank = 0;
        value = 0;
    }
};

struct CardArray
{
    Card* cards;
    int cardsSize;
    int usedCards;

    CardArray()
    {
        cards = nullptr;
        cardsSize = 0;
        usedCards = 0;
    }
};

int main()
{

    system("pause");
}