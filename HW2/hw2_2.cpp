/*
*Title: hw2_2.cpp
*Abstract: Program checks if two strings are anagram or not.
*Author: Abigail Cuevas
*ID: 9999
*Date: 09/06/2021
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    //variables declared
    string word1 ="";//to store the first word
    string word2 ="";//to store the second word
    int counter = 0;//to check if characters match

    cin>> word1 >> word2; //user input

    //check if the size of the words inputted match
    if(word1.size() == word2.size()){

        //lowercase all the letters in the string just in case
        transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
        transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

        //sort the letters in the word
        //reference: https://www.studymite.com/cpp/examples/sort-characters-of-string-in-alphabetical-order-using-cpp/
        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        //for loop to check if the letters match or not
        for(int i = 0; i < word1.size(); i++){
            if(word1[i] != word2[i]){//increments if the letters don't match
                counter++;
            }
        }
        //check if the counter incremented, its not an anagram
        if(counter > 0){
            cout<< "NO ANAGRAM" << endl;

        }else{//if not it is an anagram
            cout << "ANAGRAM" << endl;
        }

    }else{//if size of the two words don't match, its not an anagram
        cout<< "NO ANAGRAM" << endl;
    }

    return 0;//exit
}