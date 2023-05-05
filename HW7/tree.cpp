#include "tree.h"
#include "book.h"
#include <iostream>
using namespace std;


// Constructor

BinaryTree::BinaryTree(){
    root = NULL;
    
}

// Destructor

BinaryTree::~BinaryTree(){
    destroyTree(root);
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

bool BinaryTree::Search (string title){
    return searchHelper(title, root);
}

// Search Function Helper

bool BinaryTree::searchHelper (string title, node *Tree){
    if (Tree == NULL){
        return false;
    }
    else if (Tree->title == title){
        Tree->book.print();
        return true;
    }
    else if (title < Tree->title){
        return searchHelper(title, Tree->left);
    }
    else if(title > Tree->title){
        return searchHelper(title, Tree->right);
    }
    else{
        return false;
    }
}



// Insert Function

bool BinaryTree::Insert (Book book){
    return insertHelper(book, root);
}

// Insert Function Helper using .getTitle() to compare

bool BinaryTree::insertHelper (Book book,node *&Tree){
    
    if (Tree == NULL){
        Tree = new node;
        Tree->title = book.getTitle();
        Tree->book = book;
        Tree->left = NULL;
        Tree->right = NULL;
        return true;
    }
    else if (book.getTitle() < Tree->title){
        return insertHelper(book, Tree->left);
    }
    else if (book.getTitle() > Tree->title){
        return insertHelper(book, Tree->right);
    }
    else{
        return false;
    }
}

//Delete Node Function

bool BinaryTree::Delete (string title){
    return deleteHelper(title, root);
}

//Delete Function Helper

bool BinaryTree::deleteHelper (string title, node *&Tree){
    if (Tree == NULL){
        return false;
    }

    else if (Tree->title == title){
        deleteNode(Tree);
        return true;
    }

    else if (title < Tree->title){
        return deleteHelper(title, Tree->left);
    }
    else if (title > Tree->title){
        return deleteHelper(title, Tree->right);
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
        temp = Tree->right;
        while (temp->left != NULL){
            temp = temp->left;
        }
        temp->left = Tree->left;
        temp = Tree;
        Tree = Tree->right;
        delete temp;
    }
}



//Print Function Helper

void BinaryTree::PrintHelper(node *Tree){
    if (Tree != NULL){
        PrintHelper(Tree->left);
        Tree->book.print();
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
        dout<<Tree->book.getTitle()<<endl;
        PrintHelper(Tree->right, dout);

    }
}


//Print Function for output file
void BinaryTree::Print(ofstream &dout){
    PrintHelper(root, dout);
    dout<<endl;
}


//Balance Function

void BinaryTree::BalanceHelper(Book data[], int low, int high, node* &Tree) 
{
   // Terminating condition
   if (low > high) return;

   // Insert root value
   int mid = (low + high) / 2;
   insertHelper(data[mid], Tree);

   // Insert data on left
   BalanceHelper(data, low, mid-1, Tree->left);

   // Insert data on right
   BalanceHelper(data, mid+1, high, Tree->right);
}


// //Balance Function

// void BinaryTree::balance()
// {
//     // Create temporary array
    
//     Book data[Count];
    
//     // Extract data into array
//     int count = 0;
//     ExtractHelper(data, count, root);
    
    
//     root = NULL; // Reset tree
//     Count = 0; // Reset count
    
//     // Rebuild tree
//     BalanceHelper(data, 0, Count-1, root);
// }



//Extract Function Helper

void BinaryTree::ExtractHelper(Book data[], int &index,  node *Tree) 
{
    // Terminating condition
   if (Tree == NULL)
      return;

   // Traverse binary tree
   else
   {
      ExtractHelper(data, index, Tree->left);
      data[index++] = Tree->book;
      ExtractHelper(data, index, Tree->right);
   }
}

//Extract Function

void BinaryTree::Extract(Book data[], int &count)
{
    count = 0; // Reset count
    ExtractHelper(data, count, root);

}
 











int BinaryTree::Height(){
    return heightHelper(root);
}

int BinaryTree::heightHelper(node *Tree){
    if (Tree == NULL){
        return 0;
    }
    else{
        int leftHeight = heightHelper(Tree->left);
        int rightHeight = heightHelper(Tree->right);
        if (leftHeight > rightHeight){
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
    }
}


//Count Function

int BinaryTree::Count(){
    return countHelper(root);
}

//Count Function Helper

int BinaryTree::countHelper(node *Tree){
    if (Tree == NULL){
        return 0;
    }
    else{
        return countHelper(Tree->left) + countHelper(Tree->right) + 1;
    }
}

