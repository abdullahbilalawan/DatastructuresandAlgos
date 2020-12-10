//
// Created by DELL on 10/31/2020.
//


#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* link;

};

// two options insert or delete form start and end
// linked list concepts
//node insertion at beginning O(1)



//top node instead of head (initially stack is empty)
Node* top = NULL;


//push function

//simple insertion

void Push(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->link = top;
    top=temp;

}

//pop function

void Pop(){

    Node* temp;
    if(top==NULL){
        return;
    }
    temp=top;
    top=top->link;
    free(temp);
}


void Print_Stack() {

    printf("STACK");

}

