//
// Created by DELL on 11/6/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LINKEDLISTS_H
#define DATASTRUCTURESANDALGOS_LINKEDLISTS_H

#endif //DATASTRUCTURESANDALGOS_LINKEDLISTS_H



#include <iostream>
#include <stdlib.h>


using std::cout;
using std::endl;
using std::string;
using std::ostream;



// linked listof integers insert a node at beginning


struct Node
{

    int data;// int
    Node* next;// pointer to next node



};

// Head Node global var

Node* head;

//insert function


void Insert(int x){

    Node* temp = new Node;
    temp->data =x;//value
    temp->next=head;//pointer var

    //make temp to head as inserted a first member
    head = temp;







}

//print function

void Print(){
    Node* temp;
    printf("List is..  \n");

    // create a node
    while (temp!=NULL)
    {
        printf("%d   \n",temp->data);
        temp = temp->next;
    }

}






// insert a node at nth postion linked list
// insert(data,n)


void Insert_n(int data, int n){
    // create a node assign data

    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next=NULL;

    // if n is 1 adding at first position

    if (n==1)
    {
        temp1->next=head;//assign temp1 next node to head
        //assign head to the first node
        head = temp1;
        return;
    }
    else{
        //if not to insert at first node

        Node* temp2 = head;//assign to first
        for(int i =0;i<n-2;i++){//traverse till n-1
            temp2= temp2->next;


        }
        //assign temps 2 next to temp1
        temp1->next = temp2->next;// put n+1 addres in .next of temp1
        temp2->next=temp1;//



    }

    /* code */


}








// delete a node at nth position

void Delete(int n){

    Node *temp1 = head;


    if(n==1){
        head= temp1->next;
        delete(temp1);
        return;
    }

    for(int i=0;i<n-2;i++){

        //temp 1 goes to n-1 node

        Node* temp2 = temp1->next; // nth node

        temp1->next = temp2->next;//(n+1)th Node

        delete(temp2);


    }




}


// reverse a linked list
// interview question

// reverse links

//two methods


//iterative solution

// reverse each link

void Reverse(){


    //corner test case




    Node  *next,*prev,*current;// initialize nodes
    current=head;
    prev =NULL;//previous from head is NULL

    while (current != NULL)// loop for traversing

    {

        next=current->next;
        current->next=prev;
        prev = current;
        current=next;

    }
    head=prev;




}

//print forward using recursion

// void Print_forward_recursion(Node *p) {

//     if (p==NULL)
//     {
//         // exit condition
//         return;
//     }



//     printf("%d",p->data);
//     Print_forward_recursion(p->next);//recursion call



// }








//APPEND
void appendNode(float num){
    Node *newNode, *Nodeptr;
    newNode->data=num;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        Nodeptr=head;
        while (Nodeptr->next){
            Nodeptr->next=Nodeptr;


        }
        Nodeptr->next=newNode;


    }










}




void traverse(){
    //print the linked list

    Node *arrow;
    arrow=head;

    while (arrow)
    {
        std::cout<<arrow->data<<endl;
        printf("%d \n",arrow);
        arrow= arrow->next;
    }


}






int main(){

    head = NULL;
    printf("How many numbers? \n");
    int n,i,x;
    scanf("%d",&n);

    for( i =0; i<n;i++){

        printf("enter the number");
        scanf("%d",&x);
        Insert(x);


        Print();
    }

    appendNode(5);









    return 0;
}

