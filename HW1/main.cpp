#include "pinball.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
const int MAX = 1000; 
Pinball Machine[MAX]; 
int x = 0; 

void printMenu(){
    cout << "\nWelcome to Pinball world please view our options bellow"<<endl; 
    cout << "Select 1 to load machines from stored ascii file "<<endl;
    cout << "Select 2 to insert a machine of your choice "<<endl;
    cout << "Select 3 to find a machine of a specific year"<<endl; 
    cout << "Select 4 to print out the information of all machines"<<endl;
    cout << "Select 5 to exit the program"<<endl;
}

void readFile (const string filename, Pinball Temp[MAX]){
    // open the file, check for failed

    ifstream din;
    din.open(filename.c_str());

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
        if (!din.eof()){
            

            
        }

    }



    


}





int main (){
int x = 0; 
int selection = 0; 



while (x !=1){

printMenu();

while (!(cin >> selection)){
    cout << "Enter a valid number"<<endl; 
    cin.clear();
    cin.ignore(123,'\n');
}

switch (selection)
{
// Case 1 loads machines from ascii file
case(1):

    break;
// Case 2 insert machine of your choice
case(2):

    break;
// Case 3 find machine of specific year
case (3):

    break;
// Case 4 print out all information of all machines, gonna use for loop to itterate through the array
case (4):

    break;
// Case 5 exit code
case (5):

    break; 
}
    
}


}