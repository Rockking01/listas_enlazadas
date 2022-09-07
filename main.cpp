#include <iostream>

#include "ListDE.h"
#include "Banco.h"

//Programa de Guillermo Garrido Torres
//Matricula: A00835087

int main() {
    std::cout << "Programa trabajando" << std::endl;

    try
    {
        /*List<int>* integerList = new ListDE<int>();

        //Probar el adicionar
        integerList->add(new int(1));
        integerList->add(new int(2));
        integerList->add(new int(5));
        integerList->add(new int(8));
        integerList->add(new int(10));
        integerList->add(new int(3));
        integerList->add(new int(2));
        integerList->add(new int(9));

        integerList->remove(7);

        integerList->insert(new int(3),0);

        for (int i = 0; i < integerList->getLength(); i++)
        {
            cout << (*integerList->getElement(i)) << " ";
        }
        cout << endl;


       cout << (integerList->getPosition(new int (2))) << " ";
       cout << endl;
         */

        Banco* banamex = new Banco();

        banamex->adicionarCuenta(new Cuenta(1, "AC235", 236));
        banamex->adicionarCuenta(new Cuenta(2, "AC465", 1906.54));
        banamex->adicionarCuenta(new Cuenta(3, "MA392", 2034943.1));
        banamex->adicionarCuenta(new Cuenta(4, "TA7765", 1000023.5));
        banamex->adicionarCuenta(new Cuenta(5, "GR5471", 40365.1));
        banamex->adicionarCuenta(new Cuenta(6, "HP721", 124560.68));

        banamex->adicionarSolictiud(new Solicitud("colegiatura colegio","AC235",3045.4));
        banamex->adicionarSolictiud(new Solicitud("renta casa","HT3493",5500));
        banamex->adicionarSolictiud(new Solicitud("pago libros","AC465",1205.7));
        banamex->adicionarSolictiud(new Solicitud("despensa","TA7765",89500.45));
        banamex->adicionarSolictiud(new Solicitud("tennis","GR5471",87843.9));
        banamex->adicionarSolictiud(new Solicitud("loteria","HP721",1000000));

        List<Cuenta>* cuentas = banamex->getCuentas();

        for (int i = 0; i < cuentas->getLength() ; ++i) {

            cout << "No.ID: " << cuentas->getElement(i)->getNoID() << "   Saldo: " << cuentas->getElement(i)->getSaldo()<<endl;

        }

        banamex->atenderTodasLasSolicitudes();

        cuentas = banamex->getCuentas();

        cout << "\n"<<endl;
        for (int i = 0; i < cuentas->getLength() ; ++i) {

            cout << "No.ID: " << cuentas->getElement(i)->getNoID() << "   Saldo: " << cuentas->getElement(i)->getSaldo()<<endl;

        }








    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
