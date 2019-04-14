#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#define STACK_EMPTY 1

using namespace std;
typedef unsigned short int USI;
typedef int TElem;
template<typename T>
class Stack{
private:
    struct Node{
        T Data;
        Node *next;
    };
    Node *ptr;
    USI errorcode;
public:
    typedef Node *PNode;
    Stack(){
        ptr=NULL;
        errorcode = 0;
    }
    bool isEmpty(){
        bool Empty=false;
        if(ptr==NULL)Empty=true;
        return Empty;
    }
    void DoEmpty(){
        PNode tmp;
        while(ptr!=NULL){
            tmp=ptr;
            ptr=ptr->next;
            delete tmp;
            tmp=NULL;
        }
    }
    void pop(T& elem){
        if(ptr==NULL){
            errorcode = STACK_EMPTY;
        }
        else{
            elem = ptr->Data;
            PNode tmp =ptr;
            ptr =ptr->next;
            delete ptr;
            tmp=NULL;
        }
    }
    void push(T elem){
        PNode TempNode = new Node;
        TempNode->next = ptr;
        TempNode->Data = elem;
        ptr=TempNode;
    }
    ~Stack(){
        DoEmpty();
    }
    USI GetErr(){
        USI out = errorcode;
        errorcode = 0;
        return out;
    }
};

#endif // STACK_H_INCLUDED
