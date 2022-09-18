
# Documentacion

en este documento dare un poco de documentacion adicional de algunas funciones que no venian en el digrama de clasesç
y los algoritmos principales del problema

## funciones

### funcion verificar cuenta

esta funcion es sencilla, lo primero es definir cual es la primer solicitud, simplemente sacamos el primer elemento de
la cola y la metemos en un puntero definido como primerSolicitud, sacar el primer elemento de una cola es una operacion
de O(1), el ciclo for va de 0 a el largo de las lista de cuentas, n veces, dentro de el for esta un if con una 
condicional que tiene complejidad tipo O(n), el motivo es porque tenemos el getElement, este es de complejidad O(n),
lo que esta dentro del if es de complejidad es O(1), en el caso que no haya match, el crear una nueva cuenta es una
operacion de O(1), considerando esto, nos damos cuenta que la funcion tiene una complejidad O(n^2), el motivo es por el 
ciclo for y el if anidado, esos se multiplican y obtenemos esta complejidad.

### funcion atenderTodasLasSolicitudes

esta funcion empieza con inicializar algunos puenteros, operaciones esenciales lo cual tienen complejidad constante
despues tenemos un ciclo while el cual terminara cuando todas solicitudes se hayan eliminado de la cola. esto significa
que el ciclo while es de O(n), lo que tenemos dentro viene siendo todo de complejidad lineal, pero hay dos funciones que
tienen una complejidad distinta, verificarCuenta y getElement. verificarCuenta es de complejidad O(n^2), getElement es 
de O(n), como verificarCuenta es mas complejo ese es el que multiplicamos por el ciclo, lo que nos resulta en una 
funcion de complejidad O(n^3).


### funcion darDeBajaMillonarios

todas las operaciones son de complejidad O(1), lo unicas cosas de complejidad distinta son lo dentro del ciclo for
el ciclo va de 0 a n, y dentro del ciclo tenemos la funcion getElement, asi que si lo multiplicamos tenemos una funcion
de O(n^2).


## funciones extra

dentro de esta entran funciones como adicionarCuenta, adicionarSolicitud, estas funciones, agregan objetos del respecti-
vo tipo a su determinada estructura, estas son utiles para probar el programa, el porque es necesaria es porque no 
hay un constructor que tenga como parametro las listas ya hechas.

la otra funcion es desplegarCuentas, esta solo despliega todas las cuentas de la lista con formato, y otra funcion 
para deplegar es la de solicitudes en espera que solo me dice si las solicitudes ya se atendieron o no, y despliega si 
quedan o no.