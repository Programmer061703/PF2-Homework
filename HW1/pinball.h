#ifndef PINBALL

#define PINBALL

#include <iostream>
using namespace std;
const int max_pinball = 10; 

class Pinball
{
public:
    //Constructors
    Pinball();
    Pinball(const string mach_name,const int year_prod, const string manu, const float fun_rating, const string theme  );
    Pinball(const Pinball & copy);
    ~Pinball();


// Utility Methods 
    void print() const;

//Getters
    string getMach_name() const;
    int getYear_prod() const;
    string getManu() const;
    float getFun_rating() const; 
    string getTheme() const; 
// Setters
    void setMach_name(const string mach_name);
    void setYear_prod(const int year_prod);
    void setManu(const string manu);
    void setFun_rating(const float fun_rating);
    void setTheme(const string theme);
    
private:
        string mach_name;
        string manu;
        int year_prod;
        float fun_rating;
        string theme; 
        

};  
















#endif