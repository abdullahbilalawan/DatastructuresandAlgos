//
// Created by DELL on 12/24/2020.
//

#ifndef DATASTRUCTURESANDALGOS_MAX_HEAP_H
#define DATASTRUCTURESANDALGOS_MAX_HEAP_H

#endif //DATASTRUCTURESANDALGOS_MAX_HEAP_H
#include <iostream>
using namespace std;

//**********************************************************************************************
           //IMPLEMENTATION OF MAX HEAP

//************************************************************************************************

//UTILITY FUNCTIONS

int Parent(int i) {return i/2;}
int Left(int i) { return 2*i; }
int Right(int i){return 2*i +1; }


void max_heapify(int A[], int i, int n){
    int largest;
    int L = Left(i);
    int R = Right(i);
    if(L<=n && A[L]>A[i]){
        largest = L;
    }
    else if(R<=n && A[R]>A[i]){
        largest = R;
    } else{
        largest=i;
    }
    if(largest!=i){

        //swapping the elements between
        int temp = A[i];
        A[i]=A[largest];
        A[largest] = temp;

        max_heapify(A,largest,n);

    }



}


void build_max_heap(int A[], int length){

    for(int i=length/2; i>=1; i--){
        max_heapify(A,i,length);

    }


}

void heap_sort(int A[], int length){
    int heap_size = length;
    build_max_heap(A,n);
    for(int i = length; i>=2;i--){
        int temp = A[i];
        A[i]= A[0];
        A[0] = temp;
        heap_size--;
        max_heapify(A,0,heap_size);


    }



}