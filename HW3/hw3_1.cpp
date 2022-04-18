/*
*Title: hw3_1.cpp
*Abstract:Program reads two timestamps from a user. For the timestamps,  program should display the final timestamp after the addition.
*Date: 09/12/2021
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

//function to parse the passed string, turn them into a double and store them to a vector, and return it
vector<double> change(string v2){
    //temporary vector that will be returns
    vector<double> tVec;
    //using stringstream to parse
    stringstream parse(v2);

    while(parse.good()){
        string string1;//temporary string
        getline(parse, string1, ':');//gets line of string where there is a : between
        //using stoi() to change string to double
        double word = stoi(string1);
        //store word to vector
        tVec.push_back(word);
    }
    return tVec;//returns

}
//function to add both the timesstamps
void addBoth(vector<double> t1, vector<double> t2){
    //store the size of timestamps and stored them into these variables
    int t1Size = t1.size();
    int t2Size = t2.size();

    int counter1 = 0;//variable where the counter will increments if the time goes over

    //add all sections: hour, min, second
    double third = t1[t1Size - 1] + t2[t2Size - 1];//second
    double second = t1[t1Size - 2] + t2[t2Size - 2];//minute
    double first = t1[0] + t2[0];//hour


    if(third > 59){//if the second is over 59
        third -= 60;//take a minute out of the seconds
        counter1 ++;//increments
    }
    if(counter1 > 0){//if counter increments then minute need to add the minute that was taken out of the seconds section
        second += 1;//add minute
    }
    counter1 = 0;//turn counter back to 0
    if(second > 59){//if minutes is over 59
        second -= 60;//take out an hour out of minutes
        counter1++;//increments
    }
    if(counter1 > 0){//if counter incremented then hour needs to add the hour that was taken out of the minutes sections
        first+=1;//add hour
    }
    if(first > 23){//if hour is over 23
        first -= 24;//take away a day out of hour
    }
    //output the hours, minute, and second of the added timestamps
    cout << std::setfill('0') << std::setw(2) << first << ":"
         << std::setfill('0') << std::setw(2)  <<  second << ":"
         << std::setfill('0') << std::setw(2)  << third << endl;

    return;
}

int main()
{
    string tempWord;//variable where it will store users input: timestamp1
    string tempWord2;//variable where it will store users input: timestamp2
    vector<double> timestamp1;//vector where it will store hour, min, second of the first timestamp when it will be parsed
    vector<double> timestamp2;//vector where it will store hour, min, second of the second timestamp when it will be parse
    //user input
    cin >> tempWord;
    cin >> tempWord2;
    //functions will return a vector of the parsed timestamps and store it to this variable
    timestamp1 = change(tempWord);
    //function will return a vector of the parsed timestamps and store it to this variable
    timestamp2 = change(tempWord2);
    //goes to function to add both timestamps
    addBoth(timestamp1, timestamp2);

    return 0;//exits
}
