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
//DEVUELVE LA CANTIDAD DE PEDIDOS PENDIENTES
//no
int contadorPedidosPendientes2 (Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
  int retorno = -1;
  int contadorPendientes = 0;
  int i;
  int clienteEncontrado;


  if (pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
    {
	  for(int j = 0; i < clienteLen; j++)
	  {
		  //sacar id del cliente
		  clienteEncontrado = findClienteById(clienteList, clienteLen, j);
		  if(clienteEncontrado != -1)
		  {
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

	  }

      retorno = contadorPendientes;
    }

  return retorno;
}

//no

int informe_imprimirClientePedidoPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int cantidadPendientes;

	if(pedidoList != NULL && pedidoLen > 0)
	{
		printf("\n%s %10s %10s %10s %10s %10s %10s %10s", "ID_P", "KgHDPE", "KgLDPE", "KgPP", "TOTALKg", "ESTADO", "ID_C", "CANT PENDIENTE");
		cantidadPendientes = contadorPedidosPendientes2(pedidoList, pedidoLen, clienteList, clienteLen);
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
*/

/*
int contadorPedidosPendientes(Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
  int retorno = -1;
  int contadorPendientes = 0;
  int i;
  int clienteEncontrado;


  if (pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
    {
	  for(int j = 0; i < clienteLen; j++)
	  {
		  //sacar id del cliente
		  clienteEncontrado = findClienteById(clienteList, clienteLen, j);
		  if(clienteEncontrado != -1)
		  {
			   for (i = 0; i < pedidoLen; i++)
			   {
				   if (pedidoList[clienteEncontrado].isEmpty == FALSE_P &&
						   strncasecmp(pedidoList[clienteEncontrado].estadoPedido, PENDIENTE, ESTADO_LEN) == 0)
				   {
					   //pedidos pendientes de ese id y q me los cuente
					   contadorPendientes++;
				   }
			   }
		  }

	  }

      retorno = contadorPendientes;
    }

  return retorno;
}

*/


int informe_imprimirLocalidadPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	char localidad[LOCALIDAD_LEN];
	int contadorPendientes = 0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		if(utn_getNombre(localidad, "Ingrese la localidad que desea listar:", "Localidad ingresada invalida.", LOCALIDAD_LEN , QTY_REINTENTO) == 0)
		{
			for(int i = 0; i < clienteLen; i++)
			{
				if(strncasecmp(localidad,clienteList[i].localidad,LOCALIDAD_LEN) == 0)
				{
					strncpy(localidad,clienteList[i].localidad,LOCALIDAD_LEN);
					for(int j = 0; j < pedidoLen; j++)
					{
						if((clienteList[i].id==pedidoList[j].idCliente) && (strncasecmp(pedidoList[j].estadoPedido, PENDIENTE, ESTADO_LEN) == 0))
						{
							contadorPendientes++;
						}
					}
				}
			}
			if(contadorPendientes < 1)
			{
				printf("\nLa localidad ingresada no coincide con ninguna en el registro de pedidos pendientes.");
				output =-1;
			}
			else
			{
				printf("\nEn la localidad %s quedan pendientes %d pedidos.", localidad, contadorPendientes);
				output = 0;
			}
		}
	}
	return output;
}

int informe_imprimirPromedioPPCliente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int contadorClientes = 0;
	float acumuladorKilosPP = 0;
	float promedio;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
			for(int i = 0; i < clienteLen; i++)
			{
				if(clienteList[i].isEmpty == FALSE)
				{
					contadorClientes++;
				}
			}

			for(int j = 0; j < pedidoLen;j++)
			{
				if(pedidoList[j].isEmpty == FALSE)
				{
					acumuladorKilosPP = acumuladorKilosPP + pedidoList[j].kgPP;
				}
			}

			if(acumuladorKilosPP == 0)
			{
				printf("\nNo se ha cargado PP, ingrese a la opcion 5 primero");
			}
			else
			{
				promedio = acumuladorKilosPP / (float)contadorClientes;
				printf("\nEl promedio de PP reciclado es de %.2f Kg por cliente.", promedio);
				output = 0;
			}
	}


	return output;
}

int informe_imprimirClientesConPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int contadorPendientes = 0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		printf("\n%4s %20s %10s %25s %15s %6s", "ID", "NOMBRE EMPRESA", "CUIT", "DIRECCION", "LOCALIDAD", "PENDIENTES");
		for(int i = 0; i < clienteLen; i++)
		{
			if(clienteList[i].isEmpty == FALSE)
			{
				for(int j = 0; j < pedidoLen; j++)
				{
					if(clienteList[i].id == pedidoList[j].idCliente && strncasecmp(pedidoList[j].estadoPedido, PENDIENTE, ESTADO_LEN) == 0)
					{
						contadorPendientes++;
					}
				}

				if(contadorPendientes > 0)
				{

					printf("\n%4d %20s %15s %20s %15s %6d", clienteList[i].id, clienteList[i].nombreEmpresa, clienteList[i].cuit, clienteList[i].direccion, clienteList[i].localidad, contadorPendientes);
					contadorPendientes = 0;
				}
				else
				{
					printf("\nNo hay pedidos pendientes para mostrar");
				}
			}
		}
		output = 0;
	}
	return output;
}


/*
 7) Imprimir Pedidos pendientes:
Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente” con la información:
Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
*/

int informe_imprimirPedidosPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{

	}

	return output;
}


/*
8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
de plástico.
*/
