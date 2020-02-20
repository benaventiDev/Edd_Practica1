//
// Created by benav on 2/19/2020.
//

#ifndef EDDPRACTICA1_EDITOR_H
#define EDDPRACTICA1_EDITOR_H

#include <pdcurs36/curses.h>
#include "../edd/doubleLinkedList.h"
#include "../edd/LinkedList.h"
#include <string>
#include <sstream>

using namespace edd;
using namespace std;

class Editor {
private:
    doubleLinkedList<char> *mainText;
    int currentPos, x, y, mode;
    int LinesCounter = 1;
    string status;
public:
    Editor();
    string toString(int i);
    void handleInput(int c);
    void printScreen();
    char getMode() {return mode;}
    void test();



    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
    void moveTo();
    void printStatusLine();
    void updateStatus();
    string tos(int );
    void resetStatus();

};


#endif //EDDPRACTICA1_EDITOR_H
