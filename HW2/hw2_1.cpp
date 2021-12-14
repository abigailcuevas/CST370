/*
*Title: hw2_1.cpp
*Abstract: Program reads a set of ranges of two numbers from a user and displays the intersection of all ranges.
*Author: Abigail Cuevas
*ID: 9999
*Date: 09/06/2021
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //declare variables
    int numOfRanges;//number of ranges there will be
    int num1;//number of first ranges
    int num2;//number of second range

    int highestPair1 = 0;//find the highest number of the range
    int lowestPair2 = 0;//find the lowest number of the range

    vector<pair<int,int>> storedRanges;//to store the ranges in pairs
    vector<int> pair2;//to store the second pairs

    cin >> numOfRanges;//user inputs number of ranges

    if(numOfRanges <= 0){//if less than or equal to 0 exits
        return 0;
    }
    //for loop to store the numbers in a pair of vectors
    for(int i = 0; i < numOfRanges; i++){
        cin >> num1 >> num2;
        storedRanges.push_back(make_pair(num1, num2));
    }
    //reference: https://www.geeksforgeeks.org/sorting-vector-of-pairs-in-c-set-2-sort-in-descending-order-by-first-and-second/
    //sort the pairs by greatest to least
    sort(storedRanges.rbegin(), storedRanges.rend());

    highestPair1 = storedRanges[0].first; // get the first pair in the pair of vectors, this will be the
    //highest number

    //for loop to store the second pairs into a vector
    for(int i = 0; i < storedRanges.size(); i++){
        pair2.push_back(storedRanges[i].second);
    }
    //sort the pair in ascending order
    sort(pair2.begin(), pair2.end());
    //store the first number of the vector to the variable
    lowestPair2 = pair2[0];
    //check to make sure that the highestPair1 is not higher than the lowestPair2
    if(lowestPair2 < highestPair1){
        cout << -1 << endl;
    }
    else{
        cout << highestPair1 << " " << lowestPair2 << endl;
    }

    return 0;//exits
}
