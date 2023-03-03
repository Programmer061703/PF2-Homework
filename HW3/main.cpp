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
    cout << "Welcome to the Password database"<<endl;
    cout << "1)Search recursively two passwords and pull all the passwords between them"<<endl; 
    cout << "2)Search recursively by password"<<endl; 
    cout <<" 3)Search recursively of given file by hash"<<endl;
    cout <<" 4)Compare linear and binary search"<<endl;
    cout <<" 5)Iterative binary search for password"<<endl; 
    cout <<" 6)Exit system"<<endl; 
}

//Single recursvie bianary search

int searchBianaryPasswords(int itterations,vector<Password> passwords, int max, int min, string search){
    
     
    if (min>=max){
        return -1; 
    }
    int mid = min + (max - min) / 2; 

    if (search == passwords[mid].getPlaintext()){
        
        cout << "The value has been found at the middle of the list and has gone through"<< itterations << "To finish this function call"<<endl; 
        passwords[mid].print(); 

        return mid; 

    }
    //Search Left side
    if(search < passwords[mid].getPlaintext()){

        return searchBianaryPasswords(itterations + 1, passwords, mid - 1, min, search);
    }

    //Search Right side
    if(search > passwords[mid].getPlaintext()){

        return searchBianaryPasswords(itterations + 1, passwords, max, mid + 1, search);

    }
    
 
    
}

int searchBianaryHashes(int itterations,vector<Password>hash, int max, int min, int search){

 
    if (min>=max){
        return -1; 
    }
    int mid = min + (max - min) / 2; 

    if (search == stoi(hash[mid].getHash(),0,16)){
        
        cout << "The value has been found and has gone through "<< itterations << "To finish this function call"<<endl;
        hash[mid].print();  

        return mid; 

    }
    //Search Left side
    if(search < stoi(hash[mid].getHash(),0,16)){

        return searchBianaryHashes(itterations + 1, hash, mid - 1, min, search);
    }

    //Search Right side
    if(search > stoi(hash[mid].getHash(),0,16)){

        return searchBianaryHashes(itterations + 1, hash, max, mid + 1, search);

    }
    
      
}

int searchItterative(int itterations, vector<Password> passwords, int){

}

//int searchItterativePassowrd(int itterations )

//----------------------------------------------
int main()
{
    int num_itter = 0;
    int x = 0;
    //vector for hash sorted file
    vector<Password> hash;
    //vector for password sorted file
    vector<Password> password;
    //vector for hashes to search for
    vector<string> given_hashes;

    readFile("sorted_hashe_index_list.txt",hash);
    readFile("sorted_passwords_index_list.txt",password);
    readFile_given_hashes("hashes_to_search.txt",given_hashes);




   while(x != 1){
        int selection;
        menu();
        while(!(cin >> selection)){
    cout << "Please enter a valid number" << endl; 
    cin.clear();
    cin.ignore(123,'\n');
        }
     
    string Hinput;
    string Pinput;
    switch(selection){
        case(1):
     

        break; 

        case(2):

        cin >> Pinput;
        searchBianaryPasswords(0,password,password.size()-1,0,Pinput);

        break;

        case(3):
         
        cin >> Hinput; 
        searchBianaryHashes(0,hash,hash.size()-1,0, stoi(Hinput,0,16) );
        break;

        case(4):
        
        break;

        case(5):
         
        break;

        case(6):
        x=1;
        break;


}

    

}
return 0;
}
