#ifndef RESTAURANT_NODE_H
#define RESTAURANT_NODE_H

#include <iostream>
using namespace std; 

class RestNode
{
    public:
    RestNode();
    RestNode(string rest_name, float rest_rating, string meal_name, string type_meal, float price);
    RestNode(const RestNode & node); 
    ~RestNode();

    //Getter methods
    string getRest_Name();
    float getRest_Rating();
    string getMeal_Name();
    string getTyp_Meal();
    float getPrice();
    RestNode *getNext() const; 

    // Settters 

    void setRest_Name(string rest_name); 
    void setRest_Rating(float rest_rating);
    void setMeal_Name(string meal_name);
    void setTyp_Meal(string typ_meal); 
    void setPrice(float price);
    void setNext(RestNode * next); 

    void print() const; 

    private:
    string Rest_Name;
    float Rest_Rating; 
    string Meal_Name;
    string Typ_Meal; 
    float Price;
    RestNode *Next; 



};




#endif