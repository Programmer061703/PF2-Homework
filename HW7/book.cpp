#include "book.h"

Book::Book(){
    year = 0;
    title = "0";
    authorLast = "0";
    authorFirst = "0";
    genre = "0";
    rating = 0;
}

Book::Book(int year, string title, string authorLast, string authorFirst, string genre, float rating){
    this->year = year;
    this->title = title;
    this->authorLast = authorLast;
    this->authorFirst = authorFirst;
    this->genre = genre;
    this->rating = rating;
}

Book::Book(const Book &copy){
    year = copy.year;
    title = copy.title;
    authorLast = copy.authorLast;
    authorFirst = copy.authorFirst;
    genre = copy.genre;
    rating = copy.rating;
}

Book::~Book(){

}

void Book::setYear(const int year){
    this->year = year;
}

void Book::setTitle(const string title){
    this->title = title;
}

void Book::setAuthorLast(const string authorLast){
    this->authorLast = authorLast;
}

void Book::setAuthorFirst(const string authorFirst){
    this->authorFirst = authorFirst;
}

void Book::setGenre(const string genre){
    this->genre = genre;
}

void Book::setRating(const int rating){
    this->rating = rating;
}       

int Book::getYear(){
    return year;
}

string Book::getTitle(){
    return title;
}

string Book::getAuthorLast(){
    return authorLast;
}

string Book::getAuthorFirst(){
    return authorFirst;
}

string Book::getGenre(){
    return genre;
}

float Book::getRating(){
    return rating;
}

void Book::print(){
    cout << "Year: " << getYear() << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Author's Last Name: " << getAuthorLast() << endl;
    cout << "Author's First Name: " << getAuthorFirst() << endl;
    cout << "Genre: " << getGenre() << endl;
    cout << "Rating: " << getRating() << endl;
}




