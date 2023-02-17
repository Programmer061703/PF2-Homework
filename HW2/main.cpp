#include"RestaurantList.h"
#include<iostream>
#include <string>
using namespace std; 



void addMeal(RestaurantList &meal){
    string name, meal_name,meal_type, str_rating, str_price;
    float rating, price; 
    cout << "Input the name of the Restaurant"<<endl; 
    getline(cin>>ws,name);
    cout <<"Input the Rating of the Restaurant"<<endl; 
    cin >> rating; 
    cout <<"Input the Name of the Meal"<<endl; 
    getline(cin>>ws,meal_name);
    cout <<"Input the Meal type"<<endl; 
    getline(cin>>ws,meal_type);
    cout <<"Input the Price"<<endl;
    cin >> price; 


    
    meal.insertTail(name,rating,meal_name,meal_type,price);

    cout <<"Added Meal Succefully"<<endl; 


}

void change_price(RestaurantList &meal){
    string name_meal;
    float price;

    cout << "Please input the name of the meal you wish to change"<<endl; 
    getline(cin>>ws,name_meal);
    cout <<"Please input the price you wish to change this meal to"<<endl; 
    cin >> price;
    meal.changePrice(name_meal,price); 
    cout << name_meal<<" Price sucesfuly changed to $" << price <<endl; 
}

void menu(){
    cout << "Welcome to the restraunt database"<<endl;
    cout << "Press 1 to add a Meal"<<endl; 
    cout << "Press 2 to search for the highest price"<<endl; 
    cout <<"Press 3 to change the price of a specific meal"<<endl;
    cout <<"Press 4 to print the database"<<endl;
    cout <<"Press 5 to exit the database"<<endl; 
}





int main(){
    int x = 0;

    
    RestaurantList meal;


    

    while(x != 1){
        int selection;
        menu();
        while(!(cin >> selection)){
    cout << "Please enter a valid number" << endl; 
    cin.clear();
    cin.ignore(123,'\n');
        }
     

    switch(selection){
        case(1):
    addMeal(meal); 

        break; 

        case(2):
        meal.searchHigh(); 

        break;

        case(3):
        change_price(meal); 
        break;

        case(4):
        meal.print(); 
        break;

        case(5):
        x=1; 
        break;


}
        



}

}