#include <iostream>
#include "queue.h"
#include "stack.h"
#include <time.h>
#include <stdlib.h>
using namespace std; 


int main(){
// Get start time
clock_t time1=clock();



//Code starts here
srand (time(NULL));

Stack Snumbers;
int random;
for (int i = 0; i < 1000; i++){
 random = rand() % 100 + 1;
  

 if (random <= 50){
    Snumbers.push(random); 
 }
 
 if (random > 50 ){

    Snumbers.pop(); 
 }


}
Snumbers.print();

// Get end time
clock_t time2=clock();
double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
cout << "Run time: " << run_time << " seconds\n";

Queue Qnumbers;

for (int i = 0; i < 1000; i++){
 random = rand() % 100 + 1;
  

 if (random <= 50){
    Qnumbers.insert(random); 
 }
 
 if (random > 50 ){
    Qnumbers.remove(); 
 }


}
Qnumbers.print(); 


// Get end time
clock_t time3=clock();
double run_time2 = (time3-time2)/(double)CLOCKS_PER_SEC;
cout << "Run time: " << run_time2 << " seconds\n";




}