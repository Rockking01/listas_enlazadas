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
    List<Cuenta>* lCuentas;
    ColaSE<Solicitud>* cSolicitudes;

    int verficarCuenta(){
        Solicitud* primerSolicitud = this->cSolicitudes->top();


        for (int i = 0; i < this->lCuentas->getLength(); ++i) {
            if (lCuentas->getElement(i)->getNoID() == primerSolicitud->getNoID()){
                return i;
            }
        }
        this->lCuentas->add(new Cuenta(this->lCuentas->getLength(),primerSolicitud->getNoID(),float (0)));
        return this->lCuentas->getLength() - 1;
    }

public:

    Banco(){
     this->lCuentas = new ListSE<Cuenta>();
     this->cSolicitudes = new ColaSE<Solicitud>();
    }

    ~Banco(){
        delete this->lCuentas;
        delete this->cSolicitudes;
    }

    void adicionarCuenta(Cuenta* cuenta){
        this->lCuentas->add(cuenta);
    }

    void adicionarSolictiud(Solicitud* solicitud){
        this->cSolicitudes->add(solicitud);
    }

    List<Cuenta>* getCuentas(){
        return this->lCuentas;
    }

    ColaSE<Solicitud>* getSolicitudes(){
        return this->cSolicitudes;
    }

    void atenderTodasLasSolicitudes(){

        int posicion = 0;
        Solicitud* solicitud = NULL;
        Cuenta* cuenta = NULL;


        while(!this->cSolicitudes->isEmpty()){

            solicitud = this->cSolicitudes->top();
            posicion = this->verficarCuenta();
            cuenta = this->lCuentas->getElement(posicion);
            cuenta->setSaldo(cuenta->getSaldo() + solicitud->getCantidad());
            this->cSolicitudes->remove();

        }
    }

    List<Cuenta>* darDeBajaMillonarios(){

        List<Cuenta>* millonarios = new ListSE<Cuenta>();
        float millon = 1000000;
        for (int i = 0; i < this->lCuentas->getLength() ; ++i) {

            if (this->lCuentas->getElement(i)->getSaldo() >= millon){
                millonarios->add(this->lCuentas->getElement(i));
                this->lCuentas->remove(i);
                i--;
            }
        }
        return millonarios;
    }


    void desplegarCuentas(){

        for (int i = 0; i < this->lCuentas->getLength() ; ++i) {

            cout << "No.ID: " << this->lCuentas->getElement(i)->getNoID() << "   Saldo: " << this->lCuentas->getElement(i)->getSaldo()<<endl;

        }

    }

    void solicitudesEspera(){
        if (!this->cSolicitudes->isEmpty()){
            cout << "hay solicitudes en espera" << endl;
        }
        else{
            cout << "sin solicitudes en espera" << endl;
        }
    }










};


#endif //LISTAS_ENLAZADAS_BANCO_H
