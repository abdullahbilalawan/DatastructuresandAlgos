//
// Created by DELL on 12/4/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB7_H
#define DATASTRUCTURESANDALGOS_LAB7_H

#endif //DATASTRUCTURESANDALGOS_LAB7_H
#include <iostream>
#include<time.h>
#include <chrono>
using namespace std::chrono;

using namespace std;



class Fabbonacci {

public:

//fibbonacci recursive approach


//iterative approach


    unsigned long long int iterative(unsigned long long int n) {

        if (n < 1) {
            return n;
        }


        unsigned long long int fib = 1;
        unsigned long long int prev_fiv = 1;
//        unsigned long long int z = 0;


        for (unsigned long long int i = 2; i <= n; i++) {
            unsigned long long int temp = fib;
            fib+= prev_fiv;
            prev_fiv= temp;


        }
        return fib;


    }

public:
    unsigned long long int recursive(unsigned long long int n) {
        if (n <= 1)
            return n;
        return recursive(n - 1) + recursive(n - 2);
    }
};
class Factorial{

public:

    unsigned long long int recursive(unsigned long long int n){

        if(n==0){return 1;}//base step

        return n*recursive(n-1);//recursive step




    }

    unsigned long long int iterarive(unsigned long long int n){


        if(n==0){
            return 1;
        }
        unsigned long long int fact= 1,i;

        for(i=1;i<=n;i++){

            fact = fact * i;

        }

        return fact;
    }


};



class Time_Operations{

public:

    Fabbonacci fabbonacci;
    Factorial factorial;


    unsigned long long int input(){
        unsigned long long int n;

        cout<<"Enter value of n"<<endl;
        cin>>n;

        return n;
    }



    void fabbonacci_evaluation(unsigned long long int n){

        cout<<"====================================TIME COMPARISON FABBONACCI=============================="<<endl;


        cout<<" ++++++++++++++++++++++value of n is+++"<< n<<"   ++++++++++++++++++";



//        clock_t startTime = clock();

        high_resolution_clock::time_point t1 = high_resolution_clock::now(); /// Start time


        unsigned long long int fab_r_result = fabbonacci.recursive(n);
        cout<<"value of fab"  <<fab_r_result<<endl;

//        clock_t end_time = (clock() -startTime) /CLOCKS_PER_SEC;

        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time
        auto duration = duration_cast<microseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for recursive " << static_cast<double>(duration)<< " microseconds."<<endl;



//        cout<<"   TIme for fabbonacci recursive is    " << end_time;
        high_resolution_clock::time_point t3 = high_resolution_clock::now(); /// Start time

        unsigned long long int fab_i_result = fabbonacci.iterative(n);
        cout<<"value of fab "  <<fab_i_result<<endl;

        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time
        auto duration_2 = duration_cast<microseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for iterative" << static_cast<double>(duration_2)<< " microseconds."<<endl;


//        cout<<"    TIme for fabbonacci iterative  is    " << end_time2<<endl;








    }


    void factorial_evaluation(unsigned long long int n){


        cout<<"====================================TIME COMPARISON FACTORIAL=============================="<<endl;


        cout<<" value of n is"<< n;



        clock_t startTime = clock();

        unsigned long long int fac_r_result = factorial.recursive(n);

        clock_t end_time = clock() -startTime;

        cout<<"   TIme for factorial recursive is    " << end_time;
        clock_t startTime2 = clock();

        unsigned long long int fab_i_result = factorial.iterarive(n);

        clock_t end_time2 = clock() -startTime2;


        cout<<"    TIme for factorial iterative  is    " << end_time2<< endl;








    }







};



void  interface(){

    Time_Operations oper;
    unsigned long long int count_0 =0;
    unsigned long long int count_1 =0;


    while (count_0<4){
        unsigned long long int n=oper.input();
        oper.fabbonacci_evaluation(n);
        count_0++;


    }

    while (count_1<5){
        unsigned long long int n=oper.input();
        oper.factorial_evaluation(n);
        count_1++;


    }
}