#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
using namespace std;

template <class Type>
class Deque {
private:
	int s;
	Node<Type>* firstNode;
	Node<Type>* lastNode;

public:
	Deque();
	Deque(const Deque& other); 
	Deque& operator=(const Deque& other); 
	~Deque();
	bool isEmpty();
	int size();
	Type first();
	Type last();
	void insertFirst(Type o);
	void insertLast(Type o);
	Type removeFirst();
	Type removeLast();
};

// Your implementation here 

template <class Type>
Deque<Type>::Deque() {

	s = 0;
	firstNode = nullptr;
	lastNode = nullptr;

}

template <class Type>
Deque<Type>::~Deque() {

	//Node<Type>* curr = firstNode

	while (firstNode != nullptr)
	{
		Node<Type>* temp = firstNode;
		firstNode = firstNode->getNext();
		delete temp;  
	}

	s = 0;
	firstNode = nullptr;
	lastNode = nullptr;


}

template <class Type>
Deque<Type>::Deque(const Deque& other) {

	Node<Type>* temp = other.firstNode;

    Node<Type>* currH = nullptr;

    Node<Type>* currT = nullptr;

    s = other.s;

    while (temp != nullptr) 
    {
        Node<Type>* hold = new Node<Type>(temp->getData());

        //hold->data = temp->data;

        if (currH == nullptr) 
        {
            currH = hold;
            currT = hold;
        } 
        else 
        {
            currT->setNext(hold); 
            hold->setPrev(currT);
			currT = currT->getNext();
        }


        temp = temp->getNext();
    }
    firstNode = currH;
	lastNode = currT;

}

template <class Type>
Deque<Type>& Deque<Type>::operator=(const Deque& other) {

	if (this != &other) 
   {
        
        while (firstNode) 
        {
            Node<Type>* temp = firstNode;
            firstNode = firstNode->next;
            delete temp;
        }

        s = 0;

      
        if (other.firstNode) 
        {
            Node<Type>* tempOther = other.firstNode;
            Node<Type>* prev = nullptr;

            while (tempOther) 
            {
                Node<Type>* temp = new Node<Type>{tempOther->data, nullptr, prev};

                if (!firstNode) 
                {
                    firstNode = temp;
                } 
				else 
                {
                    prev->next = temp;
                }

                prev = temp;
                tempOther = tempOther->next;
                s++;
            }

			lastNode = prev;
        }
    }
    return *this;
}

template <class Type>
bool Deque<Type>::isEmpty() {

	return (s == 0);
}

template <class Type>
int Deque<Type>::size() {
	return s;
}

template <class Type>
Type Deque<Type>::first() {

	if(isEmpty())
	{
		return Type();
	}

	return firstNode->getData();

}

template <class Type>
Type Deque<Type>::last() {

	if(isEmpty() == false)
	{
		return lastNode->getData();
	}
	else
	{
		return Type();
	}
}

template <class Type>
void Deque<Type>::insertFirst(Type o) {

	Node<Type>* insertF = new Node<Type>(o);

	insertF->setNext(firstNode);
    insertF->setPrev(nullptr);

	if (firstNode != nullptr)
	{
		firstNode->setPrev(insertF);
	}
	else
	{
		lastNode = insertF;
	}

	firstNode = insertF;

	s++;

}

template <class Type>
void Deque<Type>::insertLast(Type o) {  // might be a bit off

	Node<Type>* insertL = new Node<Type>(o);

	insertL->setNext(nullptr);
    insertL->setPrev(lastNode);

	if (lastNode != nullptr)
	{
		lastNode->setNext(insertL);
	}
	else
	{
		firstNode = insertL;
	}

	lastNode = insertL;

	s++;

}

template <class Type>
Type Deque<Type>::removeFirst() {

	if(isEmpty())
	{
		throw std::out_of_range("Invalid Range");
	}
	else
	{
		s--;

		Type pop = firstNode->getData();

		Node<Type>* temp = firstNode->getNext();

		temp->setPrev(nullptr);

		delete firstNode;

		firstNode = temp;

		return pop;

	}


	return Type();
}

template <class Type>
Type Deque<Type>::removeLast() {

	if(isEmpty())
	{
		throw std::out_of_range("Invalid Range");
	}
	else
	{
		s--;

		Type pop = lastNode->getData();

		Node<Type>* temp = lastNode->getPrev();

		temp->setNext(nullptr);

		delete lastNode;

		lastNode = temp;

		return pop;

	}



	return Type();
}

#endif

