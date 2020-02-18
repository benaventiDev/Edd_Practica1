//
// Created by benav on 2/16/2020.
//

#ifndef TEST4_STACK_H
#define TEST4_STACK_H
#include "node.h"
#include "linkedList.h"
#include "doubleLinkedList.h"
#include <stdlib.h>

namespace edd{
    template <typename T>
    class stack{
    private:
        doubleLinkedList<T> *llist;
    public:
        stack();
        void push(T*);
        T* pop();
        T* peek();
        bool isEmpty();
        int getSize();

    };

}



#endif //TEST4_STACK_H
