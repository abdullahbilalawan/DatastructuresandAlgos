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

        root->left = Insert(root->left,data);

    } else if(data > root->data){
        root->right = Insert(root->right,data);
    }
    return root;


}

BstNode root;
//for empty tree root is null


int binary_search(){



}