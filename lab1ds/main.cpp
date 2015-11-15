
// Programmer: Jose B. Gutierrez
// Project Number 1
// Project Desc: Binary Representations
// Course: Data Structures
// Date: Aug. 01, 2015


#include <iostream>
using namespace std;

void printchar(char a);
void printshort(short b);
void printfloat(int c);

union myunion{
    float floatnum;
    int dummy;
};

int main()

{
    myunion numbers;
    int choice;
    short shortnum;
    char charac;

    do{
        cout << " ------------------------------------------------------\n";
        cout << " 1 - Print the binary representation of a character" << endl;
        cout << " 2 - Print the binary representation of a short integer" <<endl;
        cout << " 3 - Print the binary representation of a float"<< endl;
        cout << " 4 - Exit the program"<< endl;
        cout << " ------------------------------------------------------\n";
        cin >> choice;
        
        if(choice == 1)
        {
            cout << " Please enter a character: ";
            cin >> charac;
            printchar(charac);
        }
        if (choice == 2)
        {
            cout << " Please enter a short integer: ";
            cin >> shortnum;
            printshort(shortnum);
        }
        if (choice == 3)
        {
            cout << "Please enter a float: ";
            cin >> numbers.floatnum;
            printfloat(numbers.dummy);
        }
        if (choice ==4)
            break;
    }
    while(choice !=4);
    cout<<endl;
    
}