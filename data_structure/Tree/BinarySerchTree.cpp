#include <bits/stdc++.h>
using namespace std;
template<typename T>
class BinarySerchTree;

template<typename T>
 class Node{
    friend class BinarySerchTree<T>;
    private:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
 };

template<typename T>
class BinarySerchTree{
    public:
    BinarySerchTree();
    void isempty();
    int getsize();
    void add(const T& item);
    void remove(const T &item);
    T& getmax();
    T& getmax(Node<T>* node);
    T& getroot(){
        return root->data;
    }
    T& getmin();
    T& getmin(Node<T>* node);
    private:
    Node<T>* findmax(Node<T>* node);
    Node<T>* findmin(Node<T>* node);
    int size;
    Node<T>* root;
};
template<typename T>
BinarySerchTree<T>::BinarySerchTree() {
    size=0;
    root = new Node<T>;
}
template<typename T>
void BinarySerchTree<T>::isempty() {
    return size==0;
}
template<typename T>
int BinarySerchTree<T>::getsize() {return size;}
template<typename T>
void BinarySerchTree<T>::add(const T &item) {
    if(size==0) {
        root->data=item;
        root->parent=root;
        size++;
        return;
    }
    Node<T>* node=new Node<T>;
    node->data=item;
    Node<T>* temp=root;
    while(temp!=NULL) {
        if(item > temp->data) {
            if(temp->right==NULL) {
                temp->right=node;
                node->parent=temp;
                size++;
                return;
            }
            temp=temp->right;
        }
        else if(item < temp->data) {
            if(temp->left==NULL) {
                temp->left=node;
                node->parent=temp;
                size++;
                return;
            }
            temp = temp->left;
        }
        else {return;}
    }

}
template<typename T>
T& BinarySerchTree<T>::getmax() {
    return findmax(root)->data;
}template<typename T>
T& BinarySerchTree<T>::getmax(Node<T>* node) {
    return findmax(node)->data;
}
template<typename T>
T& BinarySerchTree<T>::getmin() {
    return findmin(root)->data;
}
template<typename T>
T& BinarySerchTree<T>::getmin(Node<T>* node) {
    return findmin(node)->data;
}
template<typename T>
Node<T>* BinarySerchTree<T>::findmax(Node<T>* node) {
   while(node->right!=NULL) {
       node=node->right;
   }
   return node;
}
template<typename T>
Node<T>* BinarySerchTree<T>::findmin(Node<T>* node) {
    while(node->left!=NULL) {
       node=node->left;
   }
   return node;
}

template<typename T>
void BinarySerchTree<T>::remove(const T& item) {
    Node<T>* temp = new Node<T>;
    temp=root;
    while(temp!=NULL) {
        if(item > temp->data) {
            temp=temp->right;
        }
        else if(item < temp->data) {
            temp=temp->left;
        }
        else{
            if(temp->left==NULL && temp ->right==NULL) {
                temp=NULL;
                size--;
                return;
            }
            else if(temp->left!=NULL && temp ->right==NULL) {
                temp->left->parent=temp->parent;
                if(temp->data > temp->parent->data) {
                    temp->parent->right=temp->left;
                }
                else {
                    temp->parent->left = temp->left;
                }
                temp=NULL;
                size--;
                return;
            }
            else if(temp->left==NULL && temp ->right!=NULL) {
                temp->right->parent=temp->parent;
                if(temp->data > temp->parent->data) {
                    temp->parent->right=temp->right;
                }
                else {
                    temp->parent->left = temp->right;
                }
                temp=NULL;
                size--;
                return;
            }
            else if(temp->left!=NULL && temp ->right!=NULL) {
                T temp2 = getmax(temp->left);
                remove(temp2);
                temp->data=temp2;
                return;
            }
        }//found item
    }
    //not found
    cout << "item not found" << endl;
    return;
}

int main(void) {
    BinarySerchTree<int> inttree;
    inttree.add(5);
    inttree.add(1);
    inttree.add(10);
    inttree.add(7);
    inttree.add(10);
    cout << inttree.getroot() << endl;
    //cout << inttree.getsize() << endl;
    //cout << inttree.getmax() << endl;
    //inttree.remove(9);
    inttree.add(3);
    inttree.add(2);
    inttree.add(4);
    inttree.remove(5);
    inttree.remove(1);
    cout << inttree.getmin() << endl;
    //cout << inttree.getsize() << endl;
    cout << inttree.getroot() << endl;

    return 0;



}