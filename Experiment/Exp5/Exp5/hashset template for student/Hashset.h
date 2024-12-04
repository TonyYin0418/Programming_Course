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

//设置Node的原因是，这种使用template的写法不能调用t的next
template <class T, class HashFun, class EqualFun>
class Hashset
{
public:
    Hashset();
    ~Hashset();
    void insert(T *);
    void remove(T &);
    T *find(T &);
    void showInfo(bool);
    //请填写程序

private:
    Node<T> **rootArr;
    int rootCapacity;    //根数组容量
    int totalCount;        //整个容器中容纳的学生元素个数
    void expandRoot();
   
    HashFun getHash;
    EqualFun getEqual;

    const int INITIAL_ROOT_CAPACITY = 16;
    //请填写程序

};

//请填写程序
template <class T, class HashFun, class EqualFun>
Hashset<T, HashFun, EqualFun>::Hashset()
{
    rootCapacity = INITIAL_ROOT_CAPACITY;
    rootArr = new Node<T> *[rootCapacity];
    for (int i = 0; i < rootCapacity; i++)
        rootArr[i] = nullptr;
    totalCount = 0;
}
template <class T, class HashFun, class EqualFun>
Hashset<T, HashFun, EqualFun>::~Hashset()
{
    for (int i = 0; i < rootCapacity; i++)
    {
        Node<T> *p = rootArr[i], *q;
        while (p != nullptr)
        {
            q = p;
            p = p->next;
            delete q;
        }
    }
    delete[] rootArr;
}

//为避免容器中出现太长的链表，影响查找效率，
//当容器中元素总数超过了根数组容量，就要调用本函数对根数组扩容，
//扩容后，所有元素的哈希值发生改变，需要全部重新计算哈希值并插入相应位置的链表中
template <class T, class HashFun, class EqualFun>
void Hashset<T, HashFun, EqualFun>::expandRoot()
{
    Node<T> **oldRootArr = rootArr;
    int oldRootCapacity = rootCapacity;
    rootCapacity <<= 1;
    rootArr = new Node<T> *[rootCapacity];
    for (int i = 0; i < rootCapacity; i++)
        rootArr[i] = nullptr;
    for (int i = 0; i < oldRootCapacity; i++)
    {
        Node<T> *p = oldRootArr[i];
        while (p)
        {
            Node<T> *pOldNext = p->next;
            int hashValue = getHash(p->data) % rootCapacity;
            p->next = rootArr[hashValue];
            rootArr[hashValue] = p;
            p = pOldNext;
        }
    }
    delete[] oldRootArr;
}

//插入新元素
template <class T, class HashFun, class EqualFun>
void Hashset<T, HashFun, EqualFun>::insert(T *s)
{
    //如果之前元素数量已经与根数组容量相同，再插入就要超过了，需要调用expandRoot()对根数组扩容并重整
    if (totalCount >= rootCapacity)
        expandRoot();
    int hashValue = getHash(*s) % rootCapacity;
    Node<T> *tmp = new Node<T>;
    tmp->data = *s;
    tmp->next = rootArr[hashValue];
    rootArr[hashValue] = tmp;
    totalCount++;
    //计算哈希值后，找到自己在根数组中的对应元素（链表头指针），然后怎么插入最简便？放在头还是尾？
}

//根据参数s，找出容器中的相同元素，并从容器中删除
//注意：有可能容器中并不存在与s相同的元素，找不到忽略即可
template <class T, class HashFun, class EqualFun>
void Hashset<T, HashFun, EqualFun>::remove(T &s)
{
    //计算哈希值，找到自己在根数组中的对应元素（链表头指针）
    int hashValue = getHash(s) % rootCapacity;
    Node<T> *p = rootArr[hashValue];
    if (p == nullptr) // 找不到
    {
        //请填写程序
        return;
        //头指针为空意味着什么？需要怎么做？
    }
    else if (getEqual(p->data, s))
    {
        //请填写程序
        rootArr[hashValue] = p->next;
        delete p;
        totalCount--;
        //头指针指向的元素（即首元素）就是要找的，需要怎么做？
    }
    else
    {
        Node<T> *pp = nullptr;
        while(p != nullptr) {
            pp = p;
            p = p->next;
            if(getEqual(p->data, s)) {
                pp->next = p->next;
                delete p;
                totalCount--;
            }
        }
        //请填写程序
        //以上两个分支都不成立才执行至此，意味着要找的元素不是链表首元素
        //怎么找到并从链表中删除？注意有可能找不到，如何应对？
    }
}

//根据参数s，找出容器中的相同元素
//注意：有可能容器中并不存在与s相同的元素，找不到返回nullptr即可

template <class T, class HashFun, class EqualFun>
T *Hashset<T, HashFun, EqualFun>::find(T &s)
{
    //计算哈希值，找到自己在根数组中的对应元素（链表头指针）
    int hashValue = getHash(s) % rootCapacity;
    Node<T> *p = rootArr[hashValue];
    //请填写程序
    while(p != nullptr) {
        if(getEqual(p->data, s)) {
            T *ret = new T;
            *ret = p->data;
            return ret;
        }
        p = p->next;
    }
    return nullptr;
}
template <class T, class HashFun, class EqualFun>
void Hashset<T, HashFun, EqualFun>::showInfo(bool showAllDetails)
{
    using namespace std;
    cout << "Hashset Status:" << endl
         << "Root array capacity: " << rootCapacity << endl
         << "Total element count: " << totalCount << endl;
    if (!showAllDetails)
        return;
    cout << endl
         << "All Elements:" << endl;
    for (int i = 0; i < rootCapacity; i++)
    {
        cout << '[' << i << "] --> ";
        Node<T> *p = rootArr[i];
        while (p)
        {
            cout << (p->data);
            cout << " --> ";
            p = p->next;
        }
        cout << endl;
    }
    cout << endl;
}

#endif
