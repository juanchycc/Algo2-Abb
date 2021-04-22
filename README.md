# Algo2-Abb
Se pide implementar un Arbol Binario de Búsqueda. Para ello se brindan las firmas de las funciones públicas a implementar y se deja a criterio del alumno la creación de las funciones privadas del TDA para el correcto funcionamiento
del Arbol cumpliendo con las buenas prácticas de programación.
Adicionalmente se pide la implementación de un iterador interno para la estructura.

En esta tarea me toco implementar un Arbol Binario de Búsqueda, este es un tipo de dato abstracto, es decir, un tipo de dato definido por una estructura de datos y operaciones,de manera tal que solo conservo la parte más relevante para mi problema (utilizando la abstraccion).

Para compilar el programa debemos utilizar la siguiente linea en la terminal:

      gcc probador.c pruebas.c abb.c -o abb -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

Y para la ejecucion:

    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./abb


Este tda pertenece a un gran grupo denominado arbol que esta formado por una coleccion de nodos en el cual se tiene a uno de estos nodos como raiz, además, el abb al ser un arbol binario podemos abstraer una idea de izquierda y derecha, pero ademas es tambien un arbol de comparacion por lo tanto los elementos a la derecha de la raiz son mayores a este y los de la izquierda menores.
Como operaciones basicas tenemos: crear, destruir, vacio, insertar, eliminar, busqueda y recorrer.
Convenciones: mayores a la derecha y menores a la izquierda, Si el elemento a insertar es igual va a la derecha, al eliminar y en caso de necesitarlo se reemplaza por el mayor de los menores.

La estructura del arbol tiene un puntero a funcion llamado destruir la cual recibe un puntero comodin (void*) esta funcion permite que el usuario en caso de ser necesario libere el espacio de memoria reservado para el elemento a borrar, si el usuario no tiene la posibilidad de mandar una funcion destruir entonces no puede pedir memoria para su elemento ya que estaria perdiendola. Esto puede suceder cuando se quiere eliminar un elemento, tenemos que llamar al destructor antes de liberar el nodo y tambien es necesario cuando destruimos el arbol.

Analisis de las operaciones implementadas en el abb:

* arbol_crear: esta funcion tiene una complejidad de O(1), ya que es la complejidad mas grande que tiene la funcion.

* arbol_insertar: en esta funcion la complejidad mas grande esta dada por la funcion auxiliar insertar quedando entonces una complejidad de O(log n). (se analiza mas abajo)

* arbol_borrar: en esta funcion la complejidad esta dada por la funcion auxiliar eliminar y buscar:
 T(eliminar)+T(buscar)=Max( O(log n),O(log n) ) = O(log n).En castellano: ambas tienen complejidad O(log n) por lo que queda un O(log n).

*arbol_buscar: en esta funcion sucede lo mismo que en insertar y borrar, la funcion auxiliar buscar en la mas compleja y luego del debido analisis(mas abajo) la complejidad queda O(log n).

* Análisis para insertar, borrar y buscar:

 Por teorema maestro---> T(n)= aT(n/b) + F(n).
 a=1----> cantidad de llamadas recursivas.
 b=2----> Veces que el problema se divide, en este caso izquierda y derecha.
 entonces: n elevado al logaritmo en base 2 de 1 es igual a n elevado a la cero---->F(n)=1, quedando por el caso dos:
 T(n)= O(log n).

 Esta complejidad O(log n) no siempre se cumple,ya que,existe el caso que mi abb tenga la misma forma que una lista simplemente enlazada y en ese caso las complejidades O(log n) serian entonces O(n) ya que el problema no se podria dividir en 2.

*arbol_raiz: O(1), simplemente es una instruccion.
*arbol_vacio: O(1), instruccion.

*Recorridos inorden,preoorden y postorden la complejidad es de O(n) por que recorren los n elementos.

*Para el iterador interno dependera de cuando se corte la iteracion, pero evaluando el peor caso, es decir que se hagan todas las iteraciones tambien tendremos un O(n)
