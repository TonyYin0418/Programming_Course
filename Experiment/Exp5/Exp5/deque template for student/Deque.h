#ifndef _DEQUE_H
#define _DEQUE_H

#include <iostream>
using namespace std;

template <class T>
class Deque
{
    public:
        Deque();
        ~Deque();
        void pushFront(T *);
        void pushBack(T *);
        T *popFront();
        T *popBack();
        void showInfo(bool);

    private:
        T **rootArr;
        int rootCapacity;
        int rootFrontIndex;
        int rootBackIndex;
        void expandRoot();

        int indexOfFrontArr;
        int indexOfBackArr;
        void addFrontArr();
        void removeFrontArr();
        void addBackArr();
        void removeBackArr();

        const int ARR_SIZE = 16;

};

template<class T>
Deque<T>::Deque()
{
    rootCapacity = ARR_SIZE;
    rootArr = new T *[rootCapacity];
    rootFrontIndex = rootCapacity >> 1;
    rootBackIndex = rootFrontIndex;
    rootArr[rootFrontIndex] = new T[ARR_SIZE];
    indexOfFrontArr = -1;
    indexOfBackArr = -1;
}

template<class T>
Deque<T>::~Deque()
{
    for (int i = rootBackIndex; i <= rootFrontIndex; i++)
        delete[] rootArr[i];
    delete[] rootArr;
}

//Deque两个方向都会增长，只要某一边塞满，继续插入元素时就调用本函数扩容
//扩容后把原来的内容调整到中间
template<class T>
void Deque<T>::expandRoot()
{
    T **newRootArr = new T *[rootCapacity * 2];
    int amountOfRootElement = rootFrontIndex - rootBackIndex + 1;
    int newRootBackIndex = (rootCapacity * 2 - amountOfRootElement) >> 1;
    for (int i = 0; i < amountOfRootElement; i++)
        newRootArr[newRootBackIndex + i] = rootArr[rootBackIndex + i];
    rootBackIndex = newRootBackIndex;
    rootFrontIndex = newRootBackIndex + amountOfRootElement - 1;
    delete[] rootArr;
    rootArr = newRootArr;
    rootCapacity *= 2;
}

//前方的边际数组已满，需调用本函数增加新的数组作为前方边际数组
template<class T>
void Deque<T>::addFrontArr()
{
    if (rootFrontIndex == rootCapacity - 1)
        expandRoot();
    rootFrontIndex++;
    rootArr[rootFrontIndex] = new T[ARR_SIZE];
    indexOfFrontArr = -1;   //有了新的边界数组，但暂无元素，置为负
}

//后方的边际数组已满，需调用本函数增加新的数组作为后方边际数组
template<class T>
void Deque<T>::addBackArr()
{
    if (rootBackIndex == 0)
        expandRoot();
    rootBackIndex--;
    rootArr[rootBackIndex] = new T[ARR_SIZE];
    indexOfBackArr = -1;    //有了新的边界数组，但暂无元素，置为负
}

//前方的边际数组剩最后一个元素，再弹出，则调用本函数将前方边际数组回撤一步
//例外：如果边际数组是最后一个数组，即使其元素清空了，也保留该数组而不调用本函数
template<class T>
void Deque<T>::removeFrontArr()
{
    delete[] rootArr[rootFrontIndex];
    rootFrontIndex--;
    indexOfFrontArr = ARR_SIZE - 1;
}

//后方的边际数组剩最后一个元素，再弹出，则调用本函数将后方边际数组回撤一步
//例外：如果边际数组是最后一个数组，即使其元素清空了，也保留该数组而不调用本函数
template<class T>
void Deque<T>::removeBackArr()
{
    delete[] rootArr[rootBackIndex];
    rootBackIndex++;
    indexOfBackArr = 0;
}

