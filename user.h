
#pragma once
#include <iostream>
#include<string>
using namespace std;
class User{
private:
    int userID;
    string username;
    string password;
    string role;  

public:
User(int userID, string userName, string password, string role){
    this-> userID = userID;
    this-> username = userName;
    this-> password = password;
    this-> role = role;
}
   
virtual void menu() = 0;
//  ~User ();

void logout() {
    cout << "\nLogging out...\n";
    system("pause");
    system("cls");   // clear screen
}



};