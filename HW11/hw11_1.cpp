/*
* Title: hw11_1.cpp
* Abstract: Program simulates the operations of linear probing
* Author: Abigail Cuevas
* Date: 12/1/2021
* ID: 9999
* References: https://www.educba.com/c-plus-plus-hash-table/
* References: https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
*/
#include<iostream>
using namespace std;

//variables used throughout
bool checking = false;
int* keys;
string* stat;
bool* deleted;
int counter = 0;
int *deleteNum;
//functions used 
int pCheck(int n);
void Delete(int tab, int num, int size);
bool search(int tab, int num, int size);
void displayS(int tab);
void store(int tempSize, int tab, int size);
int rehashing(int load, int size);
void resize(int size){
  keys = new int[size];
  stat = new string[size];
  deleted = new bool[size]();
  deleteNum = new int[size];
}

int main(){
  //variables declared
  int size = 0;
  int commands = 0;
  string comm = "";
  int cNum = 0;
  double loadedF = 0;
  //user input
  cin >> size;
  //resize the 
  resize(size);
  //user input
  cin >> commands;
  //for loop to user input commands
  for(int x = 0; x < commands; x++){
    //user input
    cin >> comm;
    //check if command equals any of the following
    if(comm == "insert" || comm == "displayStatus" || comm == "search" || comm == "delete"){        //user input
        cin >> cNum;
        int findSize;

        if(comm == "insert"){ //insert section
          counter ++; //used to check if the tables load factor
          double doub = counter;
          loadedF = doub / size;      
          //check whether the load factor is greater thatn 0.5 
          if(0.5 < loadedF ){
           // cout << "here \n";
            //resize the table
            size = rehashing(loadedF, size);
            //resize the rest of the variable
            deleted = new bool[size]();
            deleteNum = new int[size];
          }
          //store the number to the table
          findSize = cNum % size;
          store(findSize, cNum, size);

        }else if(comm == "delete"){//delete section
          Delete(cNum, findSize, size);

        }else if(comm == "displayStatus"){//displayStatus Section
          displayS(cNum);
          
        }else if(comm == "search"){ //Search section
          if(!search(cNum, findSize , size)){//if funtion return false, number is not in table
            cout << cNum << " Not found" << endl;
          }else{//if functin return ture, number was located in the table
            cout << cNum << " Found" << endl;
          }
        }

      }else if(comm == "tableSize"){//prints out the tables Size
        cout << size << endl;
      }
    }

    return 0;//edxit
}
//function to figure out the status of the table section
void displayS(int tab){
  //check whether the number was deleted 
   if(deleted[tab]){
      cout << deleteNum[tab] << " Deleted" << endl;
    }
    //check whether a number is located
    else if(stat[tab] == "active"){
      cout <<  keys[tab] << " Active" << endl;;
    }else{//check the table is empty
      cout << "Empty" << endl;
    }
    //returns the corresponding numbers
}

//function checks whether the number is found 
bool search(int tab, int num, int size){
  //variable declared
  bool result = true;
  int starting = num;
  do{//check both status of the table section if its active and if the number matches that is
  //passed, if yes return true
    if(stat[starting] == "active" && keys[starting] == tab){
        result =  true;
    }
    // go to next section, and keep going
    int temp = starting + 1;
    starting = temp % size;
  }while(starting != num);//keep looping until they match
  //if not found return false                
  if(keys[starting] != tab)
      result = false;

  return result;
}
//function deletes the number that is passed
void Delete(int tab, int num, int size){
  //variables declared
  int starting = num;
  int ending = num;
  do{//checks wther the status of the table has a number and 
  //if that number matches the number that is passed
    if(keys[starting] == tab && stat[starting]== "active" ){
        counter--;//decrements the counter
        //makes the status empty, since number is deleted
        stat[starting] = "empty";
        //is marked as deleted
        deleted[starting] = true;
        deleteNum[starting] = tab;
        break;
    }
    //go to next section
    int num = starting +1;
    starting = num % size;
  }while(ending != starting); // keep looping until they match
 
  return;
}
//function that finds the  first prime number that's twice as large as the currents table size
int pCheck(int n) {
  //increment
  n+=1;
  while(true){//while the 
    checking = true;
    int i = 2;
    while(i*i <= n){
      if(n % i == 0){
          checking = false;
          break;
        }
      i+= 1;
    }
    if(checking != false)
        return n;
    n += 1;
  }
}
//function that conducts the rehashing
int rehashing(int load, int size)
{
  //variables declared
  int i = 0;
  int s = pCheck(size * 2);
  int* c = new int[s];
  string* st = new string[s];
  //while loop
  while(i < size){
    //checks the active section table
      if(stat[i] == "active"){
        int x = keys[i];
        int increment = x % s;
        //used to store them to the temporary values
        while(st[increment] == "active"){
              int x = increment + 1;
              increment = x % s;
        }
        st[increment] = "active";
        c[increment] = keys[i];
      }
    i++;//increment
  }
  //store the new values to the corresponding varaibles
  keys = c;
  stat = st;
  return s;//returns the new size
}
//function that stores the rehashed value to their variable
void store(int tempsize, int tab, int size){
  //get the size that is active
  while(stat[tempsize] == "active"){
    int x = tempsize + 1;
    tempsize = x % size;
  }
  //store new values to their section
  stat[tempsize] = "active";
  keys[tempsize] = tab;
  deleted[tempsize] = false;
  deleteNum[tempsize] = -1;
}