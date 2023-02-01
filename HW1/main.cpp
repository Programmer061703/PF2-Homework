#include "pinball.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
const int MAX = 10; 
Pinball Machine[MAX]; 
 

void printMenu(){
    cout << "\nWelcome to Pinball world please view our options bellow"<<endl; 
    cout << "Select 1 to load machines from stored ascii file "<<endl;
    cout << "Select 2 to insert a machine of your choice "<<endl;
    cout << "Select 3 to find a machine of a specific year"<<endl; 
    cout << "Select 4 to print out the information of all machines"<<endl;
    cout << "Select 5 to exit the program"<<endl;
}

void readFile ( string filename, Pinball Temp[MAX]){
    // open the file, check for failed
    int y = 0;
    ifstream din;
    din.open(filename);

    if (din.fail()) {
        cout << "File failed to load"<<endl;
        return;

    }
    //declare local temp class variables for reading in the data
    string mach_name;

    int year_prod;
    string year_prod_string; // Required for the getline to function as it only takes in string values 
    string manu;

    float fun_rating;
    string fun_rating_string;
    string theme;
    while (!din.eof()) {
        // reading data and ignoring other data
        getline(din, mach_name, ',');
        
        getline(din, year_prod_string, ','); 
        year_prod = stoi(year_prod_string); 
        getline(din,manu,',');
        getline(din,fun_rating_string ,',');
        fun_rating = stof(fun_rating_string); 
        getline(din,theme);


        
        
     Pinball newPinball(mach_name,year_prod,manu,fun_rating,theme);
    Temp[y]=newPinball;
    y++;

            
        

    }


din.close();
    


}

void addMachine( string newMach_name,string newYear_prodString, string newManu, string newFun_ratingString, string newtheme ){
int newYear_prod;
float newFun_rating;

newYear_prod = stoi(newYear_prodString);
newFun_rating = stof(newFun_ratingString);

Pinball newMachine(newMach_name,newYear_prod,newManu,newFun_rating,newtheme);
for(int i=0; i < MAX; i++){
    if (Machine[i].getMach_name() == "0"){
        Machine[i] = newMachine; 
        return; 
    } 
}

    
}




int main (){
int x = 0; 
int selection = 0; 

string newMach_name;
string newYear_prodString;
string newManu;
string newFun_ratingString;
string newTheme;
string new_file; 


while (x !=1){

printMenu();

cin >> selection; 

switch (selection)
{
// Case 1 loads machines from ascii file
case(1):
    cout << "Please input the name of the file you wish to process"<<endl; 
    cin >> new_file; 
    readFile(new_file,Machine); 
    break;
// Case 2 insert machine of your choice
case(2):
    cout << "Input NewMachine name, year produced, manufacturere, funrating, themes all on one line seperated by commas like showed previously "<<endl;
    getline(cin,newMach_name,',');
   
    getline(cin,newYear_prodString,',');
    
    getline(cin,newManu,',');
    
    getline(cin,newFun_ratingString,',');
    
    getline(cin,newTheme);
    addMachine(newMach_name,newYear_prodString,newManu,newFun_ratingString,newTheme); 
    
    break;
// Case 3 find machine of specific year
case (3):
int year;
cout <<"Please input the specific year you wish to find";
cin >> year; 
for (int i = 0; i < MAX; i++){
    if (Machine[i].getYear_prod() == year){
        Machine[i].print(); 
    }
}
 

    break;
// Case 4 print out all information of all machines, gonna use for loop to itterate through the array
case (4):
cout <<"Entered print statment"<<endl; 
//for(int i; i<10; i++){

for(int i=0; i < MAX; i++){
Machine[i].print();

}
//}
    break;
// Case 5 exit code
case (5):
    x = 1; 
    break; 
}
    
}


}