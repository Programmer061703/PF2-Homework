#ifndef PASSWORD_H
#define PASSWORD_H

#include <iostream>
using namespace std; 

class Password
{
public:
   Password();
   Password(string plaintext, int rank, string hash );
   Password(const Password & copy);
   ~Password(); 

    //Getters
    string getPlaintext();
    int getRank();
    string getHash();

    //Setters
    void setPlaintext(string plaintext);
    void setRank(int rank);
    void setHash(string hash); 
    void print();

    
private:
    string Plaintext;
    int Rank; 
    string Hash; 


};




#endif