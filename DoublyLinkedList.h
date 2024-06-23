#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Pages.h"

using namespace std;


template<typename Object>
class DoublyLinkedList
{
    private:
        struct Node
        {
            Node* prev;
            Node* next;
            Object data;

            Node(): data{Object{}}, prev{nullptr}, next{nullptr} {}
            Node(const Object& d, Node* p, Node* n): data{d}, prev{p}, next{n} {}
        };
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList(): head{}, tail{} {head->next = tail; tail->prev = head;}

        Node findInsertPoint(const DoublyLinkedList& m){
            for(Node* itr = m.head; itr != m.tail; itr->next){
                if(itr->next == m.tail){
                    return itr;
                }
            }
        }

        void insertList(DoublyLinkedList& m, const Object& d){
            Node* before = findInsertPoint(m);
            Node newNode{Node(d, before, m.tail)};
            before->next = newNode;
            m.tail->prev = newNode;
        }

        void setHead(const Object& d){head->data = d; head->next = nullptr;}
        void setTail(const Object& d){tail->data = d; tail->next = head;}

        Object getData(){return data;}

        void printList(){
            for(Node* itr = head; itr!=nullptr; itr = itr->next){
                cout << itr->data << endl;
            }
        }

        void SearchList(Object& d, Object& e, Object& f, Object& g, const DoublyLinkedList& h){
            for(Node* itr = head; itr != nullptr; itr = itr->next){
                if(itr->data.getID() == d.getID()){
                    itr->data.SelectFunction(d,e,f,g,h);
                }
            }

            cout << "Item Not found in List...." << endl;
        }
};

#endif