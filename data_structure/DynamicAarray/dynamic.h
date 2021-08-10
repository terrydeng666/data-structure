#include <bits/stdc++.h>

template<typename T>
class DynamicArray
{
    public:
    DynamicArray();//constructor
    DynamicArray(const DynamicArray<T> &d);
    ~DynamicArray();//destructor
    DynamicArray operator = (const DynamicArray<T> &d);
    T& operator[] (int index);
    unsigned int size();
    void add(const T);
    void Delete(const T);
    void Clear();
    private:
    int length;
    T *ptr;

};