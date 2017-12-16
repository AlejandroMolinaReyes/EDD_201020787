#include "listadoble.h"

// lista
void inicializarListaDoble(listaDoble *iniciar){
    iniciar->primero = NULL;
    iniciar->ultimo = NULL;
    iniciar->tamano = 0;

}

nodoDoble* inicializarNodoDoble(nodoDoble *nodoNuevo, void *dato){
    if((nodoNuevo = (nodoDoble*)malloc(sizeof(*nodoNuevo)))==NULL){
        return NULL;
    }
    nodoNuevo->siguente = NULL;
    nodoNuevo->anterior = NULL;
    nodoNuevo->posicion = 0;
    nodoNuevo->datos = dato;
    return nodoNuevo;
}

void insertarListaVaciaDoble(listaDoble *listaVacia,int dato, void *info){
    nodoDoble *nodoNuevo = inicializarNodoDoble(nodoNuevo,info);
    nodoNuevo->posicion = dato;
    nodoNuevo->anterior = NULL;
    nodoNuevo->siguente = NULL;
    listaVacia->primero = nodoNuevo;
    listaVacia->ultimo = nodoNuevo;
    listaVacia->tamano++;
}

void insertarNodoInicioDoble(listaDoble *listaParametro,int dato, void *info){
    nodoDoble *nodoNuevo = inicializarNodoDoble(nodoNuevo,info);
    if(listaParametro->primero==NULL&&listaParametro->ultimo==NULL){
        insertarListaVaciaDoble(listaParametro,dato,info);
    }else{
        nodoNuevo->posicion = dato;
        nodoNuevo->anterior = NULL;
        nodoNuevo->siguente = listaParametro->primero;
        listaParametro->primero->anterior = nodoNuevo;
        listaParametro->primero = nodoNuevo;
        listaParametro->tamano++;
    }
}

void insertarNodoFinalDoble(listaDoble *listaParametro,int dato, void *info){
    nodoDoble *nodoNuevo = inicializarNodoDoble(nodoNuevo,info);
    if(listaParametro->primero==NULL&&listaParametro->ultimo==NULL){
        insertarListaVaciaDoble(listaParametro,dato,info);
    }else{
        nodoNuevo->posicion = dato;
        nodoNuevo->siguente = NULL;
        nodoNuevo->anterior = listaParametro->ultimo;
        listaParametro->ultimo->siguente = nodoNuevo;
        listaParametro->ultimo = nodoNuevo;
        listaParametro->tamano++;
    }
}

void insertarPosicionDespuesXDoble(listaDoble *listaParametro,int dato,nodoDoble *nodoActual, void *info){
    nodoDoble *nodoNuevo = inicializarNodoDoble(nodoNuevo,info);
    if(listaParametro->primero==NULL&&listaParametro->ultimo==NULL){
        insertarListaVaciaDoble(listaParametro,dato,info);
    }else{
        if(listaParametro->primero==listaParametro->ultimo||nodoActual==listaParametro->ultimo){
            insertarNodoFinalDoble(listaParametro,dato,info);
        }else{
                nodoNuevo->posicion = dato;
                nodoNuevo->siguente = nodoActual->siguente;
                nodoNuevo->anterior = nodoActual;
                nodoActual->siguente->anterior = nodoNuevo;
                nodoActual->siguente = nodoNuevo;
                listaParametro->tamano++;
        }
    }
}

nodoDoble* eliminarNodoPrimeroDoble(listaDoble *listaParametro){
    nodoDoble *eliminado = listaParametro->primero;
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

nodoDoble* eliminarNodoUltimoDoble(listaDoble *listaParametro){
   nodoDoble *eliminado = listaParametro->ultimo;
   if(listaParametro->ultimo!=NULL){
       if(listaParametro->primero==listaParametro->ultimo){
           listaParametro->primero = NULL;
           listaParametro->ultimo = NULL;
           listaParametro->tamano--;
       }else {
          listaParametro->ultimo->anterior->siguente = NULL;
          listaParametro->ultimo = listaParametro->ultimo->anterior;
          listaParametro->tamano--;
       }
       eliminado->siguente = NULL;
       eliminado->anterior = NULL;

    }
   return eliminado;

}

nodoDoble* eliminarNodoPosicionXDoble(listaDoble *listaParametro,nodoDoble *eliminado){
    if(listaParametro->primero!=NULL){
           if(listaParametro->primero==listaParametro->ultimo){
               listaParametro->primero = NULL;
               listaParametro->ultimo = NULL;
               listaParametro->tamano--;
           }else if(eliminado==listaParametro->ultimo){
                    eliminarNodoUltimoDoble(listaParametro);
            }else if(eliminado==listaParametro->primero){
                        eliminarNodoPrimeroCircular(listaParametro);
            }else{

                        eliminado->anterior->siguente = eliminado->siguente;
                        eliminado->siguente->anterior = eliminado->anterior;
            }
        }
        eliminado->siguente = NULL;
        eliminado->anterior = NULL;

   return eliminado;
}

nodoDoble* buscarNodoDoble(listaDoble *listaParametro, int posicion){
    nodoDoble *busqueda = listaParametro->primero;
    while(busqueda=NULL){
        if(busqueda->posicion==posicion){
            return busqueda;
        }
        busqueda = busqueda->siguente;
    }
    return busqueda;
}

void mostrarListaPrimeroDoble(listaDoble *listaParametro){
    nodoDoble *busqueda = listaParametro->primero;
    while(busqueda!=NULL){
          printf("Posicion: %i \n",busqueda->posicion);
        busqueda = busqueda->siguente;
    }
     printf("Tamaño: %i \n",listaParametro->tamano );
}

void mostrarListaUltimoDoble(listaDoble *listaParametro){
    nodoDoble *busqueda = listaParametro->ultimo;
    while(busqueda!=NULL){
      printf("Posicion: %i \n",busqueda->posicion);
        busqueda = busqueda->anterior;
    }
    printf("Tamaño: %i \n",listaParametro->tamano );
}



