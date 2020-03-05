
#include <iostream>

void swap( int * xp, int * yp );

int main( int argv, char * argc [ ] )
{
    int a = 12;
    int b = 13;

    std::cout << "Before swapping : " << a << " : " << b << std::endl;

    swap(&a, &b);

    std::cout << "After swapping : " << a <<" : "<< b << std::endl;

    return 0;
}

void swap( int * xp, int * yp ) 
{
    __asm {
        // Code here
        MOV EAX, xp
        MOV EBX, yp
        MOV xp, EBX
        MOV yp, EAX

        // Return
        RET
    }
}