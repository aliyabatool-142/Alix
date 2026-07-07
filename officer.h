#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "user.h"
#include "crime.h"
#include "murder.h"
#include "theft.h"
#include "cybercrime.h"

using namespace std;
class Officer : public User
{
public:
    Officer(int userID, string userName, string password)
        : User(userID, userName, password, "officer")
    {
    }

    int countCrimeCases(const string &filename)
    {
        ifstream fin(filename);
        if (!fin.is_open())
            return 0;

        int count = 0;
        string line;
        while (getline(fin, line))
        {
            if (!line.empty()) // ignore blank lines
                count++;
        }

        return count;
    }

    void viewMurderByID()
    {
        int id;
        cout << "Enter Murder ID to view crime: ";
        cin >> id;

        ifstream fin("murder.txt");
        if (!fin.is_open())
        {
            cout << "File not found!\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(fin, line))
        {

            // Find position of first '|'
            size_t pos = line.find('|');
            if (pos == string::npos)
                continue; // skip invalid lines

            // Extract crimeID from the line
            int crimeIDInFile = stoi(line.substr(0, pos));

            if (crimeIDInFile == id)
            {
                cout << "\n*********** CRIME FOUND ***********\n";
                cout << line << endl;
                cout << "***********************************\n";
                found = true;
                break; // no need to check more lines
            }
        }

        fin.close();

        if (!found)
            cout << "Murder ID not found.\n";
    }

    void viewTheftByID()
    {
        int id;
        cout << "Enter Theft ID to view crime: ";
        cin >> id;

        ifstream fin("theft.txt");
        if (!fin.is_open())
        {
            cout << "File not found!\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(fin, line))
        {

            // Find position of first '|'
            size_t pos = line.find('|');
            if (pos == string::npos)
                continue; // skip invalid lines

            // Extract crimeID from the line
            int crimeIDInFile = stoi(line.substr(0, pos));

            if (crimeIDInFile == id)
            {
                cout << "\n*********** CRIME FOUND ***********\n";
                cout << line << endl;
                cout << "***********************************\n";
                found = true;
                break; // no need to check more lines
            }
        }

        fin.close();

        if (!found)
            cout << "Theft ID not found.\n";
    }

    void viewCybercrimeByID()
    {
        int id;
        cout << "Enter CyberCrime ID to view crime: ";
        cin >> id;

        ifstream fin("cybercrime.txt");
        if (!fin.is_open())
        {
            cout << "File not found!\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(fin, line))
        {

            // Find position of first '|'
            size_t pos = line.find('|');
            if (pos == string::npos)
                continue; // skip invalid lines

            // Extract crimeID from the line
            int crimeIDInFile = stoi(line.substr(0, pos));

            if (crimeIDInFile == id)
            {
                cout << "\n*********** CRIME FOUND ***********\n";
                cout << line << endl;
                cout << "***********************************\n";
                found = true;
                break; // no need to check more lines
            }
        }

        fin.close();

        if (!found)
            cout << "Cybercrime ID not found.\n";
    }

   
    void updateMurderStatus()
    {
        int id;
        cout << "Enter Crime ID to update: ";
        cin >> id;
        cin.ignore(); // remove leftover newline

        ifstream fin("murder.txt");
        if (!fin)
        {
            cout << "File not found!\n";
            return;
        }

        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(fin, line))
        {
            // Find first '|' to get ID
            size_t sep1 = line.find('|');
            if (sep1 == string::npos)
            {
                temp << line << endl;
                continue;
            }

            int crimeIDInFile = stoi(line.substr(0, sep1));

            // Find second '|' to get status
            size_t sep2 = line.find('|', sep1 + 1);
            string currentStatus = line.substr(sep1 + 1, sep2 - sep1 - 1);
            currentStatus.erase(0, currentStatus.find_first_not_of(" ")); // trim spaces

            if (crimeIDInFile == id)
            {
                found = true;
                cout << "Original Status: " << currentStatus << endl;

                string newStatus;
                cout << "Enter new Status: ";
                getline(cin, newStatus);

                // Append new status after original
                string updatedStatus = currentStatus + " -> " + newStatus;

                // Rebuild line
                line = line.substr(0, sep1 + 1) + " " + updatedStatus + line.substr(sep2);
            }

            temp << line << endl;
        }

        fin.close();
        temp.close();

        remove("murder.txt");
        rename("temp.txt", "murder.txt");

        if (found)
            cout << "Murder case updated successfully!\n";
        else
            cout << "Crime ID not found.\n";
    }

    void updateTheftStatus()
    {
        int id;
        cout << "Enter Crime ID to update (Theft): ";
        cin >> id;
        cin.ignore();

        ifstream fin("theft.txt");
        if (!fin)
        {
            cout << "theft.txt not found!\n";
            return;
        }

        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(fin, line))
        {
            size_t sep1 = line.find('|');
            if (sep1 == string::npos)
            {
                temp << line << endl;
                continue;
            }

            int crimeIDInFile = stoi(line.substr(0, sep1));

            size_t sep2 = line.find('|', sep1 + 1);
            string currentStatus = line.substr(sep1 + 1, sep2 - sep1 - 1);
            currentStatus.erase(0, currentStatus.find_first_not_of(" "));

            if (crimeIDInFile == id)
            {
                found = true;
                cout << "Original Status: " << currentStatus << endl;

                string newStatus;
                cout << "Enter new Status: ";
                getline(cin, newStatus);

                string updatedStatus = currentStatus + " -> " + newStatus;

                line = line.substr(0, sep1 + 1) + " " + updatedStatus + line.substr(sep2);
            }

            temp << line << endl;
        }

        fin.close();
        temp.close();

        remove("theft.txt");
        rename("temp.txt", "theft.txt");

        if (found)
            cout << "Theft case updated successfully!\n";
        else
            cout << "Crime ID not found in Theft records.\n";
    }

    void updateCybercrimeStatus()
    {
        int id;
        cout << "Enter Crime ID to update (Cybercrime): ";
        cin >> id;
        cin.ignore();

        ifstream fin("cybercrime.txt");
        if (!fin)
        {
            cout << "cybercrime.txt not found!\n";
            return;
        }

        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(fin, line))
        {
            // Find Crime ID (before first '|')
            size_t sep1 = line.find('|');
            if (sep1 == string::npos)
            {
                temp << line << endl;
                continue;
            }

            int crimeIDInFile = stoi(line.substr(0, sep1));

            // Find status (between first and second '|')
            size_t sep2 = line.find('|', sep1 + 1);
            string currentStatus = line.substr(sep1 + 1, sep2 - sep1 - 1);

            // Trim spaces
            currentStatus.erase(0, currentStatus.find_first_not_of(" "));

            if (crimeIDInFile == id)
            {
                found = true;

                cout << "Original Status: " << currentStatus << endl;

                string newStatus;
                cout << "Enter new Status: ";
                getline(cin, newStatus);

                // Append new status behind original
                string updatedStatus = currentStatus + " -> " + newStatus;

                // Rebuild the whole line (status replaced only)
                line = line.substr(0, sep1 + 1) + " " + updatedStatus + line.substr(sep2);
            }

            temp << line << endl;
        }

        fin.close();
        temp.close();

        remove("cybercrime.txt");
        rename("temp.txt", "cybercrime.txt");

        if (found)
            cout << "Cybercrime status updated successfully!\n";
        else
            cout << "Crime ID not found in Cybercrime records.\n";
    }

