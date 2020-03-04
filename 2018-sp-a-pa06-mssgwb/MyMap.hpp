#include "MyMap.h"


void get_identity(std::string my_id[])
{
  my_id[0] = "Matthew Stroble";
  my_id[1] = "_";
}

//Private section
template<typename K, typename V>
V & MyMap<K, V>::at_helper(TreeNode<MyPair<K, V>>*& rt, const K & key)
{
  // TODO: insert return statement here
  MyPair<K, V> *temp = find(key);
  if (temp == NULL)
  {
    throw std::out_of_range("MyMap::at");
  }

  return temp->second;

}

template<typename K, typename V>
int MyMap<K, V>::size_helper(TreeNode<MyPair<K, V>>* rt) const
{
  int size = 0;
  if (rt == NULL)
  {
    return 0;
  }
  else
  {
    size++;
    size += size_helper(rt->left);
    size += size_helper(rt->right);
  }
  return size;
}

template<typename K, typename V>
void MyMap<K, V>::clear_helper(TreeNode<MyPair<K, V>>*& rt)
{
  if (rt == NULL)
    return;

  clear_helper(rt->left);
  clear_helper(rt->right);
  delete rt;

  return;
}

template<typename K, typename V>
void MyMap<K, V>::insert_helper(TreeNode<MyPair<K, V>>*& rt, const MyPair<K, V>& init_pair)
{
  if (rt == NULL)
  {
    rt = new TreeNode<MyPair<K, V>>(init_pair, NULL, NULL);
  }
  else if (init_pair.first < rt->data.first)
  {
    insert_helper(rt->left, init_pair);
  }
  else if (init_pair.first > rt->data.first)
  {
    insert_helper(rt->right, init_pair);
  }
  else if (init_pair.first == rt->data.first)
  {
    rt->data.second = init_pair.second;
  }

  // If inserting a key that already exists, update the node at that key with the new data.
  return;
}

template<typename K, typename V>
TreeNode<MyPair<K, V>>* MyMap<K, V>::get_min(TreeNode<MyPair<K, V>>* rt)
{
  if (rt->left == NULL)
  {
    return rt;
  }
  else
  {
    return get_min(rt->left);
  }
}

template<typename K, typename V>
void MyMap<K, V>::erase_helper(TreeNode<MyPair<K, V>>*& rt, const K & key)
{
  if (rt == NULL)
    return;
  TreeNode<MyPair<K, V>> *temp = rt;
  if (rt->data.first == key)
  {
    //check for childs
    if (rt->left == NULL && rt->right == NULL)
    {
      //Treenode has no children
      rt = NULL;
      delete temp;
    }
    else if (rt->left == NULL && rt->right != NULL)
    {
      //No left child Only Right child
      rt = rt->right;
      delete temp;
    }
    else if (rt->right == NULL && rt->left != NULL)
    {
      //No right child, Only Left child exists
      rt = rt->left;
      delete temp;
    }
    else if (rt->left != NULL && rt->right != NULL)
    {
      //Node has both left and right children
      TreeNode<MyPair<K, V>> * mintemp = get_min(rt->right);
      rt->data.first = mintemp->data.first;
      rt->data.second = mintemp->data.second;
      erase_helper(rt->right, rt->data.first);
    }
  }
  else
  {
    erase_helper(rt->left, key);
    erase_helper(rt->right, key);
  }
  return;
}

template<typename K, typename V>
MyPair<K, V>* MyMap<K, V>::find_helper(TreeNode<MyPair<K, V>>* rt, const K & key) const
{
  if (rt == NULL)
    return NULL;
  if (key < rt->data.first)
  {
    return find_helper(rt->left, key);
  }
  else if (key > rt->data.first)
  {
    return find_helper(rt->right, key);
  }
  else
  {
    return &rt->data; //returning address location of found pair
  }
  return NULL;
}

