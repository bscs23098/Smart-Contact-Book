#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
using namespace std;


/*
a linked list is a linear data structure 
that allows the users to store data in non-contiguous 
memory locations. A linked list is defined as a collection
of nodes where each node consists of two members which 
represents its value and a next/previous pointer which stores
the address for the next/previous node.
*/


template <typename T>
class node{
public:
    T data;
    node * next;
    node():next(nullptr){}
    node(T value){
        data = value;
        next = nullptr;
    }
    };
    template<typename T>
    void addToHead(node<T>*& head,T value){
        node<T>* n = new node(value);
        n->next=head;
        head=n;
    }
    template<typename T>
    void addToTail(node<T>*& head,T value){
        node<T> * n = new node(value);
        if (head == nullptr){
            head = n;
            return;
        }
        node<T> * temp = head;
        while (temp->next != nullptr){
            temp=temp->next;
        }
        temp->next = n;
    }
    template<typename T>
    void linkupdate(node<T>*& head,int key,T obj){
        node<T> * temp = head;
        while(temp!=nullptr){
            if(temp->data.rollnumber==key){
                temp->data = obj;
            }
            temp=temp->next;
        }
    }
    template<typename T>
    void display(node<T>* head){
        node<T> * temp = head;
        while(temp != nullptr){
            cout<<temp->data;
            temp = temp->next;
        }
    }
    template<typename T>
    bool search(node<T>* head,int key){
        node<T> * temp = head;
        while(temp!=nullptr){
            if(temp->data.rollnumber==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    template<typename T>
    int searchPosition(node<T>* head,T key){
        if(!search(head,key)){
            return -1;
        }
        else {
            node<T> * temp = head;
            int pos=0;
            while(temp!=nullptr){
                if(temp->data==key){
                    return pos;
                }
                pos++;
                temp=temp->next;
            }
            return -1;
        }
    }
    template<typename T>
    void reverseList(node<T>*& head) {
        node<T>* prev = nullptr;
        node<T>* curr = head;
        node<T>* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;  
            curr->next = prev;        
            prev = curr;        
            curr = next;        
        }

        head = prev; 
    }
    template<typename T>
    int countNodes(node<T> * head){
        int count = 0;
        node<T> * temp = head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    template <typename T>
    void link_delte(node<T>*& head,int roll){
        node<T> * temp = head;
        while (head != nullptr && head->data.rollnumber == roll) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
        }
        node<T>* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->data.rollnumber == roll) {
                node<T>* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

#endif // LINKLIST_H