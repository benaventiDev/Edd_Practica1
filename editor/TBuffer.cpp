//
// Created by benav on 2/18/2020.
//
#include "TBuffer.h"

TBuffer::TBuffer(){
    mainText = new doubleLinkedList<char>();
    currentPos = 0;
}


void TBuffer::addCharAt(char c, int index){
    currentPos++;
    mainText->addAt(c, index);
}

doubleLinkedList<char> * TBuffer::getMainText(){
    return mainText;
}

int TBuffer::getCurrentPos(){
    return currentPos;
}






