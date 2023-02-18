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
    cout << endl; 
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

cout << R"(
    ____       __                      __           _____             __  __       _____           __          
   / __ \___  / /___  ___________     / /_____     / ___/____  __  __/ /_/ /_     / ___/__  ______/ /___ _____ 
  / /_/ / _ \/ __/ / / / ___/ __ \   / __/ __ \    \__ \/ __ \/ / / / __/ __ \    \__ \/ / / / __  / __ `/ __ \
 / _, _/  __/ /_/ /_/ / /  / / / /  / /_/ /_/ /   ___/ / /_/ / /_/ / /_/ / / /   ___/ / /_/ / /_/ / /_/ / / / /
/_/ |_|\___/\__/\__,_/_/  /_/ /_/   \__/\____/   /____/\____/\__,_/\__/_/ /_/   /____/\__,_/\__,_/\__,_/_/ /_/ 
   
   
                                                                                                                                                                                                                      
)" << '\n' << endl; 

cout <<"After many years of Turmoil and interferences from forgien powers the glorious country of South Sudan has begun its millitary conquest"<<endl; 
cout <<"Assembling a battalion of Panzer II from the fallen Third Reich their fearless leader Promises to restore South Sudan to its former Glory"<<endl;
cout <<"The March of Panzers and Soldiers began March 3rd 2045 as they began their frontal assault on Sudan deeming them Inferrior to the might of South Sudan"<<endl; 
cout << "Sudan fell within 3 months as the years of internal warfare caused the government to destabalize when South Sudan began its march"<<endl; 
cout <<"As South Sudan planted its glorious flag on its rival, the neihboring country CHAD ammassed a force of 50,000 to counterattack the defensless country of South Sudan"<<endl;
cout <<"3 Months of constant seige from CHAD, South Sudans forces were to far away to assist, the Emperor activated the last plan"<<endl; 
cout<<"After the fall of Soviet Union in 1991 South Sudan had aquired a large nuclear arsenal, as a last resort began firing them at every mainland it could reach"<<endl;
cout<<"The Nuclear Fallout plunged the world into a Thousand year darkness, other than that GLORY TO SOUTH SUDAN"<<endl; 

}