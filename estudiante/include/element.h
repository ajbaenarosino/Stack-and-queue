/**
 * @file maxqueue.h
 * @brief Specification file of the element ADT
 * @authors Álvaro Jesús Baena Rosino \n Alejandro Torres Martínez
 */

#include <cstdlib>

using namespace std;

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

/**
 * @brief A template struct to represent a element made up by a T class value and an associated maximum
*/

template <class T>
struct Element {
    /**
     * @brief The value itself
    */
    T value;

    /**
     * @brief The associated maximum
    */
    T maximum;

    /**
     * @brief The default constructor
     * @param v The value to be asigned
     * @param max The associated maximum to be assigned
    */
    Element(int v = 0, int max = 0);

    /**
     * @brief The output operator
     * @param os The ostream object in which the object will be printed
     * @param out The element to be printed
    */
    template <class U> friend ostream &operator<<(ostream &os, const Element<U> &out);
};

template <class T>
Element<T>::Element(int v, int max): value(v), maximum(max){}

template <class U>
ostream &operator<<(ostream &os, const Element<U> &out) {
    os << out.value << "," << out. maximum;
    return os;
}

#endif // _ELEMENT_H_