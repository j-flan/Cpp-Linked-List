/*
 * Jeff Flanegan
 * CSC 161 C++
 * Homework 4
 * 2019-9-18
 */
/*
 * FILE:sequence3.cxx
 * CLASS IMPLEMENTED: sequence3.h
 * INVARIANT for the sequence3 class:
 * 1. The items in the sequence are stored in a Linked List
 * 2. The number of nodes in the linked list is the member variable "many_nodes".
 * 3. The current cursor position on the linked list is the member variable "cursor".
 * 4. The head pointer in the list is pointed to by the member variable "head_ptr".
 * 5. The tail pointer in the list is pointed to by the member variable "tail_ptr".
 * 6. The node before the cursor is pointed to by the member variable "precursor".
 */
#include "node1.h"
#include <algorithm>
#include <cstdlib>
#include "sequence3.h"
using namespace std;

namespace main_savitch_5
{   
    //default constructor
    sequence::sequence( ){
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
	many_nodes = 0;
    }
    //copy constructor
    sequence::sequence(const sequence& source){                  
        many_nodes = source.many_nodes;
        //NULL cursor
        if (source.cursor == NULL){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            precursor = NULL;
            cursor = NULL;
        }
        //cursor at head
        else if (source.cursor == list_locate(source.head_ptr, 1)){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            precursor = NULL;
            cursor = head_ptr;
        }
        //cursor at tail
        else if (source.cursor == list_locate(source.head_ptr, many_nodes)){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            cursor = head_ptr;
            for (int i = 1; i < many_nodes; i++){
                advance();
            }
        }
        //cursor in middle
        else{
<<<<<<< HEAD
            const node* ptr;
            ptr = source.head_ptr;                       
            int i = 0;
            //find cursor distance from head_ptr
            while(ptr != source.precursor){
                ptr = ptr->link();
=======
            //copy list up-to the cursor
            list_piece(source.head_ptr, source.cursor, head_ptr, precursor);            
            cursor = head_ptr;
            int i = 0;
            //find cursor distance from head_ptr
            while(cursor != precursor){
                cursor = cursor->link();
>>>>>>> 9863e592780a5cdb62346e826b23668ef5fb3ee8
                i++;
            }
            //copy full list
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            cursor = head_ptr;
            //move cursor the distance found
            while(i >= 0){
                advance();
                i--;
            }           
        }                                          
    }
    //destructor
    sequence::~sequence( ){
        list_clear(head_ptr);
        many_nodes = 0;
    }
    
    //return cursor to node 1
    void sequence::start( ){        
        cursor = head_ptr;
        precursor = NULL;
    }
    //move cursor and precursor forward
    void sequence::advance( ){
        precursor = cursor;
        cursor = cursor->link();
    }
    //insert before cursor or, if NULL, to the head of the list
    void sequence::insert(const sequence::value_type& entry){
        if ((precursor == NULL) || (!is_item())){                         
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;         
            tail_ptr = head_ptr;            
        }             
        else{
            list_insert(precursor, entry);
            cursor = precursor -> link();
        }    
        ++many_nodes;
    }
    //add node after the cursor position. If node is NULL, node is added to tail
    void sequence::attach(const sequence::value_type& entry){
        
        if (is_item()){
            //add after cursor, if tail - advance tail
            precursor = cursor;
            list_insert(precursor, entry);
            cursor = cursor->link();
            if (cursor == tail_ptr){
                tail_ptr = tail_ptr->link();
            }             
        }
          
        else{
            //add to head of empty list
            if(head_ptr == NULL){
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;         
                tail_ptr = head_ptr;
            }
            //add to end of list if no item found
            else{
                precursor = list_locate (head_ptr, list_length (head_ptr));
                list_insert (precursor, entry);
                tail_ptr = tail_ptr -> link();
                cursor = precursor->link();
            } 
        }
	++many_nodes;
    }
    //remove node in cursor position
    void sequence::remove_current( ){
        if (!(is_item())){
            return;
        }
        //remove tail node
        else if (precursor != NULL){
            if(cursor == tail_ptr){
                cursor = precursor;
                node *rm_ptr;  //temporary node
                rm_ptr = tail_ptr;
                tail_ptr = cursor;
                delete rm_ptr;
                //move precursor to point to cursor
                for (int i = 1; i < many_nodes - 1; i++){
                    precursor = precursor->link();
                }
            }
            //remove internal node
            else{
                cursor = cursor->link();
                list_remove(precursor);
            }
        }
        //remove head node
        else{
            cursor = cursor->link();
            list_head_remove(head_ptr);
            precursor = NULL;
        }
        --many_nodes;
    }
    
    //return value of current node
    sequence::value_type sequence::current( ) const{
        if(is_item()){
            return cursor->data();
        }
    }
    //overload assignment operator for copying lists
    void sequence::operator =(const sequence& source)
    {   
        //handle the case of the empty list
	if (this == &source)
            return;
        
<<<<<<< HEAD
        list_clear(head_ptr);
=======
>>>>>>> 9863e592780a5cdb62346e826b23668ef5fb3ee8
        many_nodes = source.many_nodes;
        //NULL cursor
        if (source.cursor == NULL){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            precursor = NULL;
            cursor = NULL;
        }
        //cursor at head
        else if (source.cursor == list_locate(source.head_ptr, 1)){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            precursor = NULL;
            cursor = head_ptr;
        }
        //cursor at tail
        else if (source.cursor == list_locate(source.head_ptr, many_nodes)){
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            cursor = head_ptr;
            for (int i = 1; i < many_nodes; i++){
                advance();
            }
        }
        //cursor in middle
        else{           
<<<<<<< HEAD
            const node* ptr;
            ptr = source.head_ptr;                       
            int i = 0;
            //find cursor distance from head_ptr
            while(ptr != source.precursor){
                ptr = ptr->link();
=======
           //copy list up-to the cursor
            list_piece(source.head_ptr, source.cursor, head_ptr, precursor);            
            cursor = head_ptr;
            int i = 0;
            //find cursor distance from head_ptr
            while(cursor != precursor){
                cursor = cursor->link();
>>>>>>> 9863e592780a5cdb62346e826b23668ef5fb3ee8
                i++;
            }
            //copy full list
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            cursor = head_ptr;
            //move cursor the distance found
            while(i >= 0){
                advance();
                i--;
            }           
<<<<<<< HEAD
        }                         
    }
   /* void sequence::list_piece(const node* start, const node* end, node*& head_ptr, node*& tail_ptr){
=======
        }                       
    }
    void sequence::list_piece(const node* start, const node* end, node*& head_ptr, node*& tail_ptr){
>>>>>>> 9863e592780a5cdb62346e826b23668ef5fb3ee8
        head_ptr = NULL;
	tail_ptr = NULL;        
	// handle the case of the empty list
        if (start == NULL)
	    return;
        // make the head node for the newly created list, and put data in it
	list_head_insert(head_ptr, start->data( ));
	tail_ptr = head_ptr;
        // copy the rest of the nodes one at a time, adding at the tail of new list
	start = start->link( ); 
	while (start != end)
	{
	    list_insert(tail_ptr, start->data( ));
	    tail_ptr = tail_ptr->link( );
	    start = start->link( );
	}
<<<<<<< HEAD
    }*/
=======
    }
>>>>>>> 9863e592780a5cdb62346e826b23668ef5fb3ee8

}



