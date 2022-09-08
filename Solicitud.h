//
// Created by memo on 06/09/22.
//

#ifndef LISTAS_ENLAZADAS_SOLICITUD_H
#define LISTAS_ENLAZADAS_SOLICITUD_H


#pragma once

#include <iostream>
#include <string>

using namespace std;

class Solicitud {
protected:
    string nombre;
    string noID;
    float cantidad;
public:

    Solicitud(string nombre, string noID, float cantidad){
        this->nombre = nombre;
        this->noID = noID;
        this->cantidad = cantidad;
    }

    ~Solicitud(){

    }

    string getNoID(){
        return this->noID;
    }

    float getCantidad(){
        return this->cantidad;
    }


};


#endif //LISTAS_ENLAZADAS_SOLICITUD_H
