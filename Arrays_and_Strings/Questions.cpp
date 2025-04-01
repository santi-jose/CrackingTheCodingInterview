// Questions from the Arrays and Strings section of the textbook
// Cracking the coding interview

#include <cstdlib>
#include <string>
#include <iostream>
#include <map>

using namespace std;

// 1: Is Unique
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

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
        // cout << "current char: " << cur << endl; // print debug

        int i = cur - 'a'; // calculate index of current char
        // cout << "current char index: " << i << endl;
        if (char_bank[i] > 0)
        { // if the value of current char in the wordbank is greatar than 0
            return false;
        }
        else
        {
            char_bank[i]++; // increment character count in word bank
            // cout << "char_bank value: " << char_bank[i] << endl;
        }
    }

    // we iterated through string without identifying duplicates
    return true;
}

// 2. Check Permutation
// Given two strings, write a method to decide if one is a permutation 
// of the other

// Parameters: 
// two input strings

// Returns: 
// boolean determining if the two strings are permutations of each other

// Examples:
//  "cat", "tac" 
//  1: c = 1
//  2: a = 1
//  3: t = 1
//  1: t = 1
//  2: a = 1
//  3: c = 1
//  -> check for equality of teh values of characters from strings
// return true, the strings are permutations of each other

// Pseudocode:
//  map to store characters in strings = char_map
//  key = character, value = character count
//  for characters in str1
//      if new char found, add to char_map
//      else increment char count in char_map
//  for characters in str2
//      if new char found, return false -> new char means no permutation
//      else decrement char count in char map
//          if char count in char map < 0, return false
//  for char in char_map, if char_count > 0 return false
//  return true if we pass all checks
bool checkPermutation(string str1, string str2){
    // map to store characters recorded in str1 and str2
    // char denotes char in string
    // int denotes count of appearances of char key
    map <char, int> char_bank;

    // iterate through characters in str1
    for(char& cur: str1){
        // if we don't have the current character in the char_bank
        if(char_bank.find(cur) == char_bank.end()){
            char_bank[cur] = 1; // add char to bank and set count to 1
        }else{ // the char exists in the bank
            char_bank[cur]++; // increment the count of current char
        }
    }

    // iterate through characters in str2
    for(char& cur: str2){
        // if we don't have the current character in the char_bank
        if(char_bank.find(cur) == char_bank.end()){
            return false;
        }else{ // the char exists in the bank
            char_bank[cur]--; // decrement the count of current char
            if(char_bank[cur] < 0){ // if the coutn is less than 0
                return false; // we have more cur chars in str2
                            // than we did in str1
            }
        }
    }

    // iterate through map to see if any counts are greater than 0
    for(auto& it: char_bank){
        if(it.second > 0){
            return false;
        }
    }
    // the map is all 0, therefore the strings are permutations of each other
    return true;
}


int main()
{
    // test isUnique() implementation
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
        cout << "Test Failed. test2 string is not unique, isUnique(test2)" << endl;
    }
    else
    {
        cout << "Test Passed. test2 string is not unique. isUnique(test2)" << endl;
    }

    // test checkPermutation() implementation
    string test3 = "taco";
    string test4 = "cota";

    string test5 = "brain";
    string test6 = "inrab";

    // checkPermutation == true
    if(checkPermutation(test3, test4)){
        cout << "Test Passed. test3 string is a permutation of test4 string." << endl;
    }else{
        cout << "Test Failed. test3 string is a permutation of test4 string." << endl;
    }
    cout << "test3: " << test3 << endl;
    cout << "test4: " << test4 << endl;

    if(checkPermutation(test5, test6)){
        cout << "Test Passed. test5 string is a permutation of test6 string." << endl;
    }else{
        cout << "Test Failed. test5 string is a permutation of test6 string." << endl;
    }

    cout << "test5: " << test5 << endl;
    cout << "test6: " << test6 << endl;

    // checkPermutation == false
    if(checkPermutation(test3, test5)){
        cout << "Test Failed. test3 string is not a permutation of test5 string." << endl;
    }else{
        cout << "Test Passed. test3 tring is not a permutation of test5 string." << endl;
    }
    
    cout << "test3: " << test3 << endl;
    cout << "test5: " << test5 << endl;


    return 0;
}