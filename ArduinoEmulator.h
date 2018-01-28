//
// Created by Piti Ongmongkolkul on 28/1/18.
//

#ifndef PONGGAME_ARDUINOEMULATOR_H
#define PONGGAME_ARDUINOEMULATOR_H
#include <chrono>
#include <unistd.h>
#include <ncurses.h>

const std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

unsigned long millis() {
    using namespace std::chrono;
    const steady_clock::time_point now = steady_clock::now();
    unsigned long time_span = duration_cast<std::chrono::milliseconds>(now-start).count();
    return time_span;
}

void delay(unsigned long ms){
    usleep(ms*1000);
}

void setupScreen(){
    initscr();
    cbreak();
    nodelay(stdscr, TRUE);
    noecho(); // Don't echo any keypresses
    curs_set(FALSE); // Don't display a cursor
}

#endif //PONGGAME_ARDUINOEMULATOR_H
