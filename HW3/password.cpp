#include "password.h"


Password::Password(){
Plaintext = "0";
Rank = 0;
Hash = "0";

}
   Password::Password(string plaintext, int rank, string hash ){
    Plaintext = plaintext; 
    Rank = rank;
    Hash = hash;
    
   }
   Password::Password(const Password & copy){
      Hash =copy.Hash;
      Plaintext = copy.Plaintext;
     Rank = copy.Rank;
   }
   Password::~Password(){

   } 

   //Getters
    string Password:: getPlaintext(){

      return Plaintext;

    }
    int Password::getRank(){
      return Rank;
    }
    string Password::getHash(){
      return Hash;
    }

    //Setters
    void Password::setPlaintext(string plaintext){
      Plaintext = plaintext;

    }
    void Password::setRank(int rank){
      Rank = rank;
    }
    void Password::setHash(string hash){
      Hash = hash;
    } 

    void Password::print(){
      cout <<endl<< "Password:" << getPlaintext()<<endl;
      cout << "Rank: "<< getRank()<<endl;
      cout << "Hash: "<< getHash()<<endl;

    }

   