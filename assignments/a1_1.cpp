/*
 Kimberlee Johnson
 CS 110B Programming Fundamentals: C++
 09/07/20
 Dave Harden
 a1_1.cpp
 
 This program asks a user to input a date in a particular format. We are assuming the user enters that information in the exact format we need. The program receives the user input, reading int data types for each number, and a char separator value for the slashes in between. Once the program receives the values and assigns them to variables, it checks to see if the month multiplied by the day equals the year. If that is true, the program prints a statement to let the user know the date is magic. If not true, the program lets the user know the date is not magic.
 */

#include <iostream>
using namespace std;

int main()
{
    int month;
    int day;
    int year;
    char separator;
    
    cout << "Hello! Please enter a date in the format 1-digit-month/1-digit-day/2-digit year, e.g. 9/7/20: " << endl;
    cin >> month >> separator >> day >> separator >> year;
    
    if ((month * day) == year) {
        cout << "The date is magic!" << endl;
    } else {
        cout << "The date is not magic." << endl;
    }
}

/*
 Hello! Please enter a date in the format 1-digit-month/1-digit-day/2-digit year, e.g. 9/7/20:
 6/10/60
 The date is magic!
 
 Hello! Please enter a date in the format 1-digit-month/1-digit-day/2-digit year, e.g. 9/7/20:
 9/7/20
 The date is not magic.
 */
