#include <bits/stdc++.h>
 template<typename T>
 class Node{
    friend class LinkedLiist;
    private:
    T data;
    Node<T>* next;
 };
 template<typename T>
 class LinkedList {
     public:
     LinkedList();
     LinkedList(const LinkedList<T> &l);
     ~LinkedList();
     void Clear();
     void Push_front(const T &item);
     void Push_back(const T &item);
     void insert(const int index ,const T &item);
     void delete_node(const int index);
     void print_list();
     int getsize();

     private:
     Node<T>* head;
     Node<T>* tail;
     int size;
 };