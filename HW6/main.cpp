#include "student-hash.h"
#include <iostream>
#include "student-list.h"
#include "student-node.h"
#include <cstdlib>
#include <fstream>
using namespace std;


// Write a read file function that takes in the name of a file and reads it to a hash table.

void read(student_hash &table){

    string full_name;
    string country;
    string city;
    string gender;
    string gpa_string;
    string filename;
    
    int length = 100;
    

    ifstream infile;
    cout << "Enter the name of the file: ";
    
    cin >> filename;
    infile.open(filename);

    if(infile.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }

    for(int i = 0; i < length; i++){

        getline(infile, full_name, ',');
        getline(infile, country, ',');
        getline(infile,city,',');
        getline(infile,gender,',');
        getline(infile,gpa_string,'\n');
        table.insert(full_name,country,city,gender,stof(gpa_string));
    }


}

//Creates a menu for the user to choose from

void menu(){

    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Update"<<endl;
    cout<<"4. Search"<<endl;
    cout<<"5. Print"<<endl;
    cout<<"6. Exit"<<endl;

}


int main(){

    int table_size = 0;
    cout<<"Enter the size of the hash table: ";
    cin>>table_size;


    student_hash table(table_size);

    read(table);

//The main program will also have six menu options that are insert, delete, update, search, print and exit

    
    string name;
    string country;
    string city;
    string gender;
    double gpa;
    int x = 0;

    // 6 case switch statment

    while(x != 1){
        int selection;
        menu();
        while(!(cin >> selection)){
    cout << "Please enter a valid number" << endl; 
    cin.clear();
    cin.ignore(123,'\n');
        }

    switch(selection){

        case(1):
            //Insert
            cin.ignore();
            cout << "Enter the name of the student: "<<endl;
            getline(cin,name);
            cout << "Enter the country of the student: "<<endl;
            getline(cin,country);
            cout << "Enter the city of the student: "<<endl;
            getline(cin,city);
            cout << "Enter the gender of the student:"<<endl;
            cin >> gender;
            cout << "Enter the gpa of the student: "<<endl;
            cin >> gpa;
            //Inserts the given data into the hash table
            table.insert(name,country,city,gender,gpa);
            break;

        case(2):
            //Delete
            cin.ignore();
            cout << "Enter the name of the student: "<<endl;
            getline(cin,name);
            //Deletes the given data from the hash table
            table.deleteNode(name);
            break;

        case(3):
        cin.ignore();
        cout << "Enter the name of the student: "<<endl;
        getline(cin,name);
        cout << "Enter the country of the student: "<<endl;
        getline(cin,country);
        cout << "Enter the city of the student: "<<endl;
        getline(cin,city);
        cout << "Enter the gender of the student: "<<endl;
        getline(cin,gender);
        cout << "Enter the gpa of the student: "<<endl;
        cin >> gpa;
        //Updates the given data from the hash table
        table.update(name,country,city,gender,gpa);
        break;

        case(4):
            //Search
            cin.ignore();
            cout << "Enter the name of the student: "<<endl;
            getline(cin,name);
            //Searches the given data from the hash table
            table.search(name);
            break;

        case(5):
            //Print
            table.print();
            break;

        case(6):
            //Exit
            x = 1;
            break;

    }







    }

    







    




    }