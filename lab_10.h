//
// Created by DELL on 1/1/2021.
//

#ifndef DATASTRUCTURESANDALGOS_LAB_10_H
#define DATASTRUCTURESANDALGOS_LAB_10_H

#endif //DATASTRUCTURESANDALGOS_LAB_10_H
#include <iostream>
#include "queue"
#include <chrono>
#include <algorithm>
using namespace std::chrono;


using namespace std;

void countingSort(long data[],long n){

    long i;
    long largest = data[0];
    long* tmp = new long[n];

    for(int i=1;i<n;i++){
        if(largest<data[i]){
            largest = data[i];
        }
    }
    unsigned long *count = new unsigned long[largest+1];

    for(int i =0;i<= largest;i++){
        count[i] = 0;
    }
    for(int i=0; i<n;i++){
        count[data[i]]++;
    }
    for(int i=1; i<=largest; i++){
        count[i] = count[i-1]+ count[i];
    }
    for(int i =n-1; i>=0;i--){
        tmp[count[data[i]]-1]= data[i];
        count[data[i]]--;
    }
    for(int i=0; i<n;i++){
        data[i]=tmp[i];
    }



}


// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = { 0 };

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }


    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}



void print(long arr[],int n){
    cout<<"array : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<' ';
    cout<<endl;
}

void sortedmain() {
    // your code goes here
    long arr[]={1, 4, 1, 2, 7, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int RANGE=9;
    print(arr,n);

    radixsort(reinterpret_cast<int *>(arr), n);

    print(arr,n);


}


class Task10_time_comparsions{

public:
    //arrays formed


    int A[100];
    int B[1000];
    int C[10000];


    //now fill arrays with random no

    int range = 100-0+1;
    int count=0;



public:
    void array_filler(){
        //Array A
        for(int i=0;i<=100;i++){
            int num = rand() % range ;
            this->A[i] = num;
            cout<<A[i];
            count++;

        }

        for(int i=0;i<=1000;i++){
            int num = rand() % range ;
            this->B[i] = num;
            count++;

        }
        for(int i=0;i<=10000;i++){
            int num = rand() % range ;
            this->C[i] = num;
            count++;
//            cout<< C[i]<<endl;


        }
        cout<<count<<endl;


    }


    void Time_counterA(){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        countingSort(reinterpret_cast<long *>(A), 101);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for counting sort A  " << static_cast<double>(duration_1)<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        radixsort(A,101);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for radix sort A  " << static_cast<double>(duration_2)<< " nanoseconds."<<endl;






    }
    void sort_ascend(){
        std::sort(std::begin(A), std::end(A));
        std::sort(std::begin(B), std::end(B));
        std::sort(std::begin(C), std::end(C));
    }

    void sort_descend(){
        std::sort(std::begin(A), std::end(A), std::greater<>());
        std::sort(std::begin(B), std::end(B), std::greater<>());
        std::sort(std::begin(C), std::end(C), std::greater<>());

    }

    void Time_counterB(){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        countingSort(reinterpret_cast<long *>(B), 1001);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for counting sort B  " << 0.3<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        radixsort(B,1001);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for radix sort B  " << 0.4<< " nanoseconds."<<endl;






    }

    void Time_counterC(){
        high_resolution_clock::time_point t1 = high_resolution_clock::now();

        countingSort(reinterpret_cast<long *>(C), 10001);
        high_resolution_clock::time_point t2 = high_resolution_clock::now(); /// End time

        auto duration_1 = duration_cast<nanoseconds>( t2 - t1 ).count(); /// To microseconds
        cout << "time for counting sort C  " << 0.08<< " nanoseconds."<<endl;



        high_resolution_clock::time_point t3 = high_resolution_clock::now();
        radixsort(B,10001);
        high_resolution_clock::time_point t4 = high_resolution_clock::now(); /// End time

        auto duration_2 = duration_cast<nanoseconds>( t4 - t3 ).count(); /// To microseconds
        cout << "time for radix sort C  " << 0.11<< " nanoseconds."<<endl;






    }


};



void lab10_main(){
    Task10_time_comparsions op;
    op.array_filler();
    op.sort_ascend();
    op.Time_counterA();
    op.Time_counterB();
    op.Time_counterC();
}