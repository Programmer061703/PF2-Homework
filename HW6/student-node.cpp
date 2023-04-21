//This is the implementation file for the student class

#include "student-node.h"

//Default constructor
student_node::student_node(){

    head = NULL;
    next = NULL;
    full_name = "0";
    country = "0";
    city = "0";
    gpa = 0;
}

//Constructor

student_node::student_node(string full_name, string country, string city, string gender, double gpa){

    this->full_name = full_name;
    this->country = country;
    this->city = city;
    this->gender = gender;
    this->gpa = gpa;
    this->next = NULL;
}

//Destructor
student_node::~student_node(){

}

//getters
string student_node::getfull_name(){
    return full_name;
}

string student_node::getcountry(){
    return country;
}

string student_node::getcity(){
    return city;
}

string student_node::getgender(){
    return gender;
}

double student_node::getgpa(){
    return gpa;
}

student_node *student_node::getnext(){
    return next;
}

//setters
void student_node::setfull_name(string full_name){
    this->full_name = full_name;
}

void student_node::setcountry(string country){
    this->country = country;
}

void student_node::setcity(string city){
    this->city = city;
}

void student_node::setgender(string gender){
    this->gender = gender;
}

void student_node::setgpa(double gpa){
    this->gpa = gpa;
}

void student_node::setnext(student_node *next){
    this->next = next;
}

//print method
void student_node::print(){
    
    cout << "Full Name: " << full_name << ", ";
    cout << "Country: " << country << ", ";
    cout << "City: " << city << ", ";
    cout << "Gender: " << gender << ", ";
    cout << "GPA: " << gpa << endl;
    
    
    
}




