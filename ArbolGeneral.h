//
// Created by memo on 03/10/22.
//

#ifndef LISTAS_ENLAZADAS_ARBOLGENERAL_H
#define LISTAS_ENLAZADAS_ARBOLGENERAL_H

#include "ListSE.h"
#include <iostream>
using namespace std;



template<class T> class ArbolGeneral {

protected:
    T* dato;
    ListSE<ArbolGeneral<T>>* hijos;

public:
    ArbolGeneral(T* dato){
        this->dato = dato;
        this->hijos = new ListSE<ArbolGeneral<T>>();
    }

    ~ArbolGeneral();

    T* getRaiz(){
        return this->dato;
    }

    bool isHoja(){
        return this->hijos->getLength() == 0;
    }

    int getGrado(){
        return this->hijos->getLength();
    }

    void adicionarParaTodaOcurrencia(T* raiz, T* hijo) {
        if ((*this->dato) == (*raiz)) {
            this->hijos->add(new ArbolGeneral<T>(hijo));

        }
        for (int i = 0; i < this->hijos->getLength(); i++) {
            this->hijos->getElement(i)->adicionarPrimeraOcurrencia(raiz, hijo);

        }
    }


    bool adicionarPrimeraOcurrencia(T* raiz, T* hijo){
        if((*this->dato) == (*raiz)){
            this->hijos->add(new ArbolGeneral<T>(hijo));
            return true;
        }
        for (int i = 0; i < this->hijos->getLength();i++){
           if( this->hijos->getElement(i)->adicionarPrimeraOcurrencia(raiz, hijo)) {
               return true;
           }
        }
        return false;
    }

    int getAltura(){
        if (isHoja()){
            return 0;
        }
        int altura = -1;

        for (int i = 0; i < this->hijos->getLength();i++){
            int altura_aux = this->hijos->getElement(i)->getAltura();
            if (altura_aux > altura){
                altura = altura_aux;
            }
        }
        return altura + 1;
    }

    int getCantidadHojas(){
        if (isHoja()){
            return 1;
        }
        int hojas = 0;
        for (int i = 0; i < this->hijos->getLength();i++){
           hojas = hojas + this->hijos->getElement(i)->getCantidadHojas();
        }
    }


};


#endif //LISTAS_ENLAZADAS_ARBOLGENERAL_H
