//
// Created by DELL on 12/6/2020.
//

#ifndef DATASTRUCTURESANDALGOS_BINARY_SEARCH_TREE_H
#define DATASTRUCTURESANDALGOS_BINARY_SEARCH_TREE_H

#endif //DATASTRUCTURESANDALGOS_BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

struct BstNode{

    int data;
    BstNode* left;
    BstNode* right;



};

//create a node method

BstNode* GetNewNode(int data){
    BstNode* newnode = new BstNode();
    newnode->data=data;
}

BstNode* Insert(BstNode* root,int data){
    if(root==NULL){
        root=GetNewNode(data);
        return root;
    }

    else if(data <= root->data){

        root->left = Insert(root->left,data);   //recursion step

    } else if(data > root->data){
        root->right = Insert(root->right,data); //recursion step
    }
    return root;


}


bool Search(BstNode* root, int element){

    if (root==NULL){
        return false;
    }
    else if(root->data==element){
        return true;
    }
    else if(root->data<= element){
        Search(root->left,element);
    } else{
        Search(root->right,element);
    }

}


int find_min(BstNode* root){
    BstNode* current = root;
    while (current->left!=NULL){
        current = current->left;
    }
    return current->data;
}

//height of the binary_search tree

int height_of_tree(BstNode* root){
    if(root==NULL){
        return-1;

    }

    //recursive step
    return 1 + max(height_of_tree(root->left),height_of_tree(root->right));

}

void binary_search(){

    BstNode* root = NULL;
    root=Insert(root,2);
    root=Insert(root,5);
    root= Insert(root,10);

}