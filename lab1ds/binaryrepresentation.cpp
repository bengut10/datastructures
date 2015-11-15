#include <iostream>
using namespace std;

void printchar(char a)
{
    unsigned char charmask = 0b10000000;
    cout << " The binary representation for " << a << " is: ";
    for(int j = 7; j >= 0; j--)
    {
        if((charmask & a)!=0)
            cout << 1;
        else
            cout<< 0;
        charmask >>=1;
        if ((j == 4)||(j == 8))
            cout << " ";
    }
    cout <<endl;
}


void printshort(short b)
{
    unsigned short mask = 0b1000000000000000;
    cout <<" The binary representation for " << b << " is: ";
    for(int i =15; i >= 0; i-- )
    {
        if ((mask & b) != 0)
            cout << 1;
        else
            cout << 0;
        mask >>=1;
        if ((i == 4)||(i == 8)||(i == 12)||(i == 16))
            cout << " ";
    }
    cout << endl;
}


void printfloat(int c)
{
    unsigned int floatmask2 = 0b10000000000000000000000000000000;
    cout << "The binary representation is: ";
    for(int k = 31; k >= 0; k-- )
    {
        if ((floatmask2 & c) != 0)
            cout << 1;
        else
            cout << 0;
        floatmask2 >>=1;
        if ((k == 4)||(k == 8)||(k == 12)||(k == 16)||(k == 20)||(k == 24)||(k == 28)||(k == 32))
            cout << " ";
    }
    
    cout << endl;
}