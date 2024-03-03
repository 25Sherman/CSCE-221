#ifndef STACK_LINEAR_ARRAY_H
#define STACK_LINEAR_ARRAY_H
#include "AbstractStack.h"

template <typename T>
class StackArrayLinear : public AbstractStack<T> {
private:
    T* data;
    int length;
    int topIndex;

public:
    StackArrayLinear();

    ~StackArrayLinear();

    StackArrayLinear(const StackArrayLinear& other);

    StackArrayLinear& operator=(const StackArrayLinear& other);

    bool isEmpty();

    int size();

    T& top();

    T pop();

    void push(const T& e);

};

// Your implementation here
template <typename T>
StackArrayLinear<T>::StackArrayLinear(){
    length = 1;
    topIndex = -1;
    data = new T[length];

}

template <typename T>
StackArrayLinear<T>::~StackArrayLinear(){
    delete[] data;
    data = nullptr;

}

template <typename T>
StackArrayLinear<T>::StackArrayLinear(const StackArrayLinear& other) {
    length = other.length;

    topIndex = other.topIndex;  //fix

    data = new T[length];

    for(int i = 0; i < length; ++i)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
StackArrayLinear<T>& StackArrayLinear<T>::operator=(const StackArrayLinear& other) {
    if (this != &other) 
    {
        delete[] data;

        length = other.length;

        topIndex = other.topIndex;

        data = new T[length];

        for (int i = 0; i <= topIndex; ++i) 
        {
            data[i] = other.data[i];
        }
    }

    return *this;
}

template <typename T>
bool StackArrayLinear<T>::isEmpty(){
    return (topIndex < 0);
}

template <typename T>
int StackArrayLinear<T>::size(){
    return (topIndex + 1);
}

template <typename T>
T& StackArrayLinear<T>::top(){
    if(isEmpty())
    {
        throw std::out_of_range("Invalid Range");
    }
   
    return data[topIndex]; 
}

template <typename T>
T StackArrayLinear<T>::pop(){
    if(isEmpty())
    {
        throw std::out_of_range("Invalid Range");
    }
    else
    {
        topIndex -= 1;
        return data[topIndex + 1];
    }
}

template <typename T>
void StackArrayLinear<T>::push(const T& e){
    if (topIndex == length - 1 || size() == length) 
    {
       
        int new_len = length + 10;

        T* newData = new T[new_len];

        for (int i = 0; i < length; ++i) 
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;

        length = new_len;
    }

    topIndex += 1;
    
    data[topIndex] = e;
}

#endif