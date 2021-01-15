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


void min_heapify(int A[], int i, int n){
    int smallest;
    int L = Left(i);
    int R = Right(i);
    if(L<=n && A[L]<A[i]){
        smallest = L;
    }
    else if(R<=n && A[R]<A[i]){
        smallest = R;
    } else{
        smallest=i;
    }
    if(smallest!=i){

        //swapping the elements between
        int temp = A[i];
        A[i]=A[smallest];
        A[smallest] = temp;

        min_heapify(A,smallest,n);

    }



}


void build_min_heap(int A[], int length){

    for(int i=length/2; i>=1; i--){
        min_heapify(A,i,length);

    }


}

void heap_sort(int A[], int length){
    int heap_size = length;
    build_min_heap(A,n);
    for(int i = length; i>=2;i--){
        int temp = A[i];
        A[i]= A[0];
        A[0] = temp;
        heap_size--;
        min_heapify(A,0,heap_size);


    }



}