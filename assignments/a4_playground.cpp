/*
 Kimberlee Johnson
 CS 110B Programming Fundamentals: C++
 09/28/20
 Professor Dave Harden
 a4_1.cpp
 
 This program...
 */

#include <iostream>
#include <cmath> // for abs
using namespace std;

const int ARRAY_SIZE = 5;

// Function returns true if there are no negative numbers, and false if there is a negative
bool noNegatives(const int array[], int size);
// Function replaces any negative values in an array with absolutes
void absoluteValues(int array[], int size);
// Prints the current state of an array
void printArray(int arrray[], int size);
// Counts the number of times the char 'e' shows up in an array
int eCount(const char array[], int size);
// Counts the number of times a specified character is in an array
int charCount(const char array[], int size, char targetChar);
// Returns true if passed in array of ints is in ascending order
bool isSorted(const int array[], int size);
// Returns true if there are two adjacent elements in the array with equal values
bool equalNeighbors(const char array[], int size);

int main ()
{
    int array[ARRAY_SIZE] = {-1, 8, 3, 4, 2};
    char charArray[ARRAY_SIZE] = {'e', 'f', 'g', 'a', 'b'};
    
    cout << "The array at the start is: " << endl;
    printArray(array, ARRAY_SIZE);
    
    if(noNegatives(array, ARRAY_SIZE)) {
        cout << "No negatives!" << endl;
    } else if (!noNegatives(array, ARRAY_SIZE)) {
        cout << "There's a negative here." << endl;
    }
    
    absoluteValues(array, ARRAY_SIZE);
    
    cout << "Now the array is: " << endl;
    printArray(array, ARRAY_SIZE);
    
    cout << "There are " << eCount(charArray, ARRAY_SIZE) << "e's." << endl;
    cout << "There are " << charCount(charArray, ARRAY_SIZE, 'a') << "a's." << endl;
    
    if (equalNeighbors(charArray, ARRAY_SIZE)) {
        cout << "There are some equal neighbors here." << endl;
    } else if (!equalNeighbors(charArray, ARRAY_SIZE)) {
        cout << "There are not equal neighbors!" << endl;
    }
    
    if (isSorted(array, ARRAY_SIZE)) {
        cout << "The array is sorted in ascending order." << endl;
    } else if (!isSorted(array, ARRAY_SIZE)) {
        cout << "The array is not sorted!" << endl;
    }
}

bool noNegatives(const int array[], int size)
{
    for (int index = 0; index < size; index++) {
        if (array[index] < 0) {
            return false;
        }
    }
    return true;
}

void absoluteValues(int array[], int size)
{
    for (int index = 0; index < size; index++) {
        if (array[index] < 0) {
            array[index] = abs(array[index]);
        }
    }
}

void printArray(int array[], int size)
{
    for (int index = 0; index < size; index ++) {
        cout << array[index] << endl;
    }
    cout << endl;
}

int eCount(const char array[], int size)
{
    int eCount = 0;
    for (int index = 0; index < size; index ++) {
        if (array[index] == 'e') {
            eCount++;
        }
    }
    return eCount;
}

int charCount(const char array[], int size, char targetChar)
{
    int charCount = 0;
    for (int index = 0; index < size; index ++) {
        if (array[index] == targetChar) {
            charCount++;
        }
    }
    return charCount;
}

bool isSorted(const int array[], int size)
{
    for (int index = 0; index < size; index++) {
        if (array[index] > array[index + 1]) {
            return false;
        }
    }
    return true;
}

bool equalNeighbors(const char array[], int size)
{
    for (int index = 0; index < size; index++) {
        if (array[index] == array[index + 1]) {
            return true;
        }
    }
    return false;
}
