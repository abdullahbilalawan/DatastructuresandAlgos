//
// Created by DELL on 11/4/2020.
//

#ifndef DATASTRUCTURESANDALGOS_PROBLEMS_H
#define DATASTRUCTURESANDALGOS_PROBLEMS_H

#endif //DATASTRUCTURESANDALGOS_PROBLEMS_H


#include <iostream>
#include <cstring>
#include "stack"
using namespace std;


// problem of balancing brackets

/*
 Problem statement
Given an expression only containing upper-case alphabets:
 A-Z, operators: /, * , +, - and characters:
 (,),{,},[,] used to mark start and end of parentheses
 , validate whether the parentheses are balanced or not.
 */

void check_bracket_balance(string expression){
    char stringarray[1024];
    strcpy(stringarray, expression.c_str());

    int test_cases = stringarray[0];

    stack<char> stack;


    for(int i=1;i<test_cases;i++){

        //check if starting if yes then add push into stack

        if(&stringarray[i]=="{"||&stringarray[i]=="("||&stringarray[i]=="["){
            stack.push(stringarray[i]);
        }

        //now checj


        



    }





}