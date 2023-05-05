#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "book.h"
using namespace std;


class node{
// BinaryTree data node definition
public:
    string title;
    node *left;
    node *right;
    Book book; // Book data

    

};

// BinaryTree class definition

class BinaryTree{

    public:

    // Constructor
    BinaryTree();
    ~BinaryTree();

    //Operators

    bool Search (string title);
    bool Insert (Book book);
    bool Delete (string title);
    void Print();
    void Print(ofstream & dout);
    void balance();
    int Height(int Value);
    
    void Extract(Book data[], int &count);
    

    private:
    // Private functions
    
    void destroyTree(node *Tree);

    bool searchHelper (string title, node *Tree);

    bool insertHelper (Book book, node *&Tree);

    bool deleteHelper (string title, node *&Tree);
    void deleteNode (node *&Tree);

    void PrintHelper(node * Tree);
   void  PrintHelper(node * Tree, ofstream & dout);

    void BalanceHelper(Book data[], int low, int high, node* &Tree);

    void heightHelper(node *Tree, int &height, int &maxHeight);

    void ExtractHelper(Book data[], int &index, node *Tree);

    void HeightHelper(int Value, node *Tree);
    
   int Value;
    
    node *root;
    

};




#endif