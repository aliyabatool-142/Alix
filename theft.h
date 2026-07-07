#pragma once
#include<iostream>
#include "crime.h"
class Theft : public Crime {
private:
    double stolenAmount;
    string stolenItem;
    bool isRecovered;
    string location;

public:
    Theft(int crimeID, string status, string date, string description, double stolenAmount, string stolenItem ,bool isRecovered, string location)
        : Crime(crimeID, "Theft", status, date, description) {
        this->stolenAmount = stolenAmount;
        this->stolenItem = stolenItem;
        this->isRecovered = isRecovered;
        this->location = location;
    }

    void displayTheftDetails() {
         ofstream file("theft.txt", ios::app);
            file<<crimeID<<" | "<<status<<" | "<<date<<" | "<<description<<" | "<<stolenAmount<<" | "<<stolenItem<<" | "<<isRecovered<<" | "<<location<<endl;
            cout << "Crime record added successfully. 👍👍👍" << endl;
            file.close();
        displayCrimedetails();
        cout << "Stolen Amount: $" << stolenAmount << endl;
        cout << "Stolen Item: " << stolenItem << endl;
        cout<<  "Is Recovered: "<<isRecovered<<endl;
        cout<<"Location: "<<location<<endl;
        cout<<"💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠\n"<<endl;
    }

};