#ifndef COLADOBLE_H
#define COLADOBLE_H

#include <stdio.h>
#include <stdlib.h>

// variables
typedef struct nodoColaDoble{
    int posicion;
    struct nodoColaDoble *siguente;
    struct nodoColaDoble *anterior;
    void *datos;

}nodoCola;

typedef struct colaDobles{
    nodoCola *primero;
    nodoCola *ultimo;
    int tamano;
}colaDoble;

// Funciones

void inicializarColaDoble(colaDoble *iniciar);

void pushDoble(colaDoble *listaParametro,int dato, void *info);

nodoCola* popDoble(colaDoble *listaParametro);

void mostrarListaPrimeroCola(colaDoble *listaParametro);

#endif // COLADOBLE_H
