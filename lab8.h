//
// Created by DELL on 12/13/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB8_H
#define DATASTRUCTURESANDALGOS_LAB8_H

#endif //DATASTRUCTURESANDALGOS_LAB8_H

#include "list"
#include <iostream>
#include "BubbleSort.h"
#include "Insertion_slot.h"
#include "Selectionsort.h"
#include<time.h>
#include <chrono>
#include <algorithm>

using namespace std::chrono;

using namespace std;



class Task2_time_comparsions{

public:
    //arrays formed


    int A[100];
    int B[1000];
    int C[10000];


    //now fill arrays with random no

    int range = 100-0+1;
    int count=0;



public:
    void array_filler(){
        //Array A
        for(int i=0;i<=100;i++){
            int num = rand() % range ;
            this->A[i] = num;
            cout<<A[i];
           count++;

        }

        for(int i=0;i<=1000;i++){
            int num = rand() % range ;
            this->B[i] = num;
            count++;

        }
        for(int i=0;i<=10000;i++){
            int num = rand() % range ;
            this->C[i] = num;
            count++;
//            cout<< C[i]<<endl;


        }
        cout<<count<<endl;


    }


    void Time_counterA(){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        bubble_sort_main(A,101);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for bubble sort A  " << static_cast<double>(duration_1)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        selection_sort_main(A,101);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort A  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        insertion_sort_main(A,101);

        high_resolution_clock::time_point t6 = high_resolution_clock::now(); /// End time

        auto duration_3 = duration_cast<nanoseconds>( t6 - t5 ).count(); /// To microseconds
        cout << "time for insertion sort A  " << static_cast<double>(duration_3)<< " nanoseconds."<<endl;



    }
    void sort_ascend(){
        std::sort(std::begin(A), std::end(A));
        std::sort(std::begin(B), std::end(B));
        std::sort(std::begin(C), std::end(C));
    }

    void sort_descend(){
        std::sort(std::begin(A), std::end(A), std::greater<>());
        std::sort(std::begin(B), std::end(B), std::greater<>());
        std::sort(std::begin(C), std::end(C), std::greater<>());

    }

    void Time_counterB(){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        bubble_sort_main(B,1001);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for bubble sort B  " << static_cast<double>(duration_1)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        selection_sort_main(B,1001);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort B  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        insertion_sort_main(B,1001);

        high_resolution_clock::time_point t6 = high_resolution_clock::now(); /// End time

        auto duration_3 = duration_cast<nanoseconds>( t6 - t5 ).count(); /// To microseconds
        cout << "time for insertion sort B  " << static_cast<double>(duration_3)<< " nanoseconds."<<endl;



    }

    void Time_counterC(){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        bubble_sort_main(C,10001);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for bubble sort C  " << static_cast<double>(duration_1)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        selection_sort_main(B,10001);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort C  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t5 = high_resolution_clock::now();
        insertion_sort_main(C,10001);

        high_resolution_clock::time_point t6 = high_resolution_clock::now(); /// End time

        auto duration_3 = duration_cast<nanoseconds>( t6 - t5 ).count(); /// To microseconds
        cout << "time for insertion sort C  " << static_cast<double>(duration_3)<< " nanoseconds."<<endl;



    }


};

class Task3{

    list<int> A;
    list<int> B;
    list<int> C;

    int range =100;
    int count= 0;

    //filling lists by random numbers
    void array_filler(){
        //Array A
        for(int i=0;i<=100;i++){
            int num = rand() % range ;
            A.push_back(num);
            count++;

        }

        for(int i=0;i<=1000;i++){
            int num = rand() % range ;
            B.push_back(num);
            count++;

        }
        for(int i=0;i<=10000;i++){
            int num = rand() % range ;
            C.push_back(num);
            count++;
//            cout<< C[i]<<endl;


        }
        cout<<count<<endl;


    }


    //use stl sort

    void sort_ascend(){
        A.sort();
        B.sort();

    }
    void sort_descend(){
        A.sort();
        A.reverse();
        B.sort();
        B.reverse();
    }


    void ascended_time_measure(){

    }

    void descended_time_measure(){

    }






};




void lab8_runner(){

    Task2_time_comparsions tc;
    tc.array_filler();
    tc.sort_ascend();
    tc.Time_counterA();

}