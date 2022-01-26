/*
*Title: hw8_1.cpp
*Abstract:Program reads a number of input values & the values themselves.
*Program will put all negative numbers in front of all positive using the first
* and second approach we learned in class.
numbers
*Author: Abigail Cuevas
*ID: 9999
*Date: 10/25/2021
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //variable declared
    int input1;
    int input2;
    vector<int> allInput;
    vector<int> secondInput;
    //user input
    cin>>input1;

    for(int y = 0; y < input1; y++){
        //user input, add to vector one is for first approach
        //other is for second approach
        cin >> input2;
        allInput.push_back(input2);
        secondInput.push_back(input2);
    }

    //first approach
    //j points to the last number in the vector
    //i points to the first number in the vector
    int j = allInput.size() - 1;
    int i = 0;
    //while loop to put negative numbers in front
    while (j > i){
            //check to see if last number is a negative number
            //check to see if first number is a positive number
        if(allInput[j] < 0 && allInput[i] >= 0){
                //swap the number at index i to index j, and j to i
                int first = allInput.at(i);
                int second = allInput.at(j);
                allInput[i] = second;
                allInput[j] = first;
        }
        //check the index at i and see if it negative number
        if(allInput[i] < 0){
                //to the next index at starter
                i++;
        }
        //check the index at i in vector, check to see if its a positive number
        if(allInput[j] >= 0){
            //to the next index backwards in ending
                j--;
            }
    }

    //second approach
    //i points to first number
    //j points to second number
    int sizes = secondInput.size();
    int firstI = 0;
    int secondJ = 0;
    for(firstI, secondJ; firstI < sizes; firstI++){
        //check if j2 equals end
        if(secondJ == sizes){
            break;
        }
        //check if j point to a positive number if positive increment, do not increment i
        //if j points to negative swap and increment both
        if(secondInput[secondJ] < 0  ){
            //swap, j point to a negative number
            int first = secondInput.at(firstI);
            int second = secondInput.at(secondJ);
            secondInput[firstI] = second;
            secondInput[secondJ] = first;
            secondJ++;
        }else{
            //pointed to positive number
            //only increment j
            secondJ++;
            firstI--;
        }
    }
    //print first approach
    for(int x = 0; x < allInput.size(); x++){
        cout << allInput[x] << " ";
    }
    cout << endl;
    //print second approach
    for(int x = 0; x < secondInput.size(); x++){
        cout << secondInput[x] << " ";
    }

    return 0;//exit
}
