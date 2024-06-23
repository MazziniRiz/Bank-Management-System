#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename Object>
class SinglyLinkedList{
    private:
        struct Node
        {
            Node* prev;
            Object data;

            Node(): data{Object{}}, prev{nullptr} {}
            Node(const Object& d, Node* p): data{d}, prev{p} {}
        };

    public:
        SinglyLinkedList(): Node() {}
        SinglyLinkedList(const Object& d, Node* p): Node(d,p) {}

        void insertNode(SinglyLinkedList& m, const Object& d){
            Node* newNode;
            newNode->data = d;
            
        }

        void printInfo(){
            cout << data << endl;
        }
};

#endif