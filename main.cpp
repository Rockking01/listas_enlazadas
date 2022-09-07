#include <iostream>
#include "ListDE.h"
#include "Banco.h"
#include <string>

//Programa de Guillermo Garrido Torres
//Matricula: A00835087

int main() {
    std::cout << "Programa trabajando" << std::endl;

    try
    {

        Banco* banamex = new Banco();

        banamex->adicionarCuenta(new Cuenta(1, "AC235", 236));
        banamex->adicionarCuenta(new Cuenta(2, "AC465", 1906.54));
        banamex->adicionarCuenta(new Cuenta(3, "MA392", 2034943.1));
        banamex->adicionarCuenta(new Cuenta(4, "GR5471", 40365.1));
        banamex->adicionarCuenta(new Cuenta(5, "HP721", 124560.68));



        banamex->adicionarSolictiud(new Solicitud("colegiatura colegio","AC235",3045.4));
        banamex->adicionarSolictiud(new Solicitud("renta casa","HT3493",5500));
        banamex->adicionarSolictiud(new Solicitud("pago libros","AC465",1205.7));
        banamex->adicionarSolictiud(new Solicitud("buggatti","TA765",3000000.45));
        banamex->adicionarSolictiud(new Solicitud("tennis","GR5471",87843.9));
        banamex->adicionarSolictiud(new Solicitud("loteria","HP721",1000000));

        banamex->desplegarCuentas();
        banamex->solicitudesEspera();


        banamex->atenderTodasLasSolicitudes();

        List<Cuenta>* millonarios = banamex->darDeBajaMillonarios();
        cout << "\n"<<endl;

        banamex->desplegarCuentas();
        banamex->solicitudesEspera();
        cout << "\n"<<endl;
        cout << "Millonarios:"<<endl;
        for (int i = 0; i < millonarios->getLength() ; ++i) {

            cout << "No.ID: " << millonarios->getElement(i)->getNoID() << "   Saldo: " << millonarios->getElement(i)->getSaldo()<<endl;

        }



    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
