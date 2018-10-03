#include "Lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 50
#define MAXTEL 21
#define MINFLOAT 1

/*Desarrollos*/

/**************INICIALIZAR*********************/
void fun_InicializarClientes(eCliente Clientes[], int nCantidadClientes){

    int i;

    for(i=0;i<nCantidadClientes;i++){

        Clientes[i].isEmpty=0;

    }
}

void fun_InicializarJuegos(eJuego Juegos[], int nCantidadJuegos){

    int i;

    for(i=0;i<nCantidadJuegos;i++){

        Juegos[i].isEmpty=0;
    }

}
/*********************************************/

int fun_BuscarLibreCliente(eCliente Clientes[],int nCantidadClientes){

int Retorno=-1;
int i;

    for(i=0;i<nCantidadClientes;i++){

        if(Clientes[i].isEmpty==0){

            Retorno=i;
            break;
        }
    }


return Retorno;
}

int fun_BuscarLibreJuegos(eJuego Juegos[],int nCantidadJuegos){

int Retorno=-1;
int i;

    for(i=0;i<nCantidadJuegos;i++){

        if(Juegos[i].isEmpty==0){

            Retorno=i;
            break;
        }
    }


return Retorno;

}

int fun_BuscarIDJuego(eJuego Juegos[],int nIDaBuscar,int nCantidadJuegos){

int retorno =-1;
int i;

    for(i=0;i<nCantidadJuegos;i++){

        if(nIDaBuscar==Juegos[i].nCodigoJuego){

            retorno=i;
            break;
        }

    }

return retorno;
}

int fun_buscarIDCliente(eCliente Clientes[],int nIDaBuscar ,int nCantidadClientes){

    int retorno =-1;
int i;

    for(i=0;i<nCantidadClientes;i++){

        if(nIDaBuscar==Clientes[i].nCodigoCliente){

            retorno=i;
            break;
        }

    }

return retorno;

}
/********************ALTAS********************/
int fun_AltaJuego(eJuego Juego[],int nCantidadJuegos){

    char auxDescripcion[80];
    float auxImporte;
    int index;

    index=fun_BuscarLibreJuegos(Juego,nCantidadJuegos);
    if(index==-1){
        printf("No Hay Espacio Disponible");
    }else{

    Juego[index].nCodigoJuego=index+1;
    Juego[index].isEmpty=1;

    printf("Ingresar Descripcion del Juego: ");
    fflush(stdin);
    gets(auxDescripcion);

    while(fun_ValidarString(auxDescripcion,MAXCHAR)!=1){

        printf("Descripcion demasiada larga!\nReingrese: ");
        gets(auxDescripcion);

    }
    strcpy(Juego[index].szDescripcion,auxDescripcion);

    printf("Ingresar Importe: ");
    fflush(stdin);
    scanf("%f", &auxImporte);

    while(fun_ValidarFloat(auxImporte,MINFLOAT)!=1){

        printf("Debe ser Mayor a cero!\nReingrese: ");
        fflush(stdin);
        scanf("%f", &auxImporte);
    }
    Juego[index].fImporte=auxImporte;


    }//else
}

int fun_AltaCliente(eCliente Cliente[], int nCantidadClientes){

    int index;
    char auxString[70];

    index=fun_BuscarLibreCliente(Cliente,nCantidadClientes);

    if(index==-1){
        printf("No hay espacio disponible!");
    }else{

        Cliente[index].nCodigoCliente=index+1;
        Cliente[index].isEmpty=1;

    printf("Ingresar nombre del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXCHAR)!=1){

        printf("Nombre demasiado largo!\nReingrese: ");
        gets(auxString);

    }

    strcpy(Cliente[index].szNombre,auxString);

    printf("Ingresar apellido del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXCHAR)!=1){

        printf("Apellido demasiado largo!\nReingrese: ");
        gets(auxString);

    }

    strcpy(Cliente[index].szApellido,auxString);

    printf("Ingresar domicilio del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXCHAR)!=1){

        printf("Domicilio demasiado largo!\nReingrese: ");
        gets(auxString);

    }
    strcpy(Cliente[index].szDomicilio,auxString);

    printf("Ingresar numero telefonico del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXTEL)!=1){

        printf("Numero Telefonico demasiado largo!\nReingrese: ");
        gets(auxString);

    }
    strcpy(Cliente[index].szTelefono,auxString);

    }//else
}

int fun_AltaAlquiler(eCliente Cliente[],eJuego Juego[],int nCantidadClientes,int nCantidadJuegos){

    int auxIDCliente;
    int auxIDJuego;
    int indexJuego;
    int indexCliente;

    printf("Ingrese ID de Juego a alquilar: ");
    fflush(stdin);
    scanf("%d", &auxIDJuego);
    indexJuego=fun_BuscarIDJuego(Juego,auxIDJuego,nCantidadJuegos);

    if(indexJuego!=-1){
        printf("ID de juego encontada!");
    }

    printf("Ingrese ID de Cliente a buscar: ");
    fflush(stdin);
    scanf("%d", &auxIDCliente);

    indexCliente=fun_buscarIDCliente(Cliente,auxIDCliente,nCantidadClientes);

    if(index!=-1){
    printf("ID Cliente encontrada!\n");
    }

    Cliente[indexCliente].nCodigoCliente=Al
}
/********************************************/


