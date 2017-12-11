#include <stdio.h>
#include <stdlib.h>
#include "listadoble.h"

int main()
{
    listaDoble *Lista = (listaDoble*)malloc(sizeof(listaDoble*));
    inicializarListaDoble(Lista);
    int opcionMenu = 0;
    int contadorPosicion = 0;

    while(opcionMenu!=4){
        printf("********** Menu **********\n\n");
        printf("1. Insertar nodo\n");
        printf("2. eliminar nodo\n");
        printf("3. Mostrar Lista\n");
        printf("4. Salir del sistema\n");
        printf("\nSelecione una opcion:\n");
        scanf("%i",&opcionMenu);

        if(opcionMenu>0 && opcionMenu<5){
            switch(opcionMenu)
            {
                case 1:
                    printf("\nIngreso algo para guardar:\n");
                    char *cadena = (char*)malloc(sizeof(char)*50);
                    scanf("%s",cadena);
                    insertarNodoFinalDoble(Lista,contadorPosicion,cadena);
                    printf("\nDato ingresado :)\n");
                    setbuf(stdin,NULL);
                    contadorPosicion++;
                    system("pause");
                    break;
                case 2:
                    printf("\n**** Lista ****\n");
                    mostrarListaPrimeroDoble(Lista);
                    printf("***************\n");
                    printf("Ingresa el dato que quierres borrar:\n");
                    char *clear = (char*)malloc(sizeof(char)*50);
                    scanf("%s",clear);
                    nodoDoble *eliminar = buscarNodoDoble(Lista,clear);
                    if(eliminar==0){
                        printf("Dato no existe\n");
                    }else{
                        eliminarNodoPosicionXDoble(Lista,eliminar);
                        printf("Dato borrado\n");
                    }
                    system("pause");
                    break;
                case 3:
                    mostrarListaPrimeroDoble(Lista);
                    system("pause");
                    break;
            }
        }else{
            printf("Opcion no validad\n");
            setbuf(stdin,NULL);
            system("pause");
        }

        system("cls");
    }
    printf("\nAdios :3\n");
    return 0;
}
