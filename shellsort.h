//
// Created by DELL on 12/2/2020.
//

#ifndef DATASTRUCTURESANDALGOS_SHELLSORT_H
#define DATASTRUCTURESANDALGOS_SHELLSORT_H

#endif //DATASTRUCTURESANDALGOS_SHELLSORT_H
#include <iostream>
using namespace std;

void swap(int a, int b){
    int temp = a;
    a=b;
    b=temp;

}






void shellsort(int* A, int n){

    for(int gap = n/2;gap>=1;gap/2){//gap=n/2 and divided by 2 with each pass
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i-gap){
                
            }
        }





    }



}