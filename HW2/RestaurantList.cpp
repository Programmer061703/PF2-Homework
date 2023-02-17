

#include "RestaurantList.h"

RestaurantList::RestaurantList(){
Head = NULL; 

}

RestaurantList::RestaurantList(const RestaurantList & copy){
   // Greates a RestNode called list 
    RestNode *list = new RestNode();
    // Sets Head Node (declared in private variables in RestList.h) equal to the newly created list node
    Head = list; 
    // Sets ptr = to a copy of Head
    RestNode *ptr = copy.Head; 
//itterates through the copy of the head node until it reaches the end
while(ptr != NULL){
    //Goes through and copies all the values of the Head node using the ptr
    list->setNext(new RestNode());
    list = list->getNext();
    list-> setRest_Name(ptr->getRest_Name());
    list-> setRest_Rating(ptr->getRest_Rating());
    list-> setMeal_Name(ptr->getMeal_Name());
    list-> setTyp_Meal(ptr->getTyp_Meal());
    list-> setPrice(ptr->getPrice());
    ptr = ptr ->getNext(); 
} 
// Sets the new copy equal to Head then cleans up by deleting the list that was just creaetd
list = Head; 
Head = list->getNext();
delete list;
    
}


 RestaurantList::~RestaurantList(){

 }

//insert method
// Here I chose to insert at the tail so that when data is inserted it will be more inline with everything, won't be as efficient as insert at head, But id rather have consistancy than a out of order list
 void RestaurantList::insertTail(string rest_name, float rest_rating, string meal_name, string typ_meal, float price){
    //Starts off by finding tail node by using a while loop to itterate through the list by setting ptr = Head. 
RestNode *ptr = Head; // Creates new list set to the values of Head
    //While loop checks iff the current position and Next position are NOT null then itterates to the next position until null is reached
    while ((ptr != NULL) && (ptr->getNext() != NULL)){
        ptr = ptr->getNext();
    }
    //Once While loop reaches end of list the new node 
    if (ptr != NULL){
        ptr->setNext(new RestNode(rest_name,rest_rating,meal_name,typ_meal,price));
    
    }
    else{
        Head = new RestNode(rest_name,rest_rating,meal_name,typ_meal,price);
    }
 }
    //Highest price
void RestaurantList:: searchHigh(){
    //In order to search for the highest 2 nodes are created, one that stores the list Head and another empty one.
    //The Code looks through the Linked list and compares each price the next price. If the price is larger it stores it in the high node. 
RestNode *ptr = Head; 
RestNode *high; 
int temp = 0;
float high_price = 0;
while((ptr!= NULL)){
if(high_price <= ptr->getPrice() ){
    high_price = ptr->getPrice(); 
    high = ptr;  
    
}
ptr = ptr->getNext();
}

high->print(); 

 
} 
    //Change Price
void RestaurantList::changePrice(string meal,float price){
RestNode *ptr = Head; 
int temp = 0;
 
while((ptr!= NULL)){
    if (meal == ptr->getMeal_Name()){
         cout << endl<< meal <<" Found"<<endl;
         ptr->setPrice(price);  
        cout <<endl<< "Price Set of "<<meal<<" set to $"<<price<<endl; 
        temp = 1; 
    }
if (temp == 0){
    cout <<endl<<"Meal not Found"<<endl; 
}
ptr = ptr->getNext();
}
}

    //Print
void RestaurantList::print() const {
    RestNode *ptr = Head; 
    
    while(ptr != NULL){
        cout <<endl; 
        ptr->print();
        ptr=ptr->getNext();
        
    }

}