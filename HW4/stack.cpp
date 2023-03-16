 #include "stack.h"
 
 Stack::Stack(){
 count = 0; 
 }
	Stack::Stack(const Stack& copy){
        count = copy.count; 
        for (int i = 0; i < count;i++){
            data[i] = copy.data[i];
        }
    }
    Stack::~Stack(){

    }
    
    void Stack:: push(const int number){
        data.push_back(number); 
        count ++; 
        return;
    }
    int Stack::pop(){
        if (!isEmpty()){
        int x = data.back(); 
        data.pop_back();
        count --;
        return x;
        }
        else{
            return -1; 
        }



    }
    int Stack::top() const{
        return data.back();
    }
    
	bool Stack::isFull() const{
        return false; 
    }
    bool Stack::isEmpty() const{
        if (count == 0 ){
            return true; 
        }
        else {
            return false; 
        }
    }
    int Stack::getCount() const{
        return count; 
    }
    void Stack::print() const{
        for (int i = 0; i < count; i++){
            cout << data[i]<<"\t"; 
            
        }
        cout <<endl; 
    }