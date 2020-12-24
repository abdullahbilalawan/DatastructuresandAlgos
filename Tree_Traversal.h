//
// Created by DELL on 12/23/2020.
//

#ifndef DATASTRUCTURESANDALGOS_TREE_TRAVERSAL_H
#define DATASTRUCTURESANDALGOS_TREE_TRAVERSAL_H

#endif //DATASTRUCTURESANDALGOS_TREE_TRAVERSAL_H
#include <iostream>
#include "binary_search_tree.h"
using namespace std;
#include <queue>

void LevelOrderTraversal(BstNode* root){
    if(root ==NULL){
        return;
    }

    queue<BstNode*> que;
    que.push(root);

    while(!que.empty()){
        BstNode* current =que.front();

        cout << current->data << "  "<<endl;
        if(current->left != NULL){
            que.push(current->left);
        }
        if(current->right != NULL){
            que.push(current->right);
        }
        que.pop();
    }

}


void PreOrderTraversal( BstNode* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<endl;

    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}




