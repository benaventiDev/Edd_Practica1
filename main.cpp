#include <iostream>
#include <pdcurs36/curses.h>
#include <string>
#include "editor/editor.h"

#include "edd/node.h"
#include "edd/linkedList.h"

void curses_init();
using namespace edd;





int main(int argc, char *argv[]) {



    Editor ed;
    string fn = "";
    if(argc > 1)
    {
        fn = argv[1];               // Set the filename
        ed = Editor(fn);
    }
    else
    {
        ed = Editor();
    }

    curses_init();                  // Initialize ncurses

    while(ed.getMode() != 'x')
    {
        ed.updateStatus();
        ed.printStatusLine();
        ed.printBuff();
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