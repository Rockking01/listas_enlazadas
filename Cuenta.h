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
    Cuenta(int noCuenta, string noID, float saldo) {
        this->noCuenta = noCuenta;
        this->noID = noID;
        this->saldo = saldo;
    }

    ~Cuenta() {

    }

    string getNoID() {
        // como es un getter tiene complejidad O(1)
        return this->noID;
    }

    void setSaldo(float saldo) {
        // como es un setter tiene complejidad O(1)
        this->saldo = saldo;
    }

    float getSaldo() {
        // como es un getter tiene complejidad O(1)
        return this->saldo;
    }
};


#endif //LISTAS_ENLAZADAS_CUENTA_H
