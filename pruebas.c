#include "probador.h"
#include "abb.h"

#define EXITO 0
#define ERROR -1
#define MAX_DESCRIPCION 60
#define PRIMERO_MAYOR 1
#define PRIMERO_MENOR -1
#define AMBOS_IGUALES 0

bool probar_crear_arbol(abb_t* arbol){
	if( arbol->nodo_raiz == NULL)
		return true;
	else 
		return false;
}

bool probar_insertar_raiz(abb_t* arbol){
	long elemento = 42;
	int retorno = arbol_insertar(arbol,(void*)elemento);

	if(retorno == EXITO && (long)arbol->nodo_raiz->elemento == elemento && arbol->nodo_raiz->derecha == NULL && arbol->nodo_raiz->izquierda == NULL)
		return true;
	else 
		return false;
}

bool probar_insertar_mayor(abb_t* arbol){
	long elemento = 62;
	int retorno = arbol_insertar(arbol,(void*)elemento);

	if(retorno == EXITO && (long)arbol->nodo_raiz->derecha->elemento == elemento)
		return true;
	else
		return false;

}

bool probar_insertar_elementos_iguales(abb_t* arbol){
	long elemento = 62;
	int retorno = arbol_insertar(arbol,(void*)elemento);

	if(retorno == EXITO && (long)arbol->nodo_raiz->derecha->derecha->elemento == elemento){
		arbol_borrar(arbol,(void*)elemento);
		return true;
	}
	else
		return false;
}

bool probar_borrar_hoja(abb_t* arbol){

	arbol_insertar(arbol,(void*)28);
	arbol_insertar(arbol,(void*)20);
	arbol_insertar(arbol,(void*)37);

	long elemento = 20;
	int retorno = arbol_borrar(arbol,(void*)elemento);

	if( retorno==EXITO && arbol->nodo_raiz->izquierda->izquierda==NULL)
		return true;
	else
		return false;
}

bool probar_borrar_con_hijo(abb_t* arbol){
	long elemento_uno = 30;
	long elemento_dos = 40;
	long elemento_borrado = 28;

	arbol_insertar(arbol,(void*)elemento_uno);
	arbol_insertar(arbol,(void*)elemento_dos);
	
	int retorno = arbol_borrar(arbol,(void*)elemento_borrado);

	if(retorno==EXITO && (long)arbol->nodo_raiz->izquierda->elemento==37 && (long)arbol->nodo_raiz->izquierda->derecha->elemento==elemento_dos)
		return true;
	else
		return false;
}


bool probar_borrar_con_dos_hijos_primero(abb_t* arbol){

	long elemento = 41;
	arbol_insertar(arbol,(void*)elemento);

	int retorno = arbol_borrar(arbol,(void*)37);

	if(retorno==EXITO && (long)arbol->nodo_raiz->izquierda->elemento==30 && (long)arbol->nodo_raiz->izquierda->derecha->elemento==40)
		return true;
	else
		return false;
}

bool probar_borrar_con_dos_hijos(abb_t* arbol){
	arbol_insertar(arbol,(void*)55);
	arbol_insertar(arbol,(void*)50);
	arbol_insertar(arbol,(void*)60);
	arbol_insertar(arbol,(void*)58);
	arbol_insertar(arbol,(void*)65);
	
	int retorno = arbol_borrar(arbol,(void*)62);
	nodo_abb_t* aux = arbol->nodo_raiz->derecha->izquierda;

	if(retorno == EXITO && (long)aux->elemento==55 && (long)aux->derecha->elemento==58 && (long)arbol->nodo_raiz->derecha->elemento==60)
		return true;
	else
		return false;

}

bool probar_buscar_existente(abb_t* arbol){
	void* elemento = arbol->nodo_raiz->derecha->izquierda->elemento;

	void* retorno = arbol_buscar(arbol,elemento);

	if(arbol->comparador(elemento,retorno)==AMBOS_IGUALES)
		return true;
	else
		return false;
}

bool probar_buscar_inexistente(abb_t* arbol){
	long elemento = (long)(arbol->nodo_raiz->derecha->izquierda->elemento)+80;

	void* retorno = arbol_buscar(arbol,(void*)elemento);

	if(retorno==NULL)
		return true;
	else
		return false;
}

bool probar_borrar_raiz(abb_t* arbol){
	int retorno = arbol_borrar(arbol,(void*)42);

	if( retorno==EXITO && (long)arbol->nodo_raiz->elemento == (long)41)
		return true;
	else
		return false;
}

bool son_iguales(void** array,int elementos[],int cantidad){
	size_t i = 0;
	bool iguales=true;
	while( i<cantidad && iguales ){
		if((long)array[i] != elementos[i])
			iguales=false;
		i++;
	}
	return iguales;
}

void probar_recorrido_inorden(abb_t* arbol,void**array,int tamanio_array,probador_t* probador){
	
	char descripcion[MAX_DESCRIPCION]="Se guardan 5 elementos en un array de manera inorden";
	int cantidad = arbol_recorrido_inorden(arbol,array,tamanio_array);
	int elementos[]={30,40,41,42,50};

	if( cantidad==tamanio_array && son_iguales(array,elementos,tamanio_array))
		describir_prueba(probador,descripcion,true);
	else
		describir_prueba(probador,descripcion,false);
	
	return;
}

