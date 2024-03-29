
/* Jeff Flanegan
 * CSC 161 C++
 * Homework 5
 * 2019-9-22
 */

// FILE: sequence4.h
//
// CLASS PROVIDED: sequence<Item> (Part of the namespace main_savitch_6B)
//
// TYPEDEFS for the sequence class:
//     sequence<Item>::value_type is the Item type from the template parameter
//     and is the data type of the objects in the sequence. It may be any of the 
//     C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//     sequence<Item>::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry 
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const Item& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//    
//   void list_piece(const node<Item>* start, const node<Item>* end, 
//                node<Item>*& head_ptr, node<Item>*& tail_ptr);
//      Precondition: start is the head of a linked list, end is the cursor of a linked list
//      Postcondition: head_ptr and tail_ptr are the head and precursor for
//      a new list that contains the same items as the portion of the list pointed to by
//      start and end. The original list is unaltered.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   Item current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#ifndef MAIN_SAVITCH_SEQUENCE3_H
#define MAIN_SAVITCH_SEQUENCE3_H
#include <cstdlib>  // Provides size_t
#include "node2.h"  // Provides node class

namespace main_savitch_6B
{
    template <class Item>
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef Item value_type;
        typedef std::size_t size_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence( );
        sequence(const sequence& source);
	~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const Item& entry);
        void attach(const Item& entry);
        void operator =(const sequence& source);
	void remove_current( );
        /*void list_piece(const node<Item>* start, const node<Item>* end, 
         *          node<Item>*& head_ptr, node<Item>*& tail_ptr); */
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return many_nodes; }
        bool is_item( ) const { return (cursor != NULL); }
        Item current( ) const;
    private:
	node<Item> *head_ptr;
	node<Item> *tail_ptr;
	node<Item> *cursor;
	node<Item> *precursor;
	size_type many_nodes;
    };
}

#include "sequence4.template"
#endif

