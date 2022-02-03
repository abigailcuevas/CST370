/*
* Title: hw11_2.cpp
* Abstract: Program solves the Coin Row problem.
* Author: Abigail Cuevas
* ID: 9999
* Date: 11/30/2021
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//fucntion to find the maximum number of two numbers passed
int max(int num1, int num2);

int main() {
  //variables declared
  int number = 0;
  int cNum = 0;
  //user input
  cin>> number;
  //store the coins
  int coins[number];
  
  for(int i = 0; i < number; i++)
  {//user input
    cin>> cNum;
    coins[i] = cNum;
  }
  //check the number of coins
  if(number <= 0){
    return 0;//exit
  }else if(number == 1){ 
    cout << "Best set:1";
    cout << "\nMax value:" << coins[0] << endl;
  }else if(number == 2){
      int set = 1;//find max of the two number
      if(coins[0] < coins[1]){
        set = 2;
      }
      //output
      cout << "Best set:" << set;
      cout << "\nMax value:" << max(coins[0], coins[1]) << endl;
    }else{//if number is greater than 2
      //variables declared
      int temp[number + 1];
      vector<vector<int> > output(number);
      //store numbers to start off
      for(int i = 0; i < 2; i++){
        temp[i] = 0;
        if(i == 1){
          temp[i] = coins[0];
        }
        output[i].push_back(i + 1);
      }
      //check each number in the coins
      for(int i = 2; i <= number; i++){
        //variable declared
        int c = (i-2);
        int d = (i-1);
        int a = coins[d] + temp[c];
        int b = temp[d];
        //store max in temporary array
        temp[i] = max(a,b);
        //check which has a the highest number and store them to 
        //the vector to keep track of the set
        if(temp[i] == a){
          output[d] = output[i-3];
          output[d].push_back(i);
        }else{
          output[d] = output[c];
        }
      }
      //varaible declared
      int find = number -1;
      int i = output[find].size();
      //print out set
      cout << "Best set:";
      for(i = 0 ; i <= output[find].size() -1; i++)
      {
        cout << output[find][i] << " ";
      }
      //printn out max value
      cout << "\nMax value:" << temp[number] << endl;
    }

    return 0;
}
//function that returns the maximum out of the two numbers
int max(int a, int b) {
  return (a<b)?b:a;
}

