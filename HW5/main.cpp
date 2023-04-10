

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


// Insertion function that sorting based off year then calls the writeFile to write the vector into a file called insertion.csv

void insertionSort(vector <Book> &books, int low, int high){

    for(int i = low +1; i <= high; i++){

        Book temp = books[i];
        int yVal = temp.getYear();

        int pos = i; 

while((pos > 0) && (books[pos-1].getYear() > yVal)){
        books[pos].setYear(books[i-1].getYear());
        books[pos].setTitle(books[i-1].getTitle());
        books[pos].setAuthorLast(books[i-1].getAuthorLast());
        books[pos].setAuthorFirst(books[i-1].getAuthorFirst());
        books[pos].setGenre(books[i-1].getGenre());
        books[pos].setRating(books[i-1].getRating());
        pos--;
    }
    
    
    books[pos] = temp;    
    }
}

//Selection sort function that sorts based off the first name of the author then calls the writeFile to write the vector into a file called selection.csv

void selectionSort(vector <Book> &books, int low, int high){
    for(int i = low; i < high; i++){
        int min = i;
        for(int j = i + 1; j < high; j++){
            if(books[j].getAuthorFirst() < books[min].getAuthorFirst()){
                min = j;
            }
        }
        Book temp = books[i];
        books[i] = books[min];
        books[min] = temp;
    }
   
}



void partition(vector <Book> &books, int low, int high, int &mid){
    
    Book pivot = books[low];

    int l = low;
    int r = high;

    while(l <= r){
        while((l<r) && (books.at(l).getAuthorLast() < pivot.getAuthorLast()))
            l++;
        
        while((l<r) && (books.at(r).getAuthorLast() >= pivot.getAuthorLast()))
            r--;
        
        
    // swap data values
    Book temp = books.at(l);
    books.at(l) = books.at(r);
    books.at(r) = temp;

   

    }

    mid = l;
    books.at(high) = books.at(mid);
    books.at(mid) = pivot;
}


void quickSort(vector <Book> &books, int low, int high){
    
    if(low < high){
        int mid = 0;
        partition(books, low, high, mid);
        quickSort(books, low, mid - 1);
        quickSort(books, mid + 1, high);
    }
    
}





int main(){
vector <Book> books;





readFile(books);

insertionSort(books, 0, books.size());
writeFile(books, "insertion.csv");

    cout << "Insertion sort complete" << endl;
readFile(books);

selectionSort(books, 0, books.size());
 writeFile(books, "selection.csv");

cout << "Selection sort complete" << endl;

readFile(books);

quickSort(books, 0, books.size() - 1);
writeFile(books, "quick.csv");

cout << "Quick sort complete" << endl;
readFile(books);

    
    



}














