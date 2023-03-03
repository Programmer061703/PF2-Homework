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

//Bianary search funtions 

int searchBianaryPasswords(int itterations,vector<Password> passwords, int max, int min, string search){
    
     
    if (min>max){
        return -1; 
    }
    int mid = min + (max - min) / 2; 

    if (search == passwords[mid].getPlaintext()){
        
        cout << "The value has been found and has gone through "<< itterations << " number of itterations"<<endl; 
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
        
       
        hash[mid].print();  
         cout << "The value has been found and has gone through "<< itterations << "Number of itterations" <<endl;

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

//Search Itterativly 
int searchItterative(int itterations, vector<Password> passwords, int max, int min, string search){
while (min <= max){
    int mid = min +(max - min)/2;

    if(search == passwords[mid].getPlaintext() ){
        passwords[mid].print();

        cout <<"This password was found after "<< itterations<<"number of itterations"<<endl; 

        return mid; 

    }

    if(search >passwords[mid].getPlaintext() ){
        min = mid + 1;
        itterations = itterations + 1; 
    }

    else{
        max = mid - 1;
        itterations = itterations + 1;
    }
     
}
return -1;
}

//Searches the list linearly, I tried usinga for loop to search the list but it would break it for some reason. So I just implamented a while loop the same way as a for loop and it fixed it 
//Why does this work but a for loop does not Lifes greatest mystery
int searchLinearly(int itterations, vector<Password> passwords, string search){
int x=0; 

while (x < passwords.size()){

    if (passwords[x].getPlaintext()==search){
        cout << "The password was found after "<<itterations<<" using a linear search"<<endl;
        passwords[x].print(); 
        break; 
    }
    x++;
    itterations++; 
}

return -1; 


 


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
     
    string Hinput; // Hash input
    string Pinput ; // Password input  
    switch(selection){
        case(1):
     

        break; 

        case(2):

        cout <<"Please input the password you wish to search for. *Note this will be faster than the itterative search*"<<endl; 
        cin >> Pinput;
        searchBianaryPasswords(0,password,password.size()-1,0,Pinput);

        break;

        case(3):
         cout << "Please input the hash you wish to search for"<<endl; 
        cin >> Hinput; 
        searchBianaryHashes(0,hash,hash.size()-1,0, stoi(Hinput,0,16) );
        break;

        case(4):

        cout << "Please input the password you wish to search for"<<endl;
        cout <<"Once input is provided the code will use a Bianary function to check for the password then use a itterative function to search for the same password"<<endl;
        cout <<"Each functions will give a number of itterations which corosponds to how many times calculations were done, fewer itterations better performance"<<endl;
        cin >> Pinput; 
        searchBianaryPasswords(0,password,password.size()-1,0,Pinput);

         searchLinearly(0,password,Pinput);

         

        
        break;

        case(5):
        cout << "Please input the password you wish to search itterativly for. *Note this will take longer than Bianary search*"<<endl;
        cin >> Pinput; 
          searchItterative(0,password,password.size()-1,0,Pinput);
        break;

        case(6):
        x=1;
        break;


}

    

}
return 0;
}
