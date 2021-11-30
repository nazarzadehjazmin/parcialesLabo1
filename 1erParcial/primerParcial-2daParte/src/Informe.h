#ifndef INFORME_H_
#define INFORME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "Pedido.h"
#include "Cliente.h"

/** \brief Para ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirLocalidadPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief Muestra la cantidad de kilos de polipropileno reciclado promedio por cliente
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirPromedioPPCliente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirClientesConPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirPedidosPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief : Se imprimirá una lista de los pedidos que se encuentren en estado “Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirPedidosProcesados(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

int informe_imprimirMaximo(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);
int informe_imprimirClientesConMasCompletos(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

#endif
