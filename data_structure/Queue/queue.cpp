#include <bits/stdc++.h>
template<typename T>
class Queue;

template<typename T>
 class Node{
    friend class Queue<T>;
    private:
    T data;
    Node<T>* next;
 };

template<typename T>
class Queue {
    public:
    Queue();
    bool empty();
    void push(const T &item);
    void pop();
    int getsize();
    T& peek();
    private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};
template<typename T>
Queue<T>::Queue() {
    size=0;
    head=nullptr;
    tail=nullptr;
}
template<typename T>
bool Queue<T>::empty() {
    return !size;
}
template<typename T>
void Queue<T>::push(const T &item) {
    if(size==0) {
        head=new Node<T>;
        head->data=item;
        head->next=nullptr;
        tail=head;

    }
    else {
        Node<T>* node=new Node<T>;
        node->data=item;
        tail->next=node;
        tail=node;
    }
    size++;
    return;

}
template<typename T>
void Queue<T>::pop() {
    if(size==0) {
        std::cout << "error" << std::endl; 
        return;
    }
     Node<T>* temp=new Node<T>;
     temp=head;
     head=head->next;
     delete temp;
     size--;
     return;
}
template<typename T>
int Queue<T>::getsize(){
    return size;
}
template<typename T>
T& Queue<T>::peek() {
    return head->data;
}
using namespace std;
int main(void) {
    Queue<int> intq;
    Queue<string> nanaq;
    cout << intq.empty()<< endl;
    intq.pop();
    intq.push(1);
    nanaq.push("FAQ");
    cout << intq.peek() << endl;
    cout << nanaq.peek() << endl;
    intq.push(2);
    intq.push(3);
    cout << intq.peek() << endl;
    cout << intq.getsize() << endl;
    intq.pop();
    cout << intq.peek() << endl;
    return 0;

}