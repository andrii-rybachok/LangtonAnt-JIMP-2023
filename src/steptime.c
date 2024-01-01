#include "steptime.h"

void clearScreen() {
    printf("\033[2J\033[H");
}

void sleepMillis(int milliseconds) {
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
}