/*
*Title: hw6_1.cpp
*Abstract: Program reads a positive number from the user and displays the reverse of the number.
*Author: Abigail Cuevas
*ID: 9999
*Date: 10/03/2021
*Reference: https://www.educative.io/edpresso/how-to-convert-an-int-to-a-string-in-cpp
*Reference: https://www.code4example.com/pseudocode/pseudocode-to-reverse-a-number/
*/

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int reversed(int n );

int main()
{
    //variable declared
    int userInput = 0;
    //user input
    cin>> userInput;
    //print the number in reverse
    cout << reversed(userInput);

    return 0;//exit
}
//function that return the reverse of the number that is passed recursively
int reversed(int n){
    //variable declared
    string lengthOfNum = "";
    //convert the int to a string to find the length
    stringstream ss;
    ss << n;
    ss >> lengthOfNum;
    //use the length of string to find the number of digits in the number passed
    int count = lengthOfNum.length();
    //decrement the counter by 1
    count--;
    //statement to find the inverse
    //if n is 0 returns
    if(n == 0){
        return 0;
    }else{
        //returns the last number that is multiplies by 10^count and adds it to the function
        return ((n%10 * pow(10, count)) + reversed(n/10));
    }
}


