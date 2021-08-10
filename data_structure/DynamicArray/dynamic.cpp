#include <bits/stdc++.h>
template<typename T>
class DynamicArray
{
    public:
    int size;
    DynamicArray();//constructor
    DynamicArray(const DynamicArray<T> &d);
    ~DynamicArray();//destructor
    DynamicArray& operator = (const DynamicArray<T> &d);
    T& operator[] (int index);
    void add(const T &item);
    void Delete(int index);
    void Clear();
    private:
    int length;
    T *ptr;

};
template<typename T>

DynamicArray<T>::DynamicArray() 
{
    length=0;
    ptr= (T*)malloc(sizeof(T));
    if(ptr==NULL) std::cout << "error";
    size=length;
}
template<typename T>

DynamicArray<T>::DynamicArray(const DynamicArray<T> &d)
 {
     length=d.length;
     ptr=(T*)malloc(sizeof(T)*length);
     memcpy(ptr,d.ptr,sizeof(T)*length);
     if(ptr==NULL) std::cout<<"error";
     size=length;
 }

 template<typename T>

 DynamicArray<T>::~DynamicArray()
 {
     if(ptr) {
         free(ptr);
         ptr=NULL;
     }
 }

template<typename T>
 DynamicArray<T> &DynamicArray<T>::operator = (const DynamicArray<T> &d) 
 {
     if(this == &d) return *this;
     if(d.length==0) Clear();
     length = d.length;
     ptr=(T*)realloc(ptr,sizeof(T)*length);
     memcpy(ptr,d.ptr,sizeof(T)*length);
     size=length;
     return *this;

 }
template<typename T>
T& DynamicArray<T>:: operator[](int index)
{
    return ptr[index];
}
template<typename T>
void DynamicArray<T>::add(const T &item) {
    length++;
    ptr = (T*)realloc(ptr,sizeof(T)*length);
    ptr[length-1]=item;
    size=length;
}

template<typename T>
void DynamicArray<T>::Delete(int index) {
    if(length==1) Clear();
    else{
        for(int i = index;i<length-1;++i) {
            ptr[i]=ptr[i+1];
        }
        length--;
    }
    size=length;
}
template<typename T>
void DynamicArray<T>::Clear() {
    length=0;
    ptr=(T*)realloc(ptr,sizeof(T));
}

int main(void) {
    DynamicArray<int> array;
    array.add(1);
    std::cout << array[0] << std::endl;
    array.add(2);
    std::cout << array[1] << std::endl;
    std::cout << array.size << std::endl;
    array.Delete(0);
    std::cout << array[0] << std::endl;
    DynamicArray<int> array2(array);
    std::cout << array2[0] << std::endl;
    DynamicArray<int> array3;
    array3=array;
    std::cout << array3[0] << std::endl;
    return 0;
}