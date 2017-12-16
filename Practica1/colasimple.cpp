#include "colasimple.h"

// lista
void inicializarColaSimple(colaSimple *iniciar){
    iniciar->primero = 0;
    iniciar->ultimo = 0;
    iniciar->tamano = 0;

}

nodoColaS* inicializarNodoCola(nodoColaS *nodoNuevo, void *dato){
    if((nodoNuevo = (nodoColaS*)malloc(sizeof(*nodoNuevo)))==0){
        return 0;
    }
    nodoNuevo->siguente = 0;
    nodoNuevo->posicion = 0;
    nodoNuevo->datos = dato;
    return nodoNuevo;
}

void insertarListaVaciaCola(colaSimple *listaVacia,int dato, void *info){
    nodoColaS *nodoNuevo = inicializarNodoCola(nodoNuevo,info);
    nodoNuevo->posicion = dato;
    nodoNuevo->siguente = 0;
    listaVacia->primero = nodoNuevo;
    listaVacia->ultimo = nodoNuevo;
    listaVacia->tamano++;
}

void pushDoble(colaSimple *listaParametro,int dato, void *info){
    nodoColaS *nodoNuevo = inicializarNodoCola(nodoNuevo,info);
    if(listaParametro->primero==NULL&&listaParametro->ultimo==NULL){
        insertarListaVaciaCola(listaParametro,dato,info);
    }else{
        nodoNuevo->posicion = dato;
        listaParametro->ultimo->siguente = nodoNuevo;
        listaParametro->ultimo = nodoNuevo;
        listaParametro->tamano++;
    }
}

nodoColaS* popDoble(colaSimple *listaParametro){
    nodoColaS *eliminado = listaParametro->primero;
    if(listaParametro->primero!=NULL){
        if(listaParametro->primero==listaParametro->ultimo){
            listaParametro->primero=NULL;
            listaParametro->ultimo=NULL;
            listaParametro->tamano--;
        }else{
            listaParametro->primero = listaParametro->primero->siguente;
            eliminado->siguente= NULL;
            listaParametro->tamano--;
        }
    }
    return eliminado;
}

void mostrarListaPrimeroCola(colaSimple *listaParametro){
    nodoColaS *busqueda = listaParametro->primero;
    while(busqueda!=NULL){
          printf("Posicion: %i \n",busqueda->posicion);
        busqueda = busqueda->siguente;
    }
     printf("Tamaño: %i \n",listaParametro->tamano );
}
