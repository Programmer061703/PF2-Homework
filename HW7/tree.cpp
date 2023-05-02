#include "tree.h"
#include <iostream>
using namespace std;


// Constructor

BinaryTree::BinaryTree(){
    root = NULL;
}

// Copy Constructor

BinaryTree::BinaryTree(const BinaryTree &copy){
    copyTree(copy.root, root);
}

// Destructor

BinaryTree::~BinaryTree(){
    destroyTree(root);
}

// Copy Constructor Helper

void BinaryTree::copyTree(node *Tree1, node *&Tree2){
    if (Tree1 == NULL){
        Tree2 = NULL;
    }
    else{
        Tree2 = new node;
        Tree2->Key = Tree1->Key;
        Tree2->Value = Tree1->Value;
        copyTree(Tree1->left, Tree2->left);
        copyTree(Tree1->right, Tree2->right);
    }
}


// Destructor Helper

void BinaryTree::destroyTree(node *Tree){
    if (Tree != NULL){
        destroyTree(Tree->left);
        destroyTree(Tree->right);
        delete Tree;
    }
}

// Search Function

bool BinaryTree::Search (string Key, string &Value){
    return searchHelper(Key, Value, root);
}

// Search Function Helper

bool BinaryTree::searchHelper (string Key, string &Value, node *Tree){
    if (Tree == NULL){
        return false;
    }
    else if (Tree->Key == Key){
        Value = Tree->Value;
        return true;
    }
    else if (Key < Tree->Key){
        return searchHelper(Key, Value, Tree->left);
    }
    else if(Key > Tree->Key){
        return searchHelper(Key, Value, Tree->right);
    }
    else{
        return false;
    }
}



// Insert Function

bool BinaryTree::Insert (string Key, string Value){
    return insertHelper(Key, Value, root);
}

// Insert Function Helper

bool BinaryTree::insertHelper (string Key, string Value, node *&Tree){
    if (Tree == NULL){
        Tree = new node;
        Tree->Key = Key;
        Tree->Value = Value;
        Tree->left = NULL;
        Tree->right = NULL;
        return true;
    }
    else if (Tree->Key == Key){
        Tree->Value = Value;
        return true;
    }
    else if (Key <= Tree->Key){
        return insertHelper(Key, Value, Tree->left);
    }
    else if (Key > Tree->Key){
        return insertHelper(Key, Value, Tree->right);
    }
    else{
        return false;
    }
}

//Delete Node Function

bool BinaryTree::Delete (string Key){
    return deleteHelper(Key, root);
}

//Delete Function Helper

bool BinaryTree::deleteHelper (string Key, node *&Tree){
    if (Tree == NULL){
        return false;
    }

    else if (Tree->Key == Key){
        deleteNode(Tree);
        return true;
    }

    else if (Key < Tree->Key){
        return deleteHelper(Key, Tree->left);
    }
    else if (Key > Tree->Key){
        return deleteHelper(Key, Tree->right);
    }
    else{
        deleteNode(Tree);
        return true;
    }
}


//Delete a single node

void BinaryTree::deleteNode (node *&Tree){
    node *temp = Tree;
    if (Tree->left == NULL){
        Tree = Tree->right;
        delete temp;
    }
    else if (Tree->right == NULL){
        Tree = Tree->left;
        delete temp;
    }
    else{
        node *current = Tree->left;
        node *parent = NULL;
        while (current->right != NULL){
            parent = current;
            current = current->right;
        }
        Tree->Key = current->Key;
        Tree->Value = current->Value;
        if (parent == NULL){
            Tree->left = current->left;
        }
        else{
            parent->right = current->left;
        }
        delete current;
    }
}



//Print Function Helper

void BinaryTree::PrintHelper(node *Tree){
    if (Tree != NULL){
        PrintHelper(Tree->left);
        cout << Tree->Key << " " << Tree->Value << endl;
        PrintHelper(Tree->right);
    }
}

//Print Function

void BinaryTree::Print(){
    PrintHelper(root);
}
//Print Function Helper for output file

void BinaryTree::PrintHelper(node *Tree, ofstream &dout){
    if (Tree != NULL){
        PrintHelper(Tree->left, dout);
        dout << Tree->Key << " " << Tree->Value << endl;
        PrintHelper(Tree->right, dout);
    }
}


//Print Function for output file
void BinaryTree::Print(ofstream &dout){
    PrintHelper(root, dout);
    dout<<endl;
}


