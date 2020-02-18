//
// Created by benav on 2/16/2020.
//

#ifndef TEST4_CIRCULARLINKEDLIST_H
#define TEST4_CIRCULARLINKEDLIST_H
#include "node.h"

namespace edd{
    template <typename T>
    class circularLinkedList{

    private:
        node<T> *first;
        node<T> *last;
        node<T> *currentNode;
        node<T> *currentNodeBackup;
        int size;
    public:
        circularLinkedList();
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
        void end();
        bool hasNext();
        bool hasPrevious();
        T* next();
        T* previous();

    };

}


#endif //TEST4_CIRCULARLINKEDLIST_H
