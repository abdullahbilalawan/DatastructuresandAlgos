//
// Created by DELL on 11/18/2020.
//

#ifndef DATASTRUCTURESANDALGOS_SELECTIONSORT_H
#define DATASTRUCTURESANDALGOS_SELECTIONSORT_H

#endif //DATASTRUCTURESANDALGOS_SELECTIONSORT_H


/*
 * left hand unsorted
 *right hand sorted
 *from left select min and shift to right
 *
 * extra memory req
 * extra large -> extra mamory size
 *
 * selection sort by swap takes less size
 * */

#include <iostream>
void selection_sort(int A[],int n){ // O(n2)

    for(int i=0;i<n-1;i++){ //n-2 passes
        int imin = i;//initialize minimum int position var

        //run from i+1th position till n-1
        for(int j=i+1;j<n;j++){
            if(A[j] < A[imin]){ //if min then current
                //pass the position
                imin=j;


            }
        }
        //swap the element to where we take min
        int temp = A[i];
        A[i]=A[imin];
        A[imin]= temp;


    }



}

void sort_main(){

    int A[] ={1,2,5,9,3,2,7,5};
    selection_sort(A,8);

    for(int i=0;i<8;i++){
        std::cout<<i<<"  "<<endl;
    }


}
