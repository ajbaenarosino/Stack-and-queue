/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * @author
 */

#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
#include "element.h"
#include "maxqueue.h"

using namespace std;

template <class T>
MaxQueue<T>::MaxQueue()
{
}

template <class T>
MaxQueue<T>::MaxQueue(vector<T> data)
{
    assign(data);
}

template <class T>
MaxQueue<T>::MaxQueue(T *data, int n)
{
    assign(data, n);
}

template <class T>
MaxQueue<T>::~MaxQueue()
{
}

template <class T>
const T &MaxQueue<T>::front() const
{
    return Stack.top();
}

template <class T>
T &MaxQueue<T>::front()
{
    return Stack.top();
}

template <class T>
const int &MaxQueue<T>::size() const {
    return Stack.size();
}

template <class T>
void MaxQueue<T>::pop()
{
    Stack.pop();
}

template <class T>
void MaxQueue<T>::push_back()
{
}

template <class T>
void MaxQueue<T>::assign(vector<T> data)
{
}

template <class T>
void MaxQueue<T>::assign(T *data, int n)
{
}

template <class T>
void MaxQueue<T>::destroy()
{
    for (int i = 0; i < Stack.size(); i++) {
        Stack.pop();
    }
}

template <class T>
ostream &operator<<(ostream &os, MaxQueue<T> &x)
{
    return os;
}
