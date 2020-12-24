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
            return 1;
        }


        unsigned long long int i = 0;
        unsigned long long int prev_fiv = 1;
        unsigned long long int result = 1;


        while (i<n-2){
            int temp=result;
            result=result+prev_fiv;
            prev_fiv=temp;
            i++;

        }



        return result;


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
        unsigned long long int fact= 1;int i;

        for(i=1;i<=n;i++){

            fact = fact * i;

        }

        return fact;
    }


};

void test(){
    Factorial ff;
    int fab1 =ff.iterarive(6);
    int fab2 = ff.recursive(6);
    cout<<fab1<<"   "<<fab2<<endl;
}


class Time_Operations{

public:

    Fabbonacci fabbonacci;
    Factorial fac;


    unsigned long long int input(){
        unsigned long long int n;

        cout<<"Enter value of n"<<endl;
        cin>>n;

        return n;
    }



    void fabbonacci_evaluation(unsigned long long int n){

        cout<<"====================================TIME COMPARISON FABBONACCI=============================="<<endl;


        cout<<" ++++++++++++++++++++++value of n is+++"<< n<<"   ++++++++++++++++++";



//        clock_t startTime ;

        high_resolution_clock::time_point t1 = high_resolution_clock::now(); /// Start time


        unsigned long long int fab_r_result = fabbonacci.recursive(n);
        cout<<"value of fab"  <<fab_r_result<<endl;

//        clock_t end_tim;

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


        cout<<" value of n is"<< n<<endl;



//        clock_t startTime = clock();
        high_resolution_clock::time_point t6 = high_resolution_clock::now(); /// Start time


        unsigned long long int fac_r_result = fac.recursive(n);
        cout<<fac_r_result;
        high_resolution_clock::time_point t7 = high_resolution_clock::now(); /// End time

        auto duration_4 = duration_cast<nanoseconds>( t7 - t6 ).count(); /// To microseconds
        cout << "time for recursive  factorial " << static_cast<double>(duration_4)<< " nanoseconds."<<endl;


        high_resolution_clock::time_point t8 = high_resolution_clock::now(); /// Start time

        unsigned long long int fab_i_result = fac.iterarive(n);

        high_resolution_clock::time_point t9 = high_resolution_clock::now(); /// End time
        cout<<"factorial Value: "<<fab_i_result <<endl;

        auto duration_5 = duration_cast<nanoseconds>( t9 - t8 ).count(); /// To microseconds
        cout << "time for iterative  factorial " << static_cast<double>(duration_5)<< " nanoseconds."<<endl;








    }







};



void  interface(){

    Time_Operations oper;
    unsigned long long int count_0 =0;
    unsigned long long int count_1 =0;




//    while (count_1<5){
//        unsigned long long int n=oper.input();
//        oper.factorial_evaluation(n);
//        count_1++;
//
//
//    }
}