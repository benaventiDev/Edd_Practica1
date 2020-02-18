//
// Created by benav on 2/16/2020.
//

#ifndef TEST4_LINKEDLIST_H
#define TEST4_LINKEDLIST_H
#include "node.h"
#include <stdlib.h>

namespace edd{
    template <typename T>
    class linkedList{

    private:
        node<T> *first;
        node<T> *last;
        node<T> *currentNode;
        node<T> *currentNodeBackup;
        int size;
    public:
        linkedList();
        void addLast(T *);
        void addFirst(T *);
        bool addAt(T *, int);
        void clear();
        bool clone();
        bool contains(T *);
        T* getAt(int);
        T* getFirst();
        T* getLast();
        int getSize();
        int indexOf(T);
        int removeAt(int);
        T* toArray();

        //This is for the iterator
        void begin();
        bool hasNext();
        T* next();


    };

}


#endif //TEST4_LINKEDLIST_H
