#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "book.h"
using namespace std;

void readFile(vector <Book> &books){
    ifstream infile;
    infile.open("books.csv");
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
            books.push_back(book);

        }

        infile.close();






    }
}



void writeFile(vector <Book> &books, string filename){
    ofstream outfile;
    outfile.open(filename);
    if(outfile.fail()){
        cout << "Error opening file" << endl;
        exit(1);
    }
    else{
        for(int i = 0; i < int(books.size()); i++){
            outfile << books[i].getYear() << ", ";
            outfile << books[i].getTitle() << ", ";
            outfile << books[i].getAuthorLast() << ", ";
            outfile << books[i].getAuthorFirst() << ", ";
            outfile << books[i].getGenre() << ", ";
            outfile << books[i].getRating() << endl;

        }

    }

    outfile.close();
}




int main(){



    
}