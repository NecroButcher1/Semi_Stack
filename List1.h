#ifndef LIST1_H_INCLUDED
#define LIST1_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BitContainer.h"
using namespace std;
enum err{ERR_MEM=1,EMPTY_OBJ=2,END=3};
template<typename T>
class List1{
private:
    struct Node{
        T data;
        Node *next;
    };
    typedef Node *PNode;
    PNode ptr,head;
    int errcode;
    BitContainer<3> bit;
public:
    List1(){
        bit.Set(1);
        errcode = 0;
        ptr=NULL;
        head=NULL;
    }
    void err_clear(){
        errcode=0;
        bit.Clear();
    }
    int get_err(){
        if(bit.test(0))errcode=ERR_MEM;
        if(bit.test(1))errcode=EMPTY_OBJ;
        if(bit.test(2))errcode=END;
        return errcode;
    }
    bool isEmpty(){
        bool t=false;
        if(head==NULL)t=true;
        return t;
    }
    bool inTheEnd(){
        bool t=false;
        if(ptr->next==NULL)t=true;
        return t;
    }
    void Insert(T _data){
        PNode p = new Node;
        bit.Clear(0);
        if(p==NULL)bit.Set(0);
        else{
            p->data=_data;
            p->next=NULL;
            if(head==NULL){
                p->next=head;
                head=p;
                ptr=p;
            }
            else{
                p->next=ptr->next;
                ptr->next=p;
            }
        }
    }
    void Extract(T &_data){
        bit.Clear(2);
        bit.Clear(1);
        PNode p;
        if(isEmpty())bit.Set(1);
        else{
            if(inTheEnd()){
                bit.Set(2);
                p=head;
                head=NULL;
                ptr=NULL;
            }
            else{
                p=ptr->next;
                ptr->next=p->next;
            }
            _data=p->data;
        }
    }
    void get(T &_data){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
            PNode p;
            if(inTheEnd()){
                bit.Set(2);
                p=head;
            }
            else{
                p=ptr->next;
            }
            _data=p->data;
        }
    }
    void put(T _data){
        bit.Clear(1);
        if(isEmpty())bit.Set(1);
        else{
            PNode p;
            if(inTheEnd()){
                p=head;
            }
            else{
                p=ptr->next;
            }
            p->data=_data;
        }
    }
    void move_forward(){
        bit.Clear(1);
        bit.Clear(2);
        if(isEmpty())bit.Set(1);
        else{
            if(ptr->next)ptr=ptr->next;
            else bit.Set(2);
        }
    }
    void move_beg(){
        if(isEmpty())bit.Set(1);
        else{
            ptr=head;
        }
    }
    void make_empty(){
        while(head!=NULL)head=head->next;
        ptr=NULL;
        head=NULL;
        bit.Set(1);
    }
};

#endif // LIST1_H_INCLUDED
