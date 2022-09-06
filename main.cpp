#include <iostream>

#include "ListDE.h"

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



    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
