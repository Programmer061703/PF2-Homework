#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


class node{
// BinaryTree data node definition
public:
    string Key;
    node *left;
    node *right;
    string Value;

    

};

// BinaryTree class definition

class BinaryTree{

    public:

    // Constructor
    BinaryTree();
    BinaryTree(const BinaryTree &copy);
    ~BinaryTree();

    //Operators

    bool Search (string Key, string &Value);
    bool Insert (string Key, string Value);
    bool Delete (string Key);
    void Print();
    void Print(ofstream & dout);

    private:

    // Private functions

    void copyTree(node *Tree1, node *&Tree2);
    void destroyTree(node *Tree);
    bool searchHelper (string key, string &Value, node *Tree);
    bool insertHelper (string Key, string Value, node *&Tree);
    bool deleteHelper (string Key, node *&Tree);
    void deleteNode (node *&Tree);
    void PrintHelper(node * Tree);
   void  PrintHelper(node * Tree, ofstream & dout);
    node *root;

};




#endif