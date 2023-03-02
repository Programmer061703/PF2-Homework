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
   Password::~Password(){

   } 

   