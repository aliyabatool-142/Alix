#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

class Criminal
{
private:
    string name;
    string country;
    string criminalType;
    int victims;
    string status;

public:
Criminal(){};
    Criminal(string name, string country, string criminalType, int victims, string status)
    {
        this->name = name;
        this->country = country;
        this->criminalType = criminalType;
        this->victims = victims;
        this->status = status;
    }


// This function converts any string into lowercase
// It helps us make the search case-insensitive
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}



void displayCriminalDetails()
{
    string name;
    cout << "Enter Name of Criminal to view his/her crime record: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    name = toLower(name);   // 🔑 make input lowercase

    ifstream fin("criminal.txt");
    if (!fin)
    {
        cout << "File not found!\n";
        return;
    }

    string line;
    bool found = false;

    // Skip header lines
    getline(fin, line);
    getline(fin, line);

    while (getline(fin, line))
    {
        size_t pos = line.find('|');
        if (pos == string::npos)
            continue;

        string crimeNameInFile = line.substr(0, pos);
        crimeNameInFile = toLower(crimeNameInFile);   // 🔑 make file data lowercase

        if (crimeNameInFile.find(name) != string::npos)
        {
            cout << "\n╭──────────────────────────────────────────────╮\n";
            cout << "│           🔍 CRIMINAL RECORD FOUND           │\n";
            cout << "╰──────────────────────────────────────────────╯\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    fin.close();

    if (!found)
        cout << "❌ Crime Record not found.\n";
}



   
};
