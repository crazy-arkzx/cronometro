#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int sec = 0;
    const int timemax = 60 * 3600;
    struct timespec ts = {1, 0};

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
            system("play -q ../src/sounds/end.wav");
            break;
        }

        if(sec >= timemax)
        {
            system("play -q ../src/sounds/max.wav");
            break;
        }

        nanosleep(&ts, NULL);
        sec++;
    }
    return 0;
}
