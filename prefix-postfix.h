//
// Created by DELL on 11/4/2020.
//

#ifndef DATASTRUCTURESANDALGOS_PREFIX_POSTFIX_H
#define DATASTRUCTURESANDALGOS_PREFIX_POSTFIX_H

#endif //DATASTRUCTURESANDALGOS_PREFIX_POSTFIX_H
#include <iostream>

using namespace std;


// pseudocode for postfix

/*
 create stack s

 expression-1 loop

 if operand push in stack

 op1 and op 1 pop

 perform operation
 push(result)

 */


/*
 *Infix to postfix
 * create a stack s
 * for ito length (exp)-1
 * if exp[i] is operanf
 * result append
 * if exp[i] is operator
 *while its not empty and higher precendence
 * resu;t = res + s.top()
 *s.pop()
 * s.push(exp[i])
 */

// array implementation of quees

// front and end var =-1 que is empty



//create array of 10

//increment to rear only
// from right bcz left is front



class Queue_by_array{

private:
    int A[10];
    int front,rear;


public:
    //default constructor

    Queue_by_array(){
        front=-1;rear=-1; //-1 means empty
    }


    //is empty function

    bool isEmpty(){
        return (front==-1 && rear==-1);


    }

    //


};


