#ifndef MYMAP_H
#define MYMAP_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "Dictionary.h"
#include "TreeNode.h"

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
class MyMap: public Dictionary<K, V>
{
    private:
        TreeNode<MyPair<K, V>> *root; //completed
        
        V & at_helper(TreeNode<MyPair<K, V>> *&rt, const K &key); //completed
    
        int size_helper(TreeNode<MyPair<K, V>> *rt) const; //completed

        void clear_helper(TreeNode<MyPair<K, V>> *&rt); //completed

        void insert_helper(TreeNode<MyPair<K, V>> *&rt, const MyPair<K, V> &init_pair); //completed

        TreeNode<MyPair<K, V>> * get_min(TreeNode<MyPair<K, V>> *rt); //completed
        
        void erase_helper(TreeNode<MyPair<K, V>> *&rt, const K &key); //completed

        MyPair<K, V> * find_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const; //completed

        void print_helper(TreeNode<MyPair<K, V>> *rt, std::string indent) const; //completed

        int count_helper(TreeNode<MyPair<K, V>> *rt, const K &key) const; //completed

        TreeNode<MyPair<K, V>> * clone(const TreeNode<MyPair<K, V>> *rt);  //completed


    public:
        MyMap(); //completed
        
        ~MyMap(); //completed
        
        MyMap(const MyMap<K, V> &source); //completed

        MyMap<K, V> & operator=(const MyMap<K, V> &source); //completed
    
        V & at(const K &key); //Completed
    
        V & operator[](const K &key); //completed needs more testing

        bool empty() const; //completed
        
        int size() const; //completed

        void clear(); //completed

        void insert(const MyPair<K, V> &init_pair); //completed

        void erase(const K &key); //completed

        MyPair<K, V> * find(const K &key) const; // completed

        void print() const; //completed

        int count(const K &key) const; //completed
};

#include "MyMap.hpp"

#endif


