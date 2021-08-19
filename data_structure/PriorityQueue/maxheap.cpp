#include <bits/stdc++.h>
#include  <unordered_map>
using namespace std;
template<typename T>
class maxheap{
    public:
    maxheap();
    bool isempty();
    void poll();
    void remove(const T &item);
    void insert(const T &item);
    void print();
    int  getsize() {return size;}
    private:
    vector<T> v;
    int parent(int index){
        if(index%2==0) {//right
        return (index-2)/2;
        }
        else {
            return (index-1)/2;
        }
    }
    int left_child(int index){return index*2 +1;}
    int right_child(int index){return index *2 +2;}
    int size;
    void bubble_up(int index){
        while(v[index]> v[parent(index)]) {
            T temp = v[index];
            v[index]=v[parent(index)];
            v[parent(index)]=temp;
            index=parent(index);
            if(index==0) return;
        }
        return;
       
    }
    void bubble_down(int index) {
        while(v[index] < v[left_child(index)] || v[index] < v[right_child(index)]) {
            if(v[left_child(index)] >= v[right_child(index)]) {
                T temp = v[index];
                v[index]= v[left_child(index)];
                v[left_child(index)]=temp;
                index = left_child(index);
            }
            else {
                T temp = v[index];
                v[index]= v[right_child(index)];
                v[right_child(index)]=temp;
                index = right_child(index);

            }
            if(index>=v.size()-2) return;
        }
        return;
    }
};
template<typename T>
maxheap<T>::maxheap() {
    size=0;
    //0開頭的heap
    //last index=size
}
template<typename T>
bool maxheap<T>::isempty() { return size==0;}
template<typename T>
void maxheap<T>::insert(const T &item) {
    v.push_back(item);
    if(size==0) {size++;return;}
    if(v[parent(size)] < v[size]) {
        bubble_up(size);
    }
    size++;
    return;
}
template<typename T>
void maxheap<T>::poll() {
    v[0]=v[size-1];
    v.pop_back();
    if(v[1]>v[0] || v[2] > v[0]) {
        bubble_down(0);
    }
    size--;
    return;
}
template<typename T>
void maxheap<T>::remove(const T &item) {
    for(int i=0;i<size;i++) {
        if(v[i]==item) {
            T temp= item;
            v[i]= v[size-1];
            v.pop_back();
            if(v[i] > v[parent(i)]) {
                bubble_up(i);
            }
            else if(v[left_child(i)] > v[i] || v[right_child(i)] > v[i]) {
                bubble_down(i);
            }
            size--;
            return;
        }
    }
    cout << "item not found" << endl;
    return;
}
template<typename T>
void maxheap<T>::print(){
    for(int i=0;i<size;++i) {
        cout << v[i] << endl;
    }
    return;
}
int main(void) {
    maxheap<int> heap;
    heap.insert(2);
    //heap.print();
    heap.insert(30);
    heap.insert(4);
    heap.insert(40);
    //heap.print();
    heap.poll();
    //heap.print();
    heap.insert(10);
    heap.insert(3);
    heap.insert(100);
    heap.insert(7);
    heap.insert(8);
    //heap.print();
    heap.remove(10);
    //heap.print();
    heap.remove(90);
    heap.print();
    cout << heap.getsize() << endl;
    return 0;
}