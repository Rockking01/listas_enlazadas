//
// Created by memo on 06/09/22.
//

#ifndef LISTAS_ENLAZADAS_CUENTA_H
#define LISTAS_ENLAZADAS_CUENTA_H

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cuenta {
protected:
    int noCuenta;
    string noID;
    float saldo;

public:
    Cuenta(int noCuenta, string noID, float saldo){
        this->noCuenta = noCuenta;
        this->noID = noID;
        this->saldo = saldo;
    }

    ~Cuenta(){

    }

    string getNoID(){
        return this->noID;
    }

    void setSaldo(float saldo){
        this->saldo = saldo;
    }

    float getSaldo(){
        return this->saldo;
    }
};


#endif //LISTAS_ENLAZADAS_CUENTA_H
