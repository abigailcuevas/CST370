/*
* Title: hw10_1.cpp
* Abstract: Program conducts the radix sort.
* Author: Abigail Cuevas
* ID: 9999
* Date: 11/18/2021
* Reference: https://www.geeksforgeeks.org/radix-sort/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//global variables
int maximum = 0;
const int ten = 10;

//functions used 
void radixSort(vector<int> &numbers);
void print(vector<int> &numbers, int size, int loop);
void loops(vector<int> &output, vector<int> count, vector<int> numbers, int size, int loop);

int main()
{
    //variables declared
    int first = 0;
    int others = 0;
    vector<int> inserted;
    //user input
    cin>> first;
    //user inputs numbers
    for(int i = 0; i < first; i++){
        cin>> others;
        inserted.push_back(others);
    }
    //copy vector to temporary vector to sort and find max number
    vector<int> temp = inserted;
    sort(temp.begin(), temp.end(), greater<int>());
    //max number stored
    maximum = temp[0];
    //function that implements radixSort
    radixSort(inserted);

    return 0;//edit
}

void radixSort(vector<int> &numbers){
    //varaible used
    int size = numbers.size();
    //for loop to to through numbers
    for(int i = 1; (maximum/i) > 0; i *= ten){
        //prints out radix sort
        print(numbers, size, i);
    }
}
//function used to print
void print(vector<int> &numbers, int size, int loop){
    //variables used
    vector<int> output(size);
    vector<int> count(ten, 0);
    //function to go through numbers
    loops(output, count,numbers, size, loop);
    //prints out each line
    for (int i = 0; i < size; i++){
        numbers[i] = output[i];
        cout << numbers[i] << " ";
    }
    cout << endl;
}
//function loop for radix sort
void loops(vector<int> &output, vector<int> count, vector<int> numbers, int size, int loop){
     //loop to get the occurences
     for (int i = 0; i < size; i++){
        count[(numbers[i] / loop) % ten]++;
     }
     //loop for the position of count
    for (int i = 1; i < ten; i++){
        count[i] += count[i - 1];
    }
    //loop to get the output of each line
    for (int i = size - 1; i >= 0; i--) {
        output[count[(numbers[i] / loop) % ten] - 1] = numbers[i];
        count[(numbers[i] / loop) % 10]--;
    }
}

