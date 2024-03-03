#ifndef STACK_LinkedList_H
#define STACK_LinkedList_H
#include "AbstractStack.h"


template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <typename T>
class StackLinkedList : public AbstractStack<T>{
private:
    Node<T>* head;
    int length;
public:
    StackLinkedList();

    ~StackLinkedList();

    StackLinkedList(const StackLinkedList& other);

    StackLinkedList& operator=(const StackLinkedList& other);

    bool isEmpty() ;

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackLinkedList<T>::StackLinkedList(){

    head = nullptr;
    length = 0;

}

template <typename T>
StackLinkedList<T>::~StackLinkedList(){

    while(head != nullptr) 
    {
        Node<T>* del = head;
        head = head->next;
        delete del;
    }
    head = nullptr; 
    length = 0;


    
/*
    Node<T>* cur = this->head;
    //Node<T>* prev = nullptr;

    for (int i = 0; i < this->length; i++) 
    {
       Node<T>* next = cur->next;
        //cur->prev = nullptr;
        delete cur;
        cur = next;
    }
    this->length = 0;
    this->head = nullptr;
    delete this;
*/

}

template <typename T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList& other) { //look at 120 hw


    Node<T>* temp = other.head;

    Node<T>* currH = nullptr;

    Node<T>* currT = nullptr;

    length = other.length;

    while (temp != nullptr) 
    {
        Node<T>* hold = new Node<T>();

        hold->data = temp->data;

        if (currH == nullptr) 
        {
            currH = hold;
            currT = hold;
        } 
        else 
        {
            currT->next = hold; 
            currT = currT->next;
        }

        temp = temp->next;
    }
    head = currH;


/*
    if(other.head == nullptr)
    {
        head = nullptr;

        return;
    }

    if (other.head) 
    {
        Node<T>* tempOther = other.head;
        Node<T>* prev = nullptr;

        while (tempOther) 
        {
            Node<T>* temp = new Node<T>{tempOther->data};
 
            if (!head) 
            {
                head = temp;
            } 
            else 
            {
                prev->next = temp;
            }

            prev = temp;
            tempOther = tempOther->next;
            length++;
        }
    }

    */

}

template <typename T>
StackLinkedList<T>& StackLinkedList<T>::operator=(const StackLinkedList& other) {

   if (this != &other) 
   {
        
        while (head) 
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        length = 0;

      
        if (other.head) 
        {
            Node<T>* tempOther = other.head;
            Node<T>* prev = nullptr;

            while (tempOther) 
            {
                Node<T>* temp = new Node<T>{tempOther->data};

                if (!head) 
                {
                    head = temp;
                } else 
                {
                    prev->next = temp;
                }

                prev = temp;
                tempOther = tempOther->next;
                length++;
            }
        }
    }
    return *this;
    
}

template <typename T>
bool StackLinkedList<T>::isEmpty(){
    return length == 0;
}

template <typename T>
int StackLinkedList<T>::size(){
    return length;
}

template <typename T>
T& StackLinkedList<T>::top(){

    if(isEmpty())
    {
        throw std::out_of_range("Invalid Range");
    }

    return head->data;

}

template <typename T>
T StackLinkedList<T>::pop(){
  
    if(isEmpty())
    {
        throw std::out_of_range("Invalid Range");
    }

    --length;

    T pop = head->data;

    Node<T>* temp = head->next;

    delete head;
    head = temp;

    return pop; // this the tail node
 
}

template <typename T>
void StackLinkedList<T>::push(const T& e){

    ++length;

    Node<T>* y = new Node<T>();
    y->data = e;
    y->next = head;
    head = y;

}


#endif