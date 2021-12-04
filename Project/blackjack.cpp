//Program made by: Daniel Tolsky
//SFU ID: 301452597
/*
Advice is given on these conditions (and their combinations):
Advice is only given if the game did not end nor did neither sides go bust.
When player's score is less than the dealer's score.
When player's score is greater than the dealer's score.
When player's score is less than or equals to 17.
When player's score is greater than or equals to 17.
When player does not contain aces in their hand.
When player contains aces in their hand.
When player contains does not large value cards (such as jack, king, queen) in their hand.
When player contains large value cards (such as jack, king, queen) in their hand.
When not all the dealer's cards are known.
When all the dealer's cards are known.
When there is no chance of bust (score is less than or equal to 11).
When there is chance of bust (score is greater than or equal to 11).
*/
//I hereby confirm that this is my own work and I have not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

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
int gameLoop(CardArray &, CardArray &, CardArray &, char);
void deal(CardArray &, CardArray &);
int score(const CardArray &);
char decisionHitOrStand();
bool isBust(int, int);
bool isTwentyOne(int, int);
bool containsAce(const CardArray &);
void aceToOne (CardArray &);
void cardsPrint(const CardArray &);
int result(int, int);
void winnerDisplay(int);
void playGames(CardArray &);
void advice(const CardArray &, const CardArray &, bool);
bool hasLargeCard(const CardArray &);
char decisionToPlay();

int main()
{
    CardArray deck; //create deck
    getNewDeck(deck); //initialize deck
    printDeck(deck); //display deck
    cout << "\nshuffled\n";
    shuffleDeck(deck); //shuffle deck (randomize)
    printDeck(deck); //display deck
    playGames(deck); //play mutiple games
    
    delete[] deck.cards; //delete deck CardArray to free memory
    system("pause");
}

void getNewDeck(CardArray & deck) //function creates a new deck of cards
{
    int cardNum = 0;

    const int cardsInDeck = 52; //52 cards in a deck
    deck.cardsSize = cardsInDeck;
    deck.usedCards = cardsInDeck;

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
    deck.usedCards = deck.cardsSize; //reset used cards back to the array size since all of the cards are present

    delete[] temp.cards;
}

int blackjack(CardArray & deck) //main game function
{
    CardArray playerHand; //array of cards in player's hands
    CardArray dealerHand; //array of cards in dealer's hands

    char choice = ' '; //to hold char value to either hit or stand
    const int blackjackWin = 21; //get 21 to win
    int pscore = 0; //these variables are briefly used to store the score of the layers to allow deletion of dynamic memory without loosing the store
    int dscore = 0;
    const int stand = 17; //dealer will stand if their score is 17 or more

    const int maxHandSize = 12; //maximum hands possible to play
    playerHand.cardsSize = maxHandSize; //sets the amount of cards that player can hold to 12 (from instructions)
    playerHand.usedCards = 0; //sets player's used cards to 0
    dealerHand.cardsSize = maxHandSize; //sets the amount of cards that dealer can hold to 12 (from instructions)
    dealerHand.usedCards = 0; //sets dealer's used cards to 0

    playerHand.cards = new Card[playerHand.cardsSize]; //create array of cards for playerHands
    dealerHand.cards = new Card[dealerHand.cardsSize]; //create array of cards for dealerHands

    if (deck.usedCards >= playerHand.usedCards || deck.usedCards >= dealerHand.usedCards) //replace deck if amount of used cards gets too close to the maximum an
    {
        shuffleDeck(deck);
    }

    cout << "\nDeal first card\n---------------\n"; //first deal
    deal(deck, playerHand);
    deal(deck, dealerHand);

    cout << "+Player+: " << playerHand.cards[playerHand.usedCards - 1].description;
    cout << "\n*Dealer*: " << dealerHand.cards[dealerHand.usedCards - 1].description;

    cout << "\n\nDeal second card\n----------------\n"; //second deal
    deal(deck, playerHand);
    deal(deck, dealerHand);

    cout << "+Player+: " << playerHand.cards[playerHand.usedCards - 2].description << " " << playerHand.cards[playerHand.usedCards - 1].description;
    cout << "\n*Dealer*: " << dealerHand.cards[dealerHand.usedCards - 2].description << " ??"; //keep dealer's second hand hidden

    if (isBust(score(playerHand), 0) && containsAce(playerHand)) //use 0 in order to not include score(dealerHand) argument, only checking if player is bust
    {
        aceToOne(playerHand);
    }

    if (isBust(score(dealerHand), 0) && containsAce(dealerHand) && score(dealerHand)) //use 0 in order to not include score(playerHand) argument, only checking if dealer is bust
    {
        aceToOne(dealerHand);
    }

    if (isBust(score(playerHand), score(dealerHand)) || isTwentyOne(score(playerHand), score(dealerHand))) //ends game if anyone goes bust or hits blackjack after second deal
    {
        cout << "\n\n+Player+:";
        cardsPrint(playerHand);
        cout << "\n*Dealer*:";
        cardsPrint(dealerHand);

        pscore = score(playerHand);
        dscore = score(dealerHand);
        delete[] playerHand.cards;
        delete[] dealerHand.cards;
        return result(pscore, dscore);
    }
    cout << "\n\nDealing to player\n----------------";

    return gameLoop(deck, playerHand, dealerHand, choice);
}

