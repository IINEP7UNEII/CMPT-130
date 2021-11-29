#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

//global variables
const int CARDS_IN_DECK = 52;
const int NUM_OF_SUITS = 4;

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

//function prototypes
void getNewDeck(CardArray &);
void printDeck(const CardArray &);
void shuffleDeck(CardArray &);
int blackjack(CardArray &);
void deal(CardArray &, CardArray &);
void winnerDisplay(int);

int main()
{
    CardArray deck; //create deck
    getNewDeck(deck); //initialize deck
    printDeck(deck); //display deck
    shuffleDeck(deck); //shuffle duck (randomize)
    printDeck(deck); //display deck

    winnerDisplay(blackjack(deck)); //play blackjack and display winner
    
    delete[] deck.cards;
    system("pause");
}

void getNewDeck(CardArray & deck) //function creates a new deck of cards
{
    int cardNum = 0;

    deck.cardsSize = CARDS_IN_DECK;
    deck.usedCards = CARDS_IN_DECK;

    deck.cards = new Card[deck.cardsSize]; //assigns address of an array of 52 cards in dynamic memory to deck.cards pointer
    
    for (int count = 0; count < deck.cardsSize; ++count)
    {
        cardNum = count + 1;

        deck.cards[count].rank = (count % 13) + 1; //sets rank of card

        switch (deck.cards[count].rank) //switch that assigns descriptions based on the rank of the card
        {
            case 1:
            {
                deck.cards[count].description = "A";
                break;
            }
            case 11:
            {
                deck.cards[count].description = "J";
                break;
            }
            case 12:
            {
                deck.cards[count].description = "Q";
                break;
            }
            case 13:
            {
                deck.cards[count].description = "K";
                break;
            }
            default:
            {
                deck.cards[count].description += to_string(deck.cards[count].rank);
                break;
            }
        }

        if (count < 13)
        {
            deck.cards[count].suit = "spades";
            deck.cards[count].description += "S";
        }
        else if (count >= 13 && count < 26)
        {
            deck.cards[count].suit = "hearts";
            deck.cards[count].description += "H";
        }
        else if (count >= 26 && count < 39)
        {
            deck.cards[count].suit = "diamonds";
            deck.cards[count].description += "D";
        }
        else
        {
            deck.cards[count].suit = "clubs";
            deck.cards[count].description += "C";
        }
        
        if (deck.cards[count].rank == 1)
        {
            deck.cards[count].value = 11;
        }
        else if (deck.cards[count].rank > 10)
        {
            deck.cards[count].value = 10;
        }
        else
        {
            deck.cards[count].value = deck.cards[count].rank;
        }
    }
}

void printDeck(const CardArray & deck) //function prints deck of cards
{
    int cardNum = 0;

    for (int count = 0; count < deck.cardsSize; ++count)
    {
        cardNum = count + 1;
        cout << deck.cards[count].description << ' ';

        if ((cardNum % 13) == 0) //for formatting
        {
            cout << '\n';
        }
    }
}

void shuffleDeck(CardArray & deck) //function shuffles deck of cards
{
    int randIndex = 0;
    srand(time(NULL));

    CardArray temp;
    temp.cards = new Card[deck.cardsSize];

    while (deck.usedCards > 1)
    {
        --deck.usedCards;
        randIndex = rand() % deck.usedCards;

        temp.cards[deck.usedCards] = deck.cards[deck.usedCards];
        deck.cards[deck.usedCards] = deck.cards[randIndex];
        deck.cards[randIndex] = temp.cards[deck.usedCards];
    }

    cout << "\nshuffled\n";
    deck.usedCards = deck.cardsSize; //reset used cards back to the array size since all of the cards are present

    delete[] temp.cards;
}

int blackjack(CardArray & deck)
{
    CardArray playerHands; //array of cards in player's hands
    CardArray dealerHands; //array of cards in dealer's hands

    playerHands.cardsSize = deck.cardsSize; //sets the amount of cards that player can hold to 52 (from deck.cardSize)
    playerHands.usedCards = 0; //sets player's used cards to 0
    dealerHands.cardsSize = deck.cardsSize; //sets the amount of cards that dealer can hold to 52 (from deck.cardSize)
    dealerHands.usedCards = 0; //sets dealer's used cards to 0

    playerHands.cards = new Card[playerHands.cardsSize]; //create array of cards for playerHands
    dealerHands.cards = new Card[dealerHands.cardsSize]; //create array of cards for dealerHands

    int playerScore = 0; //player's score
    int dealerScore = 0; //dealer's score

    cout << "\n\n\nWelcome to blackjack!\n#####################\n\nDeal first card\n---------------\n"; //first deal
    deal(deck, playerHands);
    deal(deck, dealerHands);

    cout << "+Player+: ";
    cout << "*Dealer*: ";

    cout << "\n\nDeal first card\n---------------\n"; //second deal
    deal(deck, playerHands);
    deal(deck, dealerHands);

    cout << "+Player+: ";
    cout << "*Dealer*: ";

    //continue step 3 on Implementation Notes

    delete[] playerHands.cards;
    delete[] dealerHands.cards;
    return 0;
}

void deal(CardArray & deck, CardArray & user) //deals cards to either player or dealer
{
    user.cards[user.usedCards] = deck.cards[deck.usedCards - 1];

    ++user.usedCards;
    --deck.usedCards;
}

void winnerDisplay(int result)
{
    if (result == 1)
    {
        cout << "\n\nCongrats! Player has won!";
    }
    else if (result == 0)
    {
        cout << "\n\nDraw! Good game.";
    }
    else if (result == -1)
    {
        cout << "\n\nDealer wins, better luck next time.";
    }
}