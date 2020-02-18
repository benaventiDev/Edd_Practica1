//
// Created by benav on 2/16/2020.
//
#include "node.h"
#include <iostream>

template <class T>
edd::node<T>::node(T *value) {
    data = value;
    previous = nullptr;
    next = nullptr;
}

template <class T>
void edd::node<T>::setNext(node *newNode){
    next = newNode;
}

template <class T>
void edd::node<T>::removeNext(){
    next = nullptr;
}

template <class T>
void edd::node<T>::setPrevious(node *newNode){
    previous = newNode;
}

template <class T>
void edd::node<T>::removePrevious(){
    previous = nullptr;
}

template <class T>
edd::node<T> *edd::node<T>::getNext(){
    return next;
}

template <class T>
edd::node<T> *edd::node<T>::getPrevious(){
    return previous;
}

template <class T>
T* edd::node<T>::getData(){
    return data; // retorna un puntero de data
}

template <class T>
bool edd::node<T>::hasNext(){
    return next != nullptr;
}

template <class T>
bool edd::node<T>::hasPrevious(){
    return previous != nullptr;
}

template <class T>
void edd::node<T>::print() {
    std::cout<< *data << std::endl;
}

template <class T>
edd::node<T>::~node(){}

