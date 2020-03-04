#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdexcept>
#include <string>


using std::cout;
using std::endl;


//Swap Function
template <typename T>
void swap(T &a, T &b);


//Heap class
template <typename T>
class MyHeap
{
private:

  T *Heap;              // Pointer to the heap array
  int m_maxSize;     // Maximum size of the heap
  int m_size;           // Number of elements now in the heap
  void siftdown(int pos); 
  void reserve(int new_cap); //completed
  void shrink_to_fit();  //completed


public:

  //Constructor
  MyHeap(); //completed

  //Paramatized Constructor
  MyHeap(T arr[], const int & size); 

  //Destructor
  ~MyHeap(); //needs testing

  //Copy Constructor
  MyHeap(const MyHeap<T> &source);

  //Assignment operator
  MyHeap<T> & operator=(const MyHeap<T> &source);

  // True if pos is a leaf
  bool isLeaf(int pos) const; //completed

  // Return leftchild position
  int leftchild(int pos) const;  //completed

  // Return rightchild position
  int rightchild(int pos) const;  //completed

  // Return parent position
  int parent(int pos) const;  //completed

  // Return current heap size
  int size() const;      //completed

  // Returns true if heap is empty
  bool empty(); //completed

  // Heapify contents of Heap
  void buildHeap();  //completed

  T & top()const; //completed

  void pop(); //completed

  void push(const T &x); //completed

  T & print(); //For testing

};

#include "MyHeap.hpp"

#endif