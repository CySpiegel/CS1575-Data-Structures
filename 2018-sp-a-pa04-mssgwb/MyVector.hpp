/* Define all your MyVector-related functions here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */

 /*
 MyVector will behave as an array list
 */


 //Swap function
 //type for A and B should be of type T
template <typename T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
  return;
}


//Default constructor defaulting to size 1
template <typename T>
MyVector<T>::MyVector()
{
  reserved_size = 1;
  m_data = new T[reserved_size];
  data_size = 0;
}


// We're giving you this one for free
// and as a guide for the syntax.
//Destructor
template <typename T>
MyVector<T>::~MyVector()
{
  delete[] m_data;
  m_data = NULL;
}


//Assignment overloading
template<typename T>
MyVector<T> & MyVector<T>::operator=(const MyVector<T> &source)
{
  //delete[] m_data;
  //m_data = NULL;
  if (this != &source)
  {
    delete[] m_data;
    m_data = NULL;
    this->data_size = source.data_size;
    this->reserved_size = source.reserved_size;
    this->m_data = new T[reserved_size];
    for (int i = 0; i < data_size; i++)
    {
      this->m_data[i] = source.m_data[i];
    }
  }
  return *this;
}


//Copy Constructor
template <typename T>
MyVector<T>::MyVector(const MyVector<T> &source)
{
  data_size = source.data_size;
  reserved_size = source.reserved_size;
  m_data = new T[reserved_size];
  for (int i = 0; i < data_size; i++)
  {
    m_data[i] = source.m_data[i];
  }

}


//Bracket Overloading
template <typename T>
T & MyVector<T>::operator[](int i)
{

  if (i >= reserved_size)
    throw OutOfBoundsException();

  return m_data[i];
}


// Another example: remember, return type first, 
// then scope just before the function name.
template <typename T>
T & MyVector<T>::at(int index)
{
  //Define the function here.
  if (index >= reserved_size)
    throw OutOfBoundsException();
  //need to implament try catch for out of range possability.
  return m_data[index];
}

// Purpose: Returns the element stored at the front of the vector
template <typename T>
T & MyVector<T>::front()
{
  return m_data[0];
}


// Purpose: Returns the element stored at the back of the vector
template <typename T>
T & MyVector<T>::back()
{
  return m_data[data_size - 1];
}


// Purpose: Returns the maximum number of elements that can be stored in the current Vector
template <typename T>
int MyVector<T>::capacity()
{
  return reserved_size;
}


//Reserve more space
template<typename T>
void MyVector<T>::reserve(int new_cap)
{
  if (new_cap > reserved_size)
  {
    T *tempData = new T[reserved_size];

    for (int i = 0; i < data_size; i++)
    {
      tempData[i] = m_data[i];
    }

    int tempDataSize = data_size;
    delete[] m_data;
    m_data = NULL;

    //setting m_data array to new Reserved size
    reserved_size = new_cap;
    data_size = tempDataSize;
    m_data = new T[reserved_size];

    for (int i = 0; i < data_size; i++)
    {
      m_data[i] = tempData[i];
    }

    delete[] tempData;
    tempData = NULL;
  }
  return;
}


//Shring array
template <typename T>
void MyVector<T>::shrink_to_fit()
{
  T *m_tempData = new T[data_size * 2];
  for (int i = 0; i < data_size; i++)
  {
    m_tempData[i] = m_data[i];
  }
  delete[] m_tempData;
  m_tempData = NULL;
  reserved_size = data_size * 2;
  return;
}


//filling the array with values
template <typename T>
void MyVector<T>::assign(int count, const T &value)
{
  if (count >= reserved_size)
  {
    reserve(count * 2);
  }
  else if (count < data_size)
  {
    data_size = count;
    if (data_size <= reserved_size / 4)
      shrink_to_fit();
  }

  for (int i = 0; i <= count; i++)
  {
    m_data[i] = value;
  }
}


//Clearing vector
template <typename T>
void MyVector<T>::clear()
{
  data_size = 0;
  reserved_size = 1;
  delete[] m_data;
  m_data = NULL;
  m_data = new T[reserved_size];
  return;
}


//Push back
template <typename T>
void MyVector<T>::push_back(const T &x)
{
  if (data_size >= reserved_size)
  {
    reserve(data_size * 2);
  }

  m_data[data_size++] = x;
  return;
}


//Pop 
template <typename T>
void MyVector<T>::pop_back()
{
  if (data_size-- < 0)
    throw OutOfBoundsException();

  if (data_size <= reserved_size / 4)
    shrink_to_fit();
}


//Insert
template <typename T>
void MyVector<T>::insert(int i, const T &x)
{

  if (i >= reserved_size || i < 0)
    throw OutOfBoundsException();

  /*
  if attempt to insert beyond data_size it will append it to the last
  avalable size in the array. This way you avoid having holes in the
  array list and all of the data that exists in the array is valid.
  */
  if (i >= data_size)
    i = data_size;

  data_size++;
  if (data_size >= reserved_size)
    reserve(data_size * 2);

  for (int j = size() - 1; j > i; j--)
  {
    swap(m_data[j - 1], m_data[j]);
  }
  m_data[i] = x;
  return;
}


//Remove at index i
template <typename T>
void MyVector<T>::remove(int i)
{
  /*
  Will throw exception if you attempt to remove an elament greater than the range
  */

  if (i >= reserved_size || i < 0 || data_size == 0)
    throw OutOfBoundsException();

  data_size--;
  if (data_size <= reserved_size / 4)
    shrink_to_fit();

  for (int j = i; j < data_size; j++)
  {
    swap(m_data[j], m_data[j + 1]);
  }
}


//Return size of actual data
template <typename T>
int MyVector<T>::size()
{
  return data_size;
}