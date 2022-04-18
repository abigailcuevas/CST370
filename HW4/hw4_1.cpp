/*
*Title: hw4_1.cpp
*Abstract: Program converts a directed graph from a user into a corresponding adjacency list format.
*Date: 09/20/2021
*/
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int vertices = 0;//users vertices will be stored in vertices
    int edges = 0;//users input
    int tempNum1 = 0;//first input
    int tempNum2 = 0;//second input
    set<pair<int,int>> pairs;//store the pairs into set
    set<int> all;
    //user input
    cin>> vertices;
    cin>> edges;
    //check that one or the other doesn't equal 0
    if(edges == 0){
        for(int i = 0; i < vertices; i++){
            cout << i << endl;
        }
        return 0;
    }
    
    if(vertices == 0){
        return 0;
    }
    //for loop where user input each pair
    //get stored in to the set of pairs
    for(int i = 0; i < edges; i++){
        cin >> tempNum1 >> tempNum2;
        pairs.insert(make_pair(tempNum1, tempNum2));
    }
    //insert all the numbers into the set all
    for(auto it=pairs.begin(); it!=pairs.end(); ++it){
        all.insert(it->first);
        all.insert(it->second);
    }
    //loop through the all set and print out the list
    // if the number in the all set matches the first pair number in the set
    //it will output the second number of the set pair, and will loop for each one
     for(auto it : all){
        cout << it;
        for(auto ti = pairs.begin(); ti!= pairs.end(); ++ti){
            if(it == ti->first){
                cout << "->" << ti->second;
            }
        }
        cout<< endl;
    }

    return 0;//exit
}
