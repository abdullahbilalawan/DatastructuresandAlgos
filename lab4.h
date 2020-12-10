//
// Created by DELL on 11/13/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB4_H
#define DATASTRUCTURESANDALGOS_LAB4_H

#endif //DATASTRUCTURESANDALGOS_LAB4_H



/* C++ Program to Implement Circular Doubly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*
 * Class Declaration
 */
class DoubleCircularList
{
public:
    int counter = 0;

    /*
     * Node Declaration
     */
    struct node{
        int info;
        struct node *next;
        node* prev;
    }*start, *last;

    DoubleCircularList(){
        start = NULL;
        last = NULL;
    }

    /*
     *CREATE NODE AND ALLOCATE MEMORY DYNAMICALLY
     */
    node* createNode(int value){
        struct node *temp;

        //your code here
        cout << "Node created"<<endl;
        temp->info=value;
        temp->next=NULL;temp->prev=NULL;
        return temp;
    }
    /*
     *INSERTS ELEMENT AT BEGINNING
     */
    void insertAtStart(){
        int value;
        cout<<endl<<"Enter the element to be inserted: ";
        cin>>value;

        //your code here

        //new node

        node* newNode;
        newNode= createNode(value);

        //assign links

        if(start=NULL){
            newNode->next=newNode;
            newNode->prev=newNode;
            start=newNode;
            last =newNode;
        }
        start->prev= newNode;

        newNode->next=start;

        last->next = newNode;
        start=newNode;
        counter++;











    }

    /*
     *INSERTS ELEMNET AT LAST
     */
    void insertLast(){
        int value;
        cout<<endl<<"Enter the element to be inserted: ";
        cin>>value;

        //your code here
        node* newNode;
        newNode= createNode(value);

        if(start=NULL){
            newNode->next=newNode;
            newNode->prev=newNode;
            start=newNode;
            last =newNode;
        }

        last->next=newNode;// previous last->next was pointing to first node but now we will make it point to new node
        newNode->prev = last; //make the new node prev point to last node in linked list
        newNode->next = start; //make the new node next start to first node of clinkedlist

        last= newNode; //make the last point to new node created

        counter++;















    }
    /*
     *INSERTS ELEMENT AT POSITION
     */
    void insertAtPos(){
        int value, pos, i;
        cout<<endl<<"Enter the element to be inserted: ";
        cin>>value;
        cout<<endl<<"Enter the postion of element inserted: ";
        cin>>pos;


        //create node
        node* newNode;
        newNode= createNode(value);

        // if linked list is empty

        if(start=NULL){
            newNode->next=newNode;
            newNode->prev=newNode;
            start=newNode;
            last =newNode;
        }
        else if(pos==1){//if at postition 1
            start->prev= newNode;

            newNode->next=start;

            last->next = newNode;
            start=newNode;


        }

        //if not empty find the position

        node* prev_ptr; node* current_ptr;//pointers used to denote n-1 and n position nodes
        current_ptr = start;
        for(int i=1;i<=pos;i++){

            prev_ptr =current_ptr;
            current_ptr =current_ptr->next;

            if(i==pos-1){
                prev_ptr->next = newNode;
                newNode->prev = prev_ptr;
                newNode->next = current_ptr;
                current_ptr->prev = newNode;


            }




        }
        counter++;












    }
    /*
     * Delete Node at Particular Position
     */
    void deleteAtPos()
    {
        int pos, i;
        node *ptr, *s;
        if (start == last && start == NULL)
        {
            cout<<"List is empty, nothing to delete"<<endl;
            return;
        }
        cout<<endl<<"Enter the postion of element to be deleted: ";
        cin>>pos;

        //your code here

        if(pos==1){
            counter--;
            last->next = start->next; // making the next node of last node the next node of current staring node that
            //is pointing last nodes next to 2nd node of circular linked list

            start->next->prev = last; //we know that the prev of first node is last node
            // so now we are deleting first one so 2nds node prev is called by start->next and its prev is assigned
            //last


            //now make start point to second node

            start = start->next;


        }

        node* current;node* previous;
        current=start;

        for(int i=0;i<pos-1;i++){
            current=current->next;
            previous= current->prev;




        }//when reached at position (pos) -1
        //link the previous pointer ->next to currents next as we will delete current
        previous->next = current->next;
        //make current node's next node prev-> elemt point to previous node from curent node as
        // we are deleting current node
        current->next->prev = previous;
        counter--;
        free(current);









    }
    /*
     * Display Elements of the List
     */
    void display(){
        //your code here

        int i;
        struct node *s;
        if (start == last && start == NULL) {
            cout<<"The List is empty, nothing to display"<<endl;
            return;
        }
        s = start;
        for (i = 0;i < counter-1;i++) {
            cout<<s->info<<"<->";
            s = s->next;
        }
        cout<<s->info<<endl;



    }

};

/*
 * Main: Contains Menu
 */
int lab_4main(){
    int userChoice;
    DoubleCircularList cdl;
    while (1){
        cout<<"\n-------------------------------"<<endl;
        cout<<"Operations on Doubly Circular linked list"<<endl;
        cout<<"\n-------------------------------"<<endl;
        cout<<"1.Insert at Beginning"<<endl;
        cout<<"2.Insert at Last"<<endl;
        cout<<"3.Insert at Specific Position"<<endl;
        cout<<"4.Delete at Specific Position"<<endl;
        cout<<"5.Display List"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>userChoice;
        switch(userChoice){
            case 1:
                cdl.insertAtStart();
                break;
            case 2:
                cdl.insertLast();
                break;
            case 3:
                cdl.insertAtPos();
                break;
            case 4:
                cdl.deleteAtPos();
                break;
            case 5:
                cdl.display();
                break;
            case 6:
                exit(1);
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}

