/*
 Kimberlee Johnson
 CS 110B Programming Fundamentals: C++
 09/28/20
 Professor Dave Harden
 a4_1.cpp
 
 This program asks a user to enter numbers that represent cards.
 The number of cards entered is determined by a global constant.
 The program reads each number entered into an array.
 The program also initializes a counter array, zero at each value.
 The counter represents card values. Because card values are 2-9, counter[0] represents 2.
 The passes both arrays to a function that populates the counter based by looping through hand.
 Once the counter array is populated, the program passes it to a function that runs a series of boolean functions to determine the user's poker hand.
 The function runs those boolean functions, and prints an output accordingly.
 */

#include <iostream>
using namespace std;

const int NUM_CARDS = 5;
const int POSSIBLE_CARDS = 8;

void getCards(int hand[]);
void countCards(int counter[], const int hand[]);
void checkCards(int counter[]);

bool loop(const int counter[], int target);

bool containsFourOfaKind(const int counter[]);
bool containsFullHouse(const int counter[]);
bool containsPair(const int counter[]);
bool containsThreeOfaKind(const int counter[]);
bool containsStraight(const int counter[]);
bool containsTwoPair(const int counter[]);


int main ()
{
    int hand[NUM_CARDS];
    int counter[POSSIBLE_CARDS] = {0, 0, 0, 0, 0, 0, 0, 0};
    
    getCards(hand);
    countCards(counter, hand);
    checkCards(counter);
}






// Asks the user to enter numeric cards, and reads those card values into an array
void getCards(int hand[])
{
    cout << "Enter " << NUM_CARDS << " numeric cards, no face cards. Use 2 - 9." << endl;
    for (int index = 0; index < NUM_CARDS; index++) {
        cout << "Card " << index + 1 << ": ";
        cin >> hand[index];
    }
}






// Populates a counter array with the number of times each possible card exists in a user's hand
void countCards(int counter[], const int hand[])
{
    for (int index = 0; index < NUM_CARDS; index++) {
        counter[hand[index] - 2]++;
    }
}






// Calls boolean functions that determine what kind of poker hand has been dealt
void checkCards(int counter[])
{
    if (containsFourOfaKind(counter)) {
        cout << "Four of a kind!" << endl;
    } else if (containsFullHouse(counter)) {
        cout << "Full House!" << endl;
    } else if (containsStraight(counter)) {
        cout << "Straight!" << endl;
    } else if (containsThreeOfaKind(counter)){
        cout << "Three of a kind!" << endl;
    } else if (containsTwoPair(counter)){
        cout << "Two Pair!" << endl;
    } else if (containsPair(counter)){
        cout << "Pair!" << endl;
    } else {
        cout << "High Card!" << endl;
    }
}







// Returns true if a card is in the hand 4 times
bool  containsFourOfaKind(const int counter[])
{
    return loop(counter, 4);
}






// Returns true if a hand contains a full house (a pair and three of a kind)
bool containsFullHouse(const int counter[])
{
    if (containsPair(counter) && containsThreeOfaKind(counter)) {
        return true;
    }
    return false;
}






// Returns true if a hand contains a pair
bool containsPair(const int counter[])
{
    return loop(counter, 2);
}






// Returns true if a hand contains three of a kind
bool containsThreeOfaKind(const int counter[])
{
    return loop(counter, 3);
}






// Returns true if a hand contains five consecutive cards
bool containsStraight(const int counter[])
{
    for (int i = 0; i < POSSIBLE_CARDS; i++) {
        if ((counter[i] == 1)) {
            for (int z = 1; z < NUM_CARDS; z++) {
                if (counter[i + z] != 1) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}






// Returns true if a hand contains two distinct pairs
bool containsTwoPair(const int counter[])
{
    int pairCount = 0;
    for (int i = 0; i < POSSIBLE_CARDS; i++) {
        if (counter[i] == 2) {
            pairCount++;
            if (pairCount == 2) {
                return true;
            }
        }
    }
    return false;
}






bool loop(const int counter[], int target)
{
    for (int i = 0; i < POSSIBLE_CARDS; i++)
    {
        if(counter[i] == target) {
            return true;
        }
    }
    return false;
}
