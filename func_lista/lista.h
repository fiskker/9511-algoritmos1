#include <stdio.h>
#include <stdlib.h>

typedef enum{
	FALSE,
	TRUE
} bool_t;

typedef enum{
	RV_ILLEGAL,
	RV_SUCCESS,
	RV_NOMEM
} retval_t;

typedef char* cadena_t;

typedef struct dato_mensaje{
	size_t id_msj;
    time_t timestamp;
    size_t id_usuario_mensaje; /*Puede no existir en la red*/
    cadena_t texto;
} mensaje_s;

struct nodo;
typedef struct nodo *lista_s;

retval_t LISTA_crear(lista_s *pl);
bool_t LISTA_vacia(lista_s pl);
retval_t LISTA_crear_nodo(lista_s *nodo, void *dato);
retval_t LISTA_destruir_nodo(lista_s *pnodo, void (*destructor)(void*));
retval_t LISTA_destruir(lista_s *pl, void (*destructor)(void*));
retval_t LISTA_insertar_ppio(lista_s *pl, void *d);
retval_t LISTA_insertar_final(lista_s *pl, void *d);
retval_t LISTA_insertar_decreciente(lista_s *pl, void *d, int(*cmp)(void*, void*));
void* LISTA_buscar(lista_s l, void* t, bool_t (*cmp)(void*, void*));
retval_t LISTA_recorrer(lista_s l, void *arg, void (*pf)(void*, void*));

void destructor(void* dato);
void funcion_imprimir(void * arg, void * dato);