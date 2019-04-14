#include "Stack.h"
int main()
{
    Stack<TElem> k;
    TElem el;
    for(USI i=0;i<5;i++){
        cin>>el;
        k.push(el);
    }
    for(USI i=0;i<5;i++){
        k.pop(el);
        cout<<el;
    }
    return 0;
}