int gameLoop(CardArray & deck, CardArray & playerHand, CardArray & dealerHand, char choice) //function loops the game based on player choice
{
    int pscore = 0; //these variables are briefly used to store the score of the layers to allow deletion of dynamic memory without loosing the store
    int dscore = 0;
    const int stand = 17; //dealer will stand if their score is 17 or more
    bool unknownScore = true; //variable shows when dealer's score is unknown

    advice(playerHand, dealerHand, unknownScore);
    choice = decisionHitOrStand();
    unknownScore = false;

    while (choice == 'h' && !isBust(score(playerHand), score(dealerHand)) && !isTwentyOne(score(playerHand), score(dealerHand))) //contiue loop if no one is bust, at blackjact, or player chose to stand
    {
        deal(deck, playerHand);

        if (isBust(score(playerHand), 0) && containsAce(playerHand)) //use 0 in order to not include score(dealerHand) argument, only checking if player is bust
        {
            aceToOne(playerHand);
        }

        cout << "+Player+:";
        cardsPrint(playerHand);

        if (score(dealerHand) < stand && !isBust(score(playerHand), score(dealerHand)) && !isTwentyOne(score(playerHand), score(dealerHand)) && score(dealerHand) <= score(playerHand)) //if dealer's score is less than 17 they will hit
        {
            deal(deck, dealerHand);

            if (isBust(score(dealerHand), 0) && containsAce(dealerHand) && score(dealerHand) < stand) //use 0 in order to not include score(playerHand) argument, only checking if dealer is bust
            {
                aceToOne(dealerHand);
            }

            cout << "\n*Dealer*:";
            cardsPrint(dealerHand);
        }

        if (isBust(score(playerHand), score(dealerHand)) || isTwentyOne(score(playerHand), score(dealerHand)))
        {
            cout << "\n\n+Player+:";
            cardsPrint(playerHand);
            cout << "\n*Dealer*:";
            cardsPrint(dealerHand);

            pscore = score(playerHand);
            dscore = score(dealerHand);
            delete[] playerHand.cards;
            delete[] dealerHand.cards;
            return result(pscore, dscore);
        }
        advice(playerHand, dealerHand, unknownScore);
        choice = decisionHitOrStand();

        if (choice != 'h' && score(dealerHand) < stand && score(dealerHand) <= score(playerHand)) //if statement to only print newline below once (for formatting)
        {
            while (choice != 'h' && score(dealerHand) < stand && score(dealerHand) <= score(playerHand)) //if dealer's score is less than 17 they will keep hitting
            {
                deal(deck, dealerHand);

                if (isBust(score(dealerHand), 0) && containsAce(dealerHand) && score(dealerHand) < stand) //use 0 in order to not include score(playerHand) argument, only checking if dealer is bust
                {
                    aceToOne(dealerHand);
                }

                cout << "\n*Dealer*:";
                cardsPrint(dealerHand);
            }
            cout << '\n';
        }
    }

    if (choice != 'h' && score(dealerHand) < stand && score(dealerHand) <= score(playerHand)) //if statement to only print newline below once (for formatting)
    {
        while (choice != 'h' && score(dealerHand) < stand && score(dealerHand) <= score(playerHand)) //if dealer's score is less than 17 they will keep hitting
        {
            deal(deck, dealerHand);

            if (isBust(score(dealerHand), 0) && containsAce(dealerHand) && score(dealerHand) < stand) //use 0 in order to not include score(playerHand) argument, only checking if dealer is bust
            {
                aceToOne(dealerHand);
            }

            cout << "\n*Dealer*:";
            cardsPrint(dealerHand);
        }
        cout << '\n';
    }
    
    cout << "\n+Player+:";
    cardsPrint(playerHand);
    cout << "\n*Dealer*:";
    cardsPrint(dealerHand);

    pscore = score(playerHand);
    dscore = score(dealerHand);
    delete[] playerHand.cards;
    delete[] dealerHand.cards;
    return result(pscore, dscore);
}

