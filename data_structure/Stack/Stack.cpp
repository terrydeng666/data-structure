#include <bits/stdc++.h>
template<typename T>
class Stack;

template<typename T>
 class Node{
    friend class Stack<T>;
    private:
    T data;
    Node<T>* next;
 };

template<typename T>
class Stack{
    public:
    Stack();
    bool empty();
    int getsize();
    T& top();
    void push(const T &item);
    void pop();
    private:
    int size;
    Node<T>* head;
};
template<typename T>
Stack<T>::Stack() {
    size=0;
}
template<typename T>
bool Stack<T>::empty() {
    return !size;
}
template<typename T>
int Stack<T>::getsize(){
    return size;
}
template<typename T>
T& Stack<T>::top() {
    return head->data;
}
template<typename T>
void Stack<T>::push(const T &item) {
    if(size==0) {
        head=new Node<T>;
        head->data=item;
        head->next=nullptr;
    }
    else {
        Node<T>* node=new Node<T>;
        node->data=item;
        node->next=head;
        head=node;

    }
    size++;
    return;

}
template<typename T>
void Stack<T>::pop() {
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

int main(void) {
    Stack<int> intStack;
    Stack<std::string> stringStack;
    std::cout << intStack.empty() << std::endl;
    std::cout << intStack.getsize() << std::endl;
    intStack.push(2);
    std::cout << intStack.top() << std::endl;
    std::cout << stringStack.getsize() << std::endl;
    stringStack.push("FAQ");
    std::cout << stringStack.top() << std::endl;
    std::cout << stringStack.getsize() << std::endl;
    stringStack.pop();
    stringStack.pop();
    std::cout << stringStack.getsize() << std::endl;
    intStack.push(3);
    intStack.push(5);
    std::cout << intStack.top() << std::endl;
    intStack.top()=7;
    std::cout << intStack.top() << std::endl;
    std::cout << intStack.empty() << std::endl;
    return 0;
}