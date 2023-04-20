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
string student_node::get_full_name(){
    return full_name;
}

string student_node::get_country(){
    return country;
}

string student_node::get_city(){
    return city;
}

string student_node::get_gender(){
    return gender;
}

double student_node::get_gpa(){
    return gpa;
}

student_node *student_node::get_next(){
    return next;
}

//setters
void student_node::set_full_name(string full_name){
    this->full_name = full_name;
}

void student_node::set_country(string country){
    this->country = country;
}

void student_node::set_city(string city){
    this->city = city;
}

void student_node::set_gender(string gender){
    this->gender = gender;
}

void student_node::set_gpa(double gpa){
    this->gpa = gpa;
}

void student_node::set_next(student_node *next){
    this->next = next;
}

//print method
void student_node::print(){
    cout << "Full Name: " << full_name << endl;
    cout << "Country: " << country << endl;
    cout << "City: " << city << endl;
    cout << "Gender: " << gender <<endl;
    cout << "GPA: " << gpa << endl;
    
}




