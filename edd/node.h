//
// Created by benav on 2/16/2020.
//

#ifndef TEST4_NODE_H
#define TEST4_NODE_H
/*
iterator:
hasNext() true then next() has elements



*/

namespace edd{
    template <class T>
    class node{
    private:
        node *next;
        node *previous;
        T *data; // this is a pointer;

    public:
        node(T *);
        void setNext(node *);
        void removeNext();
        void setPrevious(node *);
        void removePrevious();
        node *getNext();
        node *getPrevious();
        bool hasNext();
        bool hasPrevious();
        T* getData();
        void print();// To Delete
        ~node();
    };


}




#endif //TEST4_NODE_H