void probar_recorrido_preorden(abb_t* arbol,void**array,int tamanio_array,probador_t* probador){
	char descripcion[MAX_DESCRIPCION]="Se guardan 5 elementos en un array de manera preorden";
	int cantidad = arbol_recorrido_preorden(arbol,array,tamanio_array);
	int elementos[]={42,30,40,41,60};

	if( cantidad==tamanio_array && son_iguales(array,elementos,tamanio_array))
		describir_prueba(probador,descripcion,true);
	else
		describir_prueba(probador,descripcion,false);
	
	return;
}
void probar_recorrido_postorden(abb_t* arbol,void**array,int tamanio_array,probador_t* probador){
	char descripcion[MAX_DESCRIPCION]="Se guardan 5 elementos en un array de manera postorden";
	int cantidad = arbol_recorrido_postorden(arbol,array,tamanio_array);
	int elementos[]={41,40,30,50,58};

	if( cantidad==tamanio_array && son_iguales(array,elementos,tamanio_array))
		describir_prueba(probador,descripcion,true);
	else
		describir_prueba(probador,descripcion,false);
	
	return;
}

void probar(abb_t* arbol,probador_t* probador,bool (*prueba)(abb_t*),char descripcion[MAX_DESCRIPCION]){
	bool paso = prueba(arbol);

	describir_prueba(probador,descripcion,paso);
}


bool mostrar_elemento(void* elemento, void* extra){
	
	if(elemento){
		printf("%li ", (long)elemento);
		if((long)elemento == (long)extra)
			return true;
	}

	return false;
}

void probar_con_cada_elemento(abb_t* arbol){

	printf("Se imprime todo el arbol inorden, deberia ser: 30 40 41 42 50 55 58 60 65 \n");
	abb_con_cada_elemento(arbol, ABB_RECORRER_INORDEN, mostrar_elemento,NULL);
	printf("\n");

	printf("Se imprime todo el arbol preorden, deberia ser: 42 30 40 41 60 55 50 58 65 \n");
	abb_con_cada_elemento(arbol, ABB_RECORRER_PREORDEN, mostrar_elemento,NULL);
	printf("\n");

	printf("Se imprime todo el arbol postorden, deberia ser: 41 40 30 50 58 55 65 60 42 \n");
	abb_con_cada_elemento(arbol, ABB_RECORRER_POSTORDEN, mostrar_elemento,NULL);
	printf("\n");

	printf("Se imprime el arbol hasta el 42 inorden, deberia ser: 30 40 41 42\n");
	abb_con_cada_elemento(arbol, ABB_RECORRER_INORDEN, mostrar_elemento,(void*)42);
	printf("\n");

	printf("Se imprime el arbol hasta el 42 preorden, deberia ser: 42\n");
	abb_con_cada_elemento(arbol, ABB_RECORRER_PREORDEN, mostrar_elemento,(void*)42);
	printf("\n");

	printf("Se imprime el arbol hasta el 42 postorden, deberia ser: 41 40 30 50 58 55 65 60 42 \n");
	abb_con_cada_elemento(arbol, ABB_RECORRER_POSTORDEN, mostrar_elemento,(void*)42);
	printf("\n");

}

int comparar_elementos(void* elemento_uno,void* elemento_dos){
	if((long)elemento_uno>(long)elemento_dos)
		return PRIMERO_MAYOR;
	else if((long)elemento_uno<(long)elemento_dos)
		return PRIMERO_MENOR;
	else
		return AMBOS_IGUALES;
}

void destructor(void* elemento){
	return;
}

void llamar_pruebas(abb_t* arbol,probador_t* probador){

	probar(arbol,probador,(&probar_crear_arbol),"Se crea el arbol correctamente");
	probar(arbol,probador,(&probar_insertar_raiz),"Se inserta la raiz correctamente");
	probar(arbol,probador,(&probar_insertar_mayor),"Se inserta un elemento mayor");
	probar(arbol,probador,(&probar_insertar_elementos_iguales),"Se inserta un elemento ya existente");
	probar(arbol,probador,(&probar_borrar_hoja),"Se borra una hoja del arbol");
	probar(arbol,probador,(&probar_borrar_con_hijo),"Se borra un elemento con un unico hijo");
	probar(arbol,probador,(&probar_borrar_con_dos_hijos_primero),"Se borra un elemento con dos hijos y el primer menor no tiene hijos");
	probar(arbol,probador,(&probar_borrar_con_dos_hijos),"Se borra un elemento con dos hijos, y se reemplaza por el mayor de los menores");
	probar(arbol,probador,(&probar_buscar_existente),"Se busca un elemento del arbol");
	probar(arbol,probador,(&probar_buscar_inexistente),"Se busca un elemento que no esta en el arbol");

	int tamanio_array = 5;
	void** array = malloc(sizeof(void**)*(size_t)tamanio_array);

	if(!array)
		printf("No se pudieron probar los recorridos\n");
	else{
		probar_recorrido_inorden(arbol,array,tamanio_array,probador);
		probar_recorrido_preorden(arbol,array,tamanio_array,probador);
		probar_recorrido_postorden(arbol,array,tamanio_array,probador);
	}
	free(array);

	probar_con_cada_elemento(arbol);
	probar(arbol,probador,(&probar_borrar_raiz),"Se borra la raiz del arbol");

}

int main(){
	probador_t* probador = crear_probador();

	if(!probador)
		return -1;

	abb_t* arbol = arbol_crear((&comparar_elementos),(&destructor));

	llamar_pruebas(arbol,probador);

	arbol_destruir(arbol);
	free(probador);

}