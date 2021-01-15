//
// Created by DELL on 1/8/2021.
//

#ifndef DATASTRUCTURESANDALGOS_LAB11_H
#define DATASTRUCTURESANDALGOS_LAB11_H

#endif //DATASTRUCTURESANDALGOS_LAB11_H
#include <iostream>
#include <chrono>
using namespace std::chrono;

using namespace std;
using namespace std;

struct BstNode{

    int data;
    BstNode* left;
    BstNode* right;



};
class BstTree{
//create a node method
public:
BstNode* GetNewNode(int data){
    BstNode* newnode = new BstNode();
    newnode->data=data;
}

    int find_min(BstNode* root){
    BstNode* current = root;
    while (current->left!=NULL){
        current = current->left;
    }
    return current->data;
}

    BstNode* FindMin(BstNode* root)
    {
        while(root->left != NULL) root = root->left;
        return root;
    }

//delete a value

BstNode* Delete(BstNode* root, int data){
    if(root ==NULL){
        return root;
    }
    if(data > root->data){
        root->right = Delete(root->right,data);
    }
    if(data < root->data){
        root->left = Delete(root->left,data);
    }
    //if data is found then the deletion proccesss

    else {
        // Case 1:  No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
            //Case 2: One child
        else if(root->left == NULL) {
            struct BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            struct BstNode *temp = root;
            root = root->left;
            delete temp;
        }
            // case 3: 2 children
        else {
            BstNode* temp = (FindMin(root->right));
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;


}


//inorder traversal
void Inorder(BstNode* root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<endl;
    Inorder(root->right);
}


//preorder

void Preorder(BstNode* root){
    if(root == NULL) return;

    cout<<root->data<<endl; // Print data
    Preorder(root->left);     // Visit left subtree
    Preorder(root->right);    // Visit right subtree
}

void Postorder(BstNode* root){
    if(root == NULL) return;

    Postorder(root->left);    // Visit left subtree
    Postorder(root->right);   // Visit right subtree
    cout<<root->data<<endl;// Print data
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


//height of the binary_search tree

int height_of_tree(BstNode* root){
    if(root==NULL){
        return-1;

    }

    //recursive step
    return 1 + max(height_of_tree(root->left),height_of_tree(root->right));

}

public:
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
};
BstNode* root = NULL;
void lab_11_main(){

    BstTree tree;


    int userChoice;

    cout<<"Enter your BST operation choice (int) :"<<endl;
    cout<<"1. Insert"<<endl;
    cout<<"2. Delete"<<endl;
    cout<<"3. Preorder"<<endl;
    cout<<"4. Postorder"<<endl;
    cout<<"5. Inorder"<<endl;

    cin>> userChoice;

    switch(userChoice){
        case 1:
            int data;
            cout<<"enter data to be entered"<<endl;
            cin>> data;
            root = tree.Insert(root,data);
            lab_11_main();
            break;

        case 2:
            int data_d;
            cout<<"enter data to be delete"<<endl;
            cin>> data_d;
            root = tree.Delete(root,data);
            lab_11_main();
            break;

        case 3:
            tree.Preorder(root);
            lab_11_main();
            break;

        case 4:
            tree.Postorder(root);
            lab_11_main();
            break;

        case 5:
            tree.Inorder(root);
            lab_11_main();
            break;

    }





}