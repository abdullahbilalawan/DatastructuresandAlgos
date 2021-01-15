//
// Created by DELL on 12/3/2020.
//

#ifndef DATASTRUCTURESANDALGOS_COUNTING_DORT_H
#define DATASTRUCTURESANDALGOS_COUNTING_DORT_H

#endif //DATASTRUCTURESANDALGOS_COUNTING_DORT_H
#include <iostream>
using namespace std;

void counting_sort(int *A,int n,int range){

    //create  a array to keep count

    int count[range+1];
    int output[n];

    for(int i=0;i<n+1;i++){//fill the count array with value counts
        ++count[A[i]];
    }

    //update the count array

    for(int i=0;i<range+1;i++){


        count[i]+=count[i+1];//now array contains locations for each value

    }

    //now fill the output array by rading the input aray element
    // then read the positions

    //starting from end of A to get stability
    for(int i=n;i>=0;i--){

        output[--count[A[i]]]= A[i];
    }

    






}


void counting_sort_main(){
    int A[] ={1,2,5,9,3,2,7,5};
    counting_sort(A,9,9);

    for(int i=0;i<8;i++){
        cout<<A[i]<<"  "<<endl;
    }

}