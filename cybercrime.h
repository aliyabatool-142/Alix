#pragma once
#include<iostream>
#include "crime.h"
class Cybercrime : public Crime{
private:
    string attackType;
    string targetSystem;
    double dataLossAmount;   // in MB/GB
    string ipAddress;
    bool isInternational;
    string plateform;

public:
    Cybercrime(int crimeID, string status, string date, string description, string attackType, string targetSystem, double dataLossAmount, string ipAddress, bool isInternational, string plateform) 
        : Crime(crimeID, "Cybercrime", status, date, description){
            this->attackType = attackType;
            this->targetSystem = targetSystem;
            this->dataLossAmount = dataLossAmount;
            this->ipAddress = ipAddress;
            this->isInternational = isInternational;
            this->plateform = plateform;
    }

    void displayCybercrimeDetails(){
          ofstream file("cybercrime.txt", ios::app);
            file<<crimeID<<" | "<<status<<" | "<<date<<" | "<<description<<" | "<<attackType<<" | "<<targetSystem<<" | "<<dataLossAmount<<" | "<<ipAddress<<" | "<<isInternational<<" | "<<plateform<<endl;
            cout << "Crime record added successfully. 👍👍👍" << endl;
            file.close();
        displayCrimedetails();
        cout<<"Attack Type: "<<attackType<<endl;
        cout<<"Target System: "<<targetSystem<<endl;
        cout<<"Data Loss Amount: GB- "<<dataLossAmount<<endl;
        cout<<"IP Adress: "<<ipAddress<<endl;
        cout<<"Is International: "<<isInternational<<endl;
        cout<<"Plateform: "<<plateform<<endl;
        cout<<"💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠\n"<<endl;
    }

};