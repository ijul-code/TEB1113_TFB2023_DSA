/*
ID=22011325
Name: Izzul Muhaimie Bin Badrul Ikhwan
*/

#include <iostream>
using namespace std;

struct student{
    string id;
    string name;
    string contact;
    string email;
    
    
};

int main(){
    student student[5];
    for (int i= 0; i<5; i++){
        cout << "Enter details for Student " << (i + 1) << ":\n";
        
        cout << "Enter Student ID: ";
        cin >> student[i].id;
        
        cout << "Enter Name (no spaces): ";
        cin >> student[i].name;
        
        cout << "Enter Contact: ";
        cin >> student[i].contact;
        
        cout << "Enter Email: ";
        cin >> student[i].email;

        cout << endl;
    }
    
     cout << "\nStudent Details:\n";
    for (int i = 0; i < 5; i++) {
        cout << "**************************" << "\n";
        cout << "Student " << (i + 1) << ":\n";
        cout << "ID: " << student[i].id << "\n";
        cout << "Name: " << student[i].name << "\n";
        cout << "Contact: " << student[i].contact << "\n";
        cout << "Email: " << student[i].email << "\n";
        cout << "**************************" << "\n\n";

    }
    return 0;
    
}