/********************MODIFICACION********************/
void fun_ModificarJuego(eJuego Juego[],int nCantidadJuegos){

int index;
int auxIDJuego;
char auxDescripcion[80];
float auxFloat;

    printf("Ingrese ID de Juego a buscar: ");
    fflush(stdin);
    scanf("%d", &auxIDJuego);
    index=fun_BuscarIDJuego(Juego,auxIDJuego,nCantidadJuegos);

    if(index!=-1){
    printf("ID de juego encontrada!\n");

    printf("Ingrese Nueva Descripcion: ");
    fflush(stdin);
    gets(auxDescripcion);


    while(fun_ValidarString(auxDescripcion,MAXCHAR)!=1){

        printf("Descripcion demasiada larga!\Reingrese: ");
        fflush(stdin);
        gets(auxDescripcion);
    }

    strcpy(Juego[index].szDescripcion,auxDescripcion);

    printf("Ingrese nuevo Importe: ");
    fflush(stdin);
    scanf("%f", &auxFloat);

    while(fun_ValidarFloat(auxFloat,MINFLOAT)!=1){

        printf("Debe ser Mayor a cero!\nReingrese: ");
        scanf("%f", &auxFloat);
    }
    Juego[index].fImporte=auxFloat;

    }else{
    printf("No se encontro la ID!");
    }


}


void fun_ModificarCliente(eCliente Cliente[], int nCantidadClientes){

int index;
int IDbuscar;
char auxString[80];

    printf("Ingrese ID a buscar: ");
    fflush(stdin);
    scanf("%d", &IDbuscar);

    index=fun_buscarIDCliente(Cliente,IDbuscar,nCantidadClientes);

    if(index!=-1){
    printf("ID encontrada!\n");

printf("Ingresar nombre del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXCHAR)!=1){

        printf("Nombre demasiado largo!\nReingrese: ");
        gets(auxString);

    }

    strcpy(Cliente[index].szNombre,auxString);

    printf("Ingresar apellido del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXCHAR)!=1){

        printf("Apellido demasiado largo!\nReingrese: ");
        gets(auxString);

    }

    strcpy(Cliente[index].szApellido,auxString);

    printf("Ingresar domicilio del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXCHAR)!=1){

        printf("Domicilio demasiado largo!\nReingrese: ");
        gets(auxString);

    }
    strcpy(Cliente[index].szDomicilio,auxString);

    printf("Ingresar numero telefonico del Cliente: ");
    fflush(stdin);
    gets(auxString);

    while(fun_ValidarString(auxString,MAXTEL)!=1){

        printf("Numero Telefonico demasiado largo!\nReingrese: ");
        gets(auxString);

    }
    strcpy(Cliente[index].szTelefono,auxString);



    }else{

    printf("ID no encontrada!");
    }

}
/****************************************************/

/**********************BAJAS************************/
void fun_BajaJuego(eJuego Juegos[],int nCantidadJuegos){

int IDbuscar;
int index;

    printf("Ingrese ID de juego a dar de baja: ");
    fflush(stdin);
    scanf("%d", &IDbuscar);
    index=fun_BuscarIDJuego(Juegos,IDbuscar,nCantidadJuegos);
    if(index!=-1){
    printf("Juego Dado de baja con exito!\n");
    Juegos[index].isEmpty=0;

    }else{
    printf("No se encontro la ID!");
    }

}

void fun_BajaCliente(eCliente Clientes[],int nCantidadClientes){

int IDbuscar;
int index;

    printf("Ingrese ID de Cliente a dar de baja: ");
    fflush(stdin);
    scanf("%d", &IDbuscar);
    index=fun_buscarIDCliente(Clientes,IDbuscar,nCantidadClientes);
    if(index!=-1){
    printf("Cliente Dado de baja con exito!\n");
    Clientes[index].isEmpty=0;

    }else{
    printf("No se encontro la ID!");
    }
}
/***************************************************/

/**********************LISTAR************************/
void fun_listarJuegos(eJuego Juegos[],int nCantidadJuegos){

    int i;

    for(i=0;i<nCantidadJuegos;i++){

        if(Juegos[i].isEmpty==1){

            printf("%d\t%s\t%.2f\n",Juegos[i].nCodigoJuego,Juegos[i].szDescripcion,Juegos[i].fImporte);
        }

    }

}

void fun_listarClientes(eCliente Clientes[],int nCantidadClientes){

    int i;

    for(i=0;i<nCantidadClientes;i++){

        if(Clientes[i].isEmpty==1){

            printf("%d\t%s\t%s\t%s\nTelefono: %s\n",Clientes[i].nCodigoCliente,Clientes[i].szNombre,Clientes[i].szApellido,Clientes[i].szDomicilio, Clientes[i].szTelefono);
        }

    }

}
/****************************************************/

/********************VALIDAR********************/

int fun_ValidarString(char szCadena[],int nCantMaxCaracteres){

    int retorno=0;

    if(strlen(szCadena)<nCantMaxCaracteres){

        retorno=1;
    }else{

        retorno =-1;
    }

return retorno;
}

int fun_ValidarFloat(float fNumValidar, float nNumMinimo){

int retorno=0;

if(fNumValidar>=nNumMinimo){

    retorno=1;
}else{

    retorno=-1;
}

return retorno;
}

int fun_ValidarRangoINT(int Numero, int Maximo, int Minimo){

int retorno=-1;

    if(Numero<Maximo && Numero>Minimo){

        retorno=1;

    }

return retorno;
}
/***********************************************/
