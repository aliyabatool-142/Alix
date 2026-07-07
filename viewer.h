#pragma once
#include <iostream>
#include "user.h"
#include"criminal.h"
using namespace std;
class Viewer : public User
{
public:
    Viewer(int userID, string userName, string password)
        : User(userID, userName, password, "Viewer")
    {
    }


    // void displayCriminalDetails(){
    //     string name;
    //     cout << "Enter Name of Criminal to view his/her crime record: ";
    //     cin >> name;

    //     ifstream fin("criminal.txt");
    //     if (!fin.is_open())
    //     {
    //         cout << "File not found!\n";
    //         return;
    //     }

    //     string line;
    //     bool found = false;

    //     while (getline(fin, line))
    //     {

    //         // Find position of first '|'
    //         size_t pos = line.find('|');
    //         if (pos == string::npos)
    //             continue; // skip invalid lines

    //         // Extract crimeID from the line
    //         string crimeNameInFile = line.substr(0, pos);

    //         if (crimeNameInFile == name)
    //         {
    //             cout << "\n*********** CRIME RECORD FOUND ***********\n";
    //             cout << line << endl;
    //             cout << "***********************************\n";
    //             found = true;
    //             break; // no need to check more lines
    //         }
    //     }

    //     fin.close();

    //     if (!found)
    //         cout << "Crime Record not found.\n";

    // }


    void menu() override
    {   cout << "1️⃣  View Solved Cases Only\n";
        cout << "2️⃣  Search Criminals By Name\n";
        cout<<  "3️⃣  logout\n";
        cout << "💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠" << endl;
        int choice;
        cout << "Please enter your choice: ✒️  ";
        cin>>choice;

        if(choice == 1){

        int select;
            cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";
            cout << "       👁️   Viewing Solved Cases         \n";
            cout << "◆━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◆\n";
        cout << " Enter 1 for Murder 🔪🔪🔪 \n Enter 2 for Theft 🧱🪜 🪚\n Enter 3 for Cybercrime 🎭🎭🎭\n";
        cout<<"💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠💠 \n";
        cout << "Please enter your choice: ✒️  ";
        cin >> select;

        switch (select)
        {
        case 1:
            cout << "╭──────────────────────────────────────────────╮\n";
            cout << "│               🔪  MURDER CASES               │\n";
            cout << "╰──────────────────────────────────────────────╯\n";

            system("murder.txt");
            break;

        case 2:
            cout << "╭──────────────────────────────────────────────╮\n";
            cout << "│               🛍️  THEFT CASES                │\n";
            cout << "╰──────────────────────────────────────────────╯\n";

            system(" theft.txt ");
            break;

        case 3:
            cout << "╭──────────────────────────────────────────────╮\n";
            cout << "│             💻  CYBERCRIME CASES             │\n";
            cout << "╰──────────────────────────────────────────────╯\n";
            system("cybercrime.txt ");
            break;

        default:

            cout<<"Invalid choice.\n";
        }
        }

        else if(choice == 2){
           Criminal cr1;
            cr1.displayCriminalDetails();

        }

        else if(choice == 3){
            cout << "╔══════════════════════════════════════╗\n";
            cout << "║   🚪 Logging out of ALIX System..    ║\n";
            cout << "║   Stay safe. Justice never sleeps.   ║\n";
            cout << "╚══════════════════════════════════════╝\n";
            logout();
            return;

        }
        else{
             cout << "🤬🤬🤬Andhay instructions follow kr!!! 🤬🤬" << endl;
        }

        
    }

    ~Viewer()
    {
    }
};