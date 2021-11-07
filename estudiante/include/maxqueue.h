/**
 * @file maxqueue.h
 * @brief Specification file of the MaxQueue ADT
 * @authors Álvaro Jesús Baena Rosino \n Alejandro Torres Martínez
 */

#include <cstdlib>
#include <stack>
#include <vector>
#include "element.h"

#ifndef _MAXQUEUE_H_
#define _MAXQUEUE_H_

using namespace std;

/**
 * @brief A template class to represent a queue using stacks
*/

template <class T>
class MaxQueue
{
    /**
     * @brief The stack that must be used to emulate a queue
    */
    stack<element<T>> Stack;

    /**
     * @brief Private method which copy the content from a vector to the stack
     * @param data the vector to copy from
    */
    void copy(vector<T> data);

    /**
     * @brief Private method which copy the content from an array to the stack
     * @param data the array to copy from
     * @param n The number of T objects in the @p data vector
    */
    void copy(T* data, int n);

public:
    /**
     * @brief Default constructor of the class
    */
    MaxQueue();

    /**
     * @brief Copy constructor
     * @param data the MaxQueue<T> to copy from
    */
    MaxQueue<T>(const MaxQueue<T> &data);

    /**
     * @brief Constructor with parameters
     * @param data the vector from which obtain the data to copy in the stack
    */
    MaxQueue<T>(const vector<T> &data);

    /**
     * @brief Constructor with parameters
     * @param data the array from which obtain the data to copy in the stack
     * @param n the number of Es in the array
    */
    MaxQueue<T>(const T* data, const int n);

    /**
     * @brief Assign operator
     * @param data the object to copy from
    */
    MaxQueue<T> &operator=(const MaxQueue<T> data);

    /**
     * @brief The default queue consultor
     * @return It returns the first element of the queue (const)
    */
    const element<T> &front() const;

    /**
     * @brief The default queue modificator
     * @return It returns the first element of the queue (not const)
    */
    element<T> &front();

    /**
     * @brief The size consultor
     * @return It returns the size of the queue
    */
    const int size() const;

    /**
     * @brief It deletes the first element of the queue
    */
    void pop();

    /**
     * @brief It adds a new T eleemnt to the queue
     * @param data the element to be added
    */
    void push_back(T data);

    /**
     * @brief It deletes all the elements in the queue
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
     * @param out the MaxQueue object to be printed
     * @return a reference to the modified ostream object
    */
    template <class U> friend ostream &operator<<(ostream &os, MaxQueue<U> &out);
};

template <class T>
MaxQueue<T>::MaxQueue(): Stack() {}

template <class T>
MaxQueue<T>::MaxQueue(const MaxQueue<T> &data) {
    *this = data;
}

template <class T>
MaxQueue<T>::MaxQueue(const vector<T> &data) {
    copy(data);
}

template <class T>
MaxQueue<T>::MaxQueue(const T *data, const int n) {
    copy(data, n);
}

template <class T>
const element<T> &MaxQueue<T>::front() const {
    return Stack.top();
}

template <class T>
element<T> &MaxQueue<T>::front() {
    return Stack.top();
}

template <class T>
const int MaxQueue<T>::size() const {
    return Stack.size();
}

template <class T>
void MaxQueue<T>::pop() {
    if (Stack.size() > 0) {
        Stack.pop();
    }
}

template <class T>
void MaxQueue<T>::push_back(T data) {
    element<T> element_T_aux;
    if (Stack.empty()) {
        element_T_aux.value = element_T_aux.maximum = data;
        Stack.push(element_T_aux);
    } else {
        stack<element<T>> aux;
        T max = data;
        while(!Stack.empty()) {
            aux.push(Stack.top());
            Stack.pop();
        }
        element_T_aux.maximum = max;
        element_T_aux.value = data;
        Stack.push(element_T_aux);
        while(!aux.empty()) {
            element_T_aux = aux.top();
            element_T_aux.maximum = (max > element_T_aux.maximum) ? max : element_T_aux.maximum;
            Stack.push(element_T_aux);
            aux.pop();
        }
    }
}

template <class T>
MaxQueue<T> &MaxQueue<T>::operator=(MaxQueue<T> data) {
    Stack = data.Stack;
    return *this;
}

template <class T>
void MaxQueue<T>::copy(vector<T> data) {
    for (int i = 0; i < data.size(); i++) {
        push_back(data[i]);
    }
}

template <class T>
void MaxQueue<T>::copy(T *data, int n) {
    for (int i = 0; i < n; i++) {
        push_back(data[i]);
    }
}

template <class T>
void MaxQueue<T>::destroy() {
    while (!Stack.empty()) {
        Stack.pop();
    }
}

template <class T>
bool MaxQueue<T>::empty() {
    return size();
}

template <class U>
ostream &operator<<(ostream &os, MaxQueue<U> &out) {
    if (out.size() > 0) {
        stack<element<U>> aux = out.Stack;
        while (!aux.empty()) {
            os << aux.top() << " ";
            aux.pop();
        }
    }
    return os;
}

#endif // _MAXQUEUE_H_