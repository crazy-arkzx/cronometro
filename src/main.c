#define MINIAUDIO_IMPLEMENTATION

#include <stdio.h>
#include <time.h>
#include "miniaudio.h"

int main() 
{
    int sec = 0;
    const int timemax = 60 * 3600;
    struct timespec ts = {1, 0};

    ma_result result;
    ma_engine engine;
    
    result = ma_engine_init(NULL, &engine);   
    if(result != MA_SUCCESS) return -1;

    while(1) 
    {
        int hora = sec / 3600;
        int min = (sec % 3600) / 60;
        int seg = sec % 60;

        if(hora > 0) printf("\r%d:%02d:%02d", hora, min, seg);
        else if(min > 0) printf("\r%d:%02d", min, seg);
        else printf("\r%d", seg);

        fflush(stdout);

        if(hora == 0 && min == 5 && seg == 0)
        {
            ma_engine_play_sound(&engine, "../src/sounds/end.wav", NULL);
            break;
        }

        if(sec >= timemax)
        {
            ma_engine_play_sound(&engine, "../src/sounds/max.wav", NULL);
            break;
        }

        nanosleep(&ts, NULL);
        sec++;
    }
    ma_engine_uninit(&engine);
    return 0;
}