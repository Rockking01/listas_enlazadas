//
// Created by memo on 06/09/22.
//

#ifndef LISTAS_ENLAZADAS_NODOSE_H
#define LISTAS_ENLAZADAS_NODOSE_H


#pragma once
#include <iostream>
using namespace std;

template<class T> class NodoSE
{
protected:
    T* valor;
    NodoSE<T>* siguiente;

public:
    NodoSE(T* valor)
    {
        this->valor = valor;
        this->siguiente = NULL;
    }

    ~NodoSE()
    {
        delete valor;
    }

    inline T* getValor()
    {
        return this->valor;
    }

    inline void setValor(T* valor)
    {
        this->valor = valor;
    }

    inline NodoSE<T>* getSiguiente()
    {
        return this->siguiente;
    }

    inline void setSiguiente(NodoSE<T>* siguiente)
    {
        this->siguiente = siguiente;
    }
};


#endif //LISTAS_ENLAZADAS_NODOSE_H
