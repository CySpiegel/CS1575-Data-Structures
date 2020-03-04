#include <iostream>
// Your include files here
#include "MyHeap.h"
using std::cout;
using std::endl;


// This file is merely a rough guideline,
// and you should make your own for testing.
int main()
{

  int my_array[9] = { 1,7,6,20,0,8,3,5,9 };


  // Heap
  MyHeap<int> q(my_array, 9);

  q.pop();


  cout << q.size() << endl;
  /*
  for (int k = 0; k < 7; k++)
    q.push(k);
 

  q.push(1);
  q.push(7);
  q.push(6);
  q.push(20);
  q.push(0);
  q.push(8);
  q.push(3);
  q.push(5);
  q.push(9);
  */

  cout << q.size() << endl;
  cout << "Top of the Heap is: " << q.top() << endl;
  q.print();
  //cout << "Left child of index 1 is index: " << q.leftchild(1) << endl;
  //cout << "Right child of index 1 is index: " << q.rightchild(1) << endl;
  //cout << "Is Leaf: " << q.isLeaf(0) << endl;
  //cout << "Is Leaf: " << q.isLeaf(3) << endl;

  /*
  while (!q.empty())
  {
    cout << q.top() << endl;
    q.pop();
  }

  int my_array[6] = { 4, 6, 9, 12, 124, 4 };
  MyHeap<int> q2(my_array, 6);    // parameterized constructor

  MyHeap<int> q3(q2);             // copy constructor
  MyHeap<int> q4 = q2;            // copy constructor
  MyHeap<int> q5;                 // default constructor
  q5 = q4;                        // operator=

  while (!q4.empty())
  {
    cout << q4.top() << endl;
    q4.pop();
  }

  // Sort
  int my_array2[6] = { 4, 6, 9, 12, 124, 4 };
  
  cout << my_is_sorted(my_array2, 6) << endl;
  my_sort(my_array2, 6);
  cout << my_is_sorted(my_array2, 6) << endl;
  
  for (int k; k < 6; k++)
  {
    cout << my_array2[k] << endl;
  }
  */
  return 0;
}

