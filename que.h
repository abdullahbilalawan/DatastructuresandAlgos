//
// Created by DELL on 11/5/2020.
//

#ifndef DATASTRUCTURESANDALGOS_QUE_H
#define DATASTRUCTURESANDALGOS_QUE_H

#endif //DATASTRUCTURESANDALGOS_QUE_H


#include <iostream>
using namespace std;




class Queue_by_array{

private:
    int A[50];
    int front,rear;


public:
    //default constructor

    Queue_by_array(){
        front=-1;rear=-1; //-1 means empty
    }


    //is empty function

    bool isEmpty(){
        return (front==-1 && rear==-1);


    }

    //is full function

    bool IsFull()
    {
        return (rear+1)%50 == front ? true : false;//checking if next element is the front of array
    }


    //Enque function


    void Enque(int x){


        if(IsFull())
        {
            cout<<"Error: Queue is Full\n";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear+1)%50;//rear goes to next element
        }
        A[rear] = x;

    }



    void Dequeue()
    {
        cout<<"Dequeuing \n";
        if(isEmpty())
        {
            cout<<"Error: Queue is Empty\n";
            return;
        }
        else if(front == rear )
        {
            rear = front = -1;
        }
        else
        {
            front = (front+1)%10;//incrementing front
        }
    }


    void Print(){


        // Finding number of elements in queue
        int count = (rear+10-front)%10 + 1;
        cout<<"Queue       : ";
        for(int i = 0; i <count; i++)
        {
            int index = (front+i) % 10; // Index of element while travesing circularly from front
            cout<<A[index]<<" ";
        }
        cout<<"\n\n";
    }




};



int circular_que_demo()
{
    /*Driver Code to test the implementation
      Printing the elements in Queue after each Enqueue or Dequeue
    */
    Queue_by_array Q; // creating an instance of Queue.
    Q.Enque(2);  Q.Print();
    Q.Enque(4);  Q.Print();
    Q.Enque(6);  Q.Print();
    Q.Dequeue();	  Q.Print();
    Q.Enque(8);  Q.Print();
}


