// Table class

// Warning: The Table class does not have:
//     a destructor,
//     copy constructor,
//     or overloaded assignment operator.
// Do not depend on any of these working correctly.
// You should be able to do this assignment
// without having to to write these functions.
// Just do not pass a Table by value, assign a Table to another Table, etc.

// Member functions

// CONSTRUCTOR function
//    Table( );
// Postcondition: The table is initialized as an empty table.

// MODIFICATION MEMBER FUNCTIONS

// Insert function
//    void insert( const RecordType& entry );
// Preconditions: entry.key >= 0. Also, if entry needs to be added to the table,
//    then there must be room left in the table (size( ) < TABLE_SIZE).
// Postcondition: If the table already has a record with key equal to
//    the key in entry, that record will be replaced by entry.
//    Otherwise, entry will be added as a new record.

// CONSTANT MEMBER FUNCTIONS

// Find function
//     void find( int key, bool& found, RecordType& result ) const;
// Preconditions:  key >= 0
// Postconditions: If a record with the indicated key is in the table,
//    then found is true and result is set to a copy of that record.
//    Otherwise, found is false and result contains garbage.

// Size function
//    int size( ) const;
// Postcondition: The return value is the number if records in the table.

typedef int ItemType;
const int CAPACITY = 31;

struct RecordType
{
    int key;
    ItemType data;
};

struct Node
{
    RecordType rec;
    Node* next;
};


class Table
{
public:
    Table( );
    void insert( const RecordType& entry );
    void find( int key, bool& found, RecordType& result ) const;
    int size( ) const;
    void erase(int key);
    void print();
private:
    int hash( int key ) const;
    void findPtr( int key, bool& found, Node*& ptr ) const;
    Node* table[CAPACITY];
    int used;
};