//Programmer: Jose Benjamin Gutierrez
//Project Number: 8
//Project Desc: Heap sorts
//Course: Data Structures
//Date: Nov. 24, 2015

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/*Function printMenu
 Prints out a menu
 Precondition: None
 Post condition A menu with two options is printed to the screen*/
void printMenu();

/*Function Heapify
 Converts an integer array into a heap using percolate down
 Precondition: The items to be heapified are indexes 1 through size
    using percolateDown.
 PostCondition: The items are turned into a heap.*/
void heapify(int heapArray[], int size);

/*Function percolateDown
 Converts an integer array into a heap when called by heapify.
 Precondtion: Items that are heapified are indexes 1 through size.
 Postconditions: Arranges the items incorrect order so that they meet
    a heap's properties.*/
void percolateDown(int heapArray[], int root, int size);

/*Function displayArray
 Displays the elements in the array
 Precondition: None
 Postcondition: The elements displayed are index 1 through size.*/
void displayArray(int heapArray[],int size);

/*Function displayTree
 Desplays the elements in the array in a tree-like structure
 Precondition: None
 Postcondition: The elements in the array are displayed index 1 
    through size in a tree-like format. */
void displayTree(int heapArray[], int size);

/*DisplayOneLevel function
 Auxilary function of displaytree function
 Precondition: None
 Postcondition: Displays one level at a time when is called by
    the display tree function.*/
void displayOneLevel(int heapArray[], int numRows,
                     int level, int beginIndex, int endIndex);

/*Function heapsort
 Sorts the elements in the array
 Precondition: Integer array must be a heap. The heapify function is 
    called to convert it into a heap from elements 1 through size.
 Postcondition: The elements are sorted in ascending order.*/
void heapsort(int heapArray[], int size);


int main()
{
    srand(time(0));
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

//Definition of printMenu
void printMenu()
{
    cout << endl;
    cout << "H - Heapify" << endl;
    cout << "S - Heapsort" << endl;
}
//Definition of heapify
void heapify(int heapArray[], int size)
{
    for(int r = (size / 2); r >= 1; r--)
        {
            percolateDown(heapArray, r, size);
        }
}
//Definition of percolateDown
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
//Definition of displayArray
void displayArray(int heapArray[],int size)
{
    cout << "---------------------------------" << endl;
    for(int i = 1; i < size + 1; i++)
    {
        cout << heapArray[i] << " " ;
    }
}
//Definition of displayTree
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
//Definition of displayOneLevel
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
//Definition of heapsort
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