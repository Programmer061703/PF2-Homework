//----------------------------------------------
// Purpose: Starter code for homework 3 - you should use this code 
// to read in your files instead of starting from scratch!
//----------------------------------------------

#include "password.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// PROVIDED
bool readFile(string filename, vector<Password> &list)
{
    string password;
    string rank;
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din, password, ','))
    {
        getline(din, rank, ',');
        getline(din, hash);
        Password temp (password,stoi(rank),hash);
        list.push_back(temp);
    }
    din.close();
    return 1;
}
// PROVIDED
bool readFile_given_hashes(string filename, vector<string> &list)
{
    string hash;

    ifstream din;
    din.open(filename);
    if(din.fail()){
        cout << "Error in opening file.\n";
        return 0;
    }
    while(getline(din,hash)){
        list.push_back(hash);
    }
    return 1;
}

void menu(){
    cout << endl; 
    cout << "Welcome to the restraunt database"<<endl;
    cout << "Press 1 to add a Meal"<<endl; 
    cout << "Press 2 to search for the highest price"<<endl; 
    cout <<"Press 3 to change the price of a specific meal"<<endl;
    cout <<"Press 4 to print the database"<<endl;
    cout <<"Press 5 to exit the database"<<endl; 
}






//----------------------------------------------
int main()
{
    int x = 1;
    //vector for hash sorted file
    vector<Password> hash;
    //vector for password sorted file
    vector<Password> password;
    //vector for hashes to search for
    vector<string> given_hashes;

    readFile("sorted_hash_indexed_list.txt",hash);
    readFile("sorted_password_indexed_list.txt",password);
    readFile_given_hashes("hashes_to_search.txt",given_hashes);




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
     

        break; 

        case(2):
        

        break;

        case(3):
         
        break;

        case(4):
        
        break;

        case(5):
         
        break;

        case(6):
        x=1;
        break;


}

    return 0;

}
}
