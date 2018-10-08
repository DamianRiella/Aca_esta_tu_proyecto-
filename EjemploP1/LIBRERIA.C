#include "Libreria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxLetra 50
#define maxTelefono 21
#define minFlotante 1



/**********************************************/
void InicializarClientes(eCliente* Clientes, int CantClientes)
{

    int i;

    for(i=0; i<CantClientes; i++)
    {

        Clientes[i].isEmpty=0;

    }
}

/*********************************************/

void InicializarJuegos(eJuego* Juegos, int CantJuegos)
{

    int i;

    for(i=0; i<CantJuegos; i++)
    {

        Juegos[i].isEmpty=0;

    }
}
/**********************************************/
void InicializarAlquiler(eAlquiler* Alquileres, int CantAlquileres)
{

    int i;

    for(i=0; i<CantAlquileres; i++)
    {

        Alquileres[i].isEmpty=0;

    }
}
/*********************************************************************************/

/*********************************************************************************/
int BuscarLibreCliente(eCliente* Clientes,int CantClientes)
{

    int Retorno=-1;
    int i;

    for(i=0; i<CantClientes; i++)
    {

        if(Clientes[i].isEmpty==0)
        {

            Retorno=i;
            break;
        }
    }


    return Retorno;
}
/****************************************************/

int BuscarLibreJuegos(eJuego* Juegos,int CantJuegos)
{

    int Retorno=-1;
    int i;

    for(i=0; i<CantJuegos; i++)
    {

        if(Juegos[i].isEmpty==0)
        {

            Retorno=i;
            break;
        }
    }


    return Retorno;

}


/*********************************************************/
int BuscarLibreAlquiler(eAlquiler* Alquileres,int CantAlquiler)
{

    int Retorno=-1;
    int i;

    for(i=0; i<CantAlquiler; i++)
    {

        if(Alquileres[i].isEmpty==0)
        {

            Retorno=i;
            break;
        }
    }


    return Retorno;
}
/************************************************************************************/

/************************************************************************************/
int BuscarIDJuego(eJuego* Juegos,int IDaBuscar,int CantJuegos)
{

    int retorno =-1;
    int i;

    for(i=0; i<CantJuegos; i++)
    {

        if(IDaBuscar==Juegos[i].CodigoJuego)
        {

            retorno=i;
            break;
        }

    }

    return retorno;
}
/***************************************************/

int BuscarIDCliente(eCliente* Clientes,int IDaBuscar,int CantClientes)
{

    int retorno =-1;
    int i;

    for(i=0; i<CantClientes; i++)
    {

        if(IDaBuscar==Clientes[i].CodigoCliente)
        {

            retorno=i;
            break;
        }

    }

    return retorno;

}

/**********************************************************/

int BuscarIDAlquiler(eAlquiler* Alquileres,int IDaBuscar,int CantAlquileres)
{

    int retorno =-1;
    int i;

    for(i=0; i<CantAlquileres; i++)
    {

        if(IDaBuscar==Alquileres[i].CodigoDeAlquiler)
        {

            retorno=i;
            break;
        }

    }

    return retorno;

}
/******************************************************************************************/

/******************************************************************************************/
int AltaJuego(eJuego* Juego,int CantJuegos)
{

    char auxDescripcion[80];
    float auxImporte;
    int index;

    index=BuscarLibreJuegos(Juego,CantJuegos);
    if(index==-1)
    {
        printf("No Hay Espacio Disponible.");
        getchar();
    }
    else
    {

        Juego[index].CodigoJuego=index+1;
        Juego[index].isEmpty=1;

        printf("Ingresar Descripcion del Juego: ");
        fflush(stdin);
        gets(auxDescripcion);

        while(ValidarString(auxDescripcion,maxLetra)!=1)
        {

            printf("Descripcion demasiada larga.\nReingrese: ");
            gets(auxDescripcion);

        }
        strcpy(Juego[index].Descripcion,auxDescripcion);

        printf("Ingresar Importe: ");
        fflush(stdin);
        scanf("%f", &auxImporte);

        while(ValidarFloat(auxImporte,minFlotante)!=1)
        {

            printf("Debe ser Mayor a cero.\nReingrese: ");
            fflush(stdin);
            scanf("%f", &auxImporte);
        }
        Juego[index].Valor=auxImporte;

    }//else
    return 0;
}
/*****************************************************/

