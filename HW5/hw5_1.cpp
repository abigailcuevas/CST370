/*
*Title: Hw5_1.cpp
*Abstract: Program reads an input graph data from a user. Then it present a path for the travelling salesman problem.
*Author: Abigail Cuevas
*Date: 09/26/2021
*ID: 9999
*Reference: https://repl.it/@YBYUN/permutationsusingSTL
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> temp;
vector<pair<int, vector<int>>> finalPair;

//function to find the cost of each permutations
int findCost(vector<int> a, vector<vector<int>> b, int numV);
//function stores all the permutations into a vector
void store(int a[], int n, int t)
{
    vector<int> temp1;
    temp1.push_back(t);
	for (int i = 0; i < n; i++){
		temp1.push_back(a[i]);
	}
    temp1.push_back(t);
	temp.push_back(temp1);
}
//function to find the permutations
void find_permutations(int a[], int n, int t)
{
    do{
		store(a, n, t);
	} while (next_permutation(a, a + n));
}

int main()
{
    //variables declared
    int numV = 0;
    int numE = 0;
    int sourceV = 0;
    int destV = 0;
    int cost = 0;
    int startV = 0;
    set<int> allNums;
    //user input
    cin>> numV;
    cin>> numE;
    //check that they don't equal 0
    if(numV == 0 || numE == 0){
        return 0;
    }
    //put all the
    vector<vector<int>> pairs;
    //user inputs the edges information and the cost
    //get stored into the set and the vector
    for(int i = 0; i < numE; i++){
        cin>> sourceV >> destV >> cost;
        vector<int> allNum{ sourceV, destV , cost};
        allNums.insert(sourceV);
        pairs.push_back(allNum);
    }
    //user input the starting vertex
    cin>> startV;
    //erase the starting value so that it won't be there when we find all the permutations
    allNums.erase(startV);

    int a[allNums.size()];//this will be used to store the set
    int x = 0;
    //store the set to the array
    for(auto it = allNums.begin() ; it != allNums.end() ; it++ ){
        a[x] = *it;
        x++;
    }
    //find the permutations in the array
    find_permutations(a, allNums.size(), startV);
    //for loop to find the cost of all the permutations
    for(int i = 0; i < temp.size(); i++){
        int tempCost = findCost(temp[i], pairs, numV);
        //check to see that the cost is greater than 0
        //and store it to the vector
        if(tempCost > 0){
            finalPair.push_back(make_pair(tempCost, temp[i]));
        }
    }
    //sort from least to greatest
    sort(finalPair.begin(), finalPair.end());
    //if the vector is empty an empty path and negative cost will print out
    if(finalPair.size() <= 0){
            cout << "Path:" << endl;
            cout << "Cost:" << -1 << endl;

    }else{//if the vector isn't empty, then the path and the cost will be outputed
        //the path is stored into the vector to print out
        vector<int> traveling = finalPair[0].second;
        cout << "Path:" << traveling[0];
        //prints path
        for(int i = 1; i < traveling.size(); i++){
            cout<< "->" << traveling[i];
        }
        //prints cost
        cout << endl << "Cost:" << finalPair[0].first;
    }
    return 0;//exit
}
//function to find the cost of all the permutations
//if the numbers match each other the cost is counted
//if not then a negative number will return
int findCost(vector<int> a, vector<vector<int>> b, int numV){
    //variable declared
    int cost = 0;
    int count = 0;
    //for loop to calculate the cost
    //first for loop is the permutations
    //second for loop is the edges and the cost
    for(int j = 0; j < a.size()-1; j++){
        for(int i = 0; i < b.size(); i++){
                //check to see if they match
            if(a[j] == b[i][0] && a[j+1] == b[i][1]){
                    count++;
                    cost+= b[i][2];//find the cost
            }
        }
        //if they don't match
    }if(numV != count){
        cost = -1;
    }
    return cost;//returns the cost
}
