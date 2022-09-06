

//
// Created by memo on 04/09/22.
//

#ifndef LISTAS_ENLAZADAS_LISTDE_H
#define LISTAS_ENLAZADAS_LISTDE_H

#pragma once
#include "List.h"
#include "NodoDE.h"
#include <iostream>
using namespace std;

template<class T> class ListDE : public List<T> {
protected:
    NodoDE<T>* cabeza;
    NodoDE<T>* cola;
public:
    ListDE() : List<T>(0)
    {
        this->cabeza = NULL;
        this->cola = NULL;
    }

    ~ListDE()
    {

    }

    virtual void add(T* element)
    {
        NodoDE<T>* nuevo = new NodoDE<T>(element);
        if (this->cabeza == NULL)
        {
            this->cabeza = nuevo;
            nuevo->setAnterior(NULL);
            nuevo->setSiguiente(NULL);
            this->cola = nuevo;
        }
        else
        {
            nuevo->setAnterior(this->cola);
            this->cola->setSiguiente(nuevo);
            nuevo->setSiguiente(NULL);
            this->cola = nuevo;
        }
        this->length++;
    }


    void insert(T* element, int pos)
    {
        if (pos < 0 || pos >= this->length)
        {
            throw "No se puede insertar el elemento porque la posicion es incorrecta";
        }

        NodoDE<T>* nuevo = new NodoDE<T>(element);
        if(pos == 0){
            nuevo->setSiguiente(cabeza);
            this->cabeza->setAnterior(nuevo);
            this->cabeza = nuevo;
            this->cabeza->setAnterior(NULL);
        }
        else{
            int posTempI = 0;
            int posTempF = this->length - 1;
            NodoDE<T>* tempInicio = this->cabeza;
            NodoDE<T>* tempFinal = this->cola;
            while (posTempI < pos && posTempF > pos )
            {
                tempInicio = tempInicio->getSiguiente();
                posTempI++;
                tempFinal = tempFinal->getAnterior();
                posTempF--;
            }
            if (posTempI == pos){
                tempInicio = tempInicio->getAnterior();
                nuevo->setSiguiente(tempInicio->getSiguiente());
                tempInicio->setSiguiente(nuevo);
                nuevo->setAnterior(tempInicio);
                tempInicio->getSiguiente()->setAnterior(nuevo);
            }
            else if (posTempF == pos){
                tempFinal = tempFinal->getAnterior();
                nuevo->setSiguiente(tempFinal->getSiguiente());
                tempFinal->setSiguiente(nuevo);
                nuevo->setAnterior(tempFinal);
                tempFinal->getSiguiente()->setAnterior(nuevo);
            }
        }
        this->length++;
    }

    virtual void remove(int pos)
    {
        if (pos < 0 || pos >= this->length)
        {
            throw "Posicion incorrecta";
        }

        if(pos == 0){
            NodoDE<T>* temp = this->cabeza;
            this->cabeza = temp->getSiguiente();
            this->cabeza->setAnterior(NULL);
            delete temp;

        }
        else if(pos == this->length - 1){
            NodoDE<T>* temp = this->cola;
            this->cola = temp->getAnterior();
            this->cola->setSiguiente(NULL);
            delete temp;
        }
        else {
        int posTempI = 0;
        int posTempF = this->length - 1;
        NodoDE<T>* tempInicio = this->cabeza;
        NodoDE<T>* tempFinal = this->cola;
        while (posTempI < pos && posTempF > pos )
        {
            tempInicio = tempInicio->getSiguiente();
            posTempI++;
            tempFinal = tempFinal->getAnterior();
            posTempF--;
        }
        if (posTempI == pos){
            tempInicio->getSiguiente()->setAnterior(tempInicio->getAnterior());
            tempInicio->getAnterior()->setSiguiente(tempInicio->getSiguiente());
            delete tempInicio;

        }
        else if (posTempF == pos){
            tempFinal->getSiguiente()->setAnterior(tempFinal->getAnterior());
            tempFinal->getAnterior()->setSiguiente(tempFinal->getSiguiente());
            delete tempFinal;

        }
        }
        this->length--;
    }

    T* getElement(int pos)
    {
        if (pos < 0 || pos >= this->length)
        {
            throw "Posicion incorrecta";
        }

        int posTempI = 0;
        int posTempF = this->length - 1;
        NodoDE<T>* tempInicio = this->cabeza;
        NodoDE<T>* tempFinal = this->cola;
        while (posTempI < pos && posTempF > pos )
        {
            tempInicio = tempInicio->getSiguiente();
            posTempI++;
            tempFinal = tempFinal->getAnterior();
            posTempF--;
        }
        if (posTempI == pos){
            return tempInicio->getValor();
        }
        if (posTempF == pos){
            return tempFinal->getValor();
        }

    }

    int getPosition(T* element)
    {
        NodoDE<T>* tempInicio = this->cabeza;
        int counter = 0;
        while (tempInicio!=NULL){
            if ((*tempInicio->getValor()) == (*element)){
                return counter;
                break;
            }
            tempInicio = tempInicio->getSiguiente();
            counter++;

        }
        return -1;
    }
};




#endif //LISTAS_ENLAZADAS_LISTDE_H
