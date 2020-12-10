//
// Created by DELL on 12/2/2020.
//

#ifndef DATASTRUCTURESANDALGOS_QUICKSORT_H
#define DATASTRUCTURESANDALGOS_QUICKSORT_H

#endif //DATASTRUCTURESANDALGOS_QUICKSORT_H
#include <iostream>
using namespace std;




void swap(int x,int y){


    int temp =x;
    x=y;
    y=temp;
}

int partition(int* A,int start,int end){

    //choose the last element as  pivot

    int pivot = A[end];
    int partition_index = start;


    for(int i =start;i<end;i++){
        if(A[i]<pivot){
            swap(A[i],A[partition_index]);
            partition_index++;
        }

    }

    swap(A[partition_index],A[end]);
    return partition_index;

}

void quicksort(int *A, int start, int end){

    if(start<end){

        int partition_index = partition(A,start,end);
        quicksort(A,start,partition_index-1);
        quicksort(A,partition_index+1,end);

    }





}

void quick_sort_main(){

    int A[] ={1,2,5,9,3,2,7,5};
    quicksort(A,0,7);

    for(int i=0;i<8;i++){
        std::cout<<A[i]<<"  "<<endl;
    }


}
