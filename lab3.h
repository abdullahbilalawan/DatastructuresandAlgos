//
// Created by DELL on 11/6/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB3_H
#define DATASTRUCTURESANDALGOS_LAB3_H

#endif //DATASTRUCTURESANDALGOS_LAB3_H


#include <iostream>
using namespace std;


//class Linked_List {
//public:
//
//
//    //creating a head node
//    Node *head;
//
//    void insertAtHead(int new_value) {
//
//
//        Node *temp = new Node;
//        temp->value = new_value;//value
//        temp->next = head;//pointer var
//
//        //make temp to head as inserted a first member
//        head = temp;
//
//
//    }
//
//    void insertAtLocation(int location, int new_value) {
//
//
//
//        // create a node assign data
//
//        Node *temp1 = new Node();
//        temp1->value = new_value;
//        temp1->next = NULL;
//
//        // if n is 1 adding at first position
//
//        if (location == 1) {
//            temp1->next = head;//assign temp1 next node to head
//            //assign head to the first node
//            head = temp1;
//            return;
//        } else {
//            //if not to insert at first node
//
//            Node *temp2 = head;//assign to first
//            for (int i = 0; i < location - 2; i++) {//traverse till n-1
//                temp2 = temp2->next;
//
//
//            }
//            //assign temps 2 next to temp1
//            temp1->next = temp2->next;// put n+1 addres in .next of temp1
//            temp2->next = temp1;//
//
//
//
//        }
//
//
//    }
//
//
//    void Delete(int n) {
//
//
//        //create a temp node for traversal and assign it head
//
//        Node *temp = head;
//
//        if (n == 1) { //if deleting first node
//
//            //make the head point to second node
//
//            head = temp->next;
//
//
//            //delete node
//
//
//            delete (temp);
//
//        }
//
//        //if deleting any other n node
//
//        for (int i = 0; i < n - 2; i++) {
//
//            //temp  goes to n-1 node
//
//            //now break links of N node
//
//            Node *temp2 = temp->next; // assign temp2 node N
//
//            temp->next = temp2->next;//assign node n-1's next to point towards n+1 i.e temp2->next
//
//            delete (temp2);
//
//
//        }
//    }
//
//        void displayList(Node* p){//by recursion give head in the function
//
//        if(p==NULL){// base case if ifnode is null end recursion
//            return;
//        }
//        printf("%d \n",p->value);//display value
//        displayList(p->next);//recursive step
//
//        }
//
//
//
//        void count_list(){
//
//
//
//            Node *arrow;//arrow node for traversal
//            arrow=head;
//
//            int count= 0;
//
//            while (arrow)//while arrow is not null means till end of linked list
//            {
//                std::cout<<arrow->value<<endl;
//
//                arrow= arrow->next;
//                count++;
//            }
//
//            printf(" \n%d \n count of linked list is",count);
//
//
//    }
//
//
//
//
//
//};
//
//
//
//class lab3_main_demo{
//
//public:
//
//    Linked_List list;
//    int choice;
//
//
//    void display() {
//
//        printf("1.insert_at_head\n 2.insert at n \n 3.delete_at_n \n 4.count \n 5.displaybyrecursion \n 6.end \n");
//
//
//        printf("TO use my linked list . choose one of the following functionality:\n");
//
//        cin >> choice;
//
//    }
//
//    void choose(){
//
//    if(choice!=6){
//
//
//    switch(choice){
//
//        case 1:
//            int value;
//            cout<<"enter value"<<endl; cin>>value;
//            list.insertAtHead(value);
//            break;
//
//        case 2:
//            int val; int position;
//            cout<<"enter val"<<endl; cin>>val;
//            cout<<"enter position"<<endl; cin>>position;
//
//            list.insertAtLocation(position,val);
//            break;
//
//        case 3:
//
//            int va;
//            cout<<"enter value to delete"<<endl; cin>>va;
//
//            list.Delete(va);
//            break;
//
//        case 4:
//            list.count_list();
//            break;
//
//
//        case 5:
//            list.displayList(list.head);
//            break;
//
//
//
//
//
//    }}}
//
//
//
//    void initialize(){
//        list.head=NULL;
//    }
//};
//
//
//void demo(){
//
//
//    lab3_main_demo manager;
//    manager.initialize();
//    while (manager.choice!=6){
//        manager.display();
//        manager.choose();
//
//    }
//
//
//
//}