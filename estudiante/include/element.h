/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * @author
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef _ELEMENT_H_
#define _ELEMENT_H_

struct element {
    int value;
    int maximum;

    friend ostream &operator<<(ostream &os, element &x);
};

#endif // _ELEMENT_H_