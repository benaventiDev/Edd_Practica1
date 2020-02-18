//
// Created by benav on 2/16/2020.
//

#ifndef TEST4_QUEUE_H
#define TEST4_QUEUE_H
#include "node.h"
#include "linkedList.h"
#include "doubleLinkedList.h"
#include <stdlib.h>

namespace edd{
    template <typename T>
    class queue{
    private:
        doubleLinkedList<T> *llist;

    public:
        queue();
        bool isEmpty();
        int getSize();
        T* getFront();
        T* dequeue();
        void enqueue(T*);
        void clear();



    };

}


#endif //TEST4_QUEUE_H
