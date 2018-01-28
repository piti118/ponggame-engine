/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include "ArduinoEmulator.h" //you won't need this for real arduino
#include "PongGame.h"

using namespace std;
using namespace hw4;

const int nrow = 8;
const int ncol = 8;

PongGame pongGame(nrow, ncol);
int* buffer = new int[nrow*ncol];

/***********CHANGE THESE*********************/

void setup(){
    pongGame.start(millis());
}

void drawScreen(int* buffer){
    for(int irow=0; irow<nrow; irow++){
        for(int icol=0; icol<ncol; icol++){
            mvprintw(irow, icol, buffer[irow*ncol + icol]==0?".":"O");
        }
    }
    refresh();
}

char getInput(){
    return getch();
}

void processInput(unsigned long tick){ //You will need to change this
    char ch;
    if((ch = getInput())!=ERR){
        switch(ch){
            case 'e':
                pongGame.movePad(Player::PLAYER_ONE, PadDirection::UP);
                break;
            case 'd':
                pongGame.movePad(Player::PLAYER_ONE, PadDirection::DOWN);
                break;
            case ' ':
                pongGame.reset();
                pongGame.start(tick);
                break;
            case 'i':
                pongGame.movePad(Player::PLAYER_TWO, PadDirection::UP);
                break;
            case 'k':
                pongGame.movePad(Player::PLAYER_TWO, PadDirection::DOWN);
                break;
            case 'q':
                break;
        }
    }
}

void loop(){
    const unsigned long tick = millis();
    processInput(tick);
    pongGame.update(tick);

    if(pongGame.isDirty()){
        pongGame.paint(buffer);
        drawScreen(buffer);
    }
}

/******* TO THESE ************/

//You don't need this for arduino either
int main()
{
    setupScreen();
    setup();
    while(true){
        loop();
    }
}



