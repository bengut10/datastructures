//Programmer: Jose Benjamin Gutierrez
//Project Number: 8
//Project Desc: Heap sorts
//Course: Data Structures
//Date: Nov. 24, 2015

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

void printMenu();

void heapify(int heapArray[], int size);

void percolateDown(int heapArray[], int root, int size);

void displayArray(int heapArray[],int size);

void displayTree(int heapArray[], int size);

void displayOneLevel(int heapArray[], int numRows,
                     int level, int beginIndex, int endIndex);

void heapsort(int heapArray[], int size);


int main()
{
    //srand(time(0));
    char choice, keepGoing;
    int num, randomNum;
    int *heapArray;
    int *ptrToOne;
    
    do
    {
        cout << "Please enter the size of the array" << endl;
        cin >> num;
    
        heapArray = new int[num +1];
    
        for (int i = 1; i < num +1; i++)
        {
            randomNum = (rand() % 1000);
            heapArray[i] = randomNum;
        }
        
        ptrToOne = &heapArray[1];
        
        cout << endl;
        cout << "Displaying the contents of the tree and the array:" << endl;
        cout << endl;
        
        displayTree(ptrToOne, num);
        displayArray(heapArray, num);
        
        cout << endl;
        printMenu();
        cout << "Please enter choice " << endl;
        cin >> choice;
        cout << endl;
        
        choice = toupper(choice);
        
        if (choice == 'H')
        {
            heapify(heapArray, num);
        }
        else
        {
            heapsort(heapArray, num);
        }
        
        displayTree(ptrToOne, num);
        displayArray(heapArray, num);
        
        delete heapArray;
        
        cout << endl;
        cout << "C - Continue " << endl;
        cout << "Q - Quit" << endl;
        cin >> keepGoing;
    }
    while(keepGoing != 'Q');

}

void printMenu()
{
    cout << endl;
    cout << "H - Heapify" << endl;
    cout << "S - Heapsort" << endl;
}

void heapify(int heapArray[], int size)
{
    for(int r = (size / 2); r >= 1; r--)
        {
            percolateDown(heapArray, r, size);
        }
}

void percolateDown(int heapArray[], int root, int size)
{
    int c;
    c = 2 * root;
    while(c <= size)
    {
        if ((c < size ) && (heapArray[c] < heapArray[c+1]))
        {
            c = c+1;
        }
        if(heapArray[root] < heapArray[c])
        {
            int temp = heapArray[root];
            heapArray[root] = heapArray[c];
            heapArray[c] = temp;
            
            root = c;
            c = 2 *c;
        }
        else
        {
            break;
        }
    }
}

void displayArray(int heapArray[],int size)
{
    cout << "------------------" << endl;
    for(int i = 1; i < size + 1; i++)
    {
        cout << heapArray[i] << " " ;
    }
}


void displayTree(int heapArray[], int size)
{
    int beginIndex = 0,
    endIndex = 0,
    rowLength,
    numLevels = int(ceil(log(float(size))/ log(2.0)));
    
    for(int level = 0; level < numLevels; level++)
    {
        displayOneLevel(heapArray, numLevels,level,beginIndex,endIndex);
        rowLength = endIndex - beginIndex +1;
        beginIndex = endIndex +1;
        endIndex = min(endIndex +2*rowLength, size-1);
    }
}


void displayOneLevel(int heapArray[], int numRows,
                     int level, int beginIndex, int endIndex)
{
    int skip = int(pow(2.0, numRows-level) -1);
    
    for(int i = beginIndex; i <= endIndex; i++)
    {
        cout << setw(skip) << " ";
        cout << setw(2) << heapArray[i];
        cout << setw(skip) << " ";
    }
    cout << "\n\n";
}

void heapsort(int heapArray[], int size)
{
    int temp;
    
    heapify(heapArray, size);
    
    for(int i = size; i >= 2; i--)
    {
        temp = heapArray[1];
        heapArray[1] = heapArray[i];
        heapArray[i] = temp;
        
        percolateDown(heapArray, 1, i -1);
        
    }
}






