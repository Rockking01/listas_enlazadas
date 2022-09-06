//
// Created by memo on 04/09/22.
//

#ifndef LISTAS_ENLAZADAS_NODODE_H
#define LISTAS_ENLAZADAS_NODODE_H


#pragma once
#include <iostream>
using namespace std;

template<class T> class NodoDE {
protected:
    T* valor ;
    NodoDE<T>* siguiente;
    NodoDE<T>* anterior;

public:
    NodoDE(T* valor){
        this->valor= valor;
        this->siguiente = NULL;
        this->anterior = NULL;
    }
    ~NodoDE(){
        delete valor;
    }

    inline T* getValor(){
        return this->valor;
    }

    inline void setValor(T* valor){
        this->valor = valor;
    }

    inline NodoDE<T>* getSiguiente()
    {
        return this->siguiente;
    }

    inline void setSiguiente(NodoDE<T>* siguiente)
    {
        this->siguiente = siguiente;
    }

    inline NodoDE<T>* getAnterior()
    {
        return this->anterior;
    }

    inline void setAnterior(NodoDE<T>* anterior)
    {
        this->anterior = anterior;
    }

};

#endif //LISTAS_ENLAZADAS_NODODE_H
