


typedef struct{

int CodigoJuego;
char Descripcion[50];
float Valor;
int isEmpty;

}eJuego;
/***********************************/
typedef struct{

int CodigoCliente;
char Apellido[50];
char Nombre[50];
char Domicilio[50];
char Telefono[50];
int isEmpty;

}eCliente;

/***********************************/
typedef struct{

int Dia;
int Mes;
int Anio;

}eFecha;
/***********************************/
typedef struct{

int CodigoDeAlquiler;
int CodigoDeJuego;
int CodigoDeCliente;
eFecha Fecha;
int isEmpty;

}eAlquiler;
/**********************************************/

/**********************************************/
/** \brief Inicializa todas la pociciones de la variable cliente en 0.
 *
 * \param Array de cliente.
 * \param Cantidad maxima de cliente.
 * \return
 *
 */
void InicializarClientes(eCliente*,int);

/** \brief Inicializa todas la pociciones de la variable juegos en 0.
 *
 * \param Array de juegos.
 * \param Cantidad maxima de juegos.
 * \return
 *
 */
void InicializarJuegos(eJuego*,int);

/** \brief Inicializa todas la pociciones de la variable alquileres en 0.
 *
 * \param Array de alquileres.
 * \param Cantidad maxima de alquileres..
 * \return
 *
 */
void InicializarAlquiler(eAlquiler*,int);
/**********************************************/

/**********************************************/
/** \brief Busca el ID ingresado en el array de clientes y retorna su pocicion si lo encuentra
 *
 * \param Array de clientes.
 * \param ID a buscar.
 * \param Cantidad maxima de clientes.
 * \return Retorna la posicion del primer espacio vacio que encuentra o si no retorna -1.
 *
 */
int BuscarIDCliente(eCliente*,int,int);

/** \brief Busca el primer espacio libre que aparesca en el array de clientes.
 *
 * \param Array de cliente
 * \param Cantidad maxima de clientes
 * \return Retorna la posicion del primer espacio vacio que encuentra o si no retorna -1.
 *
 */
int BuscarLibreCliente(eCliente*,int);

/** \brief Busca el primer espacio libre que aparesca en el array de juegos.
 *
 * \param Array de juegos.
 * \param Cantidad maxima de juegos.
 * \return Retorna la posicion del primer espacio vacio que encuentra o si no retorna -1.
 *
 */
int BuscarLibreJuegos(eJuego*,int);

/** \brief Busca el ID ingresado en el array de juegos y retorna su pocicion si lo encuentra
 *
 * \param Array de juegos.
 * \param ID a buscar.
 * \param Cantidad maxima de juegos.
 * \return Retorna su posicion si lo encuentra o si no retorna -1.
 *
 */
int BuscarIDJuego(eJuego*,int,int);

/** \brief Busca el primer espacio libre que aparesca en el array de alquileres.
 *
 * \param Array de alquileres.
 * \param Cantidad maxima de alquileres.
 * \return Retorna la posicion del primer espacio vacio que encuentra o si no retorna -1.
 */
int BuscarLibreAlquiler(eAlquiler*,int);

/** \brief  Busca el ID ingresado en el array de alquilers y retorna su pocicion si lo encuentra
 *
 * \param Array de alquileres.
 * \param ID a buscar.
 * \param Cantidad maxima de alquileres.
 * \return Retorna su posicion si lo encuentra o si no retorna -1.
 *
 */
int BuscarIDAlquiler(eAlquiler*,int,int);
/**********************************************/

/**********************************************/
/** \brief Da de alta un juego.
 *
 * \param Array de juego.
 * \param Cantidad maxima de Juegos.
 * \return
 *
 */
int AltaJuego(eJuego*,int);

/** \brief Da de alta un cliente.
 *
 * \param Array de cliente.
 * \param Cantidad maxima de clientes.
 * \return
 *
 */
int AltaCliente(eCliente*,int);

/** \brief Da de alta un alquiler.
 *
 * \param Array de alquiler
 * \param Cantidad maxima de alquiler.
 * \return
 *
 */
int AltaAlquiler(eAlquiler*,eCliente*,eJuego*,int,int,int);
/**********************************************/


/**********************************************/
/** \brief Permite hacer modificaciones a juegos dados de alta.
 *
 * \param Array de juego.
 * \param Cantidad maxima de juegos.
 * \return
 *
 */
void ModificarJuego(eJuego*,int);

/** \brief Permite hacer modificaciones a clientes dados de alta.
 *
 * \param Array de clientes.
 * \param Cantidad maxima de clientes.
 * \return
 *
 */
void ModificarCliente(eCliente*,int);
/**********************************************/

/**********************************************/
/** \brief Permite dar de baja un juego, inicializando su posicion en 0.
 *
 * \param Array de juego.
 * \param Cantidad maxima de juego.
 * \return
 *
 */
void BajaJuego(eJuego*,int);

/** \brief Permite dar de baja un cliente, inicializando su posicion en 0.
 *
 * \param Array de cliente.
 * \param Cantidad maxima de cliente.
 * \return
 *
 */
void BajaCliente(eCliente*,int);
/**********************************************/


/**********************************************/
/** \brief Muestra todos los juegos dados de alta en forma de lista.
 *
 * \param Array de Juego.
 * \param Cantidad maxima de juegos.
 * \return
 *
 */
void listarJuegos(eJuego*,int);

/** \brief Muestra todos los clientes dados de alta en forma de lista
 *
 * \param Array de clientes.
 * \param Cantidad maxima de clientes.
 * \return
 *
 */
void listarClientes(eCliente*,int);
/**********************************************/


/**********************************************/
/** \brief Valida el tamaño de la cadena de caracteres ingresada por teclado con la canidad maxima permitida.
 *
 * \param Cadena de caracteres ingresada por teclado.
 * \param Cantidad maxima de caracteres
 * \return Retorna 1 si la cadena es valida y -1 si no lo es.
 *
 */
int ValidarString(char*,int);

/** \brief Valida el tamaño de numero flotante ingresada por teclado con la canidad manima permitida.
 *
 * \param Numero a validar.
 * \param Numero minimo permitido.
 * \return Retorna 1 si la cadena es valida y -1 si no lo es.
 *
 */
int ValidarFloat(float,float);

/** \brief Valida el numero entero ingresado por teclado con los rangos de max y min permitidos.
 *
 * \param Numero a validar.
 * \param Numero maximo permitido.
 * \param numero minimo permitido.
 * \return Retorna 1 si la cadena es valida y -1 si no lo es.
 *
 */
int ValidarEntero(int,int,int);
/**********************************************/

