// Questions from the Arrays and Strings section of the textbook
// Cracking the coding interview

// 1: Is Unique
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// parameters: input string in
// is this specifically for lowercase alphabetical characters?
// does this include alphanumeric values?
// I will implement a solution using only lowercase alphabetical characters
// returns: boolean value true or false depending on if the string has a
// consists of all unique characters
// examples:
// in: abcdefg
// out: true
// in: aabbccddeeffgg
// out: false
// pseudocode:
//  word_bank = {0x26}
//  for every character in string
// subtract the int value of 'a' by the current char to receive index
// 'a' = 0, 'b' = 1 ,... , 'z' = 25
//      index = current_char - 'a'
//      if value @ word_bank[index] > 0
//          return false
//      else
//          increment value @ word_bank[index]
// if we escape the for loop without returning false
//  return true
bool isUnique(string in)
{
    int char_bank[26] = {0}; // initialize word_bank as array of ints size 26, w/ 0's

    for (char cur : in)
    {
        cout << "current char: " << cur << endl; // print debug

        int i = cur - 'a'; // calculate index of current char
        cout << "current char index: " << i << endl;
        if (char_bank[i] > 0)
        { // if the value of current char in the wordbank is greatar than 0
            return false;
        }
        else
        {
            char_bank[i]++; // increment character count in word bank
            cout << "char_bank value: " << char_bank[i] << endl;
        }
    }

    // we iterated through string without identifying duplicates
    return true;
}

int main()
{
    string test1 = "abcd";
    string test2 = "abcdd";

    if (isUnique(test1))
    {
        cout << "Test Passed. test1 string is unique, isUnique(test1)"  << endl;
    }
    else
    {
        cout << "Test Failed. test1 string is unique. isUnique(test1)"  << endl;
    }

    if (isUnique(test2))
    {
        cout << "Test Failed. test2 string is not unique, isUnique(test1)" << endl;
    }
    else
    {
        cout << "Test Passed. test2 string is not unique. isUnique(test1)" << endl;
    }

    return 1;
}