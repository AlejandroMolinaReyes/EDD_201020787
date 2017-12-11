#include "listadoble.h"
#include <string.h>

void inicializarListaDoble(listaDoble *iniciar){
    iniciar->primero = 0;
    iniciar->ultimo = 0;
    iniciar->tamano = 0;
}

void insertarNodoFinalDoble(listaDoble *listaParametro,int posicion, void *info){
    nodoDoble *nodoNuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nodoNuevo->posicion = posicion;
    nodoNuevo->datos = info;
    if(listaParametro->primero==0&&listaParametro->ultimo==0){
        nodoNuevo->anterior = 0;
        nodoNuevo->siguente = 0;
        listaParametro->primero = nodoNuevo;
        listaParametro->ultimo = nodoNuevo;
        listaParametro->tamano++;

    }else{
        nodoNuevo->siguente = 0;
        nodoNuevo->anterior = listaParametro->ultimo;
        listaParametro->ultimo->siguente = nodoNuevo;
        listaParametro->ultimo = nodoNuevo;
        listaParametro->tamano++;

    }
}


nodoDoble* eliminarNodoPrimeroDoble(listaDoble *listaParametro){
    nodoDoble *eliminado = listaParametro->primero;
    if(listaParametro->primero!=0){
        if(listaParametro->primero==listaParametro->ultimo){
            listaParametro->primero=0;
            listaParametro->ultimo=0;
            listaParametro->tamano--;
        }else{
            listaParametro->primero = listaParametro->primero->siguente;
            listaParametro->primero->anterior = 0;
            eliminado->siguente= 0;
            listaParametro->tamano--;
        }
    }
    return eliminado;
}

nodoDoble* eliminarNodoUltimoDoble(listaDoble *listaParametro){
   nodoDoble *eliminado = listaParametro->ultimo;
   if(listaParametro->ultimo!=0){
       if(listaParametro->primero==listaParametro->ultimo){
           listaParametro->primero = 0;
           listaParametro->ultimo = 0;
           listaParametro->tamano--;
       }else {
          listaParametro->ultimo->anterior->siguente = 0;
          listaParametro->ultimo = listaParametro->ultimo->anterior;
          listaParametro->tamano--;
       }
       eliminado->siguente = 0;
       eliminado->anterior = 0;

    }
   return eliminado;

}

nodoDoble* eliminarNodoPosicionXDoble(listaDoble *listaParametro,nodoDoble *eliminado){
    if(listaParametro->primero!=0){
           if(listaParametro->primero==listaParametro->ultimo){
               listaParametro->primero = 0;
               listaParametro->ultimo = 0;
               listaParametro->tamano--;
           }else if(eliminado==listaParametro->ultimo){
                eliminarNodoUltimoDoble(listaParametro);
           }else if(eliminado==listaParametro->primero){
                eliminarNodoPrimeroDoble(listaParametro);
           }else{
               eliminado->anterior->siguente = eliminado->siguente;
               eliminado->siguente->anterior = eliminado->anterior;
            }
        }
        eliminado->siguente = 0;
        eliminado->anterior = 0;

   return eliminado;
}

nodoDoble* buscarNodoDoble(listaDoble *listaParametro, void *cadena){
    nodoDoble *busqueda = listaParametro->primero;
    while(busqueda!=0){
        if(strcmp((char*)busqueda->datos,(char*)cadena)==0){
            return busqueda;
        }
        busqueda = busqueda->siguente;
    }
    return 0;
}

void mostrarListaPrimeroDoble(listaDoble *listaParametro){
    nodoDoble *nodo = listaParametro->primero;
    while(nodo!=0){
        printf("Dato: %s\n",nodo->datos);
        nodo = nodo->siguente;
    }
    printf("Tamano: %i \n",listaParametro->tamano );
}



