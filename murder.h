#pragma once
#include<iostream>
#include "crime.h"
#include <fstream>
#include<sstream>
using namespace std;
class Murder : public Crime {
private:
    string wayOfKilling;
    string weaponUsed;
    string crimeScene;
    string victimName;
    int victimAge;
    int noOfSuspects;

public:
Murder(int crimeID, string status, string date, string description, string wayOfKilling, string weaponUsed, string crimeScene, string victimName, int victimAge, int noOfSuspects ) 
    : Crime (crimeID,"Murder",status, date, description){
    this-> wayOfKilling = wayOfKilling;
    this-> weaponUsed = weaponUsed;
    this-> crimeScene = crimeScene;
    this-> victimName = victimName;
    this->victimAge = victimAge;
    this->noOfSuspects = noOfSuspects;
}


void displayMurderDetails(){

    ofstream file("murder.txt", ios::app);
            file<<crimeID<<" | "<<status<<" | "<<date<<" | "<<description<<" | "<<wayOfKilling<<" | "<<weaponUsed<<" | "<<crimeScene<<" | "<<victimName<<" | "<<victimAge<<" | "<<noOfSuspects<<endl;
            cout << "Crime record added successfully. 👍👍👍" << endl;
            file.close();



    displayCrimedetails();
    cout<<"Way of killing: "<<wayOfKilling<<endl;
    cout<<"Weapon used: "<<weaponUsed<<endl;
    cout<<"Crime scene: "<<crimeScene<<endl;
    cout<<"Victim name: "<<victimName<<endl;
    cout<<"Victim Age: "<<victimAge<<endl;
    cout<<"Number of suspects: "<<noOfSuspects<<endl;
    cout<<"💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠\n";
}

Murder() : Crime() {
    crimeID = 0;
    status = "";
    date = "";
    description = "";
    wayOfKilling = "";
    weaponUsed = "";
    crimeScene = "";
    victimName = "";
    victimAge = 0;
    noOfSuspects = 0;
}

// void updateStatusInFile(int crimeID, string newStatus) {
//     ifstream fin("murder.txt");
//     ofstream fout("temp.txt");

//     string line;
//     bool found = false;

//     while (getline(fin, line)) {
//         stringstream ss(line);
//         string id, type, status, date, desc;

//         getline(ss, id, '|');
//         getline(ss, type, '|');
//         getline(ss, status, '|');
//         getline(ss, date, '|');
//         getline(ss, desc);

//         if (id == to_string(crimeID)) {
//             status = newStatus;
//             found = true;
//         }

//         fout << id << "|" << type << "|" << status
//              << "|" << date << "|" << desc << "\n";
//     }

//     fin.close();
//     fout.close();

//     remove("murder.txt");
//     rename("temp.txt", "murder.txt");

//     if (found)
//         cout << "Status updated successfully!\n";
//     else
//         cout << "No matching record found!\n";
// }


// void update(){
    // int id;
    // cout<<"Enter Crime ID: ";
    // cin>>id;
    // string newStatus;
    // cout<<"enter status : "<<endl;
    // cin>>newStatus;

    //  ofstream file("murder.txt", ios::out);
        // file<<crimeID<<" | "<<status<<" | "<<date<<" | "<<description<<" | "<<wayOfKilling<<" | "<<weaponUsed<<" | "<<crimeScene<<" | "<<victimName<<" | "<<victimAge<<" | "<<noOfSuspects<<endl;
        // file.close();
    // if (id == crimeID){
    //     status = newStatus;


        
    //     // ofstream file("murder.txt", ios::out);
    //         // if (file.open()){
    //         //     file<<"hi";

    //         // file.close();
    //         // }
            

    // }
     
    // else{
    //     cout<<"Record not found."<<endl;
        
    // }
    // file<<crimeID<<" | "<<status<<" | "<<date<<" | "<<description<<" | "<<wayOfKilling<<" | "<<weaponUsed<<" | "<<crimeScene<<" | "<<victimName<<" | "<<victimAge<<" | "<<noOfSuspects<<endl;
    //     file.close();
// }



};