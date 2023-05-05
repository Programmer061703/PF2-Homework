#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "book.h"
#include "tree.h"
using namespace std;

void readFile(const string filename, BinaryTree &tree){
    ifstream infile;
    infile.open(filename);
    if(infile.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }

    else{

        string Syear;
        string title;
        string authorLast;
        string authorFirst;
        string genre;
        string srating;

        // While loop that uses getline to read in the file with a delemator of a comma then appends the data to the vector

        while (getline (infile, Syear, ',')){
            getline (infile, title, ',');
            getline (infile, authorLast, ',');
            getline (infile, authorFirst, ',');
            getline (infile, genre, ',');
            getline (infile, srating, '\n');

            // Converts the string to an int and float

            int year = stoi(Syear);
            float rating = stof(srating);

            // Creates a new book object and appends it to the vector

            Book book(year, title, authorLast, authorFirst, genre, rating);
            tree.Insert(book);
            
            

        }

        infile.close();






    }
}



void menu(){

    cout<<"1. Load"<<endl;
    cout<<"2. Search"<<endl;
    cout<<"3. Insert"<<endl;
    cout<<"4. Delete"<<endl;
    cout<<"5. Print"<<endl;
    cout<<"6. Exit"<<endl;

}


int main(){
    
BinaryTree Tree;

int x = 0;
int count = 0;

    while(x != 1){
        int selection;
        menu();
        while(!(cin >> selection)){
    cout << "Please enter a valid number" << endl; 
    cin.clear();
    cin.ignore(123,'\n');
        }

    switch(selection){

    // Load

    case 1:
    {
        cout << "Enter the name of the file you would like to load" << endl;
        string filename;
        cin >> filename;
        readFile(filename, Tree);
        
        break;
    }
     case 2:
    {
        cout << "Enter the title of the book you would like to search for" << endl;
        string title;
        cin >> title;
        if(Tree.Search(title)){
            cout << "Book found" << endl;
        }
        else{
            cout << "Book not found" << endl;

        }
        
        break;
    }

    case 3:
    {
        cout << "Enter the title of the book you would like to insert" << endl;
        string title;
        cin >> title;
        if(Tree.Search(title)){
            cout << "Book already exists" << endl;
        }
        else{
            cout << "Enter the year of the book" << endl;
            int year;
            cin >> year;
            cout << "Enter the author's last name" << endl;
            string authorLast;
            cin >> authorLast;
            cout << "Enter the author's first name" << endl;
            string authorFirst;
            cin >> authorFirst;
            cout << "Enter the genre of the book" << endl;
            string genre;
            cin >> genre;
            cout << "Enter the rating of the book" << endl;
            float rating;
            cin >> rating;
            Book book(year, title, authorLast, authorFirst, genre, rating);
            Tree.Insert(book);
            //Tree.balance();
            cout << "Book inserted" << endl;
        }
        break;
    }

    case 4:
    {
        cout << "Enter the title of the book you would like to delete" << endl;
        string title;
        cin >> title;
        if(Tree.Search(title)){
            Tree.Delete(title);
            cout << "Book deleted" << endl;
        }
        else{
            cout << "Book not found" << endl;

        }
        break;
    }

    case 5:
    {
        Tree.Print();
        
        cout << "Number of books: " << Tree.Count() << endl;
        int h = Tree.Height();
        cout<< "Height of tree: " << h << endl;
        break;
    }

    case 6:
    {
        x = 1;
        break;
    }

    default:
    {
        cout << "Please enter a valid number" << endl;
        break;
    }

    }

   

    
}

return 0;
}