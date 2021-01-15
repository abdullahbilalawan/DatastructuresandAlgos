//
// Created by DELL on 12/25/2020.
//

#ifndef DATASTRUCTURESANDALGOS_ASSIGNMENT2_H
#define DATASTRUCTURESANDALGOS_ASSIGNMENT2_H

#endif //DATASTRUCTURESANDALGOS_ASSIGNMENT2_H

#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;


void nested_loop(int n){
    for(int i=0; i<n; i++){
        //inside first loop
        for(int j=0; j<2*i; j++){
            //inside second loop
            int k=j;
            while(k>=0){
                k=k-1;
            }
        }
    }

}

void analyze_loop(){


    // i will check time of loop for
    /**
     * 100
     * 1000
     *10000
     * 100000
     * 1000000  e.t.c */
    int y=10;
    for(int x=0;x<20;x++){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        nested_loop(y);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for loop on  " << y << "took  "<< static_cast<double>(duration_1)<< " nanoseconds."<<endl;
        //incremating y
        y+=50;

    }

}