int AltaCliente(eCliente* Cliente, int CantClientes)
{

    int index;
    char auxString[70];

    index=BuscarLibreCliente(Cliente,CantClientes);

    if(index==-1)
    {
        printf("No hay espacio disponible.");
        getchar();
    }
    else
    {

        Cliente[index].CodigoCliente=index+1;
        Cliente[index].isEmpty=1;

        printf("Ingresar nombre del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxLetra)!=1)
        {

            printf("Nombre demasiado largo.\nReingrese: ");
            gets(auxString);

        }

        strcpy(Cliente[index].Nombre,auxString);

        printf("Ingresar apellido del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxLetra)!=1)
        {

            printf("Apellido demasiado largo.\nReingrese: ");
            gets(auxString);

        }

        strcpy(Cliente[index].Apellido,auxString);

        printf("Ingresar domicilio del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxLetra)!=1)
        {

            printf("Domicilio demasiado largo.\nReingrese: ");
            gets(auxString);

        }
        strcpy(Cliente[index].Domicilio,auxString);

        printf("Ingresar numero telefonico del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxTelefono)!=1)
        {

            printf("Numero Telefonico demasiado largo.\nReingrese: ");
            gets(auxString);

        }
        strcpy(Cliente[index].Telefono,auxString);

    }
    return 0;

}
/******************************************************/

int AltaAlquiler(eAlquiler* Alquileres, eCliente* Cliente,eJuego* Juego,int CantAlquileres,int CantClientes,int CantJuegos)
{

    int auxIDCliente;
    int auxIDJuego;
    int indexJuego;
    int indexCliente;
    int indexAlquileres;
    int dia, mes, anio;

    indexAlquileres=BuscarLibreAlquiler(Alquileres,CantAlquileres);

    if(indexAlquileres==-1)
    {
        printf("No hay espacio disponible.");
        getchar();
    }
    else
    {
        Alquileres[indexAlquileres].CodigoDeAlquiler=indexAlquileres+1;
        Alquileres[indexAlquileres].isEmpty=1;

        printf("Ingrese dia(1-31):\n");
        fflush(stdin);
        scanf("%d",&dia);
        if(dia<=31 && dia>0)
        {
            Alquileres[indexAlquileres].Fecha.Dia=dia;

            printf("Ingrese mes(1-12):\n");
            fflush(stdin);
            scanf("%d",&mes);
            if(mes<=12 && mes>0)
            {
                Alquileres[indexAlquileres].Fecha.Mes=mes;

                printf("Ingrese anio(Ej:1990):\n");
                fflush(stdin);
                scanf("%d",&anio);
                if(anio<=2018 && anio>1990)
                {
                    Alquileres[indexAlquileres].Fecha.Anio=anio;
                }
                else
                {
                    printf("Error. Anio invalido.\n");
                    getchar();
                }

            }
             else
                {
                    printf("Error. Mes invalido.\n");
                    getchar();
                }
        }
         else
                {
                    printf("Error. Dia invalido.\n");
                    getchar();
                }


        printf("Ingrese ID de Juego a alquilar: ");
        fflush(stdin);
        scanf("%d", &auxIDJuego);
        indexJuego=BuscarIDJuego(Juego,auxIDJuego,CantJuegos);

        if(indexJuego!=-1)
        {
            printf("\nID de juego encontrada.\n");

            Alquileres[indexJuego].CodigoDeJuego=indexJuego;

            printf("\nIngrese ID de Cliente a buscar: ");
            fflush(stdin);
            scanf("%d", &auxIDCliente);
            indexCliente=BuscarIDCliente(Cliente,auxIDCliente,CantClientes);

            if(indexCliente!=-1)
            {
                printf("\nID Cliente encontrada.\n");

                Alquileres[indexCliente].CodigoDeCliente=indexCliente;
            }
            else
            {
                printf("ID Cliente no encontrado.\n");
                getchar();
            }

        }
        else
        {
            printf("ID Juego no encontrado.\n");
            getchar();
        }
    }

        return 0;

}

/*************************************************************************************/

/************************************************************************************/
void ModificarJuego(eJuego* Juego,int CantJuegos)
{

    int index;
    int auxIDJuego;
    char auxDescripcion[80];
    float auxFloat;

    printf("Ingrese ID de Juego a buscar: ");
    fflush(stdin);
    scanf("%d", &auxIDJuego);
    index=BuscarIDJuego(Juego,auxIDJuego,CantJuegos);

    if(index!=-1)
    {
        printf("ID de juego encontrada.\n");

        printf("Ingrese Nueva Descripcion: ");
        fflush(stdin);
        gets(auxDescripcion);


        while(ValidarString(auxDescripcion,maxLetra)!=1)
        {

            printf("Descripcion demasiada larga.\nReingrese: ");
            fflush(stdin);
            gets(auxDescripcion);
        }

        strcpy(Juego[index].Descripcion,auxDescripcion);

        printf("Ingrese nuevo Importe: ");
        fflush(stdin);
        scanf("%f", &auxFloat);

        while(ValidarFloat(auxFloat,minFlotante)!=1)
        {

            printf("Debe ser Mayor a cero.\nReingrese: ");
            scanf("%f", &auxFloat);
        }
        Juego[index].Valor=auxFloat;

    }
    else
    {
        printf("No se encontro ID.");
        getchar();
    }


}

/*****************************************************/

void ModificarCliente(eCliente* Cliente, int CantClientes)
{

    int index;
    int IDbuscar;
    char auxString[80];

    printf("Ingrese ID a buscar: ");
    fflush(stdin);
    scanf("%d", &IDbuscar);

    index=BuscarIDCliente(Cliente,IDbuscar,CantClientes);

    if(index!=-1)
    {
        printf("ID encontrada.\n");

        printf("Ingresar nombre del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxLetra)!=1)
        {

            printf("Nombre demasiado largo.\nReingrese: ");
            gets(auxString);

        }

        strcpy(Cliente[index].Nombre,auxString);

        printf("Ingresar apellido del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxLetra)!=1)
        {

            printf("Apellido demasiado largo.\nReingrese: ");
            gets(auxString);

        }

        strcpy(Cliente[index].Apellido,auxString);

        printf("Ingresar domicilio del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxLetra)!=1)
        {

            printf("Domicilio demasiado largo.\nReingrese: ");
            gets(auxString);

        }
        strcpy(Cliente[index].Domicilio,auxString);

        printf("Ingresar numero telefonico del Cliente: ");
        fflush(stdin);
        gets(auxString);

        while(ValidarString(auxString,maxTelefono)!=1)
        {

            printf("Numero Telefonico demasiado largo.\nReingrese: ");
            gets(auxString);

        }
        strcpy(Cliente[index].Telefono,auxString);



    }
    else
    {

        printf("ID no encontrada.");
        getchar();
    }

}
/**************************************************************************************/

/*************************************************************************************/
void BajaJuego(eJuego* Juegos,int CantJuegos)
{

    int IDbuscar;
    int index;

    printf("Ingrese ID de juego a dar de baja: ");
    fflush(stdin);
    scanf("%d", &IDbuscar);
    index=BuscarIDJuego(Juegos,IDbuscar,CantJuegos);
    if(index!=-1)
    {
        printf("Juego Dado de baja con exito.\n");
        Juegos[index].isEmpty=0;
        getchar();

    }
    else
    {
        printf("No se encontro ID.");
        getchar();
    }

}

/******************************************************/

void BajaCliente(eCliente* Clientes,int CantClientes)
{

    int IDbuscar;
    int index;

    printf("Ingrese ID de Cliente a dar de baja: ");
    fflush(stdin);
    scanf("%d", &IDbuscar);
    index=BuscarIDCliente(Clientes,IDbuscar,CantClientes);
    if(index!=-1)
    {
        printf("Cliente Dado de baja con exito.\n");
        Clientes[index].isEmpty=0;

    }
    else
    {
        printf("No se encontro ID.");
        getchar();
    }
}
/*************************************************************************************/

/*************************************************************************************/
void listarJuegos(eJuego* Juegos,int CantJuegos)
{

    int i;

        printf("ID    | NOMBRE | VALOR\n\n");

    for(i=0; i<CantJuegos; i++)
    {

        if(Juegos[i].isEmpty==1)
        {

            printf("%d\t%s\t%.2f\n",Juegos[i].CodigoJuego,Juegos[i].Descripcion,Juegos[i].Valor);
            getchar();
        }

    }

}

/***********************************************************/
void listarClientes(eCliente* Clientes,int CantClientes)
{

    int i;

    printf("ID     |NOMBRE|APELLIDO|DOMICILIO|TELEFONO\n\n");

    for(i=0; i<CantClientes; i++)
    {

        if(Clientes[i].isEmpty==1)
        {

            printf("%d\t%s\t%s\t%s\t%s\n",Clientes[i].CodigoCliente,Clientes[i].Nombre,Clientes[i].Apellido,Clientes[i].Domicilio, Clientes[i].Telefono);
            getchar();
        }

    }

}
/*********************************************************************************************/

/*********************************************************************************************/

int ValidarString(char* Cadena,int CantMaxCarac)
{

    int retorno=-1;

    if(strlen(Cadena)<CantMaxCarac)
    {

        retorno=1;
    }


    return retorno;
}
/*******************************************************/

int ValidarFloat(float NumValidar, float NumMinimo)
{

    int retorno=-1;

    if(NumValidar>=NumMinimo)
    {

        retorno=1;
    }


    return retorno;
}

/**********************************************************/

int ValidarEntero(int Num, int Max, int Min)
{

int retorno=-1;

    if(Num<Max && Num>Min){

        retorno=1;

    }

return retorno;
}


