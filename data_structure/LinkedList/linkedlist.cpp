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
     bool isEmpty;
 };

 template <typename T>
 LinkedList<T>::LinkedList() 
 {
     head=nullptr;
     tail=nullptr;
     size=0;
     isEmpty=true;
 }
 template <typename T>
 LinkedList<T>::LinkedList(const LinkedList<T> &l) 
 {
     this->head=(T*)malloc(sizeof(T));
     memcpy(this->head,l.head,sizeof(T)*l.size);
     this->tail = this->head + size;
     this->size=l.size;
     this->isEmpty=false;
 }
template <typename T>
 LinkedList<T>::~LinkedList() 
 {
     free(this->head);
     free(this->tail);
 }
 template <typename T>
 void LinkedList<T>::Clear() 
 {
     head=(T*)realloc(head,sizeof(T));
     tail=head;
     size=0;
     isEmpty=true;
 }
 template <typename T>
 void LinkedList<T>::Push_front(const T &item) 
 {
     Node<T>* node;
     node->data=item;
     if(isEmpty) {
         this->head=node;
         this->tail=node;
         isEmpty=false;
     }
     else {
        node->next=this->head;
        this->head=node;
     }
     return;
 }
 template <typename T>
 void LinkedList<T>::Push_back(const T &item) 
 {
     Node<T>* node;
     node->data=item;
     if(isEmpty) {
         this->head=node;
         this->tail=node;
         isEmpty=false;
     }
     else {
         tail->next=node;
         tail=node;
     }
     tail->next=nullptr;
     return;
 }

