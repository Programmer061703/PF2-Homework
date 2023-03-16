#include "queue.h"
#include <vector>

   
   Queue::Queue(){
    count = 0;
   }
	Queue::Queue(const Queue& copy){
        count = copy.count;
         for (int i = 0; i < count; i++){
            data[i]= copy.data[i];  
         }

    }
   Queue:: ~Queue(){

   }
    
    void Queue::insert(const int number){
        data.push_back(number);
        count++;
        return; 
    }
    int Queue::remove(){
        data.erase(data.begin());
        count--;  
    }
    
	bool Queue::isFull() const{
        if(data.size()==data.max_size()){
            return true;
        }
        else{
            return false; 
        }


    }   
    bool Queue::isEmpty() const{
        if (data.empty()){
            return true; 
        }
        else{
            return false; 
        }
    }
    int Queue::getCount() const{
        return count; 
    }
    void Queue::print() const{
        for (int i = 0; i < count; i++){
            cout << data[i]<<endl; 
        }

    }