#include "pinball.h"
#include <iostream>
using namespace std; 


//Constructors
    Pinball::Pinball(){
        mach_name = "0";
        year_prod = 0;
        manu = "0";
        fun_rating = 0;
        theme = "0";


    }
   Pinball:: Pinball(const string mach_name1,const int year_prod1, const string manu1, const float fun_rating1, const string theme1  ){
    mach_name=mach_name1;
    year_prod=year_prod1;
    manu=manu1;
    fun_rating=fun_rating1;
    theme=theme1;
   }
    Pinball::Pinball(const Pinball & copy){
        mach_name = copy.mach_name;
        year_prod = copy.year_prod;
        manu = copy.manu;
        fun_rating = copy.fun_rating;
        theme = copy.theme;
    }
    Pinball::~Pinball(){

    }


// Utility Methods 
    void Pinball::print() const{
         cout << mach_name; 
         cout << year_prod; 
         cout << manu; 
         cout << fun_rating; 
         cout << theme;
    }

//Getters
    string Pinball::getMach_name() const{

    }
    int Pinball::getYear_prod() const{

    }
    string Pinball::getManu() const{

    }
    float Pinball::getFun_rating() const{

    }
    string Pinball::getTheme() const{

    }
// Setters
    void Pinball::setMach_name(const string mach_name){

    }
    void Pinball::setYear_prod(const int year_prod){

    }
    void Pinball::setManu(const string manu){

    }
    void Pinball::setFun_rating(const float fun_rating){

    }
    void Pinball::setTheme(const string theme){

    }
    
