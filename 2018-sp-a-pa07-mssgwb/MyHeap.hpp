#include "MyHeap.h"



template <typename T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
  return;
}

//MyHeap Private
template<typename T>
void MyHeap<T>::reserve(int new_cap)
{
  T *newHeap = new T[new_cap];
  for (int i = 0; i < m_size; i++)
  {
    newHeap[i] = Heap[i];
  }
  m_maxSize = new_cap;
  delete[] Heap;
  Heap = NULL;
  Heap = newHeap;
  return;
}

template<typename T>
void MyHeap<T>::shrink_to_fit()
{
  T *newHeap = new T[m_size * 2];
  for (int i = 0; i < m_size; i++)
  {
    newHeap[i] = Heap[i];
  }
  delete[] Heap;
  Heap = NULL;
  Heap = newHeap;
  return;
}


template<typename T>
void MyHeap<T>::siftdown(int pos)
{
  // Stop if pos is a leaf
  while (!isLeaf(pos)) 
  {
    int greaterChild = leftchild(pos);
    int rc = rightchild(pos);

    if ((rc < m_size) && (Heap[rc] > Heap[greaterChild]))
      greaterChild = rc;            // Set to greater child's value

    if (Heap[pos] > Heap[greaterChild])
    {
      return; // Done
    }

    // Move down (change index)
    swap(Heap[pos], Heap[greaterChild]);
    pos = greaterChild;             
  }
}

//MyHeap Public
template<typename T>
MyHeap<T>::MyHeap()
{
  m_maxSize = 1;
  Heap = new T[m_maxSize];
  m_size = 0;
}

template<typename T>
MyHeap<T>::MyHeap(T arr[], const int & size)
{
  m_maxSize = size;
  Heap = new T[m_maxSize];
  m_size = size;

  for (int i = 0; i < size; i++)
  {
    Heap[i] = arr[i];
  }
  buildHeap();
  
}

template<typename T>
MyHeap<T>::~MyHeap()
{
  delete[] Heap;
}

template<typename T>
MyHeap<T>::MyHeap(const MyHeap<T> &source)
{
  m_size = source.m_size;
  m_maxSize = source.m_maxSize;
  Heap = new T[m_maxSize];
  for (int i = 0; i < m_size; i++)
  {
    Heap[i] = source.Heap[i];
  }
}

template<typename T>
MyHeap<T>& MyHeap<T>::operator=(const MyHeap<T>& source)
{
  // TODO: insert return statement here
  if (this != &source)
  {
    delete[] Heap;
    Heap = NULL;
    this->m_size = source.m_size;
    this->m_maxSize = source.m_maxSize;
    this->Heap = new T[m_maxSize];
    for (int i = 0; i < m_size; i++)
    {
      Heap[i] = source.Heap[i];
    }
  }
  return *this;
}


  template<typename T>
  bool MyHeap<T>::isLeaf(int pos) const
  {
    return ((pos >= m_size / 2) && (pos < m_size));
  }

  template<typename T>
  int MyHeap<T>::leftchild(int pos) const
  {
    if (((2 * pos) + 1) < m_size)
    {
      return ((2 * pos) + 1);
    }
    else
    {
      //throw std::out_of_range{ "Out of range" };
    }
  }

  template<typename T>
  int MyHeap<T>::rightchild(int pos) const
  {
    if (((2 * pos) + 2) < m_size)
    {
      return ((2 * pos) + 2);
    }
    else
    {
      //throw std::out_of_range{ "Out of range" };
    }
  }

  template<typename T>
  int MyHeap<T>::parent(int pos) const
  {
    if (((pos - 1) / 2) < m_size)
    {
      return ((pos - 1) / 2);
    }
  }

  template<typename T>
  int MyHeap<T>::size() const
  {
    return m_size;
  }

  template<typename T>
  bool MyHeap<T>::empty()
  {
    return (m_size == 0);
  }

  template<typename T>
  void MyHeap<T>::buildHeap()
  {
    for (int i = parent(m_size - 1); i >= 0; i--)
    {
      siftdown(i);
    }
  }

  template<typename T>
  T & MyHeap<T>::top()const
  {
    if (m_size > 0)
    {
      return Heap[0];
    }
  }

  template<typename T>
  void MyHeap<T>::pop()
  {
    if (m_size - 1 < 0)
      throw std::out_of_range("Poped on empty heap");

    swap(Heap[0], Heap[m_size - 1]);
    m_size--;
    if (m_size != 0)
    {
      siftdown(0);  // Siftdown new root val
    }
    
    if (m_size <= (m_maxSize / 4))
    {
      shrink_to_fit();
    }
  }

  template<typename T>
  void MyHeap<T>::push(const T &x)
  {
    if (m_size >= m_maxSize)
    {
      reserve(m_size * 2);
    }
    Heap[m_size++] = x;

    int parentIndex = parent(m_size - 1);
    int currentIndex = m_size - 1;
    while(x > Heap[parentIndex])
    {
      if (x > Heap[parentIndex])
      {
        swap(Heap[currentIndex], Heap[parentIndex]);
        currentIndex = parentIndex;
        parentIndex = parent(currentIndex);
      }
    }
    return;
  }

  template<typename T>
  T & MyHeap<T>::print()
  {
    cout << "[ ";
    for(int i = 0; i < m_size; i++)
    {
      cout << Heap[i] << ", ";
    }
    cout << " ]" << endl;

  }