#pragma once
#include<iostream>
#include <string>
#include"crime.cpp"
using namespace std;
class Crime{
protected:
    int crimeID;
    string crimeType;
    string status;
    string date;
    string description;

public:
    Crime(){};
    
    Crime(int crimeID, string crimeType, string status, string date, string description) {
    this->crimeID = crimeID;
    this->crimeType = crimeType;
    this->status = status;
    this->date = date;
    this->description = description;
    }

    void displayCrimedetails() {
        cout << "Crime ID: " << crimeID << endl;
        cout << "Crime Type: " << crimeType << endl;
        cout << "Status: " << status << endl;
        cout << "Date: " << date << endl;
        cout << "Description: " << description << endl;
    }


};