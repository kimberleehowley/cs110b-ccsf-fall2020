/*
 Kimberlee Johnson
 CS110B Programming Fundamentals C++
 09/21/20
 Dave Harden
 a3_1.cpp
 
 This program plays a guessing game with a human user. First, it asks the human if it would like to play. If the human says no, the program exits. If the human says yes, the human will think of a number between 1 and 100, inclusive [0]. Then, the program "guesses" the number that the human is thinking of by finding the midpoint between two numbers, starting with the midpoint between 1 and 100. The program then prompts the human user for input to indicate whether the guess is lower 'l', higher 'h', or correct 'c' than the number in question. Based on the human's response, the program calculates a new midpoint "guess", and updates the user with its new guess and the prompt again, until 'c' is entered by the user. After a human user enters 'c', the program asks the human if they would like to play again. If the human says yes, the program repeats: asking the user to think of a number and sharing its hypothesis. If the human says no, the program exits.
 [0] To ensure inclusivity, we set the HIGH global constant to 101.
 */

#include <iostream>
using namespace std;

int LOW = 1;
int HIGH = 101;

void playOneGame();
void getUserResponseToGuess(int guess, char& result);
int getMidpoint(int low, int high);

int main()
{
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}





// Initializes int guess at 50, and the low and high int variables to the global constants representing the respective range limits
// Initializes a char result to track a user's input
// Prompts the user to think of a number between 1 and 100
// For at least one iteration, and then while the user has not indicated the guess is correct
// Exexcutes a helper function that alerts the user of the current guess (starting at int 50), and prompts the user to input feedback
// Based on user feedback, adjusts either the low or high value, and then updates the guess value to the result of executing a helper function
void playOneGame()
{
    char result;
    int guess = 50, low = LOW, high = HIGH;
    
    cout << "Think of a number between 1 and 100. " << endl;
    
    do {
        getUserResponseToGuess(guess, result);
        if (result == 'l') {
            high = guess;
            guess = getMidpoint(low, guess);
        }
        else if (result == 'h') {
            low = guess;
            guess = getMidpoint(guess, high);
        }
    } while (result != 'c');
}






// Receives an int guess and char result
// The char result is passed by reference
// Alerts the user of the current guess, and prompts the user to input feedback
// Sends that feedback via char& result back to the playOneGame() function
void getUserResponseToGuess(int guess, char& result)
{
    // Tells user the guess.
    cout << "My guess is " << guess << ". " << "Enter \'l\' if your number is lower,\'h\' if it is higher, \'c\' if it is correct: ";
    cin >> result;
}






// Receives two ints that represent the upper and lower bound of a range of numbers
// Adds the two values, then divides them by 2 to get the midpoint (lowest value automatically calculated)
// Returns the midpoint value
int getMidpoint(int low, int high)
{
    int midpoint = (low + high) / 2;
    return midpoint;
}






/*
 Ready to play (y/n)? y
 Think of a number between 1 and 100.
 My guess is 50. Enter 'l' if your number is lower,'h' if it is higher, 'c' if it is correct: l
 My guess is 25. Enter 'l' if your number is lower,'h' if it is higher, 'c' if it is correct: h
 My guess is 37. Enter 'l' if your number is lower,'h' if it is higher, 'c' if it is correct: c
 Great! Do you want to play again (y/n)? n
 Program ended with exit code: 0
 */

