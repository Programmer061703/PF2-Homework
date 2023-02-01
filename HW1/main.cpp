#include "pinball.h"
#include <iostream>
#include <fstream>
using namespace std;

//Create machine array
const int SIZE = 10;
Pinball machine[SIZE];

void load_machines(const string filename){
ifstream din;
din.open(filename);
if (din.fail()){

    cout << "Failed to read file"<<endl;
    return; 
}

}


int main(){


}