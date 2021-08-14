#include <bits/stdc++.h>
template<typename T>
class LinkedList;

 template<typename T>
 class Node{
    friend class LinkedList<T>;
    private:
    T data;
    Node<T>* next;
 };
 template<typename T>
 class LinkedList {
     public:
     LinkedList();
     LinkedList(const LinkedList<T> &l);
     //~LinkedList();
     // LinkedList& operator = (const LinkedList<T> &d);
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
     this->head=l.head;
     this->tail=l.tail;
     this->size=l.size;
     this->isEmpty=false;
 }
/*template <typename T>
 LinkedList<T>::~LinkedList() 
 {
     delete head;
     delete tail;
 }*/
 template <typename T>
 void LinkedList<T>::Clear() 
 {
     delete head;
     head = new Node<T>;
     tail=head;
     size=0;
     isEmpty=true;
 }
 template <typename T>
 void LinkedList<T>::Push_front(const T &item) 
 {
     Node<T>* node=new Node<T>;
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
     size++;
     return;
 }
 template <typename T>
 void LinkedList<T>::Push_back(const T &item) 
 {
     Node<T>* node=new Node<T>;
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
     size++;
     return;
 }
 template <typename T>
 void LinkedList<T>::insert(const int index ,const T &item) 
 {
     if(index>size-1) {
         std::cout << "out of boundary,FAQ";
         return;
     }
     Node<T>* temp=new Node<T>;
     Node<T>* node=new Node<T>;
     if(index==size-1) {
         tail->next=node;
         node->next=nullptr;
         node->data=item;
         size++;
     }
     node->data=item;
     int i=0;
     for(temp=head;i<index-1;i++,temp=temp->next);
     node->next=temp->next;
     temp->next=node;
     size++;
     return;
 }
 template <typename T>
 void LinkedList<T>::delete_node(const int index)
 {
     if(index>size-1) {
         std::cout << "out of boundary,FAQ";
         return;
     }
     Node<T>* temp=new Node<T>;
     Node<T>* node=new Node<T>;
     int i=0;
     for(temp=head;i<index-1;i++,temp=temp->next);
     //i=index-1
     node=temp->next;
     temp->next=node->next;
     delete node;
     size--;
     return;
 }

template <typename T>
 void LinkedList<T>::print_list() 
 {
     Node<T>* node = new Node<T>;
     int i=0;
     for(node = head;i<size;i++,node = node->next) {
         std::cout << node->data << std::endl;
     }
 }
 template <typename T>
 int LinkedList<T>::getsize() {
     return size;
 }
/*template<typename T>
 LinkedList<T> &LinkedList<T>::operator = (const LinkedList<T> &l) 
 {
     if(this == &l) return *this;
     if(l.isEmpty) Clear();
     head=nullptr;
     tail=nullptr;
     return *this;

 }
 */

 int main(void) {
     LinkedList<int> intL;
     LinkedList<char> charL;
     intL.Push_front(1);
     charL.Push_front('a');
     intL.print_list();
     charL.print_list();
     LinkedList<int> intL2(intL);
     intL2.print_list();
     intL.Push_front(0);
     intL.print_list();
     intL.Push_back(2);
     intL.print_list();
     std::cout << intL.getsize()<< std::endl;
     intL.insert(1,22);
     intL.print_list();
     intL.delete_node(1);
     intL.print_list();
     return 0;
 }