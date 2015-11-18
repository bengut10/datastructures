typedef int ItemType; 
const int CAPACITY = 31;

struct RecordType
{
       int key;
       ItemType data;
};

// Table class member functions

// CONSTRUCTOR function
//    Table( );
// Postcondition: The table is initialized as an empty table.
       
// MODIFICATION MEMBER FUNCTIONS
                  
// Insert function 
//    void insert( const RecordType& entry );
// Preconditions: entry.key >= 0. If entry needs to be added to the table,
//    then there must be room left in the table (size( ) < TABLE_SIZE).
// Postconditions: If the table already has a record with key equal to 
//    the key in entry, that record will be replaced by entry.
//    Otherwise, entry will be added as a new record.

// CONSTANT MEMBER FUNCTIONS

// Find function
//     void find( int key, bool& found, RecordType& result ) const;
// Preconditions:  key >= 0. 
// Postconditions: If a record with the indicated key is in the table, 
//    then found is true and result is set to a copy of that record.
//    Otherwise, found is false and result contains garbage. 
               
// Size function
//    int size( ) const; 
// Preconditions:  None. 
// Postconditions: The return value is the number if records in the table.
 

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
   // HELPER FUNCTIONS 
   int hash( int key ) const;
   void findIndex( int key, bool& found, int& i ) const;
   
   // DATA MEMBERS
   RecordType table[CAPACITY];
   int used;
};