    void viewAllCrime()
    {
        int choice;
        cout << "Enter 1 to view murder cases, 2 for theft cases or 3 for cybercrime cases: ";
        cin >> choice;

        string filename;

        switch (choice)
        {
        case 1:
            filename = "murder.txt";
            break;

        case 2:
            filename = "theft.txt";
            break;

        case 3:
            filename = "cybercrime.txt";
            break;

        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        ifstream fin(filename);
        if (!fin)
        {
            cout << filename << " not found!" << endl;
            return;
        }

        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }

        fin.close();
    }

    void menu() override
    {   cout << "1️⃣  Register FIR\n";
        cout << "2️⃣  Update Crime Status\n";
        cout << "3️⃣  View All Crimes\n";
        cout << "4️⃣  Search Crime by ID\n";
        cout << "5️⃣  View Crime Statistics\n";
        cout << "6️⃣  Logout\n";
        cout << "💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠" << endl;

        int choice;
        cout << "Please enter your choice: ✒️  ";
        cin >> choice;

        int crimeID;
        string crimeType;
        string status;
        string date;
        string description;

        switch (choice)
        {
        case 1:
            int select;
            cout << " Enter 1 for Murder 🔪🔪🔪 \n Enter 2 for Theft 🧱🪜 🪚\n Enter 3 for Cybercrime 🎭🎭🎭\n";
            cout << "💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠" << endl;
            cout << "Please enter your choice: ✒️  ";
            cin >> select;
            if (select == 1)
            {
                cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";
                cout << "          🔪   Regestring FIR (MURDER)        \n";
                cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";

                cout << "           ✧✧✧ ENTER DETAILS ✧✧✧\n";
                cout << "           ──────────────────────\n";



                string wayOfKilling;
                string weaponUsed;
                string crimeScene;
                string victimName;
                int victimAge;
                int noOfSuspects;

                cout << "Enter Crime ID  👉  ";
                cin >> crimeID;
                cout << "Enter Crime Status 👉  ";
                cin >> status;
                cout << "Enter Crime Date 👉  ";
                cin >> date;
                cout << "Enter Crime Description 👉  ";
                cin.ignore();
                getline(cin , description);
                cout << "Enter Way of Killing 👉  ";
                getline(cin , wayOfKilling);
                cout << "Enter Weapon used 👉  ";                
                getline(cin , weaponUsed);
                cout << "Enter Crime Scene 👉  ";                
                getline(cin , crimeScene);
                cout << "Enter Victim Name 👉  ";
                getline(cin , victimName);
                cout << "Enter Victim Age 👉  ";
                cin >> victimAge;
                cout << "Enter Number of Suspects 👉  ";
                cin >> noOfSuspects;


                Murder m1(crimeID, status, date, description, wayOfKilling, weaponUsed, crimeScene, victimName, victimAge, noOfSuspects);
                cout << " 💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠" << endl;
                m1.displayMurderDetails();
            }
            else if (select == 2)
            {
                 cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";
                cout << "         🛍️  Regestring FIR  (THEFT)         \n";
                cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";

                cout << "           ✧✧✧ ENTER DETAILS ✧✧✧\n";
                cout << "           ──────────────────────\n";
                double stolenAmount;
                string stolenItem;
                bool isRecovered;
                string location;

                cout << "Enter Crime ID 👉  ";
                cin >> crimeID;
                cout << "Enter Crime Status 👉  ";
                cin >> status;
                cout << "Enter Crime Date 👉  ";
                cin.ignore();
                getline(cin, date);
                cout << "Enter Crime Description 👉  ";                
                getline(cin , description);
                cout << "Enter Stolen Amount 👉  ";
                cin >> stolenAmount;
                cout << "Enter Stolen Item 👉   ";
                cin.ignore();
                getline(cin , stolenItem);
                cout << "Enter 1 if the amount has been recovered and 0 if the amount hasn't been recovered 👉  ";
                cin >> isRecovered;
                cout << "Enter location of Robbery 👉  ";
                cin.ignore();
                getline(cin , location);

                Theft t1(crimeID, status, date, description, stolenAmount, stolenItem, isRecovered, location);
                cout << "💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠" << endl;
                
                t1.displayTheftDetails();
            }
            else if (select == 3)
            {
                 cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";
                cout << "       💻  Regestring FIR (CYBER-CRIME)        \n";
                cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";

                cout << "           ✧✧✧ ENTER DETAILS ✧✧✧\n";
                cout << "           ──────────────────────\n";
                string attackType;
                string targetSystem;
                double dataLossAmount; // in MB/GB
                string ipAddress;
                bool isInternational;
                string plateform;

                cout << "Enter Crime ID 👉  ";
                cin >> crimeID;
                cout << "Enter Crime Status 👉  ";
                cin >> status;
                cout << "Enter Crime Date 👉  ";
                cin.ignore();
                getline(cin , date);
                cout << "Enter Crime Description 👉  ";
                
                getline(cin , description);
                cout << "Enter Attack Type 👉   ";
                getline(cin , attackType);
                cout << "Enter Target system 👉  ";
                getline(cin , targetSystem);
                cout << "Enter Data Loss Amount(in GB) 👉  ";
                cin>>dataLossAmount;
                cout << "Enter IP Adress 👉  ";
                cin.ignore();
                getline(cin , ipAddress);
                cout << "Enter 1 if the attack is international and 0 if it's not 👉  ";
                cin >> isInternational;
                cout << "Enter Plateform 👉  ";
                getline(cin , plateform);

                Cybercrime c1(crimeID, status, date, description, attackType, targetSystem, dataLossAmount, ipAddress, isInternational, plateform);
                cout << "💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠" << endl;
                
                c1.displayCybercrimeDetails();
            }
            else
            {
                cout << "🤬🤬🤬Andhay instructions follow kr!!! 🤬🤬";
            }
            break;


        case 2:
            cout << "╔══════════════════════════════════════════════╗\n";
            cout << "║        📝  UPDATE CRIME RECORD               ║\n";
            cout << "╚══════════════════════════════════════════════╝\n";

            cout << "Enter 1 to Update Murder Status 🔪🔪\n";
            cout << "Enter 2 to Update Theft Status 🧱🪜\n";
            cout << "Enter 3 to Update Cybercrime Status 🎭🎭\n";

            int type;
            cout << "Please enter your choice: ✒️  ";
            cin >> type;

            if (type == 1)
                updateMurderStatus();
            else if (type == 2)
                updateTheftStatus();
            else if (type == 3)
                updateCybercrimeStatus();
            else
                cout << "🤬🤬🤬Andhay instructions follow kr!!! 🤬🤬\n";

            break;


        case 3:
            cout << "╔══════════════════════════════════════════════╗\n";
            cout << "║             👁️  VIEW CRIME RECORDS           ║\n";
            cout << "╚══════════════════════════════════════════════╝\n";

            viewAllCrime();
            break;

        case 4:
            cout << "╔══════════════════════════════════════════════╗\n";
            cout << "║        🔍  SEARCHING CRIME BY ID             ║\n";
            cout << "╚══════════════════════════════════════════════╝\n";

            cout << "Enter 1 to view murder cases 🔪🔪🔪\n 2 to view theft cases 🧱🪜 🪚 \n 3 for cybercrime. 🎭🎭🎭\n";
            int pick;
            cout << "Please enter your choice: ✒️  ";
            cin >> pick;

            if (pick == 1)
            {
                viewMurderByID();
            }
            else if (pick == 2)
            {
                viewTheftByID();
            }
            else if (pick == 3)
            {
                viewCybercrimeByID();
            }
            else
            {
                cout << "🤬🤬🤬Andhay instructions follow kr!!! 🤬🤬" << endl;
            }

            break;

        case 5:{
            cout << "╔══════════════════════════════════════════════╗\n";
            cout << "║          📊  VIEW CRIME STATISTICS            ║\n";
            cout << "╚══════════════════════════════════════════════╝\n";


            int murders = countCrimeCases("murder.txt");
            int thefts = countCrimeCases("theft.txt");
            int cyber = countCrimeCases("cybercrime.txt");

            cout << "Murder cases: " << murders << endl;
            cout << "Theft cases: " << thefts << endl;
            cout << "Cybercrime cases: " << cyber << endl;

            int total = murders + thefts + cyber;
            cout<<"Total number of cases : "<<total<<endl;

            break;
        }
        case 6:
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║   🚪 Logging out of ALIX System..    ║\n";
            cout << "║   Stay safe. Justice never sleeps.   ║\n";
            cout << "╚══════════════════════════════════════╝\n";
            logout();
            break;
        }
    }

    ~Officer()
    {
    }
};