#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    int sec = 0;
    const int timemax = 60 * 3600;

    while(1) 
    {
        int hora = sec / 3600;
        int min = (sec % 3600) / 60;
        int seg = sec % 60;

        if(hora > 0) printf("\r%d:%02d:%02d", hora, min, seg);
        else if(min > 0) printf("\r%d:%02d", min, seg);
        else printf("\r%d", seg);

        fflush(stdout);

        if(hora == 0 && min == 1 && seg == 0)
        {
            system("play -q sounds/end.wav");
            break;
        }

        if(sec >= timemax)
        {
            system("play -q sounds/max.wav");
            break;
        }

        sleep(1);
        sec++;
    }
    return 0;
}