void deal(CardArray & deck, CardArray & user) //function deals cards to either player or dealer
{
    user.cards[user.usedCards] = deck.cards[deck.usedCards - 1];

    ++user.usedCards;
    --deck.usedCards;
}

int score(const CardArray & hand) //function returns score of a hand
{
    int score = 0;

    for (int count = 0; count < hand.cardsSize; ++count)
    {
        score += hand.cards[count].value;
    }
    return score;
}

char decisionHitOrStand() //function handles input for the letter entered (handles input errors aswell)
{
    char input = ' ';
	cout << "\nEnter h to hit or s to stand: ";
	cin >> input;

	while (input != 'h' && input != 's') 
	{
		cerr << "\nERROR: Please enter h to hit or s to stand: ";
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

int result(int player, int dealer) //function returns result of a game
{
    const int blackjackWin = 21; //get 21 to win
    if (player > blackjackWin)
    {
        return -1;
    }
    else if (dealer > blackjackWin)
    {
        return 1;
    }
    else if (player > dealer)
    {
        return 1;
    }
    else if (dealer > player)
    {
        return -1;
    }
    else if (player == dealer)
    {
        return 0;
    }
    else
    {
        cerr << "\n\nERROR: Logic error in result()";
        return 0;
    }
}

bool isBust(int player, int dealer) //function returns true if player's or dealer'ss core went above 21 otherwise returns false
{
    const int blackjackWin = 21; //get 21 to win

    if (player > blackjackWin || dealer > blackjackWin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isTwentyOne(int player, int dealer) //function returns true if etiher player or dealer got blackjack (21) as a score
{
    const int blackjackWin = 21; //get 21 to win

    if (player == blackjackWin || dealer == blackjackWin)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool containsAce(const CardArray & user) //function cheacks if hand contains an ace
{
    for (int count = 0; count < user.usedCards; ++count)
    {
        if (user.cards[count].rank == 1) //1 is the rank of aces
        {
            return true;
        }
    }
    return false;
}

void aceToOne (CardArray & user) //function converts ace to the value of 1
{
    int count = 0;
    const int blackjackWin = 21; //get 21 to win

    while (count < user.usedCards && score(user) > blackjackWin) //loop while not out of bounds and user's score is less than 21 (in case of multiple aces)
    {
        if (user.cards[count].value == 11) //1 is the rank of aces
        {
            user.cards[count].value = 1;
        }
        ++count;
    }
}

void cardsPrint(const CardArray & user) //function prints cards in a hand (either player's hand or the dealers')
{
    for (int count = 0; count < user.usedCards; ++count) //displays all cards in hand
    {
        cout << ' ' << user.cards[count].description;
    }
}

void winnerDisplay(int result) //function displays winner
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
    else
    {
        cerr << "\n\nERROR: Unexpected argument in winnerDisplay()";
    }
    cout << endl; //for formatting
}

void playGames(CardArray & deck) //game loop for part 3
{
    int wins = 0;
    int losses = 0;
    int draws = 0;
    int games = 0;
    int result = 0;
    char choice = ' ';

    cout << "\n\n\nWelcome to blackjack!\n#####################\n";
    choice = decisionToPlay();
    
    while (choice == 'p')
    {
        ++games;
        cout << '\n';

        result = blackjack(deck);
        winnerDisplay(result); //display winner

        cout << "\n\nDo you want to play another hand? ";
        choice = decisionToPlay();

        if (result == 1)
        {
            ++wins;
        }
        else if (result == 0)
        {
            ++draws;
        }
        else if (result == -1)
        {
            ++losses;
        }

        if (choice == 'q')
        {
            cout << "\n\nPost game summary:\nWins: " << wins << "\nLosses: " << losses << "\nDraws: " << draws << "\nGames: " << games << '\n';
        }
        shuffleDeck(deck); //shuffle deck (randomize)
    }
}

char decisionToPlay() //function asks player if they want to continue playing (or start playing)
{
    char input = ' ';
	cout << "\nEnter p to play or q to quit: ";
	cin >> input;

	while (input != 'p' && input != 'q') 
	{
		cerr << "\nERROR: Please enter p to play or q to quit: ";
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

void advice(const CardArray & playerDeck, const CardArray & dealerDeck, bool unknown) //function gives advice to player to hit or stand
{
    const int stand = 17; //stand if their score is 17 or greater
    const int minHit = 11; //always hit if score is below 11 (no sense to stand)

    cout << '\n';

    if (score(playerDeck) <= minHit)
    {
        cout << "You should definitely hit, your score is " << score(playerDeck) << " which is less than or euqal to 11, there is no chance of bust";
    }
    else if (score(playerDeck) < score(dealerDeck) && !isBust(score(playerDeck), score(dealerDeck)) && !isTwentyOne(score(playerDeck), score(dealerDeck)) && !unknown)
    {
        cout << "It is recommended that you hit because your score (" << score(playerDeck) << ") is lower than the dealers' (you WILL lose if you stand!)";
    }
    else if (score(playerDeck) == score(dealerDeck) && !isBust(score(playerDeck), score(dealerDeck)) && !isTwentyOne(score(playerDeck), score(dealerDeck)) && !unknown)
    {
        cout << "You are currently have the same score (" << score(playerDeck) << ") as the dealer";

        if (score(playerDeck) < stand && hasLargeCard(playerDeck))
        {
            cout << ", htting could secure your position because your score (" << score(playerDeck) << ") is still below 17\nand you have a large card which reduces chance of bust on next deal";
        }
        else
        {
            cout << " it is recommended to stand\nas hitting would be highly risking a bust";
        }
    }
    else if (score(playerDeck) > score(dealerDeck) && !isBust(score(playerDeck), score(dealerDeck)) && !isTwentyOne(score(playerDeck), score(dealerDeck)) && !unknown)
    {
        cout << "You are currently have a greater score than the dealer";

        if (containsAce(playerDeck) && score(playerDeck) < stand)
        {
            cout << ", consider hitting as you still have an ace for backup and your score (" << score(playerDeck) << ") is less than 17";
        }
        else if (score(playerDeck) >= stand)
        {
            cout << " you should stand as your score (" << score(playerDeck) << ") is already greater than or equals to 17 and is greater than the dealer's score";
        }
    }
    else if (unknown)
    {
        if (score(playerDeck) < stand && hasLargeCard(playerDeck))
        {
            cout << "Hitting could secure your position because your score (" << score(playerDeck) << ") is still below 17\nand you have a large card which reduces chance of bust on next deal";
        }
        else if (containsAce(playerDeck) && score(playerDeck) < stand)
        {
            cout << "Consider hitting as you still have an ace for backup and your score (" << score(playerDeck) << ") is less than 17";
        }
        else if (score(playerDeck) < stand)
        {
            cout << "Hitting could help you to get he lead, although the chances are risky as you do not have\nan ace or a large card";
        }
        else if (score(playerDeck) >= stand)
        {
            cout << "You should stand as your score (" << score(playerDeck) << ") is already greater than or equals to 17, hitting would be risky";
        }
        else
        {
            cout << "It is recommended to stand as hitting would be highly risking a bust";
        }
    }

    cout << '\n';
}

bool hasLargeCard(const CardArray & user) //function return whether a hand contains a large card (10, jack, queen, king)
{
    const int largeCardRank = 11; //not 1 because aces can be reverted to a 1 in case of bust
    for (int count = 0; count < user.usedCards; ++count) //displays all cards in hand
    {
        if (user.cards[count].rank >= largeCardRank)
        {
            return true;
        }
    }
    return false;
}