/*
*Title: hw2_3.cpp
*Abstract: Program checks if an input string is a palindrome or not.
*Date: 09/06/2021
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string word = ""; //user input
    int counter = 0; //counter to counter if letters don't match
    int divider = 0; //divides the string word into two
    int wordSize = 0; //

    cin >> word;//user input
    
    //reference: https://www.cplusplus.com/reference/cctype/tolower/
    //lowercase all the letters in the string to make sure all the letters match
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    divider = word.size()/2;//string size is divides by 2 to check each side
    wordSize = word.size() - 1;// strings length -1 to get the last letter

    //for loop to check whether the first letter and the last letter match. each time i increments to go to the next and so on....
    for(int i = 0; i < divider; i++){
        if(word[i] != word[wordSize - i]){//if current letter at i does not match the last letter - i
            counter++;//counter increments
        }
    }
    if(counter > 0){ //if the counter is greater than 0
        cout << "FALSE" << endl;//then there was no palindrome
    }else{//if the counter did not increment
        cout << "TRUE" << endl;//then there was a palindrome
    }

    return 0;//exits
}
