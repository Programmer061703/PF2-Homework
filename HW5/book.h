// I need to make a book class Year Title, Author's last name, Author's first name, Genre, Rating
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Book{
private:
    int year;
    string title;
    string authorLast;
    string authorFirst;
    string genre;
    int rating;
public:
    Book();
    Book(int year, string title, string authorLast, string authorFirst, string genere, int rating);
    Book(const Book& copy);
    ~Book();

    void setYear(int year);
    void setTitle(string title);
    void setAuthorLast(string authorLast);
    void setAuthorFirst(string authorFirst);
    void setGenre(string genere);
    void setRating(int rating);
    int getYear();

    string getTitle();
    string getAuthorLast();
    string getAuthorFirst();
    string getGenre();
    int getRating();
    void print();
};

#endif
