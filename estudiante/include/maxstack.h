/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * @author
 */

#include <cstdlib>
#include <queue>
#include <vector>
#include "element.h"

#ifndef _MAXSTACK_H_
#define _MAXSTACK_H_

using namespace std;

/**
 * @brief A template class to represent a stack using queues
*/

template <class T>
class MaxStack
{
    /**
     * @brief The queue that must be used to emulate a stack
    */
    queue<element<T>> Queue;

    /**
     * @brief Private method which copy the content from a vector to the queue
     * @param data the vector to copy from
    */
    void copy(vector<T> data);

    /**
     * @brief Private method which copy the content from an array to the queue
     * @param data the array to copy from
     * @param n The number of T objects in the @p data vector
    */
    void copy(T* data, int n);

public:
    /**
     * @brief Default constructor of the class
    */
    MaxStack();

    /**
     * @brief Copy constructor
     * @param data the MaxStack<T> to copy from
    */
    MaxStack<T>(const MaxStack<T> &data);

    /**
     * @brief Constructor with parameters
     * @param data the vector from which obtain the data to copy in the queue
    */
    MaxStack<T>(const vector<T> &data);

    /**
     * @brief Constructor with parameters
     * @param data the array from which obtain the data to copy in the queue
     * @param n the number of elements in the array
    */
    MaxStack<T>(const T* data, const int n);

    /**
     * @brief Assign operator
     * @param data the object to copy from
    */
    MaxStack<T> &operator=(const MaxQueue<T> data);

    /**
     * @brief The default stack consultor
     * @return It returns the first element of the queue (const)
    */
    const element<T> &top() const;

    /**
     * @brief The default stack modificator
     * @return It returns the first element of the queue (not const)
    */
    element<T> &top();

    /**
     * @brief The size consultor
     * @return It returns the size of the stack
    */
    const int size() const;

    /**
     * @brief It deletes the first element of the stack
    */
    void pop();

    /**
     * @brief It adds a new T eleemnt to the stack
     * @param data the element to be added
    */
    void push(T data);

    /**
     * @brief It deletes all the elements in the stack
    */
    void destroy();

    /**
     * @brief An operator to know if the container is empty or not
     * @return True if it is empty and false if it is not
    */
    bool empty();

    /**
     * @brief The << operator
     * @param os the ostream variable in which the object will be printed
     * @param out the MaxStack object to be printed
     * @return a reference to the modified ostream object
    */
    template <class U> friend ostream &operator<<(ostream &os, MaxStack<U> &out);
};

template <class T>
MaxStack<T>::MaxStack(): Queue() {}

template <class T>
MaxStack<T>::MaxStack(const MaxStack<T> &data) {
    *this = data;
}

template <class T>
MaxStack<T>::MaxStack(const vector<T> &data) {
    copy(data);
}

template <class T>
MaxStack<T>::MaxStack(const T *data, const int n) {
    copy(data, n);
}

template <class T>
const element<T> &MaxStack<T>::top() const {
    return Queue.front();
}

template <class T>
element<T> &MaxStack<T>::top() {
    return Queue.front();
}

template <class T>
const int MaxStack<T>::size() const {
    return Queue.size();
}

template <class T>
void MaxStack<T>::pop() {
    Queue.pop();
}

template <class T>
void MaxStack<T>::push(T data) {
    element<T> element_T_aux;
    if (Queue.empty()) {
        element_T_aux.value = element_T_aux.maximum = data;
        Queue.push(element_T_aux);
    } else {
        queue<element<T>> aux;
        T max = data;
        while(!Queue.empty()) {
            aux.push(Queue.front());
            Queue.pop();
        }
        element_T_aux.maximum = (max > element_T_aux.maximum) ? max : element_T_aux.maximum;
        element_T_aux.value = data;
        Stack.push(element_T_aux);
        while(!aux.empty()) {
            element_T_aux = aux.top();
            element_T_aux.maximum = (max > element_T_aux.maximum) ? max : element_T_aux.maximum;
            element_T_aux.value = aux.top().value;
            Stack.push(element_T_aux);
            aux.pop();
        }
    }
}

template <class T>
MaxStack<T> &MaxStack<T>::operator=(MaxStack<T> data) {
    Queue = data.Queue;
}

template <class T>
void MaxStack<T>::copy(vector<T> data) {
    for (int i = 0; i < data.size(); i++) {
        push(data[i]);
    }
}

template <class T>
void MaxStack<T>::copy(T *data, int n) {
    for (int i = 0; i < n; i++) {
        push(data[i]);
    }
}

template <class T>
void MaxStack<T>::destroy() {
    while (!Queue.empty()) {
        Queue.pop();
    }
}

template <class T>
bool MaxStack<T>::empty() {
    return size();
}

template <class U>
ostream &operator<<(ostream &os, MaxStack<U> &out) {
    if (out.size() > 0) {
        queue<element<U>> aux = out.Queue;
        while (!aux.empty()) {
            os << aux.front() << " ";
            aux.pop();
        }
    }
    return os;
}

#endif // _MAXSTACK_H_