template<typename K, typename V>
void MyMap<K, V>::print_helper(TreeNode<MyPair<K, V>>* rt, std::string indent) const
{
  if (rt == NULL)
  {
    cout << indent << "   empty" << endl;
    return;
  }
  print_helper(rt->right, indent += "  ");  // Do right subtree
  cout << indent << " " << rt->data.first << " " << rt->data.second << endl;        // Print node value
  print_helper(rt->left, indent += "");   // Do left subtree
  return;
}

template<typename K, typename V>
int MyMap<K, V>::count_helper(TreeNode<MyPair<K, V>>* rt, const K & key) const
{
  int countTotal = 0;
  if (rt == NULL)
  {
    return 0;
  }
  else
  {
    if (rt->data.first == key)
    {
      countTotal++;
    }
    countTotal += count_helper(rt->left, key);
    countTotal += count_helper(rt->right, key);
  }
  return countTotal;
}

template<typename K, typename V>
TreeNode<MyPair<K, V>>* MyMap<K, V>::clone(const TreeNode<MyPair<K, V>>* rt)
{
  if (rt != NULL)
  {
    TreeNode<MyPair<K, V>> *root = new TreeNode<MyPair<K, V>>(rt->data, clone(rt->left), clone(rt->right));
    return root;
  }
  else
  {
    return NULL;
  }
}





//Public Section

//Default Constructor
template<typename K, typename V>
MyMap<K, V>::MyMap()
{
  this->root = NULL;
}

template<typename K, typename V>
MyMap<K, V>::~MyMap()
{
  //childs must be deleted first
  clear_helper(root);
}

//Copy Constructor 
template<typename K, typename V>
MyMap<K, V>::MyMap(const MyMap<K, V>& source)
{
  this->root = NULL;
  this->root = clone(source.root); 
}

//Assignment Overload
template<typename K, typename V>
MyMap<K, V>& MyMap<K, V>::operator=(const MyMap<K, V>& source)
{
  // TODO: insert return statement here
  if (this != &source)
  {
    this->clear();
    this->root = clone(source.root);
    return *this;
  }
}

//
template<typename K, typename V>
V & MyMap<K, V>::at(const K & key)
{
  // TODO: insert return statement here
  //Insert at key if it exists and throw error if not found
  return at_helper(root, key);

}

template<typename K, typename V>
V & MyMap<K, V>::operator[](const K & key)
{
  //TODO: insert return statement here
  //Overight at key and if not found use insert
  MyPair<K, V> *temp = find(key);
  if (temp != NULL)
  {
    return temp->second;
  }
  //this->insert(MyPair<int, std::string>(key, ""));
  this->insert(MyPair<K, V>(key));
  temp = find(key);
  return temp->second;

}

template<typename K, typename V>
bool MyMap<K, V>::empty() const
{
  if (this->size() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename K, typename V>
int MyMap<K, V>::size() const
{
  return size_helper(root);
}

template<typename K, typename V>
void MyMap<K, V>::clear()
{
  clear_helper(root);
  root = NULL;
}

template<typename K, typename V>
void MyMap<K, V>::insert(const MyPair<K, V>& init_pair)
{
  insert_helper(root, init_pair);
}

template<typename K, typename V>
void MyMap<K, V>::erase(const K & key)
{
  MyPair<K, V> *temp = find(key);
  if (temp != NULL)
  {
    erase_helper(root, key);
  }
  return;
}

//find returns the object if found, if not found returns NULL.
template<typename K, typename V>
MyPair<K, V>* MyMap<K, V>::find(const K & key) const
{
  return find_helper(root, key);
}

template<typename K, typename V>
void MyMap<K, V>::print() const
{
  if (root == NULL)
    cout << "   empty" << endl;
  else
    print_helper(root, "");
  return;
}

template<typename K, typename V>
int MyMap<K, V>::count(const K & key) const
{
  return count_helper(root, key);
}
