#include "EditorFirst.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

EditorFirst::EditorFirst()
{
    currentPos = 0;



    //Not my code
    x=0;y=0;mode='i';
    status = "Normal Mode";
    filename = "untitled";

    /* Initializes buffer and appends line to
        prevent seg. faults */
    buff = new Buffer();
    buff->appendLine("");
}

EditorFirst::EditorFirst(string fn)
{
    x=0;y=0;mode='n';
    status = "Normal Mode";
    filename = fn;

    buff = new Buffer();

    ifstream infile(fn.c_str());
    if(infile.is_open())
    {
        while(!infile.eof())
        {
            string temp;
            getline(infile, temp);
            buff->appendLine(temp);
        }
    }
    else
    {
        cerr << "Cannot open file: '" << fn << "'\n";
        buff->appendLine("");
    }
}

void EditorFirst::updateStatus()
{
    switch(mode)
    {
        case 'n':
            // Normal mode
            status = "Normal Mode";
            break;
        case 'i':
            // Insert mode
            status = "Insert Mode";
            break;
        case 'x':
            // Exiting
            status = "Exiting";
            break;
    }
    status += "\tCOL: " + tos(x) + "\tROW: " + tos(y);
}

string EditorFirst::tos(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

void EditorFirst::handleInput(int c){
    buff->addCharAt(currentPos, char(c));
    currentPos++;

}


void EditorFirst::handleInput1(int c)
{
    //TODO: Handle right, left, up and down.

    switch(c)
            {
                case 0x0013:// CTRL + S
                    break;
                case 27:
                    // The Escape/Alt key
                    mode = 'n';
                    break;
                case 0x0008:

                case 127:
                case KEY_BACKSPACE:

                    // The Backspace key
                    if(x == 0 && y > 0)
                    {

                        x = buff->lines[y-1].length();
                        // Bring the line down
                        buff->lines[y-1] += buff->lines[y];
                        // Delete the current line
                        deleteLine();
                        moveUp();
                    }else if(x==0 && y ==0){}
                    else
                    {
                        // Removes a character
                        buff->lines[y].erase(--x, 1);
                    }
                    break;
                case KEY_DC:
                    // The Delete key
                    if(x == buff->lines[y].length() && y != buff->lines.size() - 1)
                    {
                        // Bring the line down
                        buff->lines[y] += buff->lines[y+1];
                        // Delete the line
                        deleteLine(y+1);
                    }
                    else
                    {
                        buff->lines[y].erase(x, 1);
                    }
                    break;
                case KEY_ENTER:
                case 10:
                    // The Enter key
                    // Bring the rest of the line down
                    if(x < buff->lines[y].length())
                    {
                        // Put the rest of the line on a new line
                        buff->insertLine(buff->lines[y].substr(x, buff->lines[y].length() - x), y + 1);
                        // Remove that part of the line
                        buff->lines[y].erase(x, buff->lines[y].length() - x);
                    }
                    else
                    {
                        buff->insertLine("", y+1);
                    }
                    x = 0;
                    moveDown();
                    break;
                case KEY_BTAB:
                case KEY_CTAB:
                case KEY_STAB:
                case KEY_CATAB:
                case 9:
                    // The Tab key
                    buff->lines[y].insert(x, 4, ' ');
                    x += 4;
                    break;
                default:
                    // Any other character
                    buff->lines[y].insert(x, 1, char(c));
                    x++;
                    break;
            }

}

void EditorFirst::moveLeft()
{
    if(x-1 >= 0)
    {
        x--;
        move(y, x);
    }
}

void EditorFirst::moveRight()
{
    if(x+1 < COLS && x+1 <= buff->lines[y].length())
    {
        x++;
        move(y, x);
    }
}

void EditorFirst::moveUp()
{
    if(y-1 >= 0)
        y--;
    if(x >= buff->lines[y].length())
        x = buff->lines[y].length();
    move(y, x);
}

void EditorFirst::moveDown()
{
    if(y+1 < LINES-1 && y+1 < buff->lines.size()) // LINES is /* terminal height */
        y++;
    if(x >= buff->lines[y].length())
        x = buff->lines[y].length();
    move(y, x);
}
void EditorFirst::printBuff() {
    /*This go over screen line by screen line. Screen line is not a real line,
     * is just how many lines are being displayed in the screen */
    string* lines = buff->getLines();

    for (int i = 0; i < LINES - 1; i++){ // LINES is /* terminal height */
        if(i >= buff->getLinesCounter()) // If there are remaining lines in the screen, not being used by the text editor
        {
            move(i, 0); //This erase any text on the lines shown on the screen that may have previous text
            clrtoeol(); // Erase the current line to the right of the cursor.
        } else{ // Here is where I print the actual lines.
            mvprintw(i, 0, lines[i].c_str());
        }
        clrtoeol();
    }

    move(y, x);

}

void EditorFirst::printBuff1() //TODO: Delete
{
    for(int i=0; i<LINES-1; i++) // LINES is /* terminal height */
    {
        if(i >= buff->lines.size())
        {
            move(i, 0);
            clrtoeol(); // Erase the current line to the right of the cursor.
        }
        else
        {
            mvprintw(i, 0, buff->lines[i].c_str());
        }
        clrtoeol();
    }
    move(y, x);
}

void EditorFirst::printStatusLine()
{
    attron(A_REVERSE);
    mvprintw(LINES-1, 0, status.c_str());
    clrtoeol();
    attroff(A_REVERSE);
}

void EditorFirst::deleteLine()
{
    buff->removeLine(y);
}

void EditorFirst::deleteLine(int i)
{
    buff->removeLine(i);
}

void EditorFirst::saveFile()
{
    if(filename == "")
    {
        // Set filename to untitled
        filename = "untitled";
    }

    ofstream f(filename.c_str());
    if(f.is_open())
    {
        for(int i=0; i<buff->lines.size(); i++)
        {
            f << buff->lines[i] << endl;
        }
        status = "Saved to file!";
    }
    else
    {
        status = "Error: Cannot open file for writing!";
    }
    f.close();
}

