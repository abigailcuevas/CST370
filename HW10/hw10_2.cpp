/*
* Title: hw10_2.cpp
* Abstract: Program conducts heap operation.
* Author: Abigail Cuevas
* ID: 9999
* Date: 11/17/2021
* Reference: https://www.geeksforgeeks.org/heap-sort/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//function
bool checkHeap(vector<int> allNumber);
void display(vector<int> allNumber);
void heapify(vector<int> &allNumbers);
void checkCycle(vector<int> &allNumbers, int loop, int s, int left, int right);

int main()
{
    //variable declared
    int first = 0;
    int numbers = 0;
    int second = 0;
    string command = "";
    int otherCommand = 0;
    //user input
    cin>> first;

    vector<int> allNumber (first+1);
    //user inputs number for heap
    for(int i = 1; i < first+1; i++){
        cin >> numbers;
        allNumber[i] = numbers;
    }
    //function to check whether the given numbers is a heap
    bool result = checkHeap(allNumber);
    //if not a heap, function rearanges to make heap
    if(!result){
        cout << "This is NOT a heap." << endl;
        heapify(allNumber);
    }else{
        cout << "This is a heap." << endl;
    }
    //user input 
    cin >> second;
    //user inputs commands
    for(int i = 0; i < second; i++){
        cin>> command;
        //insert command, user insert 
        if(command == "insert"){
            cin>> otherCommand;
            allNumber.push_back(otherCommand);
            heapify(allNumber);
        //delete max command
        }else if(command == "deleteMax"){
            allNumber[1] = allNumber.back();
            allNumber.pop_back();
            heapify(allNumber);
        }else{
            //output commands
            //diplays max
            if(command == "displayMax"){
                cout << allNumber[1];
            //diplays heap
            }if (command == "display"){
                display(allNumber);
            }cout << endl;
        }
    }
    //exit
    return 0;
}

//to find left child = i * 2
//to find right child = (i*2) + 1
//function check whether the given vector is a heap
bool checkHeap(vector<int> allNumber){
    int size = allNumber.size();
    int i = size/2;
    //while loop check left child and right child
    while(i > 0){
        //check left or right is less than size
        if((i*2) < size || ((i*2)+1) < size){
            //check to make sure child isn't greater than parent
             if(allNumber[i*2] > allNumber[i] || allNumber[(i*2)+1] > allNumber[i]){
                 return false;
            }
        }
        i --;
    }
    //return true if its a heap, otherwise returns false
    return true;
}
//fucntion to display the heap
void display(vector<int> allNumber){
    for(int i = 1; i < allNumber.size(); i++)
        cout << allNumber[i] << " ";
}
//to find left child = i * 2
//to find right child = (i*2) + 1
//function to rearage the given vector into a heap
void heapify(vector<int> &allNumber){
    //variable that will be used
    int size = allNumber.size();
    int loop = size/2;
    int left = 0, right = 0;
    //as long as checking heap returns false, check rearanging
    while(!checkHeap(allNumber)){
        checkCycle(allNumber, loop, size, left, right);
    }
    return;
}
//to find left child = i * 2
//to find right child = (i*2) + 1
//functino that rearranges the heap
void checkCycle(vector<int> &allNumbers, int loop, int size, int left, int right){
    //variable used
    bool checker;
    //go throught the vector of numbers
    while(loop > 0) {
        //variable used
        checker = false;
        left = loop * 2;
        right = (loop * 2) + 1;
        //get everything in order
        while(left < size && !checker){
            //check left side isn't greater than the size
            if(size > left){
                //check to see if right schild is greater than left
                //move it
                if(allNumbers[right] > allNumbers[left]){
                    left = right;
                //check if left child is less than parent
                }if(allNumbers[left] <= allNumbers[loop]){
                    checker = true;
                }else{
                    //swap them 
                    int first = allNumbers[left];
                    int second = allNumbers[loop];
                    allNumbers[loop] = first;
                    allNumbers[left] = second;
                }
            }//if
        }//while
        loop--;
    }//while
    return;
}


