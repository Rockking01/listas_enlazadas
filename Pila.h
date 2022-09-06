//
// Created by memo on 06/09/22.
//

#ifndef LISTAS_ENLAZADAS_PILA_H
#define LISTAS_ENLAZADAS_PILA_H

#pragma once
#include <iostream>
using namespace std;

template<class T> class Pila
{

public:
    virtual void push(T* elemento) = 0; //adicionar
    virtual T* pop() = 0; //extraer
    virtual T* top() = 0; //tope
    virtual bool isEmpty() = 0; // es vacia
};

#endif //LISTAS_ENLAZADAS_PILA_H
