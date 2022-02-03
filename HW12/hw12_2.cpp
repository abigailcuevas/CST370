/*
* Title: hw12_2.cpp 
* Abstract: Program implements the floyd algorithm to display all pairs of shortest paths.
* Author: Abigail Cuevas
* ID: 9999
* Date: 12/6/2021
* Reference: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/
*/
#include <iostream>
#include <vector>

using namespace std;
//global variables
int infinity = 1111111;
vector<vector<int> > allNum;
//functions used 
void floydA(int size);
bool min(int first, int second);

int main() {
  //variables declared
  int num = 0;
  int inserted = 0;
  //user input
  cin>> num;
  //adjust vector size
  allNum.resize(num);
  //user inputs all numbers
  //numbers store in vector
  for(int i = 0; i < num; i++){
    vector<int> temp;
    for(int j = 0; j < num; j++){
      cin >> inserted;
      //check whether user inputted -1(infinity)
      if(inserted == -1){
        inserted = infinity;
      }
      temp.push_back(inserted);
    }
    allNum[i] = temp;
  }
  //implements algorithm
  floydA(num);
  //prints out the shortest path
  for(int i = 0; i < num; i++){
    for(int j = 0; j < num; j++){
      if(allNum[i][j] == infinity){
        cout << "-1 ";
      }else{
        cout << allNum[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;//exit
} 
//psuedocode of floyd algorithm
void floydA(int size){
  //variable declared
  int i = 0;
  while(i < size){
    int x = 0;
    while(x < size){
      int j = 0;
      while(j < size){
        //variables declared
        int firstNum = allNum[x][i] + allNum[i][j];
        int secondNum = allNum[x][j];
        //checks to find the shortest path
        bool result = min(firstNum, secondNum);

        if(result){
            allNum[x][j] = firstNum;
        }
        j++;
      }
      x++;
    }
    i++;
  } 
}
//function that return true or false whether the first numbers is less than the second number
bool min(int first, int second){
  if(first < second){
    return true;
  }
  return false;
}
