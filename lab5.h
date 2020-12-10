//
// Created by DELL on 11/20/2020.
//

#ifndef DATASTRUCTURESANDALGOS_LAB5_H
#define DATASTRUCTURESANDALGOS_LAB5_H

#endif //DATASTRUCTURESANDALGOS_LAB5_H
//parenthesis check using stack of array
#include <iostream>
#include <cstring>

using namespace std;


class Stack
{
private:
    char A[100];  // array to store the stack
    char top;   // variable to mark the top index of stack.
public:
    // constructor
    Stack()
    {
        top = -1; // for empty array, set top = -1
    }

    // Push operation to insert an element on top of stack.
    void Push(char x)
    {
        if(top == 100 -1) { // overflow case.
            printf("Error: stack overflow\n");
            return;
        }
        A[++top] = x;
    }

    // Pop operation to remove an element from top of stack.
    void Pop()
    {
        if(top == -1) { // If stack is empty, pop should throw error.
            printf("Error: No element to pop\n");
            return;
        }
        top--;
    }

    // Top operation to return element at top of stack.
    int Top()
    {
        return A[top];
    }

    // This function will return 1 (true) if stack is empty, 0 (false) otherwise
    int IsEmpty()
    {
        if(top == -1) return 1;
        return 0;
    }


    // This will print all the elements in the stack at any stage.
    void Print() {
        int i;
        printf("Stack: ");
        for(i = 0;i<=top;i++)
            printf("%d ",A[i]);
        printf("\n");
    }
};


bool check_bracket_balance(string expression){

    bool balance = true;
    char top;
    char stringarray[1024];
    strcpy(stringarray, expression.c_str());

    int test_cases = stringarray[0];

    Stack stack;


    for(int i=1;i<expression.length();i++){

        //check if starting if yes then add push into stack

        if(&stringarray[i]=="{"||&stringarray[i]=="("||&stringarray[i]=="["){

            cout<<"Entering into stack"<<stringarray[i]<<endl;
            stack.Push(stringarray[i]);
            continue;
        }

        //now check if stack is empty return empty
        if(stack.IsEmpty()){
            return false;
        }




        switch (stringarray[i]) { //create a switch to see closing braces

            case ')':
                top = stack.Top();//extract the top of stack
                stack.Pop();//pop the top element
                //check if it is ( if yes balanced
                //other wise unbalanced
                if (top == '{' || top =='['){
                    balance= false;
                }
                break;


            case '}':
                top = stack.Top();//extract the top of stack
                stack.Pop();//pop the top element
                //check if it is ( if yes balanced
                //other wise unbalanced
                if (top == '(' || top =='['){
                    balance= false;
                }
                break;
            case ']':
                top = stack.Top();//extract the top of stack
                stack.Pop();//pop the top element
                //check if it is ( if yes balanced
                //other wise unbalanced
                if (top == '(' || top =='{'){
                    balance= false;
                }
                break;



        }//switch ends


        if(stack.IsEmpty()){
            return true;
        }








    }

    return balance;





}



void lab5_demo(string ep){

    if(check_bracket_balance(ep)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"non balanced"<<endl;
    }
}