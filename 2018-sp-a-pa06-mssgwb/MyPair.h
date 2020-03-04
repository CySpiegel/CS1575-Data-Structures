/* Declaration of MyPair, which resembles std::pair
 * Use this as the element to store in your TreeNode.
 * Do not edit this file.
 */

#ifndef MYPAIR_H
#define MYPAIR_H

template <typename K, typename V> 
struct MyPair
{
    K first; 
    V second;
    MyPair(const K &key): first(key) {}
    MyPair(const K &key, const V &value): first(key), second(value) {}
};

#endif

