//
// Created by benav on 2/19/2020.
//
/*
 * currentPos will handle the position within the doubleLinkedList
 * y will handle the number of lines, while x will handle the postion in the current line
 * currentpos' purpose is to keep track within the list while x and y is to display on screen.
 *
 *
 */

#include <unistd.h>
#include "Editor.h"

Editor::Editor(){
    mainText = new doubleLinkedList<char>();
    currentPos = -1;/*C'est seulement pour savoir la postion actuelle dedans la liste mais rien a voir avec la position sur l'ecran  */
    LinesCounter = 1; /* Afin de creer le tableau qui contient chaque ligne pour l'imprimer sur l'ecran rien a voir avec la position sur l'ecran*/
    status = "";
    x=0;y=0;mode='i';
}



string Editor::toString(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}




void Editor::handleInput(int c){

    switch(c)
    {
        case KEY_LEFT:
            moveLeft();
            return;
        case KEY_RIGHT:
            moveRight();
            return;
        case KEY_UP:

                moveUp();



            return;
        case KEY_DOWN:

                moveDown();


            return;
    }


    switch(c){

        case KEY_ENTER:
        case 10:
            currentPos++;
            LinesCounter++;
            y++;
            x = 0;
            mainText->addAt( '\n', currentPos);
            break;
        default:
            currentPos++;
            x++;
            mainText->addAt( char (c), currentPos);
            //status += ".Size hi: " + tos(mainText->getSize());

    }





}


void Editor::test(){






}

void Editor::resetStatus(){
    status ="";
}
void Editor::printScreen(){

    string lines[LinesCounter] = {};
    string line = "";
    int i = 0;
    mainText->begin();

    while(mainText->hasNext()){
        line += mainText->next();
        if(mainText->next() == '\n'){
            //y++; x =0;// TODO: aqui puede ser un buen lugar para poner la posicion actual
            lines[i]= (line);
            i++;
            line = "";
        }
    }
    if(line.compare("") != 0){
        lines[LinesCounter-1] = line;
    }


    for(int i=0; i<LINES-1; i++) // LINES is /* terminal height */
    {
        if(i >= (sizeof(lines)/sizeof(lines[0])))
        {
            move(i, 0);
            clrtoeol(); // Erase the current line to the right of the cursor.
        }
        else
        {
            mvprintw(i, 0, lines[i].c_str());
        }
        clrtoeol();
    }

}


void Editor::updateStatus(){

    status += "\tCOL: " + tos(x) + "\tROW: " + tos(y) + "CP: "+ tos(currentPos);
}

void Editor::printStatusLine(){

    attron(A_REVERSE);
    mvprintw(LINES-1, 0, status.c_str());
    clrtoeol();
    attroff(A_REVERSE);
    move(y, x);
    status = "";
}

string Editor::tos(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

void Editor::moveLeft(){
    currentPos--;
    if(currentPos < -1){
        currentPos = -1;
    }

    moveTo();

}


void Editor::moveRight()
{

    currentPos++;
    if(currentPos >= mainText->getSize()){
        currentPos = mainText->getSize()-1;
    }
    moveTo();

}

void Editor::moveUp(){
    int newY = y-1;
    int newX = x;
    if(newY < 0){
        return;
    }
    int ycounter = 0;
    int xcounter = 0;
    int newPos = 0;
    mainText->begin();
    while(mainText->hasNext()){
        if(mainText->next() == '\n'){
            if(ycounter == newY){

                break;
            }
            newPos++;
            xcounter = 0;
            ycounter++;
        } else{

            if(ycounter == newY && xcounter == newX){
                break;
            }
            xcounter++;
            newPos++;

        }


    }
    currentPos = newPos-1;
    moveTo();

}




void Editor::moveDown() {

    int currentPosCopy = currentPos;
if(currentPosCopy < 0){currentPosCopy = 0;}
if(mainText->getSize()==0){ return;}
node<char> *current = mainText->getNodeAt(currentPosCopy);

    if(current != nullptr && current->getData() == '\n'){
        currentPosCopy++;
        current = mainText->getNodeAt(currentPosCopy);
        while (current != nullptr && current->getData() != '\n'){
            currentPosCopy++;
            current = current->getNext();
            if(current== nullptr){ return;}
            if(current->getData() == '\n'){  break;}
        }
        currentPos = currentPosCopy;
        moveTo();
        return;
    }



while (current != nullptr && current->getData() != '\n'){
    currentPosCopy++;
    current = current->getNext();
    if(current== nullptr){ return;}
    if(current->getData() == '\n'){ currentPosCopy++; break;}
}

    current = mainText->getNodeAt(currentPosCopy);
    int counter = 0;
    while (current != nullptr && current->getData() != '\n'){
        current = current->getNext();
        if(counter == x){ break;}
        counter++;
    }
    currentPos = currentPosCopy + counter - 1;
    moveTo();

}

void Editor::moveTo(){
    node<char> *current = mainText->getNodeAt(0);
    if(current == nullptr || currentPos == -1){//if no data or new pos is -1
        x = 0; y = 0;
    }else{
        x = 0; y = 0;
        int counter = 0;
        mainText->begin();

        while(mainText->hasNext()){
            x++;
            if(mainText->next()== '\n'){
                y++;
                x = 0;
            }
            if(counter == currentPos){
                break;
            }
            counter++;
        }
    }

    //move(y, x);
    //move(50,100);

}