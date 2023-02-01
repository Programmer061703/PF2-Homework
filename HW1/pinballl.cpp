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
        size = 0; 


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
         cout <<theme<<endl;
    }

//Getters
    string Pinball::getMach_name() const{
        return mach_name;
    }
    int Pinball::getYear_prod() const{
        return year_prod;
    }
    string Pinball::getManu() const{
        return manu;
    }
    float Pinball::getFun_rating() const{
        return fun_rating;
    }
    string Pinball::getTheme() const{
        return theme;
    }
// Setters
    void Pinball::setMach_name(const string mach_nameIn){
        mach_name = mach_nameIn;
    }
    void Pinball::setYear_prod(const int year_prodIn){
        year_prod = year_prodIn;
    }
    void Pinball::setManu(const string manuIn){
        manu = manuIn; 
    }
    void Pinball::setFun_rating(const float fun_ratingIn){
        fun_rating = fun_ratingIn;
    }
    void Pinball::setTheme(const string themeIn){
        theme = themeIn; 
    }

    
