//
// Created by DELL on 11/22/2020.
//

#ifndef DATASTRUCTURESANDALGOS_INSERTION_SLOT_H
#define DATASTRUCTURESANDALGOS_INSERTION_SLOT_H

#endif //DATASTRUCTURESANDALGOS_INSERTION_SLOT_H
#include <iostream>
using namespace std;

void insertion_slot(int A[],int n){


    for(int i=1;i<n-1;i++){//loop will execute from 2nd elemeny (1st index to n-1)

        int value= A[i]; //take out the value at that index
        int hole = i;//imaginary hole index


        while (hole>0 && A[hole-1]>value){

            A[hole] = A[hole-1];//shifting the imaginary hole towards left for all
            //greater than value
            hole--;

        }
        A[hole]= value;





    }





}
//Big o of N


void insertion_sort_main(int A[], int n){


    insertion_slot(A,n);

    for(int i=0;i<n;i++){
        std::cout<<A[i]<<"  ";
    }
    cout<<" "<<endl;


}