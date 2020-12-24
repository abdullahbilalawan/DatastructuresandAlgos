//
// Created by DELL on 12/18/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB09_H
#define DATASTRUCTURESANDALGOS_LAB09_H

#endif //DATASTRUCTURESANDALGOS_LAB09_H
#include <iostream>
#include "quicksort.h"


#include <chrono>
#include <algorithm>

using namespace std::chrono;
using namespace std;


class time_comparsions{

public:
    //arrays formed


    int A[100];
    int B[1000];
    int C[10000];
    int D[100000];



    //now fill arrays with random no

    int range = 100-0+1;
    int count=0;



public:
    void array_filler(){
        //Array A
        for(int i=0;i<=100;i++){
            int num = rand() % range ;
            this->A[i] = num;

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



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        quicksort(A,0,100);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort A  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;




    }
    void sort_ascend(){
        std::sort(std::begin(A), std::end(A));
        std::sort(std::begin(B), std::end(B));
        std::sort(std::begin(C), std::end(C));
    }

    void sort_descend(){
        std::sort(std::begin(A), std::end(A), std::greater<>());
        std::sort(std::begin(B), std::end(B), std::greater<>());
        std::sort(std::begin(C),  std::end(C), std::greater<>());

    }


    void Time_counterB(){


        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        quicksort(B,0,1000);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort B  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;





    }

    void Time_counterC(){



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        quicksort(C,0,10000);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort C  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;






    }
    void Time_counterD(){



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        quicksort(D,0,100000);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for selection sort C  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;






    }





};



void lab9_runner(){

    time_comparsions tc;
    tc.array_filler();
    tc.sort_descend();

    tc.Time_counterA();
    tc.Time_counterB();
    tc.Time_counterC();


}