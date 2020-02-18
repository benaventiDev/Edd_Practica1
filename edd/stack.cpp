//
// Created by benav on 2/18/2020.
//
#include <iostream>
#include "stack.h"


template <typename T>
edd::stack<T>::stack(){//LIFO
    llist = new doubleLinkedList<T>();
}

template <typename T>
T* edd::stack<T>::pop(){
    if(llist->getSize()==0){
        return nullptr;
    }
    T* last = llist->getLast();
    llist->removeAt(getSize()-1);
    return last;
}

template <typename T>
void edd::stack<T>::push(T* data){
    llist->addLast(data);
}

template <typename T>
T* edd::stack<T>::peek(){
    return llist->getLast();
}

template <typename T>
bool edd::stack<T>::isEmpty(){
    return llist->getSize() == 0;
}

template <typename T>
int edd::stack<T>::getSize(){
    return llist->getSize();
}
