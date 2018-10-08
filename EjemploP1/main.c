#include <stdio.h>
#include <stdlib.h>
#include "Libreria.h"
#define CANT_JUEGO 20
#define CANT_CLIENTE 100
#define CANT_ALQUILER 2000

int main()
{

    eCliente Clientes[CANT_CLIENTE];
    eJuego Juegos[CANT_JUEGO];
    eAlquiler Alquileres[CANT_ALQUILER];
    int opc1;
    int opc2;

    InicializarJuegos(Juegos,CANT_JUEGO);
    InicializarClientes(Clientes,CANT_CLIENTE);
    InicializarAlquiler(Alquileres,CANT_ALQUILER);

do{
        system("cls");
        printf("1_Juegos\n2_Clientes\n3_Alquileres\n4_Salir\n\nIngrese Opcion: ");
        fflush(stdin);
        scanf("%d",&opc1);

        while(!ValidarEntero(opc1,2,0)){
        printf("\nOpcion Incorrecta, Reingrese:\n ");
        fflush(stdin);
        scanf("%d",&opc1);
        }

        switch(opc1)
        {

        case 1://******Menu Juegos****/
                system("cls");
               printf("1_Alta\n2_Modificacion\n3_Baja\n4_Listar\n5_Atras\n\nIngrese Opcion: ");
                    fflush(stdin);
                    scanf("%d",&opc2);
                    while(!ValidarEntero(opc2,5,0)){
                    printf("\nOpcion Incorrecta, Reingrese:\n ");
                    fflush(stdin);
                    scanf("%d",&opc2);
                    }
                    switch(opc2){

                    case 1:
                            system("cls");
                            AltaJuego(Juegos,CANT_JUEGO);
                            break;

                    case 2:
                            system("cls");
                            ModificarJuego(Juegos,CANT_JUEGO);
                            break;
                    case 3:
                            system("cls");
                            BajaJuego(Juegos,CANT_JUEGO);
                            break;
                    case 4:
                            system("cls");
                            listarJuegos(Juegos,CANT_JUEGO);
                            getchar();
                            break;
                    case 5:
                            break;
                    }

                break;



        case 2://******Menu Clientes****/
                system("cls");
                printf("1_Alta\n2_Modificacion\n3_Baja\n4_Listar\n5_Atras\n\nIngrese Opcion: ");
                    fflush(stdin);
                    scanf("%d",&opc2);
                    while(!ValidarEntero(opc2,5,0)){
                    printf("\nOpcion Incorrecta, Reingrese:\n ");
                    fflush(stdin);
                    scanf("%d",&opc2);
                    }
                    switch(opc2){

                    case 1:
                            system("cls");
                            AltaCliente(Clientes,CANT_CLIENTE);
                            break;

                    case 2:
                            system("cls");
                            ModificarCliente(Clientes,CANT_CLIENTE);
                            break;
                    case 3:
                            system("cls");
                            BajaCliente(Clientes,CANT_CLIENTE);
                            break;
                    case 4:
                            system("cls");
                            listarClientes(Clientes,CANT_CLIENTE);
                            getchar();
                            break;
                    case 5:
                            break;
                    }
                break;

        case 3://*******Alta de Alquileres***********/
                system("cls");
                AltaAlquiler(Alquileres,Clientes,Juegos,CANT_ALQUILER,CANT_CLIENTE,CANT_JUEGO);
                getchar();
                break;

        }

}while(opc1!=4);
    return 0;
}

