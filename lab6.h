//
// Created by DELL on 11/27/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB6_H
#define DATASTRUCTURESANDALGOS_LAB6_H

#endif //DATASTRUCTURESANDALGOS_LAB6_H
#include <iostream>
#include "list"


using namespace std;


class Queue_array{

private:
    int A[6];
    int front,rear;


public:
    //default constructor

    Queue_array(){
        front=-1;rear=-1; //-1 means empty
    }


    //is empty function

    bool isEmpty(){
        return (front==-1 && rear==-1);


    }

    //is full function

    bool IsFull()
    {
        return rear==6;//checking if next element is the front of array
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
            rear = (rear+1);//rear goes to next element
        }
        A[rear] = x;

    }

    int First_element(){
        return A[front];
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
            front = (front+1);//incrementing front
        }
    }


    void Print(){


        // Finding number of elements in queue
        int count = (rear-front) + 1;
        cout<<"Queue       : ";
        for(int i = 0; i <count; i++)
        {
            int index = (front+i) ; // Index of element while travesing circularly from front
            cout<<A[index]<<" ";
        }
        cout<<"\n\n";
    }
    // clear que

    void clear_Que(){
        fill( begin( A ), end( A ), 0 );


    }






};



class waiting_room{


public:

    int id=0;
    Queue_array que;
    list<string> names;




    void RegisterPatient(){

        if(!que.IsFull()) {
            string pt_name;
            cout<<"ENter name"<<endl;
            cin>>pt_name;



            id++;
            string c = to_string(id);
            names.push_back(pt_name+" "+c);
            que.Enque(id);
            cout << "Patient registered at id" << id << " " << "wait for ur turn" << endl;
        }else{
            cout<<"no more token generated come tommorw"<<endl;
        }

    }


    void ServePatient(){
        que.Dequeue();
        int front = que.First_element();
        cout<<"Patient id"<< front<<" has been checked"<<endl;
    }

    void ClearAll() {
        que.clear_Que();
        cout<<"que is cleared appontments cancelled due to emergency"<<endl;


    }

    void show_all_patient(){
        names.sort();

        cout<<"Display"<<endl;

        for (auto v : names) {
            std::cout << v << "\n";
        }

        que.Print();



    }






};


void lab6_main(){
    cout<<"==================================WELCOME TO CLINIC========================"<<endl;
    cout<<"))))))))))))))))))))))))))))Generate TOken here((((((((((((((((((((((((((((("<<endl;

   waiting_room room;
   int i=0;
   while(i<5) {
       room.RegisterPatient();
       i++;
   }
   room.show_all_patient();
}