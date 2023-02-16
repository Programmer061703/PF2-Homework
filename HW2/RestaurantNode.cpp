#include "RestaurantNode.h"



RestNode::RestNode(){
    Rest_Name = " "; 
    Rest_Rating = 0;
    Meal_Name = " ";
    Typ_Meal = " "; 
    Price = 0; 
    Next = NULL;



}
RestNode::RestNode(string rest_name, float rest_rating, string meal_name, string type_meal, float price){
    Rest_Name = rest_name; 
    Rest_Rating = rest_rating;
    Meal_Name =meal_name;
    Typ_Meal = type_meal; 
    Price = price; 
    Next = NULL; 
    
}
RestNode::RestNode(const RestNode & copy){

    Rest_Name = copy.Rest_Name; 
    Rest_Rating = copy.Rest_Rating;
    Meal_Name = copy.Meal_Name;
    Typ_Meal = copy.Typ_Meal;
    Price = copy.Price; 
    Next = copy.Next; 



}
 RestNode::~RestNode(){

 }

 //Getter methods
 string RestNode::getRest_Name(){
    return Rest_Name;

 }
 float RestNode::getRest_Rating(){
    return Rest_Rating;
 }
 string RestNode::getMeal_Name(){
    return Meal_Name; 
 }
 string RestNode::getTyp_Meal(){
    return Typ_Meal;
 }
 float RestNode::getPrice(){
    return Price; 
 }
 RestNode *RestNode::getNext() const{
    return Next; 
 }


 // Settters 

void RestNode::setRest_Name(string rest_name){
    Rest_Name = rest_name;
}
void RestNode::setRest_Rating(float rest_rating){
    Rest_Rating = rest_rating; 
}
void RestNode::setMeal_Name(string meal_name){
    Meal_Name = meal_name;
}
void RestNode::setTyp_Meal(string typ_meal){
    Typ_Meal = typ_meal; 
} 
void RestNode::setPrice(float price){
    Price = price; 
}
void RestNode::setNext(RestNode * next){
    Next = next; 
}


void RestNode::print() const{
cout << "Restaurant Name: "<< Rest_Name << endl
    << "Rating: "<<endl << Rest_Rating << "Meal Name: "<< Meal_Name <<endl<< "Type of Meal "<<Typ_Meal <<endl << "Price: "<< Price << endl; 
}
