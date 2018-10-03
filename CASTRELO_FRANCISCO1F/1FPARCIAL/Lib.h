/* Prototipo y Estructuras*/

typedef struct{

int nCodigoJuego;
char szDescripcion[50];
float fImporte;
int isEmpty;

}eJuego;
/***********************************/
typedef struct{

int nCodigoCliente;
char szApellido[50];
char szNombre[50];
char szDomicilio[50];
char szTelefono[50];
int isEmpty;

}eCliente;
/***********************************/
typedef struct{

int nCodigoDeAlquiler;
int nCodigoDeJuego;
int nCodigoDeCliente;
//eFecha Fecha;
int isEmpty

}eAlquiler;
/***********************************/
typedef struct{

int nDia;
int nMes;
int nAnio;

}eFecha;
/***********************************/

/**************INICIALIZAR*********************/
void fun_InicializarClientes(eCliente[],int);
void fun_InicializarJuegos(eJuego[],int);
void fun_InicializarAlquiler(eAlquiler[],int);
/*********************************************/

int fun_BuscarIDCliente(eCliente[],int,int);
int fun_BuscarLibreCliente(eCliente[],int);
int fun_BuscarLibreJuegos(eJuego[],int);
int fun_BuscarIDJuego(eJuego[],int,int);

/********************ALTAS********************/
int fun_AltaJuego(eJuego[],int);
int fun_AltaCliente(eCliente[],int);
int fun_AltaAlquiler(eCliente[],eJuego[],int,int);
/*********************************************/


/********************MODIFICACION********************/
void fun_ModificarJuego(eJuego[],int);
void fun_ModificarCliente(eCliente[],int);
/****************************************************/

/**********************BAJAS************************/
void fun_BajaJuego(eJuego[],int);
void fun_BajaCliente(eCliente[],int);
/***************************************************/



/**********************LISTAR************************/

void fun_listarJuegos(eJuego[],int);
void fun_listarClientes(eCliente[],int);
/****************************************************/


/********************VALIDAR********************/

int fun_ValidarString(char[],int);
int fun_ValidarFloat(float,float);
int fun_ValidarRangoINT(int,int,int);
/***********************************************/
