//
// Created by DELL on 11/25/2020.
//

#ifndef DATASTRUCTURESANDALGOS_MERGESORT_H
#define DATASTRUCTURESANDALGOS_MERGESORT_H

#endif //DATASTRUCTURESANDALGOS_MERGESORT_H
#include <iostream>

using namespace std;


void merge(int*A,int*L,int*R,int leftcount,int rightcount){
    // we took input of two L and R array
    //A combined array and L and R counts


    int i,j,k;//for keeping the array counts
    i=0;j=0;k=0;

    while(i<leftcount && j<rightcount){

        if(L[i]<R[i]){//if at that index L or R has smaller value
            A[k++] = L[i++];
        }
        else{
            A[k++]=R[j++];
        }
    }
    //now if some of them is left we will append it

    while (i<leftcount){
        A[k++]= L[i++];
    }

    while (j<rightcount){
        A[k++]=R[j++];
    }






}


void merge_sort(int *A,int n){

    int mid,i, *L, *R;
    mid = n/2;


    if(n<2){
        return;
    }

    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*)malloc(mid*sizeof(int));
    R = (int*)malloc((n- mid)*sizeof(int));

    for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

    merge_sort(L,mid);  // sorting the left subarray
    merge_sort(R,n-mid);  // sorting the right subarray
    merge(A,L,R,mid,n-mid);  // Merging L and R into A as sorted list.
    free(L);
    free(R);



}