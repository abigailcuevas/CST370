/*
*Title: hw3_2.cpp
*Abstract: Program read the number of elements in a set. It will the display the decimal number, the binary number, and the subset one by one.
*Name: Abigail Cuevas
*ID: 9999
*Date: 09/12/2021
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//function to get the binary number and the subsets
//the function passes the decimal number, all the elements, and the number of elements
void all(int n, vector<string> t, int n2){
    //the decimal number will be stored in num
    int n3 = n;
    vector<int> binary;//store the binary numbers

    //for loop to find the binary numbers of each decimal number
    for(int i = n2; i > 0; i-- ){
        //use modules on the decimal number, store in to the vector,
        //after divide by 2 to find the binary number
        binary.push_back(n%2);
        n /= 2;
    }
    //prints out the decimal number
    cout<< n3 << ":";
    //check to see if 0 was inputted for the number of elements
    if(binary.size() == 0){//if yes then output a 0 for binary number
        cout << 0;
    }else{//if not then it output the binary number
        for (int j = 0; j < binary.size(); j++){
            cout << binary[binary.size() - j - 1] << "";
        }
    }
    cout << ":";
    //checks if binary number has zeroes
    int zeroCount = count(binary.begin(), binary.end(), 0);

    if(zeroCount== n2)//if binary number is ALL zeroes, then the subset is empty
    {
        cout << "EMPTY" << endl;
        return;
    }
    //for loop to find the subsets
     for (int j = 0; j < binary.size(); j++){
            //if the binary number equals 1 then it prints out that element
        if(binary[binary.size() - j - 1] == 1){
            cout << t[j] << " ";
        }
    }
    cout<<endl;
    return;//returns
}

int main()
{
    int number = 0;//variable that user inputs how many elements there will be
    int num1 = 0;//variable to store the decimal numbers
    string inputNum = "";//user inputs the elements
    //store the elements in this vector
    vector<string> setNum;
    //user input
    cin>> number;
    //store the number in num1 to find the decimal number
    num1 = number;
    //for loop to add all the elements the user inputted to the vector
    for(int i = 0; i < number; i++){
        cin>>inputNum;
        setNum.push_back(inputNum);//storing in vector
    }
    //find all the possible decimal number
    number = pow(2,number);
    //for loop to find the binary and subsets of each decimal number
    for(int i = 0; i < number; i++){
        //goes to function where it store the decimal number, the vector, and the number of elements that the
        //user inputted
       all(i, setNum, num1);
    }

    return 0;//exit
}

