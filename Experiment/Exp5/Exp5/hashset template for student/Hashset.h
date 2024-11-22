#ifndef _HASHSET_H
#define _HASHSET_H

#include <iostream>

template <class T>
class Node
{
public:
    Node<T> *next;
    T data;
};

template <class T, class HashFun, class EqualFun>
class Hashset
{
public:
    //请填写程序

private:
    Node<T> **rootArr;
    //请填写程序
};

//请填写程序

#endif
