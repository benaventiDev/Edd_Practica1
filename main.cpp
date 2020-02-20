#include <iostream>
#include <pdcurs36/curses.h>
#include <string>
#include <stdio.h>
#include "editor/Editor.h"

#include "edd/node.h"
#include "edd/doubleLinkedList.h"
#include "edd/linkedList.h"

void curses_init();
using namespace edd;


int main1(){

    char c;
    int x = 0;
    int y = 0;
    std::cout<< "Enter text:" << std::endl;
    Editor ed = Editor();
    do{
        c =getchar();

    }while (c!='.');



/*
    doubleLinkedList<char>* mainText= buffer->getMainText();
    std::cout<< "Size is: " << mainText->getSize() << std::endl;
    string line ="";
    mainText->begin();
    std::cout << "begin text" <<std::endl;
  */
    /*
    Editor ed = Editor();
    int c;
    do{

        c = getchar();
        ed.handleInput(c);

    }while (c != '.');

    ed.test();
*/


    return 0;
}


int main(int argc, char *argv[]) {



    Editor ed;
    string fn = "";
    if(argc > 1)
    {
        fn = argv[1];               // Set the filename
        //ed = Editor(fn);
    }
    else
    {
        ed = Editor();
    }

    curses_init();                  // Initialize ncurses

    while(ed.getMode() != 'x')
    {

        ed.printScreen();
        ed.updateStatus();
        ed.printStatusLine();


        int input = getch();        // Blocking until input
        ed.handleInput(input);
    }


    refresh();                      // Refresh display
    endwin();                       // End ncurses mode



    return 0;
}



void curses_init()
{
    initscr();                      // Start ncurses mode
    noecho();                       // Don't echo keystrokes
    cbreak();                       // Disable line buffering
    keypad(stdscr, true);           // Enable special keys to be recorded
}