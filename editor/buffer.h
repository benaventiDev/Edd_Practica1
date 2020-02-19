#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <vector>
#include "../edd/doubleLinkedList.h"

using namespace std;
using namespace edd;

class Buffer
{
private:
    doubleLinkedList<char> *mainText;
    int newLineCounter;
public:
    Buffer();

    vector<string> lines;

    /* Some helper functions */
    void addCharAt( int, char);
    void insertLine(string, int);
    void appendLine(string);
    void removeLine(int);

    /* Substitutes all tabs in string for 4 spaces, so that
     * the tabs won't screw everything up */
    string remTabs(string);


    //TODO: my fucntions
    int getTextSize();
    string getLine(int);
    string* getLines();// Its an array that returns every line
    int getLinesCounter();



};

#endif
