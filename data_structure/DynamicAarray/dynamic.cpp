#include <bits/stdc++.h>
using namespace std;

#define ll long long


template<typename T>
class linkedlist;

template<typename T>
class node {
    friend class linkedlist<T>;
    private:
        T data;
        node<T> *link;
};

template<typename T>
class linkedlist {
    public:
        linkedlist();
        bool isempty();
        void create(const T& element);
        void insertnode(const int x, const T& element);
        void deletenode(const int& x);
        void print();
        int size;
    private:
        node<T> *head;
};

template<typename T>
linkedlist<T>::linkedlist(): size(0) {};

template<typename T>
bool linkedlist<T>::isempty(){
    if (size == 0)
        return true;
    else 
        return false;
}

template<typename T>
void linkedlist<T>::create(const T& element){
    node<T> *temp = new node<T>;
    temp->data = element;
    temp->link = NULL;
    head = temp;
    size++;
    return;
}

template<typename T>
void linkedlist<T>::insertnode(const int x, const T& element){
    node<T> *temp = new node<T>;
    node<T> *cur = new node<T>;
    int cnt = 1;
    temp->data = element;
    if (x - 1 == size){
        for (cur = head; cur->link != NULL; cur = cur->link);
        temp->link = NULL;
        cur->link = temp;
        size++;
        return;
    }
    else {
        for (cur = head; cnt != x; cur = cur->link, cnt++);
        temp->link = cur->link;
        cur->link = temp;
        size++;
        return;
    }
}

template<typename T>
void linkedlist<T>::deletenode(const int& x){
    node<T> *temp = new node<T>;
    node<T> *cur = new node<T>;
    int cnt = 1;
    if (x == 1){
        cur = head->link;
        temp = head;
        head = cur;
        size--;
        delete temp;
        return;
    }
    if (x > size)
        return;
    if (x == size){
        for (cur = head; cnt != x - 1; cur = cur->link, cnt++);
        temp = cur->link;
        cur->link = NULL;
        delete temp;
        size--;
        return;
    }
    else {
        for (cur = head; cnt != x - 1; cur = cur->link, cnt++);
        temp = cur->link;
        cur->link = temp->link;
        delete temp;
        size--;
        return;
    }
}

template<typename T>
void linkedlist<T>::print(){
    node<T> *temp = new node<T>;
    for (temp = head; temp != NULL; temp = temp->link)
        cout << temp->data << " ";
    cout << "\n";
    cout << size << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //do some linked list operation

    return 0;
}