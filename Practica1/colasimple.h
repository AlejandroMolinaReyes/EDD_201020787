#ifndef COLASIMPLE_H
#define COLASIMPLE_H

#include <stdio.h>
#include <stdlib.h>

// variables
typedef struct nodoColaSimple{
    int posicion;
    struct nodoColaSimple *siguente;
    void *datos;

}nodoColaS;

typedef struct colaSimple{
    nodoColaS *primero;
    nodoColaS *ultimo;
    int tamano;
}colaSimple;

// Funciones

void inicializarColaSimple(colaSimple *iniciar);

void pushSimple(colaSimple *listaParametro,int dato, void *info);

nodoColaS* popSimple(colaSimple *listaParametro);

void mostrarListaPrimeroColaSimple(colaSimple *listaParametro);

#endif // COLASIMPLE_H
