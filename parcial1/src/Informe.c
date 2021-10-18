#include "Informe.h"

/*
int crearPedidoRecoleccion(Pedido* listPedido, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int idPedido;

	if(listPedido != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		if(printClientes(clienteList, clienteLen) == 0 &&
		uploadPedidoRecoleccion(listPedido, pedidoLen, &idPedido) == 0)
		{
			printf("\nEl pedido de recolección ha sido creado exitosamente");
		}
		output = 0;
	}

	return output;
}
*/


/*
 6) Imprimir Clientes:
 Se imprimirá una lista de clientes con todos sus datos
  junto con la cantidad de “pedidos de recolección” que posee en estado “Pendiente”.
*/

/*

 */
//DEVUELVE LA CANTIDAD DE PEDIDOS PENDIENTES
int contadorPedidosPendientes (Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
  int retorno = -1;
  int contadorPendientes = 0;
  int i;


  if (pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
    {
	  for(int j = 0; i < clienteLen; j++)
	  {
		  //sacar id del cliente
		  findClienteById(clienteList, clienteLen, j);

		  for (i = 0; i < pedidoLen; i++)
		  {
			  if (pedidoList[i].isEmpty == FALSE_P &&
				  strncasecmp(pedidoList[i].estadoPedido, PENDIENTE, ESTADO_LEN) == 0)
			  {
				  //pedidos pendientes de ese id y q me los cuente
				  contadorPendientes++;
			  }
		  }
	  }

      retorno = contadorPendientes;
    }

  return retorno;
}

int informe_imprimirClientePedidoPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int cantidadPendientes;

	if(pedidoList != NULL && pedidoLen > 0)
	{
		printf("\n%s %10s %10s %10s %10s %10s %10s %10s", "ID_P", "KgHDPE", "KgLDPE", "KgPP", "TOTALKg", "ESTADO", "ID_C", "CANT PENDIENTE");
		cantidadPendientes = contadorPedidosPendientes(pedidoList, pedidoLen, clienteList, clienteLen);
		if(cantidadPendientes != -1)
		{
			for(int i = 0; i < pedidoLen; i++)
			{
				if(pedidoList[i].isEmpty == FALSE_P &&
				   strncasecmp(pedidoList[i].estadoPedido, PENDIENTE, ESTADO_LEN) == 0)
				{
					printf("\n%d %12.2f %10.2f %11.2f %10.2f %14s %4d %4d", pedidoList[i].id, pedidoList[i].kgHDPE, pedidoList[i].kgLDPE, pedidoList[i].kgPP, pedidoList[i].totalKg, pedidoList[i].estadoPedido, pedidoList[i].idCliente, cantidadPendientes);
				}
			}
		}
		output = 0;
	}


	return output;
}




