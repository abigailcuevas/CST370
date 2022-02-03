/*
* Title: hw12_1.cpp 
* Abstract: Program collect maximum number of coins on an n x m board 
* Author: Abigail Cuevas
* ID: 9999
* Date: 12/7/2021
* Reference: https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//functions used
void coins(vector<vector<int>> &a, vector<vector<int>> b, int num1, int num2);
int getVal(int l, int t);
void sub(int &t, int &l, int &num1, int &num2);
void add(int &n1, int &n2);

//global variables used
const int one = 1;
int maximum = 0; 
int l = 0;
int t = 0;

int main() {
  //variable declared
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;
  //user input
  cin >> num1 >> num2;

  vector<vector<int>> board(num1+1, vector<int> (num2+1, 0));
  vector<vector<int>>temp = board;
  //user inputs, and is store into vector
  for(int i = 1; i <= num1; i++){
    
    for(int j = 1; j <= num2; j++){
      cin>> num3;
      board[i][j] = num3;
    }
  }
  //function used 
  coins(board, temp, num1, num2);
  //to store the pairs
  vector<pair<int, int>> allNum;
  t = num1 - one;
  l = num2 - one;
  //get the maximum
  maximum = board[num1][num2];
  
  do{
    
      allNum.push_back(make_pair(num1, num2));
      
      if(num1 == 1 && num2 == 1){
       break;
      }
      //get top and left
      int checkTop = board[t][num2];
      int checkLeft = board[num1][l];

      //following backtracks and checks the following path
      //will pick the path from the left, not top
      if(t == 0 ){//done
       add(num1, t);
      }
      else if(l == 0){
       add(l, num2);
      }
      else if(checkTop <= checkLeft){
        add(num1, t);
      }else{
        add(l, num2);
      }

      sub(t, l, num1, num2);
  }while(true);

  //outputs the maximum coins the the path
  cout << "Max coins:" << maximum << endl;
  cout << "Path:";
  for(int i = allNum.size() -1; i >= 0; i--){
    if(i != allNum.size() - 1){
      cout << "->" ;
    }
    cout << "(" << allNum[i].first << "," << allNum[i].second << ")";
  }
  
  return 0;//exit
} 
//function get the vector and find the maximum
void coins(vector<vector<int>> &a, vector<vector<int>> b, int num1, int num2){
  //variables declared
  l = 0;
  t = 0;
  int i = 1;
  int counter;
  //while loop
  while(i <= num1){ 
    int j = 1;
    while(j <= num2){ 
      counter = 0;
      l = j - one;
      t = i - one;
      //get left and top section
      int leftSection = b[i][l];
      int topSection = b[t][j];

      //check
      counter = getVal(leftSection, topSection);
      counter++;
      //check where there is a coin
      if(a[i][j] == 1){
        b[i][j] = counter;
      }else{
        counter--;
        b[i][j] = counter;
      }
      j++;
    }
    i++;
  }
  //store to vector
  a = b;
}
//function takes in two values to find the max
int getVal(int l, int t){
  //returns the min
  return (t > l) ? t : l;
}
//function decrements the values
void sub(int &t, int &l, int &num1, int &num2){
  t--;
  l --;
  num1 --;
  num2--;
}
//function increments the values
void add(int &n1, int &n2){
  n1++;
  n2++;
}

