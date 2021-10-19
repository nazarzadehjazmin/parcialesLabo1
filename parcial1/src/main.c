#include <stdio.h>
#include <stdlib.h>
#include "Informe.h"
#define EMPTY_LIST_CLI "\nNo hay clientes en la lista. \nIngrese a la opcion 1 para dar de alta, luego, reingrese la opcion seleccionada\n"
#define EMPTY_LIST "\nError, listas vacias"

int main(void) {
	setbuf(stdout, NULL);
	Cliente clienteList[QTY_CLIENTE];
	Pedido pedidoList[QTY_PEDIDO];
	int menuOption;
	int id = 0;

	if(initCliente(clienteList, QTY_CLIENTE) == 0 &&
	   initPedido(pedidoList, QTY_PEDIDO) == 0)
	{
		do
		{
			if(utn_getNumero(&menuOption, "\n\nMenu principal:\n1-Alta cliente \n2-Modificar cliente \n3-Baja cliente \n4-Crear pedido de recoleccion \n5-Procesar residuos \n6-Imprimir clientes \n7-Imprimir pedidos pendientes \n8-Imprimir pedidos procesados \n9-Cantidad de pedidos pendientes por localidad \n10-Cantidad de kg de PP promedio por cliente \n11-Salir \n", ERROR_MSG, 1, 11, QTY_REINTENTO) == 0)
			{
				switch(menuOption)
				{
					case 1:
						alta_menu(clienteList, QTY_CLIENTE);
						break;
					case 2:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   ModificarCliente(clienteList, QTY_CLIENTE) == 0)
						{
							printClientes(clienteList, QTY_CLIENTE);
						}
						else
						{
							printf(EMPTY_LIST_CLI);
						}

						break;
					case 3:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0)
						{
							removeCliente(clienteList, QTY_CLIENTE, id);
						}
						else
						{
							printf(EMPTY_LIST_CLI);
						}
						break;
					case 4:

						 if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0)
						{
							 alta_menu_Pedido(pedidoList, QTY_PEDIDO, clienteList, QTY_CLIENTE);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 5:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   isPedidoListEmpty(pedidoList, QTY_PEDIDO) == 0)
						{
							procesarResiduos(pedidoList, QTY_PEDIDO);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 6:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   isPedidoListEmpty(pedidoList, QTY_PEDIDO) == 0)
						{
							informe_imprimirClientesConPendientes(pedidoList, QTY_PEDIDO, clienteList, QTY_CLIENTE);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 7:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   isPedidoListEmpty(pedidoList, QTY_PEDIDO) == 0)
						{

						}
						break;
					case 8:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   isPedidoListEmpty(pedidoList, QTY_PEDIDO) == 0)
						{

						}
						break;
					case 9:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   isPedidoListEmpty(pedidoList, QTY_PEDIDO) == 0)
						{
							informe_imprimirLocalidadPendiente(pedidoList, QTY_PEDIDO, clienteList, QTY_CLIENTE);
						}
						break;
					case 10:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0 &&
						   isPedidoListEmpty(pedidoList, QTY_PEDIDO) == 0)
						{
							informe_imprimirPromedioPPCliente(pedidoList, QTY_PEDIDO, clienteList, QTY_CLIENTE);
						}
						break;
				}
			}
		}while(menuOption != 11);
	}


	return EXIT_SUCCESS;
}




