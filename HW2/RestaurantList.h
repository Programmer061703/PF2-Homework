#ifndef RESTAURANT_LIST_H
#define RESTAURANT_LIST_H


#include "RestaurantNode.h"
#include<iostream>
using namespace std; 


class RestaurantList
{



public:
    RestaurantList();
    RestaurantList(const RestaurantList & copy);
    ~RestaurantList();

    //insert method
    void insertTail(string rest_name, float rest_rating, string meal_name, string typ_meal, float price);
    //Highest price
    bool searchHigh(float price); 
    //Change Price
    void changePrice(string meal,float price); 
    //Print
    void print() const; 

private:
    RestNode * Head; 
    
};

















#endif