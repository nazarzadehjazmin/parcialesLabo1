#ifndef INFORME_H_
#define INFORME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "Pedido.h"
#include "Cliente.h"

//int crearPedidoRecoleccion(Pedido* listPedido, int pedidoLen, Cliente* clienteList, int clienteLen);

//int contadorPedidosPendientes2 (Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

//int informe_imprimirClientePedidoPendiente(Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

int informe_imprimirLocalidadPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

int informe_imprimirPromedioPPCliente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

int informe_imprimirClientesConPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

#endif
