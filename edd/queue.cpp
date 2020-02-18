//
// Created by benav on 2/18/2020.
//

#include "queue.h"


template <typename T>
edd::queue<T>::queue(){ //FIFO
    llist = new doubleLinkedList<T>();
}

template <typename T>
bool edd::queue<T>::isEmpty(){
    return llist->getSize() == 0;
}

template <typename T>
int edd::queue<T>::getSize(){
    return llist->getSize();
}

template <typename T>
T* edd::queue<T>::getFront(){
    return llist->getFirst();
}

template <typename T>
T* edd::queue<T>::dequeue(){
    if(llist->getSize()==0){
        return nullptr;
    }
    T* first = llist->getFirst();
    llist->removeAt(0);
    return first;
}

template <typename T>
void edd::queue<T>::enqueue(T* data){
    llist->addLast(data);
}

template <typename T>
void edd::queue<T>::clear(){
    llist->clear();
}