//从前方插入新的元素
template<class T>
void Deque<T>::pushFront(T *s)
{
    //整个队列为空，s是首个被插入的元素，应插入中间位置
    if (rootFrontIndex == rootBackIndex && indexOfFrontArr < 0)
    {
        //请填写程序
        indexOfBackArr = indexOfFrontArr = (ARR_SIZE) >> 1;
        rootArr[rootFrontIndex][indexOfFrontArr] = *s;
        return;
    }
    //队列已有元素，s不是首个被插入的元素
    //请填写程序
    if(rootFrontIndex == ARR_SIZE - 1) {
        addFrontArr();
    }
    rootArr[rootFrontIndex][++indexOfFrontArr] = *s;
    //注意如果当前的前方边际数组已满，则需要调用addFrontArr()
    //前方添加了边际数组后应如何处理？一般情况下又该如何处理？
}

//从后方插入新的元素
template<class T>
void Deque<T>::pushBack(T *s)
{
    if(rootFrontIndex == rootBackIndex && indexOfBackArr < 0) {
        indexOfBackArr = indexOfFrontArr = (ARR_SIZE) >> 1;
        rootArr[rootFrontIndex][indexOfBackArr] = *s;
        return;
    }
    if(rootBackIndex == ARR_SIZE - 1) {
        addBackArr();
        indexOfBackArr = ARR_SIZE; // ! ! ! ! !
    }
    rootArr[rootBackIndex][--indexOfBackArr] = *s;
    //请填写程序
    //如果你能写出pushFront()，就能仿照写出本函数
}
template<class T>
T *Deque<T>::popFront()
{
    //整个队列还剩最后一个元素，或为空
    if (rootFrontIndex == rootBackIndex && indexOfFrontArr == indexOfBackArr)
    {
        if (indexOfFrontArr >= 0) //最后一个元素
        {
            T *ret = new T(rootArr[rootFrontIndex][indexOfFrontArr]);
            indexOfFrontArr = indexOfBackArr = -1;
            return ret;
            //请填写程序
            //注意不可直接返回序列内的元素，该元素已被“开除”，可能被新插入的元素覆盖
        }
        else //空，无元素可弹出
            return nullptr;
    }
    T *ret = new T(rootArr[rootFrontIndex][indexOfFrontArr]);
    indexOfFrontArr--;
    if(indexOfFrontArr == -1) removeFrontArr();
    return ret;
    //队列中还有多个元素，即将被弹出的不是最后一个元素
    //请填写程序
    //注意如果当前的前方边际数组还剩最后一个元素，则弹出后要调用removeFrontArr()
}
template<class T>
T *Deque<T>::popBack()
{
    if (rootFrontIndex == rootBackIndex && indexOfFrontArr == indexOfBackArr)
    {
        if (indexOfFrontArr >= 0) //最后一个元素
        {
            T *ret = new T(rootArr[rootFrontIndex][indexOfFrontArr]);
            indexOfFrontArr = indexOfBackArr = -1;
            return ret;
        }
        else //空，无元素可弹出
            return nullptr;
    }
    T *ret = new T(rootArr[rootFrontIndex][indexOfBackArr]);
    indexOfBackArr++;
    if(indexOfBackArr == ARR_SIZE) removeFrontArr();
    return ret;

    //请填写程序
    //如果你能写出popFront()，就能仿照写出本函数
}
template<class T>
void Deque<T>::showInfo(bool showAllDetails)
{
    using namespace std;
    cout << "Deque Status:" << endl
         << "Root Array: capacity: " << rootCapacity << ", from " << rootBackIndex << " to " << rootFrontIndex << endl
         << "Element Arrays: capacity: " << ARR_SIZE << endl
         << "Left most element of left most array: " << indexOfBackArr << endl
         << "Right most element of right most array: " << indexOfFrontArr << endl;
    if (showAllDetails)
    {
        cout << endl;
        cout << "All Elements:" << endl;
        for (int i = indexOfBackArr; i < ARR_SIZE; i++)
            cout << (rootArr[rootBackIndex][i]);
        for (int m = rootBackIndex + 1; m < rootFrontIndex; m++)
            for (int i = 0; i < ARR_SIZE; i++)
                cout << (rootArr[m][i]);
        for (int i = 0; i <= indexOfFrontArr; i++)
            cout << (rootArr[rootFrontIndex][i]);
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "Left most element: ";
        cout << (rootArr[rootBackIndex][indexOfBackArr]);
        cout << "Right most element: ";
        cout << (rootArr[rootFrontIndex][indexOfFrontArr]);
        cout << endl;
    }
}


#endif
