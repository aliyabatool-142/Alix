#include<windows.h>
#include<iostream>
#include<fstream>
#include <string>
#include "crime.h"
#include"theft.h"
#include"murder.h"
#include"cybercrime.h"
#include "admin.h"
#include "officer.h"
#include "viewer.h"
#include "criminal.h"
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);   // enable UTF-8 output

    int userID;
    int choice;
    string username;
    string password;
    cout<<endl;
    cout << "\n";
cout << "╔══════════════════════════════════════════════════════╗\n";
cout << "║                                                      ║\n";
cout << "║        █████╗ ██╗     ██╗██╗  ██╗                    ║\n";
cout << "║       ██╔══██╗██║     ██║╚██╗██╔╝                    ║\n";
cout << "║       ███████║██║     ██║ ╚███╔╝                     ║\n";
cout << "║       ██╔══██║██║     ██║ ██╔██╗                     ║\n";
cout << "║       ██║  ██║███████╗██║██╔╝ ██╗                    ║\n";
cout << "║       ╚═╝  ╚═╝╚══════╝╚═╝╚═╝  ╚═╝                    ║\n";
cout << "║                                                      ║\n";
cout << "║   ADVANCED LAW & INVESTIGATION EXCHANGE SYSTEM       ║\n";
cout << "║                                                      ║\n";
cout << "║        Developed by: Aliya & Alishba                 ║\n";
cout << "╚══════════════════════════════════════════════════════╝\n\n";

    
    cout<<"Enter User ID 👉  ";
    cin>>userID;
    cout<<"Enter User Name 👉  ";
    cin>>username;
    cout<<"Enter Password 👉  ";
    cin>>password;

   
    Admin a1(userID, username, password);
    Officer o1 (userID, username, password);
    Viewer v1 (userID, username, password);

    if(userID == 01 && username == "aliya" && password == "12345"){
        cout << "╭──────────────────────────────────────────────╮\n";
        cout << "│           👑  WELCOME, ALIYA                 │\n";
        cout << "│            Role: ADMINISTRATOR               │\n";
        cout << "╰──────────────────────────────────────────────╯\n\n";

        a1.menu();
        // a1.~Admin();
    }
    else if (userID == 02 && username == "alishba" && password == "67890"){
        cout << "╭──────────────────────────────────────────────╮\n";
        cout << "│          👮  WELCOME, ALISHBA                │\n";
        cout << "│              Role: OFFICER                   │\n";
        cout << "╰──────────────────────────────────────────────╯\n\n";

        o1.menu();
        // o1.~Officer();
    }
    else if (userID == userID && username == username && password == password){
        cout << "╭──────────────────────────────────────────────╮\n";
        cout << "│        👁️  WELCOME, RESPECTED USER            │\n";
        cout << "│             Role: VIEWER                     │\n";
        cout << "╰──────────────────────────────────────────────╯\n\n";

        v1.menu();
        // v1.~Viewer();
    }
    else{
        cout<<"Invalid credentials. Access denied. "<<endl;
    }
    
}
