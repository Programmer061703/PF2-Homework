

#ifndef STUDENT_NODE_H
#define STUDENT_NODE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

// Create the container class called student-node which will be used to create a linked list of students.

class student_node
{

//Public contains the functions that can be used by the user 


public:

//Constructor
    student_node();
    student_node(string full_name, string country, string city, string gender, double gpa);


//Destructor
    ~student_node();



//getters
string get_full_name();
string get_country();
string get_city();
string get_gender();
double get_gpa();
student_node *get_next();

//setters
void set_full_name(string full_name);
void set_country(string country);
void set_city(string city);
void set_gender(string gender);
void set_gpa(double gpa);
void set_next(student_node *next);

//print method

void print();








private:
//Private atributes are full name (key), country, city, gender, gpa,and a next pointer.

    string full_name;
    string country;
    string city;
    string gender;
    double gpa;
    student_node *next;
    student_node *head;






};

#endif

