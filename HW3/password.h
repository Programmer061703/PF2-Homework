#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>
using namespace std; 

class Password
{
    public:
   Password();
   Password(string plaintext, int rank, string hash );
   ~Password(); 

    //Getters
    
    private:
    string Plaintext;
    int Rank; 
    string Hash; 


};




#endif