


//MyList Class implamentation
//Sets pointers to null
template<typename T>
MyList<T>::MyList()
{
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
}


template<typename T>
MyList<T>::~MyList()
{
  clear();
}


template<typename T>
MyList<T> & MyList<T>::operator=(const MyList<T> &source)
{
  if (this != &source)
  {
    clear();
    Node<T>* temp = source.m_head;
    while (temp != NULL)
    {
      this->push_back(temp->m_element);
      temp = temp->m_next;
    }
    delete temp;
    return *this;
  }
}


template <typename T>
MyList<T>::MyList(const MyList<T> &source)
{
  m_head = NULL;
  m_tail = NULL;
  m_size = 0;
  //*this = source;

  
  Node<T>* temp = source.m_head;
  while (temp != NULL)
  {
    push_back(temp->m_element);
    temp = temp->m_next;
  }
  delete temp;
  
}


template <typename T>
T& MyList<T>::front()
{
  return m_head->m_element;

}

template <typename T>
T & MyList<T>::back()
{
  return m_tail->m_element;
}

template<typename T>
void MyList<T>::assign(int count, const T &value)
{
  this->clear();
  for (int i = 0; i < count; i++)
  {
    this->push_back(value);
  }
}


//Clear destroys everything.
template <typename T>
void MyList<T>::clear()
{
  Node<T>* temp;
  while (m_head != NULL)
  {
    temp = m_head;
    m_head = temp->m_next;
    delete temp;
  }
  m_tail = NULL;
  m_size = 0;
}

template <typename T>
void MyList<T>::push_front(const T &x)
{

  if (m_head != NULL)
  {
    Node<T> *temp = new Node<T>(x, NULL, m_head);
    m_head->m_prev = temp;
    m_head = temp;
    temp = NULL;
    m_size++;
    return;
  }
  else
  {
    Node<T> *temp = new Node<T>(x, NULL, NULL);
    m_head = temp;
    m_tail = m_head;
    temp = NULL;
    m_size++;
    return;
  }
}


//Stupid push_back method for single linked list
//ITS SO FUCKING SLOW
/*
template <typename T>
void MyList<T>::push_back(const T &x)
{
  if (m_head != NULL)
  {
    Node<T> *temp = m_head;
    while (temp->m_next != NULL)
    {
      temp = temp->m_next;
    }
    temp->m_next = new Node<T>(x, temp, NULL);
    temp->m_prev = m_tail;
    m_tail = temp;
    temp = NULL;
  }
  else
  {
    m_head = new Node<T>(x, NULL, NULL);
    m_head->m_next = NULL;
    m_head->m_prev = NULL;
    m_tail = m_head;
  }
  m_size++;
  return;
}
*/


//Speedy push_back
template <typename T>
void MyList<T>::push_back(const T &x)
{
  if (m_tail != NULL)
  {
    Node<T> *temp = m_tail;
    temp->m_next = new Node<T>(x, temp, NULL);
    m_tail = temp->m_next;
    m_tail->m_prev = temp;
    temp = NULL;
  }
  else
  {
    m_head = new Node<T>(x, NULL, NULL);
    m_tail = m_head;
  }
  m_size++;
  return;
}


//Working
template <typename T>
void MyList<T>::pop_back()
{
  if (m_tail == NULL)
  {
    return;
  }
  else if (m_size == 1)
  {
    clear();
    return;
  }
  else
  {
    Node<T> *temp = m_tail;
    m_tail = m_tail->m_prev;
    m_tail->m_next = NULL;
    temp->m_next = NULL;
    temp->m_prev = NULL;
    delete temp;
    m_size--;
    return;
  }
}
/*
//Remove this befor submitting
template <typename T>
void MyList<T>::pop_front()
{
  if (m_head == NULL)
  {
    return;
  }
  else if (m_size == 1)
  {
    Node<T> *temp = m_head;
    m_tail = NULL;
    m_head = NULL;
    delete temp;
    m_size--;
    return;
  }
  else
  {
    Node<T> *temp = m_head;
    m_head = temp->m_next;
    m_head->m_prev = NULL;
    temp->m_next = NULL;
    temp->m_prev = NULL;
    delete temp;
    m_size--;
    return;
  }
}
*/

// Simplified version that only takes one position
// Insert behaves like the STD iterator insert if 
//attempted possition is outsize of the range
template <typename T>
void MyList<T>::insert(int i, const T &x)
{
  int count = 0;
  int pos = 0;
  int listSize = this->size();
  bool posFound = false;
  while (count <= i && posFound == false)
  {
    for (int k = 0; k < listSize + 1; k++)
    {
      if (count == i)
      {
        pos = k;
        posFound = true;
        break;
      }
      count++;
    }

  }
  count = 0;

  Node<T> *temp = m_head;
  if (pos == 0)
  {
    this->push_front(x);
  }
  else if (pos == this->size())
  {
    this->push_back(x);
  }
  else
  {
    //itterating to possition in the list
    while (count < pos)
    {
      temp = temp->m_next;
      count++;
    }

    Node<T> *temp2 = temp->m_prev;
    temp2->m_next = new Node<T>(x, temp2, temp);
    temp->m_prev = temp2->m_next;
    temp = NULL;
    temp2 = NULL;
    m_size++;
    return;

  }
  return;
}

//Removes all data in the list that matchies i
template <typename T>
void MyList<T>::remove(T i)
{
  Node<T> *temp;
  int orgSize = this->size();
  for (int k = 0; k < orgSize; k++)
  {
    if (this->back() == i)
    {
      pop_back();
    }
    else
    {
      this->push_front(this->back());
      this->pop_back();
    }
  }
  return;
}

//Removes the node in the list at the possition.
template <typename T>
void MyList<T>::erase(int i)
{

  if (empty() == true)
  {
    //If list is empty do nothing.
    //I would throw error but we have no error class to throw
    return;
  }

  if (m_size == 1)
  {
    if (i == 0)
    {
      clear();
      return;
    }
    /*
    Since the list only has one elament and if erase attempts to erace outsize
    of the length of the list, i would throw error
    */
  }

  if (m_size > 1)
  {
    int count = 0;
    Node<T> *temp = m_head;
    while (count < i)
    {
      temp = temp->m_next;
      count++;
    }

    if (temp->m_prev != NULL)
    {
      temp->m_prev->m_next = temp->m_next;
    }
    else
    {
      m_head = temp->m_next;
    }

    if (temp->m_next != NULL)
    {
      temp->m_next->m_prev = temp->m_prev;
    }
    else
    {
      m_tail = temp->m_prev;
    }
    delete temp;
    m_size--;
    return;
  }
}


template <typename T>
void MyList<T>::reverse()
{
  int listSize = this->size();

  for (int i = 0; i < listSize; i++)
  {
    this->insert(i, this->back());
    this->pop_back();
  }
  return;
}


template <typename T>
void MyList<T>::resize(int count)
{
  int listSize = this->size();

  if (count > listSize)
  {
    count = count - listSize;
    for (int i = 0; i < count; i++)
    {
      this->push_back(0);
    }
  }
  else if (count < listSize)
  {
    count = listSize - count;
    for (int i = 0; i < count; i++)
    {
      this->pop_back();
    }
  }
  return;
}


template <typename T>
bool MyList<T>::empty()
{
  return (m_size <= 0);
}


template <typename T>
int MyList<T>::size()
{
  return m_size;
}
