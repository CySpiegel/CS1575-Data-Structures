#ifndef MYUNORDEREDMAP_H
#define MYUNORDEREDMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Dictionary.h"

using std::cout;
using std::endl;

/*
Writes to a string array containing: 
    * the your (the student author’s) Campus Username in lowercase (at index 0)
    * and Student ID# (at index 1).
Takes as input a pre-existing length-2 string array.
*/
void get_identity(std::string my_id[]);
      

template <typename K, typename V>
class MyUnorderedMap: public Dictionary<K, V>
{
    private:
        MyPair<K, V> *m_data;
        
        int data_size;
        int reserved_size;

        // To make it easier on you (rather than use void pointers) we'll only test with std::string keys
        int hash(const K &key) const; //completed
        
    public:
        // Should start data_size and reserved_size at 0, m_data to nullptr
        MyUnorderedMap(); // completed
        
        ~MyUnorderedMap(); //completed
        
        MyUnorderedMap(const MyUnorderedMap<K, V> &source); //completed

        MyUnorderedMap<K, V> & operator=(const MyUnorderedMap<K, V> &source); //completed
    
        V & at(const K &key); // completed
    
        V & operator[](const K &key); //completed

        bool empty() const; //completed
        
        int size() const; //completed

        // data_size and reserve size should be 0 after this.
        void clear(); //completed

        void insert(const MyPair<K, V> &init_pair);//completed

        void erase(const K &key); //completed

        MyPair<K, V> * find(const K &key) const; //completed

        void print() const; //completed

        int count(const K &key) const; //completed

        // This one was not in the BST, but is in the HT
        // Grows or shrinks reserved_size and size of dynamic array to be new_cap large,
        // and nothing else.
        // Other functions, like insert, erase, or [], should decide how large to make the new cap
        // and call reserve themselves with that size.
        // Those other functions should choose to double the reserved size when the HT becomes 60% full,
        // and to shrink the HT when it becomes 10% full, to a resulting 30%.
        // Remember to re-hash!
        void reserve(int new_cap); //completed

};

#include "MyUnorderedMap.hpp"

#endif

