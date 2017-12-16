#include "coladoble.h"

// lista
void inicializarColaDoble(colaDoble *iniciar){
    iniciar->primero = 0;
    iniciar->ultimo = 0;
    iniciar->tamano = 0;

}

nodoCola* inicializarNodoCola(nodoCola *nodoNuevo, void *dato){
    if((nodoNuevo = (nodoCola*)malloc(sizeof(*nodoNuevo)))==0){
        return 0;
    }
    nodoNuevo->siguente = 0;
    nodoNuevo->anterior = 0;
    nodoNuevo->posicion = 0;
    nodoNuevo->datos = dato;
    return nodoNuevo;
}

void insertarListaVaciaCola(colaDoble *listaVacia,int dato, void *info){
    nodoCola *nodoNuevo = inicializarNodoCola(nodoNuevo,info);
    nodoNuevo->posicion = dato;
    nodoNuevo->anterior = 0;
    nodoNuevo->siguente = 0;
    listaVacia->primero = nodoNuevo;
    listaVacia->ultimo = nodoNuevo;
    listaVacia->tamano++;
}

void pushDoble(colaDoble *listaParametro,int dato, void *info){
    nodoCola *nodoNuevo = inicializarNodoCola(nodoNuevo,info);
    if(listaParametro->primero==NULL&&listaParametro->ultimo==NULL){
        insertarListaVaciaCola(listaParametro,dato,info);
    }else{
        nodoNuevo->posicion = dato;
        nodoNuevo->anterior = listaParametro->ultimo;
        listaParametro->ultimo->siguente = nodoNuevo;
        listaParametro->ultimo = nodoNuevo;
        listaParametro->tamano++;
    }
}

nodoCola* popDoble(colaDoble *listaParametro){
    nodoCola *eliminado = listaParametro->primero;
    if(listaParametro->primero!=NULL){
        if(listaParametro->primero==listaParametro->ultimo){
            listaParametro->primero=NULL;
            listaParametro->ultimo=NULL;
            listaParametro->tamano--;
        }else{
            listaParametro->primero = listaParametro->primero->siguente;
            listaParametro->primero->anterior = NULL;
            eliminado->siguente= NULL;
            listaParametro->tamano--;
        }
    }
    return eliminado;
}

void mostrarListaPrimeroCola(colaDoble *listaParametro){
    nodoCola *busqueda = listaParametro->primero;
    while(busqueda!=NULL){
          printf("Posicion: %i \n",busqueda->posicion);
        busqueda = busqueda->siguente;
    }
     printf("Tamaño: %i \n",listaParametro->tamano );
}
