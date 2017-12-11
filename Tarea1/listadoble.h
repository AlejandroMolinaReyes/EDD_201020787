#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// variables
typedef struct nodoListaDoble{
    int posicion;
    struct nodoListaDoble *siguente;
    struct nodoListaDoble *anterior;
    void *datos;

}nodoDoble;

typedef struct listasDobles{
    nodoDoble *primero;
    nodoDoble *ultimo;
    int tamano;
}listaDoble;

// Funciones
void inicializarListaDoble(listaDoble *iniciar);

void insertarNodoFinalDoble(listaDoble *listaParametro,int dato, void *info);

nodoDoble* eliminarNodoPrimeroDoble(listaDoble *listaParametro);

nodoDoble* eliminarNodoUltimoDoble(listaDoble *listaParametro);

nodoDoble* eliminarNodoPosicionXDoble(listaDoble *listaParametro,nodoDoble *eliminado);

nodoDoble* buscarNodoDoble(listaDoble *listaParametro, void *cadena);

void mostrarListaPrimeroDoble(listaDoble *listaParametro);



#endif // LISTADOBLE_H_INCLUDED
