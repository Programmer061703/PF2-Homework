

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
string getfull_name();
string getcountry();
string getcity();
string getgender();
double getgpa();
student_node *getnext();

//setters
void setfull_name(string full_name);
void setcountry(string country);
void setcity(string city);
void setgender(string gender);
void setgpa(double gpa);
void setnext(student_node *next);

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

