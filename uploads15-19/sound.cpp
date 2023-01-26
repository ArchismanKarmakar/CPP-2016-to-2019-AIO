#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define cls(); System("cls");
#include <direct.h>

#include <iostream> 
#include <windows.h> // WinApi header 

using namespace std;

/*int main() 
{ 
    Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
    Beep(400,250);
    Beep(523,250);
    Beep(600,350);
    Beep(550,250);
    Beep(600,250);
    Beep(680,350);
    Beep(650,250);
    Beep(700,250);
    Beep(880,350);
    Beep(750,150);
    Beep(700,150);
    Beep(650,150);
    Beep(610,150);
    Beep(570,150);
    Beep(530,150);
    Beep(510,150);
    cin.get(); // wait 
    return EXIT_SUCCESS; 
   
}*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sndfile>


#define BUFFER_SIZE 1000000
#define SAMPLE_RATE 44100.0
#define PI 3.141592654

void writeAudioFile(double *buffer) {
    
    SF_INFO sndInfo;

    sndInfo.samplerate = SAMPLE_RATE;
    sndInfo.channels   = 1;
    sndInfo.frames     = BUFFER_SIZE;
    sndInfo.format     = SF_FORMAT_PCM_16 | SF_FORMAT_WAV;

    SNDFILE *outFile = sf_open("sin.wav", SFM_WRITE, &sndInfo);

    sf_writef_double(outFile, buffer, BUFFER_SIZE);
    sf_close(outFile);
}

int main() {

    double buffer[BUFFER_SIZE];

    for (int s = 0; s < BUFFER_SIZE; ++s)
        buffer[s] = 0;

    // sine wave: y(t) = amplitude * sin(2 * PI * frequency * time), time = s / sample_rate

    /*
       A  : 440
       A# : 466.16
       B  : 493.88
       C  : 523.25
       C# : 554.37
       D  : 587.33
       D# : 622.25
       E  : 659.26
       F  : 698.46
       F# : 739.99
       G  : 783.99
       G# : 830.61
    */

    double frequency;
    int offSet; 
    int durration;

    printf("\nSin Wave Generator\n\n");
    while (scanf("%lf %d %d", &frequency, &offSet, &durration) == 3) {

        double amplitude = 1.0;

        printf("%lf Hz\t%d offset\t%d durration\n", frequency, offSet, durration);

        for (int s = offSet; s < BUFFER_SIZE && s < offSet + durration; ++s) 
            buffer[s] += amplitude * sin( (2.0 * PI * frequency) * (s / SAMPLE_RATE));      
    }

    double max = 1.0;
    for (int s = 0; s < BUFFER_SIZE; ++s)
        if (buffer[s] > max)
            max = buffer[s];

    //normalize
    for (int s = 0; s < BUFFER_SIZE; ++s)
        buffer[s] /= max;

    writeAudioFile(buffer);
}