#include "student-list.h"

#include <iostream>

using namespace std;

student_list::student_list()
{
    head = NULL;
}

student_list::student_list(const student_list &copy)
{
    head = NULL;
    student_node *temp = copy.head;
    while(temp != NULL)
    {
        insertNode(temp->getfull_name(), temp->getcountry(), temp->getcity(), temp->getgender(), temp->getgpa());
        temp = temp->getnext();
    }
}

student_list::~student_list()
{
    student_node *temp = head;
    while(temp != NULL)
    {
        student_node *temp2 = temp;
        temp = temp->getnext();
        delete temp2;
    }
}


//Insert method

int student_list::insertNode(string full_name, string country, string city, string gender, double gpa){

//Find tail node
int collision = 0;


student_node *temp = head;
student_node *tail = NULL;
while(temp != NULL)
{
    tail = temp;
    collision++;
    temp = temp->getnext();

}

//Insert new node

if(tail != NULL){
    

    tail->setnext(new student_node(full_name,country,city,gender,gpa));
   
}

else{
    
    head = new student_node(full_name,country,city,gender,gpa); 

}
return collision; 
    
    }

//Search method

bool student_list::searchNodes(string full_name){


    student_node *temp = head;
    while(temp != NULL)
    {
        if(temp->getfull_name() == full_name)
        {
            cout<<"Found node"<<endl;
            //Print the node
            temp->print();

            return true;
        }
        temp = temp->getnext();
    }

    cout<<"Node not found"<<endl;
    return false;
}


//Delete method

bool student_list::deleteNode(string full_name){

    student_node *temp = head;
    student_node *prev = NULL;
    while(temp != NULL)
    {
        if(temp->getfull_name() == full_name)
        {
            cout<<"Deleting node"<<endl;
            if(prev != NULL)
            {
                prev->setnext(temp->getnext());
            }
            else
            {
                head = temp->getnext();
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->getnext();
    }

    cout<<"Node not found"<<endl;
    return false;
}

//Update method

bool student_list::updateNodes(string full_name, string country, string city, string gender, double gpa){

//Find node by full_name
student_node *temp = head;

while(temp -> getfull_name() != full_name){
    temp = temp -> getnext();

}
if(temp == NULL){
    cout<<"Node not found"<<endl;
    return false;
}
else{

    
    cout<<"Updating node"<<endl;

    temp -> setfull_name(full_name);
    temp -> setcountry(country);
    temp -> setcity(city);
    temp -> setgender(gender);
    temp -> setgpa(gpa);

    return true;

}

}

//Print method

void student_list::printNodes(){

    student_node *temp = head;
    while(temp != NULL)
    {
        temp->print();
        temp = temp->getnext();
    }

}

int student_list::numCollisions(){

    int count = 0;
    student_node *temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->getnext();
    }
    return count;


}