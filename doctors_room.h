//
// Created by DELL on 12/3/2020.
//

#ifndef DATASTRUCTURESANDALGOS_DOCTORS_ROOM_H
#define DATASTRUCTURESANDALGOS_DOCTORS_ROOM_H

#endif //DATASTRUCTURESANDALGOS_DOCTORS_ROOM_H


#include <iostream>
#include <stack>
using namespace std;
#include <list>
class Queue{
public:
    int array[10];
    string A[10];
    int front=-1;
    int rear=-1;

    int N=sizeof(array);


    bool isempty(){
        if(front==-1&& rear==-1){
            return true;
        }
        else{
            return false;
        }

    }
    bool isfull(){
        if (rear==sizeof(array)){
            return true; // if queue is full then return true

        }
        else{
            return false;
        }
    }
    void clearall(){
        fill(std::begin(array),std::end(array),0);
    }

    int front_id(){

        return  array[front];

    }
    void Enqueue(int x , string y){
        if ((rear+1)%N==front){

        }


        else if (isempty())
        {
            front=0;
            rear=0;
            array[rear]=x; // if queue is empty then add value to index0
            A[rear]=y;

        }
        else{
            rear=(rear+1)%N;
            array[rear]=x;
            A[rear]=y;
        }
    }
    void Dequeue(){
        if (isempty()){
            return; // if queue is empty then nothing will be dequed
        }
        else if(front==rear){
            front=rear=-1;//empty Queue

        }
        else {
            front=(front+1)%N; // inceremtn front
        }

    }

    void Print(){

        cout<<"***********************************DISPLAY IN ALPHABETICALLY SORTED WAY*****************"<<endl;
        while(front!=rear){
            cout<<"Name   "<<A[front];cout<<"    id"<<array[front]<<endl;
            front++;
            if(front==rear){
                break;
                cout << ' -  ';

            }
            cout<<endl;
        }
    }

    void sort_array(){

        //bubble sort
        for(int i=0;i<=9;i++){

            for(int j=0;j<8;j++){

                if(A[j][0]>A[j+1][0]){//check each element next  if smaller than swap
                    //swap names

                    string temp = A[j];
                    A[j]=A[j+1];
                    A[j] = A[j+1];
                    A[j+1]=temp;

                    //swap ids
                    int tem = array[j];
                    array[j]=array[j+1];
                    array[j+1]= tem;


                }
            }


        }



    }
};
class waitingRoom{
public:
    int id=1;

    Queue queue;
    list<string>namesofallpatients;
    int noofnames;
    char names[10];
    void RegisterPatient(){

        if(!queue.isfull()){


            string name;//here is name
            cout<<"enter name of patient "<<endl;
            cin>>name;


            queue.Enqueue( id , name);
            //wait


            id++;
            cout << "id of patient is:  " << id  << " name of patient is:" << name <<endl;
            noofnames++;}

      }


    void ServePatient(){
        // serve all patients


        queue.Dequeue();
        cout<<"The patient"<<queue.front_id()<<endl;



    }
    // make function cancelall

    void CancelAll(){

        //to cancelall
        queue.clearall();


    }

    bool CanDoctorGoHome(){
        while(queue.isempty()){
            return true;

        }
        return  false;



    }
    void ShowAllPatients(){
        //display
        queue.sort_array();
        queue.Print();




    }
};




int doctor_main(){
    cout<<" token generator"<< endl;
    waitingRoom wR;
    int r=0;
    while (r<9){
        wR.RegisterPatient();
        r++;

    }
    wR.ShowAllPatients();

}









