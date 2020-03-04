#include "MyUnorderedMap.h"

void get_identity(std::string my_id[])
{
  my_id[0] = "Matthew Stroble";
  my_id[1] = "_";
}


template<typename K, typename V>
int MyUnorderedMap<K, V>::hash(const K & key) const
{
  int myKey = 0;
  for (int i = 0; i < key.length(); i++)
  {
    myKey += (key[i] *(i+2) * 17);
  }
  myKey = myKey % reserved_size;
  return myKey;
}

template<typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap()
{
  m_data = nullptr;
  data_size = 0;
  reserved_size = 0;
}

template<typename K, typename V>
MyUnorderedMap<K, V>::~MyUnorderedMap()
{
  clear();
}

template<typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap(const MyUnorderedMap<K, V>& source)
{
  m_data = nullptr;
  this->reserved_size = source.reserved_size;
  this->data_size = source.data_size;
  this->m_data = new MyPair<K, V>[reserved_size];
  for (int i = 0; i < source.reserved_size; i++)
  {
    this->m_data[i].first = source.m_data[i].first;
    this->m_data[i].second = source.m_data[i].second;
  }
}

template<typename K, typename V>
MyUnorderedMap<K, V>& MyUnorderedMap<K, V>::operator=(const MyUnorderedMap<K, V>& source)
{
  // TODO: insert return statement here
  if (this != &source)
  {
    delete[] m_data;
    m_data = nullptr;
    this->reserved_size = source.reserved_size;
    this->data_size = source.data_size;
    this->m_data = new MyPair<K, V>[reserved_size];
    for (int i = 0; i < source.reserved_size; i++)
    {
      this->m_data[i].first = source.m_data[i].first;
      this->m_data[i].second = source.m_data[i].second;
    }
  }
  return *this;
}

template<typename K, typename V>
V & MyUnorderedMap<K, V>::at(const K & key)
{
  // TODO: insert return statement here
  if (this->count(key) > 0)
  {
    MyPair<K, V> *temp = this->find(key);
    return temp->second;
  }
  else
  {
    throw std::out_of_range("Map_base::at");
  }
}

template<typename K, typename V>
V & MyUnorderedMap<K, V>::operator[](const K & key)
{
  if (this->count(key) > 0)
  {
    return this->at(key);
  }
  else
  {
    this->insert(MyPair<K,V>(key));
    return this->at(key);
  }
}

template<typename K, typename V>
bool MyUnorderedMap<K, V>::empty() const
{
  return (data_size == 0);
}

template<typename K, typename V>
int MyUnorderedMap<K, V>::size() const
{
  return data_size;
}

template<typename K, typename V>
void MyUnorderedMap<K, V>::clear()
{
  delete[] m_data;
  m_data = nullptr;
  reserved_size = 0;
  data_size = 0;
}

template<typename K, typename V>
void MyUnorderedMap<K, V>::insert(const MyPair<K, V>& init_pair)
{

  //build new array
  if (reserved_size == 0)
  {
    //inital reserve
    reserve(2);
  }

  //Reserve 
  if ((((data_size + 1.0) / reserved_size) * 100.00) > 60)
    reserve(reserved_size * 2);


  bool placed = false;
  int index = hash(init_pair.first);

  do
  {

    if (m_data[index].first == "-1" || m_data[index].first == "TOMB")
    {
      m_data[index].first = init_pair.first;
      m_data[index].second = init_pair.second;
      data_size++;
      placed = true;
    }
    else if (m_data[index].first == init_pair.first)
    {
      m_data[index].second = init_pair.second;
      placed = true;
    }
    else if(m_data[index].first != init_pair.first)
    {
      cout << "collision in insert detected " << endl;
    }

    index++;
    if (index >= reserved_size)
      index = 0;

  } while (!placed);


  
  return;
}

template<typename K, typename V>
void MyUnorderedMap<K, V>::erase(const K & key)
{
  if (this->count(key) > 0)
  {
    MyPair<K, V> *temp = this->find(key);
    temp->first = "TOMB";
    data_size--;
    if (((static_cast<float>(data_size) / reserved_size) * 100) <= 10)
    {
      reserve(static_cast<int>(reserved_size * .30));
    }
    return;
  }
  else
  {
    return;
  }
}

template<typename K, typename V>
MyPair<K, V>* MyUnorderedMap<K, V>::find(const K & key) const
{
  MyPair<K, V> *temp;
  if (this->count(key) > 0)
  {
    int index = hash(key);
    bool exists = false;
    do
    {
      if (m_data[index].first == key)
      {
        temp = &m_data[index];
        exists = true;
      }
      index++;
      if (index >= reserved_size)
      {
        index = 0;
      }
    } while (m_data[index].first != "-1" && !exists);
  }
  else
  {
    temp = nullptr;
  }
  return temp;
}

template<typename K, typename V>
void MyUnorderedMap<K, V>::print() const
{
  int count = 0;

  cout << "[";
  for (int i = 0; i < reserved_size; i++)
  {
    if (count < data_size - 1)
    {
      if (m_data[i].first != "-1" && m_data[i].first != "TOMB")
      {
        cout << "(" << m_data[i].first << ": " << m_data[i].second << "), ";
        count++;
      }
    }
    else
    {
      if (m_data[i].first != "-1" && m_data[i].first != "TOMB")
        cout << "(" << m_data[i].first << ": " << m_data[i].second << ")";
    }
    
  }
  cout << "]";

}

template<typename K, typename V>
int MyUnorderedMap<K, V>::count(const K & key) const
{
  if (empty() == false)
  {
  int count = 0;
  int index = hash(key);
  bool exists = false;

  //check what count does on an un-initalized hash table

    do
    {
      if (m_data[index].first == key)
      {
        count++;
        exists = true;
      }
      index++;
      if (index >= reserved_size)
      {
        index = 0;
      }
    } while (m_data[index].first != "-1" && !exists);
    return count;
  }
  else
  {
    return 0;
  }
}

template<typename K, typename V>
void MyUnorderedMap<K, V>::reserve(int new_cap)
{
  //new array and setting keys to empty flag
  MyPair<K, V> *temp = new  MyPair<K, V>[new_cap];
  for (int i = 0; i < new_cap; i++)
  {
    temp[i].first = "-1";
  }

  //Only called for inital data when reserved_size is zero;
  if (reserved_size == 0)
  {
    reserved_size = new_cap;
    m_data = temp;
    temp = nullptr;
    return;
  }

  //pos in new array
  int index = 0;
  int oldReserved_size = reserved_size;
  reserved_size = new_cap;


  //walk through old m_data looking for valid data to rehash
  for (int i = 0; i < oldReserved_size; i++)
  {
    bool placed = false;

    //loop through original array looking for valid data to hash into new temp table;
    if (m_data[i].first != "-1" && m_data[i].first != "TOMB")
    {
      index = hash(m_data[i].first);
      bool placed = false;
      do
      {
        if (temp[index].first == "-1")
        {
          temp[index].first = m_data[i].first;
          temp[index].second = m_data[i].second;
          placed = true;
        }
        else
        {

          index++;
          if (index >= reserved_size)
          {
            index = 0;
          }
          if (temp[index].first == "-1")
          {
            temp[index].first = m_data[i].first;
            temp[index].second = m_data[i].second;
            placed = true;
          }

        }
      } while (!placed);
      
    }
  }


  delete[] m_data;
  m_data = temp;
  temp = nullptr;

  return;
}

