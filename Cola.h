//
// Created by memo on 06/09/22.
//

#ifndef LISTAS_ENLAZADAS_COLA_H
#define LISTAS_ENLAZADAS_COLA_H

#pragma once
#include <iostream>
using namespace std;

template<class T> class Cola
{

public:
    virtual void add(T* elemento) = 0;
    virtual T* remove() = 0;
    virtual T* top() = 0;
    virtual T* last() = 0;
    virtual bool isEmpty() = 0;
};



#endif //LISTAS_ENLAZADAS_COLA_H
