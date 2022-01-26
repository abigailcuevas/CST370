/*
*Title: hw9_1.cpp
*Abstract: Program conducts the topological sorting based on Kahn’s algorithm.
*Author: Abigail Cuevas
*ID: 9999
*Date: 11/07/2021
*Reference: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//functions
void TS(int starting, vector<int> allEdges[]);
void print(int starting, vector<int> topological, vector<int> copy, int counter);

int main()
{
    //variables declared
    int vertices = 0;
    int edges = 0;
    int first = 0;
    int second = 0;
    //user input
    cin>> vertices;
    cin>> edges;
    //variable to store the edges
    vector<int> allEdges[vertices];
    //for loop for user to input edges
    for(int i = 0; i < edges; i++){
        cin>> first >> second;
        allEdges[first].push_back(second);
    }
    //get the topological sorting
    TS(vertices, allEdges);

    return 0;
}
//Function to print the topological sorting of the edges inputted
void TS(int starting, vector<int> allEdges[]){
    //variables decalred
    vector<int> used(starting, 0); //used as indegree
    vector<int> topological;
    queue<int> q;
    //for loop to check all the indegrees of the vertices
    for(int i = 0; i < starting; i++){
        for (auto it = allEdges[i].begin();
         it != allEdges[i].end(); ++it){
            used[*it]++;
         }
    }
    //for loop and check withere any vertices had an indegree of 0
    //if yes add to the queue
    for(int i = 0; i < starting; i++){
        if(used[i] == 0){
            q.push(i);
        }
    }
    //store the indegrees to a new variable since it'll be changes
    vector<int> copy = used;
    int counter = 0;
    //loop while the queue is not empty
    while(!q.empty()){
        //get the front and pop to go to next
        int curr = q.front();
        q.pop();
        //add to vector
        topological.push_back(curr);
        //for loop to go to next neighbor and decrement it by 1 
        //if neighbor becomes 0 add to queue
        // counter increments
        for (auto it = allEdges[curr].begin(); it != allEdges[curr].end(); ++it)
            if(--used[*it] == 0)
                q.push(*it);
        counter++;
    }
    //print everything
    print(starting, topological, copy, counter);
    return;
}
//function to print out the indegrees and the topological sorting
void print(int starting, vector<int> topological, vector<int> copy, int counter){
    //for loop to print the indegrees
    for(int i = 0; i < starting; i++){
        cout << "In-degree[" << i << "]:" << copy[i] << endl;
    }
    //check whether there was a cycle
    if(counter != starting){
            cout << "No Order:" << endl;

    }else{//print out topological order
        cout << "Order: " << topological[0];
        for(int i = 1; i < topological.size(); i++)
            cout << "->" << topological[i];
    }
    return;
}


