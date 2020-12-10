//
// Created by DELL on 10/31/2020.
//

#ifndef DATASTRUCTURESANDALGOS_STRINGREVERSAL_H
#define DATASTRUCTURESANDALGOS_STRINGREVERSAL_H

#endif //DATASTRUCTURESANDALGOS_STRINGREVERSAL_H


#include <iostream>
#include <stack>
#include <cstring>

using namespace std;



void Reverse_Stack(char c[],int n){
    stack<char> S;
// loop for push
    for(int i=0;i<n;i++){
        S.push(c[i]);
    }
//loop for pop

for(int i=0;i<n;i++){

    c[i]=S.top();
    S.pop();
}




}


class my_Stack{

private:

    char A[101];
    int top;

public:
    void Push(int x);
    void Pop();
    int TOp();
    bool IsEmpty();


};


void demo_reverse_string(){

    char  C[51];
    printf("Enter a string");
    gets(C);
    Reverse_Stack(C,strlen(C));
    printf("output= %s",C);
}
