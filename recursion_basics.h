//
// Created by DELL on 11/4/2020.
//

#ifndef DATASTRUCTURESANDALGOS_RECURSION_BASICS_H
#define DATASTRUCTURESANDALGOS_RECURSION_BASICS_H

#endif //DATASTRUCTURESANDALGOS_RECURSION_BASICS_H
#include <iostream>
using namespace std;
int factorial(int n){

    if(n==0){return 1;}//base step

    return n*factorial(n-1);//recursive step


}

void factorial_demo(){
    int n;
    cout<<"Give me integer n"<<endl;

    cin>>n;
    int result = factorial(n);
    cout<<result<<endl;

}


//fabbonacci by recursion

int fib(int n){

    if(n<=1){return n;}

    return fib(n-1)+fib(n-2);
}

void fabb_demo(){
    int n;
    cout<<"Give me integer n"<<endl;

    cin>>n;
    int result = fib(n);
    cout<<result<<endl;

}


int  power_recursion(int x,int n){

    if(n==0){return 1;}

    return x*power_recursion(x,n-1);

}
