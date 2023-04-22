#include "student-hash.h"
#include "student-node.h"

student_hash::student_hash(int size){
    this->size = size;
    this->collisions = 0;
    table = new student_list[size];
    // for loop that creates a new student_list for each index in the table
    for(int i = 0; i < size; i++){
        table[i] = student_list();
    }

}

student_hash::student_hash(const student_hash &copy){
    size = copy.size;
    table = new student_list[size];
    for(int i = 0; i < size; i++){
        table[i] = copy.table[i];
    }
}

student_hash::~student_hash(){
    delete [] table;
    table = NULL;
    size = 0;

}

//Insert method

bool student_hash::insert(string full_name, string country, string city, string gender, double gpa){

    int index = Hash(full_name);
    //table[index].insertNode(full_name,country,city,gender,gpa);
    collisions += table[index].insertNode(full_name,country,city,gender,gpa);

    return true;

}

//Search method

bool student_hash::search(string full_name){

    int index = Hash(full_name);
    return table[index].searchNodes(full_name);

}

//Delete method

bool student_hash::deleteNode(string full_name){

    int index = Hash(full_name);
    return table[index].deleteNode(full_name);

}

//Update method

bool student_hash::update(string full_name, string country, string city, string gender, double gpa){
    int index = Hash(full_name);
    return table[index].updateNodes(full_name,country,city,gender,gpa);


}

//Print method

void student_hash::print(){
    for(int i = 0; i < size; i++){
        cout << "Index " << i << ":"<< endl;
        table[i].printNodes();
        cout << endl;
    }
    cout << "Total collisions: " << collisions << endl;

}

int student_hash::Hash(string full_name){
    int index = 0;
    for(unsigned int i = 0; i < full_name.length(); i++){
        index += full_name[i];
    }
    index = index % size;
    return index;
}


