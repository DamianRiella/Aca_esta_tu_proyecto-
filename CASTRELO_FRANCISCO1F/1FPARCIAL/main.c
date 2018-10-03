#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#define CANT 3

int main()
{

    eCliente Clientes[CANT];
    eJuego Juegos[CANT];
    eAlquiler Alquileres[CANT*2];
    int nOpcion;
    int nSubOpcion;

    fun_InicializarJuegos(Juegos,CANT);
    fun_InicializarClientes(Clientes,CANT);

do{
        printf("1)Juegos\n2)Clientes\n4)Salir\nIngrese Opcion: ");
        fflush(stdin);
        scanf("%d",&nOpcion);

        while(!fun_ValidarRangoINT(nOpcion,2,0)){
        printf("Opcion Incorrecta, Reingrese: ");
        fflush(stdin);
        scanf("%d",&nOpcion);
        }

        switch(nOpcion){

        case 1:     printf("1.Alta\n2.Modificacion\n3.Baja\n4.Listar\n5.Atras\nIngrese Opcion: ");
                    fflush(stdin);
                    scanf("%d",&nSubOpcion);
                    while(!fun_ValidarRangoINT(nSubOpcion,5,0)){
                    printf("Opcion Incorrecta, Reingrese: ");
                    fflush(stdin);
                    scanf("%d",&nSubOpcion);
                    }
                    switch(nSubOpcion){

                    case 1: fun_AltaJuego(Juegos,CANT);
                            break;

                    case 2: fun_ModificarJuego(Juegos,CANT);
                            break;
                    case 3: fun_BajaJuego(Juegos,CANT);
                            break;
                    case 4: fun_listarJuegos(Juegos,CANT);
                            break;
                    case 5:
                            break;
                    }

                break;



        case 2:     printf("1.Alta\n2.Modificacion\n3.Baja\n4.Listar\n5.Atras\nIngrese Opcion: ");
                    fflush(stdin);
                    scanf("%d",&nSubOpcion);
                    while(!fun_ValidarRangoINT(nSubOpcion,5,0)){
                    printf("Opcion Incorrecta, Reingrese: ");
                    fflush(stdin);
                    scanf("%d",&nSubOpcion);
                    }
                    switch(nSubOpcion){

                    case 1: fun_AltaCliente(Clientes,CANT);
                            break;

                    case 2: fun_ModificarCliente(Clientes,CANT);
                            break;
                    case 3: fun_BajaCliente(Clientes,CANT);
                            break;
                    case 4: fun_listarClientes(Clientes,CANT);
                            break;
                    case 5:
                            break;
                    }
                break;

        }

}while(nOpcion!=4);
    return 0;
}
