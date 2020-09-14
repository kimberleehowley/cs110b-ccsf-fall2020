/*
 Kimberlee Johnson
 CS 110B Programming Fundamentals: C++
 09/14/20
 Dave Harden
 a2_1.cpp
 
 This program mirrors the card game blackjack. It deals a user two random numbers, the "cards", keeping track of the sum of the cards in an accumulator variable. It then asks the user if they would like another card. If they would like another card, the program deals another random number, and adds the number to the accumulator. If the player would not like another card, the program asks the user if they would like to play again. If at any point the accumulator sums to 21, the program prints "Congratulations!" If the sum exceeds 21, the program prints "Bust." and asks the user if they'd like to play again. If the user ever says they do not want to play again, the program exits.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    unsigned seed;
    int firstCard, secondCard, newCard, total;
    char drawCard, playAgain;
    
    do {
        seed = time(0);
        srand(seed);
    
        firstCard = rand() % 10 + 1;
        secondCard = rand() % 10 + 1;
        total = firstCard + secondCard;
        
        cout << "First cards: " << firstCard << ", " << secondCard << endl;
        cout << "Total: " << total << endl;
        cout << "Do you want another card? (y/n): " << endl;
        cin >> drawCard;
        
        while (toupper(drawCard) == 'Y') {
            newCard = rand() % 10 + 1;
            total += newCard;
            cout << "Card: " << newCard << endl;
            cout << "Total: " << total << endl;
            if (total < 21) {
                cout << "Do you want another card? (y/n): ";
                cin >> drawCard;
            } else if (total >= 21) {
                drawCard = 'n';
            }
        }
        if (total == 21) {
            cout << "Congratulations!" << endl;
        } else if (total > 21) {
            cout << "Bust." << endl;
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (toupper(playAgain) == 'Y');
}

/*
 First cards: 5, 2
 Total: 7
 Do you want another card? (y/n):
 y
 Card: 1
 Total: 8
 Do you want another card? (y/n): y
 Card: 6
 Total: 14
 Do you want another card? (y/n): y
 Card: 4
 Total: 18
 Do you want another card? (y/n): y
 Card: 1
 Total: 19
 Do you want another card? (y/n): y
 Card: 4
 Total: 23
 Bust.
 Do you want to play again? (y/n): y
 First cards: 6, 5
 Total: 11
 Do you want another card? (y/n):
 y
 Card: 10
 Total: 21
 Congratulations!
 Do you want to play again? (y/n): n
 Program ended with exit code: 0
 */
