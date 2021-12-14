/*
*Title: hw1_2.cpp
*Abstract: Program reads inputted number from user and displays the number(s) that occurs the most frequently.
*Author: Abigail Cuevas
*ID: 9999
*Date: 08/28/2021
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //variable declared
    vector<int> allNumbers;//to get all the numbers user inputted
    vector<int> tempNum;//to store the numbers that appear the most
    vector<int> highestNum;//to store the frequency of each number
    int x;//to store the users choice
    int number;//to get the users inputted numbers
    int currentNum = 1;//to calculate
    int finalNum = 0;//the final high number

    cin>>x;//gets users amount of number they will input
    if(x <= 0){
        return 0;
    }
    for(int i = 0; i < x; i++){//for loop to get users inputted numbers
        cin>>number;
        allNumbers.push_back(number);//store number in vector
    }

    sort(allNumbers.begin(),allNumbers.end(),greater<int>());//sort the numbers in descending order

    for(int i = 0; i < allNumbers.size()-1; i++){ // for loop to get all the numbers occurrence
        if(allNumbers[i] == allNumbers[i+1]){//check if the numbers are equal to one another
            currentNum++;//increments
        }else{//stores the numbers occurrence in a vector
            highestNum.push_back(currentNum);
            currentNum = 1;//put it back to 1
        }
    }
    
    highestNum.push_back(currentNum);//to store the most frequent incase it doesn't go to the else statement
    sort(highestNum.begin(), highestNum.end(), greater<int>());//sort to get the highest occurrence
    finalNum = highestNum[0];//highest occurrence will be store on this variable
    
    cout << "Frequency:" << finalNum << endl;//prints of the frequency
    currentNum = 1;//put it back to 1

    for(int i = 0; i < allNumbers.size()-1; i++){//for loop to get the numbers that match the highest occurrence
        if(allNumbers[i] == allNumbers[i+1]){
            currentNum++;//get the occurrence of each number
            if(currentNum  == finalNum){//if it match store them in a vector
                tempNum.push_back(allNumbers[i]);
            }
        }else{
            currentNum = 1;
        }
    }
    //print out the number(s) that occurred the most
    cout << "Number:";
    if(tempNum.size() > 0 ){ //if the number occurred more than once
        for(int i = 0; i < tempNum.size(); i++){
            cout << tempNum[i] << " ";
        }
    }else{//if the number only occurred once
        for(int i = 0; i < allNumbers.size(); i++){
            cout << allNumbers[i] << " ";
        }
    }
    cout << endl;

    return 0;//exit
}