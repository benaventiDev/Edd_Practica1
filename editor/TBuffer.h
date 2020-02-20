//
// Created by benav on 2/18/2020.
//

#ifndef EDDPRACTICA1_TBUFFER_H
#define EDDPRACTICA1_TBUFFER_H

#include "../edd/doubleLinkedList.h"
using namespace edd;

class TBuffer{
private:
    doubleLinkedList<char> *mainText;
    int currentPos;

public:
    TBuffer();
    void addCharAt(char, int);

    doubleLinkedList<char> * getMainText();
    int getCurrentPos();




};



#endif //EDDPRACTICA1_TBUFFER_H
