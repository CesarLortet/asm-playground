// cycles.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

int add64(int a, int b);

int main()
{
    std::cout << add64(5, 3);
}

int add64(int a, int b)
{
    int r = 0;

    int lowStartCycle = 0;
    int highStartCycle = 0;
    int lowEndCycle = 0;
    int highEndCycle = 0;

    int elapsedHighCycle = 0;
    int elapsedLowCycle = 0;

    long long start = 0;
    long long end = 0;

    long long cycle = 0;

    __asm {

        // Get current time stamp
        RDTSC
        MOV DWORD PTR[lowStartCycle], EAX
        MOV DWORD PTR[highStartCycle], EDX

        //Addition
        MOV EAX, DWORD PTR [a]
        ADD EAX, DWORD PTR [b]
        MOV DWORD PTR [r], EAX

        //Get an other time stamp
        RDTSC
        MOV EAX, DWORD PTR[lowEndCycle]
        MOV EDX, DWORD PTR[highEndCycle]

    }

    //Calculate difference
    cycle = (highEndCycle - highStartCycle) ^ 64 - (lowEndCycle - lowStartCycle) ^ 64;

    elapsedHighCycle = highEndCycle - highStartCycle;
    elapsedLowCycle = lowEndCycle - lowStartCycle;

    std::cout << "Time cycle: " << cycle << std::endl;
    return r;
}