/*
*Title: hw9_2.cpp
*Abstract: Program connects several connected components of a graph with 
*minimum number of edges to create a single connected component of the graph.
*Name: Abigail Cuevas
*ID: 9999
*Date: 11/07/2021
*References: https://www.geeksforgeeks.org/bfs-disconnected-graph/
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> all;
//functions
void bfs(int starting, vector<int> allEdges[], vector<int> &used);
void BFS(int starting, vector<int> allEdges[]);

int main()
{
    //variables declared
    int vertices = 0;
    int edges = 0;
    int info1 = 0;
    int info2 = 0;
    vector<pair<int,int>> finalE;
    //user input
    cin >> vertices;
    cin >> edges;
    //to store the edges the user will input
    vector<int> allEdges[vertices];
    //user inputs edges
    for(int i = 0; i < edges; i++){
        cin >> info1 >> info2;
        allEdges[info1].push_back(info2);
    }
    //passes to bfs function to check the graphs
    BFS(vertices,allEdges);

    //if size is greater than 1 then there are more than 1 graphs
    if(all.size() > 1){
        //for loop to store the new edges into a vector
        for (int i = 0; i < all.size()-1; i++) {
            finalE.push_back(make_pair(all[i][0],all[i+1][0] ));
        }
        //print out the new edges
        for (int i = 0; i < finalE.size(); i++) {
            cout << "Edge: " << finalE[i].first << "-" << finalE[i].second << endl;
        }
    }else{//there is only 1 graph
        cout << "No new edge:" << endl;
    }

    return 0;//exit
}

//function checks where the number has been visited or not
//if not visited passed to bfs() function
void BFS(int starting, vector<int> allEdges[]){
    //mark all vertices as not visited
    vector<int> used(starting, 0);
    //for loop to check whether the vertices has been visited
    for(int i = 0; i < starting; i++){
        //if not visited yet goes to function bfs()
        //make sure to double check for disconnected graphs
        if(used[i] == 0){
            bfs(i, allEdges, used);
        }
    }
}

//function checks whether vertices has been visited
void bfs(int starting, vector<int> allEdges[], vector<int> &used){
    //variable declared
    queue<int> q;
    //mark are visited
    used[starting] = 1;
    //add to queue
    q.push(starting);
    //vector to store the graph
    vector<int> temp;

    while(!q.empty()){
        starting = q.front();
        //store the graph
        temp.push_back(starting);
        q.pop();
        //for loop to check its neighbor
        for(int i = 0; i != allEdges[starting].size(); ++i){
            //if not visited add to the queue and then mark it as visited
            if(used[allEdges[starting][i]]==0){
                used[allEdges[starting][i]] = 1;
                q.push(allEdges[starting][i]);
            }
        }
    }
    //sorts the graph 
    sort(temp.begin(), temp.end());
    //adds it to the vector
    all.push_back(temp);
}
