/*
*Title: hw4_2.cpp
*Abstract: Program that solves the Knapsack problem. The user inputs the number of items for the knapsack and then the knapsacks capacity.
*After the user will input each items capacity and value. The program with them determine the best subset
*Date: 09/20/2021
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//function to get all the combination of the items and returns a pair<int, vector> where the key
//is the the value of the combinations that were added and the vector is the different combinations
pair<int, vector<int>> all(int n, vector<pair<int, int>> t2, int n2, int capacity){
    //to store the items weight and value
    vector <int> weight;
    vector <int> value;
    //for loop to add them to the vector
    for(int i = 0; i < t2.size(); i++){
        weight.push_back(t2[i].first);
        value.push_back(t2[i].second);

    }
    //vector to get the binary number
    vector<int> binary;
    //for loop to get binary number
    for(int i = n2; i > 0; i-- ){\
        binary.push_back(n%2);
        n /= 2;
    }
    //variable where the value and weight of them item will be stored
    int allVal = 0;
    int allWeight = 0;

    vector<int> finalPair;
    //for loop to get the weight of the items and the value of the items after you
    //added them
     for (int j = 0; j < binary.size(); j++){
        if(binary[binary.size() - j - 1] == 1){
            finalPair.push_back(j + 1);
            allWeight += weight[j];
            allVal += value[j];
        }
    }
    //pair used to return
    pair<int, vector<int>> returnPair;
    //check to make sure that the weight of the items doesn't pass the capacity that the user inputted
    //if it does pass the capacity the value will be 0 and then will be stored into the pair
    //if it does not pass the capacity we need to sort the weights of the different items and store them to the pair
    if(allWeight <= capacity){
        sort(finalPair.begin(), finalPair.end());
         returnPair = make_pair(allVal, finalPair);
    }else{
         returnPair = make_pair(0, finalPair);
    }
    return returnPair;//returns
}

int main()
{
    int number = 0;//variable where user input how many items there will be
    int num1 = 0;//number will be stored in this variable
    int capacity = 0; //variable where user enters capacity
    int weight = 0;//variable where user enters the items weight
    int value = 0;//variable where user enters the items value
    int finalCapacity = 0;//variable that will output the final capacity

    vector<pair<int, int >> setNum; //a vector or pairs to store the items
    vector<pair<int, vector<int>>> pairingAll;//store the value and weight after they've been added
    //user input
    cin>> number;
    cin>> capacity;
    //check to make sure item number or capacity is not equal to 0
    if(number == 0 || capacity == 0){
        return 0;
    }
    num1 = number;
    //for loop to get the items weight and value
    for(int i = 0; i < number; i++){
        cin >>weight >> value;
        //store in to the vector of pairs
        setNum.push_back(make_pair(weight, value));
    }

    number = pow(2,number); //number used to find all combinations
    //for loop to find all the combinations weight and value
    for(int i = 0; i < number; i++){
        //store them to the vector, where the final value is the key and the weights are stored in a vector
       pairingAll.push_back(all(i, setNum, num1, capacity));
    }
    //sort the vector by value from greater to least
    //to get the highest value
    sort(pairingAll.rbegin(), pairingAll.rend());
    /*for(int i = 0; i < pairingAll.size(); i++){
        cout << pairingAll[i].first << endl;
    }*/
    //store the item weights of the highest value that were in the pair to a new vector
    vector<int> itemNumber  = pairingAll[0].second;
    //if the highest value in the pair[0] equals to the pair[1]
    //then that mean there are more than one solution
    if(pairingAll[0].first == pairingAll[1].first){
        cout << "Item:Multiple solutions";

    }else{//print the items
        cout << "Item:";
        for(int i = 0; i < itemNumber.size(); i++){
            cout << itemNumber[i] << " ";
        }
    }
    //for loop to get the capacity of the items
    for(int i = 0; i < itemNumber.size(); i++){
        int x = itemNumber[i];
        finalCapacity += setNum[x - 1].first;
    }
    //output everything
    cout << endl;
    cout << "Capacity:" << finalCapacity <<  endl;;
    cout << "Value:" << pairingAll[0].first << endl;

    return 0;//exit
}
