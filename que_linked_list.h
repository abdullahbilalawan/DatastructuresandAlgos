//
// Created by DELL on 11/6/2020.
//

#ifndef DATASTRUCTURESANDALGOS_QUE_LINKED_LIST_H
#define DATASTRUCTURESANDALGOS_QUE_LINKED_LIST_H

#endif //DATASTRUCTURESANDALGOS_QUE_LINKED_LIST_H

#include <iostream>

using namespace std;


struct Node{

    int data;
    Node* next;

};

Node* front = NULL; Node* rear =NULL;

void enqueue(int x){
    Node* temp = new Node;
    temp->data=x;

    temp->next=NULL;
    if(front==NULL && rear==NULL){

        front=rear=temp;
        return;
    }

    rear->next=temp;
    rear=temp;




}


// To Dequeue an integer.
void Dequeue() {
    struct Node* temp = front;
    if(front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

int Front() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return 1;
    }
    return front->data;
}

void Print() {
    struct Node* temp = front;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}