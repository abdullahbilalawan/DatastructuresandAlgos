//
// Created by DELL on 11/14/2020.
//

#ifndef DATASTRUCTURESANDALGOS_ASSIGNMENT_NO_1_DSA_H
#define DATASTRUCTURESANDALGOS_ASSIGNMENT_NO_1_DSA_H

#endif //DATASTRUCTURESANDALGOS_ASSIGNMENT_NO_1_DSA_H
#include "stack" //using stack of STL library

#include <iostream>
#include "list"
using namespace std;

// ===========================QUestion 1==================================


void Decoder(){

    string input_expression;

    //taking input

    cout<<"Enter Expression only S or G is allowed do not type any other"<<endl;

    cin>>input_expression;





    //converting string to a char array

    // declaring character array : p
    char p[input_expression.length()];
    //std::cout<<"the input expression length is"<<input_expression.length()<<endl;


    int i;
    for (i = 0; i < sizeof(p); i++) {
        p[i] = input_expression[i];
        //cout << p[i];
    }
    //initialize a output array
    list<int> output={};



    //initializing a int stack from STL library
    stack<int> stack;




    //run a loop on char array
    char s ='S';char g ='G';

    //counter

    int counter=0;



    while(counter<input_expression.length()+1){

        stack.push(counter);



        cout<<p[counter]<<counter<<endl;







        if(p[counter]==s) {// if the element has shrink
            cout << "shrinking" << endl;

            while(!stack.empty()) {//till it doesnt get empty
                int t = stack.top();

                //append tou output
                output.push_back(t+1);

                stack.pop();//pop the values to make it empty
            }

        }

//
        else if(p[counter]==g){

        }

            //when for loop ends clear the stack and append to output in case of end Gs

        if(counter==input_expression.length()){
            for(int i=0;i<stack.size();i++) {//till it doesnt get empty
                int t = stack.top();

                //append tou output
                output.push_back(t);

                stack.pop();//pop the values to make it empty
            }
        }





        counter++;
      

    }
    cout<<"output is"<<endl;
    for( auto x = output.begin( ); x != output.end( ); ++x) {

        cout<<*x<<endl;

    }



}


//=========================QUESTION-2=========================================

class Node{
public:
    int process_length;
    Node* next;
};


class RoundRobin{
public:


    struct Node* head = NULL;
    void insert_at_end(int newdata) {
    Node *newnode = new Node;//create new node
    Node *ptr = head;
    newnode->process_length = newdata;
    newnode->next = head;//circular so last pointing towards head
    if (head!= NULL) {
    while (ptr->next != head)//traverse till end
        ptr = ptr->next;
    ptr->next = newnode;//make link to new node
    } else
    newnode->next = newnode;//if it is empty make a node and point links to it
    head = newnode;
    }




    void display() {//display function of round robin scheduling
    Node* ptr;
    ptr = head;
    do {
    cout<<"Process  ||"<< ptr->process_length<<"||" <<" ";
    ptr = ptr->next;
    } while(ptr != head);//traverse till end
    cout<<"\n"<<endl;
    }




    //count no_of_nodes

    int nodeCount(){

        int nodeCount;
        Node* curr = head;
        if(head != NULL) {
            nodeCount = 1;//if head not null make count 1 then while runs
        }//end if
        else {
            nodeCount = 0;//if empty returns 0
        }//end else

        while(curr->next != NULL && curr->next != head) {//if list doesnt goto end
            nodeCount += 1;//increase node count
            curr = curr->next;//make current point to next node
        }//end while
        return nodeCount;



    }


    int check_for_zeros(){
        int zero_count=0;
        int node_count =nodeCount();
        int iter=0;
        bool isRunning= true;


        Node* curr = head;



        while (isRunning){

            if(curr->process_length==0){
                zero_count+=1;
            }
            iter+=1;
            if(zero_count==node_count || iter==node_count){

                isRunning= false;
            }
            curr=curr->next;



        }
        return zero_count;






    }






    void round_robin_scheduling(){


        //check
//        insert_at_end(3);
//        insert_at_end(4);
//        display();



//initialization

        Node* curr = head;
        int timeQuantum = 5;
        int numOfZeroes = 0;
        int numOfProcesses = nodeCount();


        while(numOfZeroes<numOfProcesses){//while all processes are completed

            if(curr->process_length<=timeQuantum){

                curr->process_length=0;//proccesss is done under quantum time
            }
            else if(curr->process_length>timeQuantum){

                curr->process_length-=timeQuantum;

            }

            cout<<"{{{{{{{{{{{{{{{{{{{{PROCESSING}}}}}}}}}}}}}}}}}}}}}}}}}}}"<<endl;

            display();
            numOfZeroes = check_for_zeros();
            curr = curr->next;



        }



    }



};



void question_2_demo(){

    RoundRobin rr;//initialize object

    //insert processses
    rr.insert_at_end(3);
    rr.insert_at_end(4);
    rr.insert_at_end(5);
    rr.insert_at_end(6);
    //display before RR'
    cout<<"display before process"<<endl;
    rr.display();

    //call RR
    rr.round_robin_scheduling();


    cout<<"dispay after process \n"<< endl;
    rr.display();



}