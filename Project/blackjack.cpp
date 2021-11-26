#include <iostream>
using namespace std;

//global variables
const int CARDS_IN_DECK = 52;

//function prototypes
void getNewDeck(CardArray);

//Card struct
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

//CardArray struct
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

void getNewDeck(CardArray & deck)
{
    deck.cardsSize = CARDS_IN_DECK;
    deck.usedCards = CARDS_IN_DECK;

    deck.cards = new 
    //continue Assign the Card pointer the address of an array of 52 cards in dynamic memory (using new).
}