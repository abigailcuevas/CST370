/*
*Title: hw7_1.cpp
*Abstract: Program conducts the BFS traversal of a graph and displays city names in the range of hop(s) from a starting city
*Author: Abigail Cuevas
*ID: 9999
*Date: 10/18/2021
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

//variable used throughout the program
map<string, set<string>> allgraph;
int globalnum;
//fucntion to find the number of hops, starting city is passed
void bfs(string v){
    //variable to keep track of the the hops from city to city
    vector<int> mark(allgraph.size(), -1);
    queue<string> q;
    //variable to find where the starting city is located in the map
    int firstC = 0;
    for (auto it = allgraph.begin(); it != allgraph.end(); ++it){
        if( it->first == v){
            break;
        }firstC++;
    }
    //mark that city as the first hop
    mark[firstC] = 0;
    q.push(v);
    //while loop to loop through the cities that are pushed to the queue
    while(!q.empty()){
        //get the city in the queue
        string curr = q.front();
        int currentIndex = 0;
        //for loop to find that city and where its located in the map
        for (auto it = allgraph.begin(); it != allgraph.end(); ++it){
            if( it->first == curr){
               break;
            }
            currentIndex++;
        }
        //clear that city from the queue
        q.pop();
        //iterator to loop thought the map set
        set<string>::iterator i;
        //for loop to find the all the destination cities from the starting city that was at the front of the queue
        for (i = allgraph[curr].begin(); i != allgraph[curr].end(); ++i){
            int x = 0;
            //for loop to find destination cities
            for (auto it = allgraph.begin(); it != allgraph.end(); ++it){
                if( it->first == *i){
                    break;
                }
                x++;
            }
            //check to see if it has been visited
            if(mark[x] == -1){
                //if not visited add to keep track of the hops
                mark[x] = mark[currentIndex] + 1;
                //push to queue
                q.push(*i);
            }
        }
    }
    //cout << "graph.size(): " << allgraph.size() << " ,hops: " << mark.size() << endl;
    //for loop to print out the hops
    int finalInt = 0;
    for (auto it = allgraph.begin(); it != allgraph.end(); ++it){
            //make sure to print out cities that are greater than 0 hops and less than the
            //hops the user inputed
        if(mark[finalInt] >= 0 && mark[finalInt] <= globalnum){
            cout << it->first<< ":"<< mark[finalInt] << endl;
        }finalInt++;
    }
}

int main()
{
    //variables declared
    int vertices = 0;
    int edges = 0;
    string cities = "";
    string sourceCity = "";
    string destination = "";
    string startingCity = "";
    int hops = 0;
    //user input
    cin>>vertices;
    //for loop to add the cities
    for(int i = 0; i < vertices; i++){
        cin >> cities;
        allgraph[cities];
    }
    //user input
    cin >> edges;
    //for loop to add the edges
    for(int i = 0; i < edges; i++){
        cin >> sourceCity >> destination;
        allgraph[sourceCity].insert(destination);
    }
    //user input
    cin >> startingCity;
    cin >> hops;

    globalnum = hops;
    //pass the starting city to the bfs function
    bfs(startingCity);

    return 0;//exit
}
