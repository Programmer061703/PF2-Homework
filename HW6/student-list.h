//The Student List header file
//Implement default constructor, copy constructor, destructor along with insert, delete, update, search, and print methods.
// This is the headerclass file for the student list class

#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "student-node.h"

#include <iostream>
using namespace std;

class student_list
{
//Default constructrr
public:

//Constructor
    student_list();
    student_list(const student_list &copy);
//Destructor
    ~student_list();

//Insert method
int insertNode(string full_name, string country, string city, string gender, double gpa);
//Delete method
bool deleteNode(string full_name);
//Update method
bool updateNodes(string full_name, string country, string city, string gender, double gpa);
//Search method
bool searchNodes(string full_name);
//Print method
void printNodes();
// Num of collisions
int numCollisions();


//Get head
student_node *getHead();

private:
    student_node *head;
};


#endif

