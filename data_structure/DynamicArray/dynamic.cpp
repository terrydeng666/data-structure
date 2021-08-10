#include "dynamic.h"
template<typename T>

DynamicArray<T>::DynamicArray() 
{
    length=0;
    ptr= (T*)malloc(sizeof(T));
    if(ptr==NULL) std::cout << "error";
}
template<typename T>

DynamicArray<T>::DynamicArray(const DynamicArray<T> &d)
 {
     length=d.length;
     ptr=(T*)malloc(sizeof(T)*length);
     memcpy(ptr,d.ptr,sizeof(T)*length);
     if(ptr==NULL) std::cout<<"error";
 }
 template<typename T>