/*
*Title: hw1_1.cpp
*Abstract: Program reads input numbers from user and displays the closest distance between two numbers among all input numbers.
*Author: Abigail Cuevas
*ID: 9999
*Date: 08/27/2021
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    vector<int> userInput;//where all the number will be stored
    int temporary;//the number user input
    int interval;//how many numbers user will input
    int min_Distance;//to find the distance between the number
    
    cin >>interval;//user inputs how many numbers they will do
    if(interval <= 0){
        return 0;
    }
    for(int i = 0; i < interval; i++){//for loop
        cin >> temporary;//user enters random numbers
        userInput.push_back(temporary);//numbers get stored into the vector
        temporary = 0;//sets it back to 0
    }

    sort(userInput.begin(), userInput.end());//sort the number least to greatest
    int freq_min = userInput[userInput.size()-1];//frequency will have the highest number stored
    
    for(int i = 0; i < userInput.size() -1; i++)//for loop to find the number with the closest distance
    {
        min_Distance = abs(userInput[i] - userInput[i+1]);//calculates the distance between the two numbers
        if(freq_min > min_Distance){//the number with the closest distance will be stored into the variable
            freq_min = min_Distance;
        }
    }
    //outputs the min distance
    cout << endl << "Min Distance:" << freq_min<< endl;
    min_Distance = 0;
    for(int i = 0; i < userInput.size() - 1; i++)//for loop to print the pairs
    {
        min_Distance = abs(userInput[i] - userInput[i+1]);//get the distance between the two numbers
        if(min_Distance == freq_min){//if it equals the min distance it'll output the pairs
            cout << "Pair:" << userInput[i] << " " << userInput[i+1] << endl;
        }
    }
    return 0;//exit
}