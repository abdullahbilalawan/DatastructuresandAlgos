//
// Created by DELL on 11/22/2020.
//

#ifndef DATASTRUCTURESANDALGOS_ALIZA_ASSIGNMENT_H
#define DATASTRUCTURESANDALGOS_ALIZA_ASSIGNMENT_H

#endif //DATASTRUCTURESANDALGOS_ALIZA_ASSIGNMENT_H
#include <iostream>
using namespace std;
#include "list"
#include "stack"



class decoderalgorithm{
public:
    void decoderalgo(){

        //take input
        string input;
        std::cout<<"write expression only S and G are incuded"<<std::endl; // we declare that input contain S and G only
        std::cin>>input;

        //make input array to traverse through all characters in input

        char inputarray[input.length()];//length of input array is number of char in input
        //make outputarray
        list<int>outputarray={}; //null
        //call stack
        stack <int> stack;
        //traverse through input

        int i ;
        int m;
        for (i=0;i<<input.length();i++){
            inputarray[m]=input[m];
        }
        // traverse through input and push position of elements in stack
        int x;
        for (x=0;x<input.length()+1;x++){
            stack.push(x);
            //represent data that is beingpushed
            cout<<inputarray[x]<<x<<endl;

            //check whether input is s or g by using if else loop
            if(inputarray[x]='S'){
                while(!stack.empty()){
                    int position=stack.top();
                    outputarray.push_back(position+1);
                    stack.pop();
                }


            }
            else if(inputarray[x]='G'){
                if(x==input.length()){
                    for (int w=0;w<stack.size();w++){
                        int position=stack.top();
                        outputarray.push_back(position);


                    }
                }
                x++;
            }

        }
        cout<<"output is"<<endl;
        for (auto x=outputarray.begin();x!=outputarray.end();++x){
            cout<<*x<<endl;
        }
    }

};