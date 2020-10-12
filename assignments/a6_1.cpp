/*
 Kimberlee Johnson
 CS 110B Programming Fundamentals: C++
 09/28/20
 Professor Dave Harden
 a6_1.cpp
 
 This file (program) tests my knowledge of strings and C-strings.
 I wrote several functions.
 The outputs from executing those functions test whether I met assignment instructions.
 
 
 */
#include <iostream>
#include <cctype>
using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);

int main()
{
    char str1[] = "Hello, World!";
    char str2[] = "flower";
    char str3[] = "jolene";
    char str4[] = "abba";
    char str5[] = "hannah";
    char str6[] = "HaNNaH";
    char str7[] = "abc cba";
    char str8[] = "abc cb";
    char str9[] = "Dolly Parton";
    char str10[] = "dolly parton";
    char str11[] = "DOLLY PARTON";
    char str12[] = "dolLy Parton!";
    char str13[] = "!!!!2doorsdownDolly!!!";
    char str14[] = "d!!!!!!!!!!p!!!!!!!";
    char str15[] = "";
    char str16[] = "evenchar";
    char str17[] = "oddchar";
    
    
    cout << lastIndexOf(str1, 'l') << endl;
    cout << lastIndexOf(str1, 'L') << endl;
    cout << lastIndexOf(str15, 'A') << endl;

    reverse(str2);
    cout << str2 << endl;
    reverse(str16);
    cout << str16 << endl;
    reverse(str17);
    cout << str17 << endl;
    
    cout << replace(str3, 'e', 'a') << endl;
    cout << replace(str3, 'b', 'a') << endl;
    cout << replace(str16, 'r', 'z') << endl;
    cout << replace(str17, 'r', 'z') << endl;
    
    cout << isPalindrome(str4) << endl;
    cout << isPalindrome(str5) << endl;
    cout << isPalindrome(str6) << endl;
    cout << isPalindrome(str7) << endl;
    cout << isPalindrome(str8) << endl;
    cout << isPalindrome(str16) << endl;
    cout << isPalindrome(str17) << endl;
    
    
    toupper(str9);
    cout << str9 << endl;
    toupper(str10);
    cout << str10 << endl;
    toupper(str11);
    cout << str11 << endl;
    toupper(str16);
    cout << str16 << endl;
    toupper(str17);
    cout << str17 << endl;
    
    cout << numLetters(str12) << endl;
    cout << numLetters(str13) << endl;
    cout << numLetters(str14) << endl;
    cout << numLetters(str16) << endl;
    cout << numLetters(str17) << endl;
}






// Searches a string for a case sensitive target char, and returns the lastIndex where it can be seen.
// Loops through the string as long as the char in the loop is not the escape sequence.
// If the char in the loop is the target character, it assigned the lastIndex variable to that current index.
// If the target char is never found, the lastIndex variable remains -1.
int lastIndexOf(const char* inString, char target)
{
    int lastIndex = -1;
    int index = 0;
    
    while (*inString != '\0') {
        if (*inString == target) {
            lastIndex = index;
        }
        index++;
        inString++;
    }
    return lastIndex;
}






// Reverses a passed-in string in place (without making a copy of the string).
// Iterates through the string by getting the length of the string - 1.
// Starts at the first and last chars in the string.
// Stores the first char in a temp variable.
// Assigns the first char's position to hold the char at the last point in the loop.
// Replaces the char at the last point in the loop with the temp variable.
// Continues iterating by decreasing the last char position and increasing the first char position.
void reverse(char* inString)
{
    int size = strlen(inString) - 1;
       
    for (int i = 0; i < size; i++, size--) {
        char temp = inString[i];
        inString[i] = inString[size];
        inString[size] = temp;
    }
}






// Searches for a target char in a string, and replaces the target with a new char.
// Iterates through the string until the escape character is found (end of string).
// If the char at the loop point is the target, the function replaces it, and increments the replacement counter.
// If the char is not found, the function returns 0.
int replace(char* inString, char target, char replacementChar)
{
    int replacements = 0;
    while (*inString != '\0') {
        if (*inString == target) {
            replacements++;
        }
        inString++;
    }
    return replacements;
}






// Checks to see whether a C-string is a palindrome (spelled the same as its reverse).
// Gets the length of the string - 1.
// Iterates over the string and compares the first char to the last char (length - 1).
// If those two chars are the same, the loop continues to compare the second and penultimate char, and so on.
// If the string is a palindrome, the function returns true.
// If not, the function returns false.
bool isPalindrome(const char* inString)
{
    int size = strlen(inString) - 1;
    for (int i = 0; i < size; i++, size--) {
        if ((tolower(inString[i])) != (tolower(inString[size]))) {
            return false;
        }
    }
    return true;
}






// Converts the C-string parameter to all uppercase.
// Iterates through the string as long as the char in the loop is not the escape sequence.
// Calls the toupper helper function to point the char at that point in the loop to the uppercase version of the char.
void toupper(char* inString)
{
    while (*inString != '\0') {
        if (*inString != toupper(*inString)) {
            *inString = toupper(*inString);
        }
        inString++;
    }
}






// Returns the number of letters in the C-string.
// Iterates through the loop until the escape sequence is hit.
// If the char at that point in the loop is not a letter, the loop continues.
// If the char *is* a char, it increments the letterCount variable.
// Returns the letterCount variable.
int numLetters(const char* inString)
{
    int letterCount = 0;
    while (*inString != '\0') {
        if (isalpha(*inString)) {
            letterCount++;
        }
        inString++;
    }
    return letterCount;
}






/*
 10
 -1
 -1
 rewolf
 rahcneve
 rahcddo
 2
 0
 1
 1
 1
 1
 1
 1
 0
 0
 0
 DOLLY PARTON
 DOLLY PARTON
 DOLLY PARTON
 RAHCNEVE
 RAHCDDO
 11
 14
 2
 8
 7
 Program ended with exit code: 0
 */
