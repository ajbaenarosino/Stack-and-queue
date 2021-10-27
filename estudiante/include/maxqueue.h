/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */

#include <cstdlib>
#include <stack>
#include <vector>
#include "element.h"

#ifndef _MAXQUEUE_H_
#define _MAXQUEUE_H_

using namespace std;

template <class T>
class MaxQueue
{
        stack<element<T>> Stack;

        void copy(vector<T> data);

        void copy(T* data, int n);

        void copy(MaxQueue<T> data);

    public:
        MaxQueue();

        MaxQueue<T>(const MaxQueue<T> &data);

        MaxQueue<T>(const vector<T> &data);

        MaxQueue<T>(const T* data, const int n);

        const element<T> &front() const;

        element<T> &front();

        const int size() const;

        void pop();

        void push_back(T data);

        void destroy();

        bool empty();

        template <class U> friend ostream &operator<<(ostream &os, MaxQueue<U> &out);
};

template <class T>
MaxQueue<T>::MaxQueue() {
    element<T> aux;
    aux.value = aux.maximum = 0;
    Stack.push(aux);
}

template <class T>
MaxQueue<T>::MaxQueue(const MaxQueue<T> &data) {
    copy(data);
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
    Stack.pop();
}

template <class T>
void MaxQueue<T>::push_back(T data) {
    stack<element<T>> aux;
    while(!empty()) {
        aux.push(front());
        pop();
    }
    element<T> element_T_aux;
    element_T_aux.value = data;
    element_T_aux.maximum = (aux.top().maximum > data) ? aux.top().maximum : data;
    Stack.push(element_T_aux);
    T max = data;
    while(!aux.empty()) {
        element_T_aux = aux.top();
        element_T_aux.maximum = (max > element_T_aux.maximum) ? max : element_T_aux.maximum;
        element_T_aux.value = aux.top().value;
        Stack.push(element_T_aux);
        aux.pop();
    }
}

template <class T>
void MaxQueue<T>::copy(MaxQueue<T> data) {
    Stack = data.Stack;
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
    stack<element<U>> aux = out.Stack;
    while(!aux.empty) {
        cout << aux.top() << " ";
        aux.pop();
    }
    return os;
}

#endif // _MAXQUEUE_H_