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

nodoDoble* inicializarNodoDoble(nodoDoble *nodoNuevo, void *dato);

void insertarListaVaciaDoble(listaDoble *listaVacia,int dato, void *info);

void insertarNodoInicioDoble(listaDoble *listaParametro,int dato, void *info);

void insertarNodoFinalDoble(listaDoble *listaParametro,int dato, void *info);

void insertarPosicionDespuesXDoble(listaDoble *listaParametro,int dato,nodoDoble *nodoActual, void *info);

nodoDoble* eliminarNodoPrimeroDoble(listaDoble *listaParametro);

nodoDoble* eliminarNodoUltimoDoble(listaDoble *listaParametro);

nodoDoble* eliminarNodoPosicionXDoble(listaDoble *listaParametro,nodoDoble *eliminado);

nodoDoble* buscarNodoDoble(listaDoble *listaParametro, int posicion);

void mostrarListaPrimeroDoble(listaDoble *listaParametro);

void mostrarListaUltimoDoble(listaDoble *listaParametro);



#endif // LISTADOBLE_H_INCLUDED
