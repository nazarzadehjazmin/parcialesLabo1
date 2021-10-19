#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "Cliente.h"

#define QTY_PEDIDO 1000
#define QTY_CLIENTE_P 100
#define PENDIENTE "pendiente"
#define COMPLETADO "completado"
#define TRUE_P 1
#define FALSE_P 0
#define ERROR_MSG_P "Error, reingrese el dato"
#define QTY_REINTENTOS_P 10
#define LOCALIDAD_LEN 60
#define MAX_KG 500000
#define MIN_KG 1
#define ESTADO_LEN 25


typedef struct
{
	 int id;
	 float kgHDPE;
	 float kgLDPE;
	 float kgPP;
	 float totalKg;
	 char estadoPedido[ESTADO_LEN];
	 int idCliente;
	 int isEmpty;
} Pedido;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Pedido* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPedido(Pedido* list, int len);



/** \brief Searching an empty index
 * \param list Pedido* list Pointer to array of employees
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int findEmptyIndex_Pedido(Pedido *list, int len);


/** \brief Asks the order's data
 * \param list Pedido* list Pointer to array of employees
 * \param int len Array length
 * \param int* id Pointer to id
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
//int uploadPedidoRecoleccion(Pedido *list, int len, int *id, Cliente *clienteList, int clienteLen);
int uploadPedidoRecoleccion(Pedido *pedidoList, int pedidoLen, int *id, Cliente *clienteList, int clienteLen);

/** \brief add in a existing list of order the values received as parameters
 * in the first empty position
 * \param list Pedido*
 * \param len int
 * \param id int
 * \param localidad[] char
 * \param float totalKgHDPE
 * \param totalKgLDPE float
 * \param totalKgPP float
 * \param totalKgResiduos float
 * \param estadoPedido int
 * \param idCliente int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addPedidoRecoleccion(Pedido* list, int len, int id, float kgHDPE, float kgLDPE, float kgPP, float totalKg, char estadoPedido[], int idCliente);



int procesarResiduos(Pedido* pedidoList, int pedidoLen);

/** \brief find an order by Id en returns the index position in array.
 *
 * \param list Pedido*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findPedidoById(Pedido* list, int len, int id);


/** \brief prints the content of one order
 *
 * \param list Pedido*
 * \return int 0 success, -1 error
 *
 */
int printPedidoRecoleccion(Pedido* pedido);


/** \brief prints the content of cliente's list
 *
 * \param list Pedido*
 * \param length int
 * \return int 0 success, -1 error
 *
 */
int printPedidosRecoleccion(Pedido* pedidoList, int pedidoLen);


/** \brief for preloaded data
 *
 * \param list Pedido*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int hardcodearData_PedidoRecoleccion(Pedido* list, int len);


/** \brief creates a menu for "alta"
 *
 * \param list Pedido*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int alta_menu_Pedido(Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);



/** \brief identifies if there are any orders
 *
 * \param list Pedido*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int isPedidoListEmpty(Pedido *list, int len);



/** \brief changes the different parameters of one order
 *
 * \param list Pedido*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
//int ModificarPedido(Pedido* list, int len);


/** \brief Remove a order by Id (put isEmpty Flag in 1)
 *
 * \param list Pedido*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
//int removePedido(Pedido* list, int len, int id);

#endif
