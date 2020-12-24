//
// Created by DELL on 11/18/2020.
//

#ifndef DATASTRUCTURESANDALGOS_BUBBLESORT_H
#define DATASTRUCTURESANDALGOS_BUBBLESORT_H

#endif //DATASTRUCTURESANDALGOS_BUBBLESORT_H

#include <iostream>
using namespace std;

/*
 * ================BUBBLE SORT ALGO=================
 * 1. scan the array
 * 2.comapre to adjacent
 * 3.if > then swap
 * 4.if not move next
 * 5. swap ->the postion
 * */

//runn till n-2 id adjacent smaller swap
//2 parts unsorted sorted

//from right wgere greater with ach pass become sorted
// for k n-1 passes we are guranteed to be sorted


//Big (0) of n^2 it is a slow running algorithm



void simple_bubble_sort(int X[],int n){



    for(int i=0;i<n-1;i++){//after n-1 passes array is sorted

        //in each pass traverse till n-2 and swap j and j+1 element if
        //j > j+1

        for(int j=0; j<n-2;j++){

            if(X[j]>X[j+1]){
                //swap the elements j and j+1 index
                int temp = X[j];
                X[j]=X[j+1];
                X[j+1]= temp;
            }

        }



    }


}


void bubble_sort_main(int A[], int n){


    simple_bubble_sort(A,n);

    for(int i=0;i<n;i++){
        std::cout<<A[i]<<"  ";
    }

    cout<<" "<<endl;


}
