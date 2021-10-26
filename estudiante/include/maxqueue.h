/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */

#include <bits/stdc++.h>
#include <stack>
#include "element.h"

#ifndef _MAXQUEUE_H_
#define _MAXQUEUE_H_

template <class T> class MaxQueue {

    stack<T> Stack;

    public:
        MaxQueue<T>();

        MaxQueue<T>(vector<T> data);

        MaxQueue<T>(T* data, int n);

        ~MaxQueue();

        const T &front() const;

        T &front();

        const int &size() const;

        void pop();

        void push_back();

        void assign(vector<T> data);

        void assign(T* data, int n);

        void destroy();

        friend ostream &operator<<<T>(ostream &os, MaxQueue<T> out);
};

#endif