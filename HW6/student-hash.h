#ifndef STUDENT_HASH_H
#define STUDENT_HASH_H

#include "student-list.h"
#include "student-node.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class student_hash
{

public:
student_hash(int size);
student_hash(const student_hash &copy);
~student_hash();

//Insert method
bool insert(string full_name, string country, string city, string gender, double gpa);
//Search method
bool search(string full_name);
//Delete method
bool deleteNode(string full_name);
//Update method
bool update(string full_name, string country, string city, string gender, double gpa);
//Print method
void print();



private:
int Hash(string full_name);
int Hash2(int index);

int size;
student_list *table;

};

#endif