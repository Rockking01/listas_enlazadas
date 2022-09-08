//
// Created by memo on 06/09/22.
//

#ifndef LISTAS_ENLAZADAS_BANCO_H
#define LISTAS_ENLAZADAS_BANCO_H

#pragma once

#include <iostream>
#include <string>
#include "ColaSE.h"
#include "PilaSE.h"
#include "List.h"
#include "ListSE.h"
#include "Cuenta.h"
#include "Solicitud.h"

using namespace std;

class Banco {
protected:
    List<Cuenta> *lCuentas;
    ColaSE<Solicitud> *cSolicitudes;

    int verficarCuenta() {
        Solicitud *primerSolicitud = this->cSolicitudes->top();

        //inicia ciclo para checar cada cuenta y compararla con el id del usuario.
        for (int i = 0; i < this->lCuentas->getLength(); ++i) {
            if (lCuentas->getElement(i)->getNoID() == primerSolicitud->getNoID()) {
                return i;
            }
        }

        // considerando que este es un ciclo for que recorre cada elemento dee la lista es decir n
        // y dentro de este tenemos el metodo get element el cual tambien es un algoritmo de complejidad O(n)
        //puedo concluir que esta funcion tiene una complejidad O(n^2)

        this->lCuentas->add(new Cuenta(this->lCuentas->getLength(), primerSolicitud->getNoID(), float(0)));
        return this->lCuentas->getLength() - 1;
    }

public:

    Banco() {
        this->lCuentas = new ListSE<Cuenta>();
        this->cSolicitudes = new ColaSE<Solicitud>();
    }

    ~Banco() {
        delete this->lCuentas;
        delete this->cSolicitudes;
    }

    void adicionarCuenta(Cuenta *cuenta) {
        this->lCuentas->add(cuenta);
    }

    void adicionarSolictiud(Solicitud *solicitud) {
        this->cSolicitudes->add(solicitud);
    }

    List<Cuenta> *getCuentas() {
        return this->lCuentas;
    }

    ColaSE<Solicitud> *getSolicitudes() {
        return this->cSolicitudes;
    }


    void atenderTodasLasSolicitudes() {

        int posicion = 0;
        Solicitud *solicitud = NULL;
        Cuenta *cuenta = NULL;

        //se recorre cada elemento de la cola de solicitudes, es decir n elementos y
        // durante cada elemento se hace la verificacion, la cual tiene una complejidad O(n^2)
        //dentro de este ciclo hay un get element de complejidad O(n)
        // esto nos deja con un algoritmo con una complejidad de O(n^3)
        while (!this->cSolicitudes->isEmpty()) {

            solicitud = this->cSolicitudes->top();
            posicion = this->verficarCuenta();
            cuenta = this->lCuentas->getElement(posicion);
            cuenta->setSaldo(cuenta->getSaldo() + solicitud->getCantidad());
            this->cSolicitudes->remove();

        }
    }


    List<Cuenta> *darDeBajaMillonarios() {

        // esta parte hace una comparacion de un cada valor de saldo de cada cuenta por una cantidad
        // recorre toda la lista enlazada, y cada que encuentra un match lo mete a otra lista y lo remueve
        // en el codigo tenemos un ciclo for que de cicla n elementos
        //dentro tenemos el uso de la funcion getElement, este algoritmo es de complejidad O(n)
        // por lo que podemos concluir que este algoritmo es de complejidad de O(n^2)

        List<Cuenta> *millonarios = new ListSE<Cuenta>();
        float millon = 1000000;
        for (int i = 0; i < this->lCuentas->getLength(); ++i) {

            if (this->lCuentas->getElement(i)->getSaldo() >= millon) {
                millonarios->add(this->lCuentas->getElement(i));
                this->lCuentas->remove(i);
                i--;
            }
        }
        return millonarios;
    }


    void desplegarCuentas() {

        for (int i = 0; i < this->lCuentas->getLength(); ++i) {

            cout << "No.ID: " << this->lCuentas->getElement(i)->getNoID() << " |  Saldo: "
                 << this->lCuentas->getElement(i)->getSaldo() << endl;

        }

    }

    void solicitudesEspera() {
        if (!this->cSolicitudes->isEmpty()) {
            cout << "hay solicitudes en espera" << endl;
        } else {
            cout << "sin solicitudes en espera" << endl;
        }
    }


};


#endif //LISTAS_ENLAZADAS_BANCO_H
