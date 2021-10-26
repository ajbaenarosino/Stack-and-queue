/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */

#include <cstdlib>

using namespace std;

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

template <class T>
struct element {
    T value;
    T maximum;
    friend ostream &operator<<(ostream &os, element<T> &x);
};

template <class T>
ostream &operator<<(ostream &os, element<T> &out) {
    os << out.value << "|" << out.maximum;
    return os;
}

#endif // _ELEMENT_H_