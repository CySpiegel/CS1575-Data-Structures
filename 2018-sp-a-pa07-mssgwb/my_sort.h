#include "MyHeap.h"

template<typename T>
void my_sort(T arr[], int size)
{

  MyHeap<T> MaxHeap(arr, size);

  for (int i = 0; i < size; i++)
  {
    arr[i] = MaxHeap.top();
    MaxHeap.pop();
  }

}