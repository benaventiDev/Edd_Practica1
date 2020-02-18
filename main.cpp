#include <iostream>
#include <pdcurs36/curses.h>
#include <string>

void curses_init();




int main(int argc, char *argv[]) {







    return 0;
}



void curses_init()
{
    initscr();                      // Start ncurses mode
    noecho();                       // Don't echo keystrokes
    cbreak();                       // Disable line buffering
    keypad(stdscr, true);           // Enable special keys to be recorded
}