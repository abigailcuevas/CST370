/*
*Title: hw6_2.cpp
*Abstract: Program implements the Depth-First Search(DFS) algorithm using stack and mark array.
*Author: Abigail Cuevas
*ID: 9999
*Date: 10/03/2021
*Reference: https://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal.htm
*Reference: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//variables used throughout the program
map<int, bool> used;
map<int, set<int>> allGraph;
set<int> tempSet;
int counterMark = 0;
//function
void depthAlgorithm(int v, int *arr);

int main()
{
    //variable declared
    int numOfVert = 0;
    int numOfEdge = 0;
    int edgeInfo = 0;
    int edgeInfo2 = 0;
    int starting = 0;
    //user input
    cin >> numOfVert;
    cin >> numOfEdge;
    //check both aren't 0
    if(numOfVert == 0 & numOfEdge == 0){
        return 0;
    }
    //for loop to add the edges information and store them on the map
    for(int x = 0; x < numOfEdge; x++){
        cin >> edgeInfo >> edgeInfo2;
        allGraph[edgeInfo].insert(edgeInfo2);
        tempSet.insert(edgeInfo2);
        tempSet.insert(edgeInfo);
    }
    //user input, where it will start
    cin >> starting;
    //check and make sure the the number is one of the vertices
    if(tempSet.find(starting) == tempSet.end()){
        return 0;
    }
    //create an array to sort
    int markArr[numOfVert];

    for(int i = 0; i < numOfVert; i++){
        markArr[i] = 0;
    }
    //function that will find all the connections, pass the map and the array to store them to the array
    depthAlgorithm(starting, markArr);
    //print the array
    for(int i = 0; i < numOfVert; i++){
        cout << "Mark[" << i << "]:" << markArr[i] << endl;
    }

    return 0;//exit
}

void depthAlgorithm(int v, int *arr)
{
    //the passes number will be declared as visited, to keep track
    //of the visited number
    used[v] = true;
    //increment the mark number
    counterMark+=1;
    //store them on the array, this is what will be printed later
    arr[v] = counterMark;
    set<int>::iterator i;
    //for loop to go through the set
    for (i = allGraph[v].begin(); i != allGraph[v].end(); ++i){
      //if the passed number is not marked as visited
      //go through it
      if (!used[*i]){
          depthAlgorithm(*i, arr);
      }//end of if
    }//end of for
}