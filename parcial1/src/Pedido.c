#include "Pedido.h"

static int generateNewId_Pedido(void);

static int generateNewId_Pedido(void)
{
	static int id = 6;
	id++;
	return  id;
}

int initPedido(Pedido* list, int len)
{
	int output = -1;

	if (list != NULL && len > 0)
	{
	  for (int i = 0; i < len; i++)
		{
		  list[i].isEmpty = TRUE_P;
		}
	  output = 0;
	}
	return output;
}

int findEmptyIndex_Pedido(Pedido *list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE_P)
			{
				output = i;
				break;
			}
		}
	}

	return output;
}

/*
int uploadPedido(Pedido *list, int len, int *id)
{
	int output = -1;
	Pedido buffer;

	if(list != NULL && len > 0 && findEmptyIndex_Pedido(list, len) != -1)
	{
		if(utn_getNumero(&buffer.idCliente, "\nId del cliente: ", ERROR_MSG_P, 1, QTY_CLIENTE_P, QTY_REINTENTOS_P) == 0 &&
		   utn_getFloat(&buffer.kgHDPE, "\nTotal de Kg HDPE: ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0 &&
			utn_getFloat(&buffer.kgLDPE, "\nTotal de Kg LDPE: ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0 &&
			utn_getFloat(&buffer.kgPP, "\nTotal de Kg PP: ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0 &&
			utn_getNombre(buffer.estadoPedido, "\nEstado del pedido: ", ERROR_MSG_P, ESTADO_LEN, QTY_REINTENTOS_P) == 0
			)
		{
			buffer.id = generateNewId_Pedido();
			buffer.totalKg = buffer.kgHDPE + buffer.kgLDPE + buffer.kgPP;
			strncpy(buffer.estadoPedido, PENDIENTE, ESTADO_LEN);
			if(addPedido(list, len, buffer.id, buffer.kgHDPE, buffer.kgLDPE, buffer.kgPP, buffer.totalKg, buffer.estadoPedido, buffer.idCliente) == 0)
			{
				output = 0;
			}
		}
	}

	return output;
}
*/

/*
int addPedido(Pedido* list, int len, int id, float totalKgHDPE, float totalKgLDPE, float totalKgPP, float totalKgResiduos, char estadoPedido[], int idCliente)
{
	int output = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && totalKgHDPE >= 0 && totalKgLDPE >= 0 && totalKgPP >= 0 && totalKgResiduos > 0 && estadoPedido != NULL && idCliente > 0)
	{
		i = findEmptyIndex_Pedido(list, len);
		if(i != -1)
		{
			list[i].id = id;
			list[i].kgHDPE = totalKgHDPE;
			list[i].kgLDPE = totalKgLDPE;
			list[i].kgPP = totalKgPP;
			list[i].totalKg = totalKgResiduos;
			strncpy(list[i].estadoPedido, estadoPedido, ESTADO_LEN);
			list[i].idCliente = idCliente;
			list[i].isEmpty = FALSE_P;
		}
		output = 0;
	}

	return output;
}
*/


/*
int uploadPedidoRecoleccion(Pedido *list, int len, int *id, Cliente *clienteList, int clienteLen)
{
	int output = -1;
	Pedido buffer;
	int idClienteIngresado;
	int idClienteBuscado;

	if(list != NULL && len > 0 && findEmptyIndex_Pedido(list, len) != -1 && clienteList != NULL && clienteLen > 0)
	{

		if(utn_getNumero(&idClienteIngresado, "\nId del cliente existente: ", ERROR_MSG_P, 1, QTY_CLIENTE_P, QTY_REINTENTOS_P) == 0)
		{
			idClienteBuscado = findClienteById(clienteList, clienteLen, idClienteIngresado);

			if( //idClienteIngresado == idClienteBuscado &&
		       utn_getFloat(&buffer.totalKg, "\nCantidad total de residuos (Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0)
			{

				buffer.id = generateNewId_Pedido();
				buffer.kgHDPE = 0;
				buffer.kgLDPE = 0;
				buffer.kgPP = 0;
				//inicializo a todos como pendientes
				strncpy(buffer.estadoPedido, PENDIENTE, ESTADO_LEN);
				buffer.idCliente = idClienteBuscado;
				if(addPedidoRecoleccion(list, len, buffer.id, buffer.kgHDPE, buffer.kgLDPE, buffer.kgPP, buffer.totalKg, buffer.estadoPedido, buffer.idCliente) == 0)
				{
					printPedidosRecoleccion(list, len);
					printf("\nPedido de recoleccion agregado exitosamente");
				}
			}
		}
		output = 0;
	}

	return output;
}

int addPedidoRecoleccion(Pedido* list, int len, int id, float kgHDPE, float kgLDPE, float kgPP, float totalKg, char estadoPedido[], int idCliente)
{
	int output = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && kgHDPE >= 0 && kgLDPE >= 0 && kgPP >= 0 && totalKg > 0 && estadoPedido != NULL && idCliente > 0)
	{
		i = findEmptyIndex_Pedido(list, len);
		if(i != -1)
		{
			list[i].id = id;
			list[i].kgHDPE = kgHDPE;
			list[i].kgLDPE = kgLDPE;
			list[i].kgPP = kgPP;
			list[i].totalKg = totalKg;
			strncpy(list[i].estadoPedido, estadoPedido, ESTADO_LEN);
			list[i].idCliente = idCliente;
			list[i].isEmpty = FALSE_P;
		}
		output = 0;
	}

	return output;
}
*/

/*
int uploadPedidoRecoleccion(Pedido *list, int len, int *id, Cliente *clienteList, int clienteLen)
{
	int output = -1;
	Pedido buffer;
	int idClienteIngresado;
	int idClienteBuscado;

	if(list != NULL && len > 0 && findEmptyIndex_Pedido(list, len) != -1 && clienteList != NULL && clienteLen > 0)
	{

		if(utn_getNumero(&idClienteIngresado, "\nId del cliente existente: ", ERROR_MSG_P, 1, QTY_CLIENTE_P, QTY_REINTENTOS_P) == 0)
		{
			idClienteBuscado = findClienteById(clienteList, clienteLen, idClienteIngresado);

			if(
		       utn_getFloat(&buffer.totalKg, "\nCantidad total de residuos (Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0)
			{

				buffer.id = generateNewId_Pedido();
				buffer.kgHDPE = 0;
				buffer.kgLDPE = 0;
				buffer.kgPP = 0;
				//inicializo a todos como pendientes
				strncpy(buffer.estadoPedido, PENDIENTE, ESTADO_LEN);
				buffer.idCliente = idClienteBuscado;

				if(addPedidoRecoleccion(list, len, buffer.id, buffer.kgHDPE, buffer.kgLDPE, buffer.kgPP, buffer.totalKg, buffer.estadoPedido, buffer.idCliente) == 0)
				{
					printPedidosRecoleccion(list, len);
					printf("\nPedido de recoleccion agregado exitosamente");
				}
			}
		}
		output = 0;
	}

	return output;
}

int addPedidoRecoleccion(Pedido* list, int len, int id, float kgHDPE, float kgLDPE, float kgPP, float totalKg, char estadoPedido[], int idCliente)
{
	int output = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && kgHDPE >= 0 && kgLDPE >= 0 && kgPP >= 0 && totalKg > 0 && estadoPedido != NULL && idCliente > 0)
	{
		i = findEmptyIndex_Pedido(list, len);
		if(i != -1)
		{
			list[i].id = id;
			list[i].kgHDPE = kgHDPE;
			list[i].kgLDPE = kgLDPE;
			list[i].kgPP = kgPP;
			list[i].totalKg = totalKg;
			strncpy(list[i].estadoPedido, estadoPedido, ESTADO_LEN);
			list[i].idCliente = idCliente;
			list[i].isEmpty = FALSE_P;
		}
		output = 0;
	}

	return output;
}
*/

int uploadPedidoRecoleccion(Pedido *pedidoList, int pedidoLen, int *id, Cliente *clienteList, int clienteLen)
{
	int output = -1;
	Pedido buffer;
	int idClienteIngresado;
	int idClienteBuscado;

	if(pedidoList != NULL && pedidoLen > 0 && findEmptyIndex_Pedido(pedidoList, pedidoLen) != -1 && clienteList != NULL && clienteLen > 0)
	{

		if(utn_getNumero(&idClienteIngresado, "\nId del cliente existente: ", ERROR_MSG_P, 1, QTY_CLIENTE_P, QTY_REINTENTOS_P) == 0)
		{
			idClienteBuscado = findClienteById(clienteList, clienteLen, idClienteIngresado);

			if(
		       utn_getFloat(&buffer.totalKg, "\nCantidad total de residuos (Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0)
			{

				buffer.id = generateNewId_Pedido();
				buffer.kgHDPE = 0;
				buffer.kgLDPE = 0;
				buffer.kgPP = 0;
				//inicializo a todos como pendientes
				strncpy(buffer.estadoPedido, PENDIENTE, ESTADO_LEN);
				buffer.idCliente = idClienteBuscado;
				pedidoList[idClienteBuscado] = buffer;

				printPedidosRecoleccion(pedidoList, pedidoLen);
				printf("\nPedido de recoleccion agregado exitosamente");

			}
		}
		output = 0;
	}

	return output;
}

int addPedidoRecoleccion(Pedido* list, int len, int id, float kgHDPE, float kgLDPE, float kgPP, float totalKg, char estadoPedido[], int idCliente)
{
	int output = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && kgHDPE >= 0 && kgLDPE >= 0 && kgPP >= 0 && totalKg > 0 && estadoPedido != NULL && idCliente > 0)
	{
		i = findEmptyIndex_Pedido(list, len);
		if(i != -1)
		{
			list[i].id = id;
			list[i].kgHDPE = kgHDPE;
			list[i].kgLDPE = kgLDPE;
			list[i].kgPP = kgPP;
			list[i].totalKg = totalKg;
			strncpy(list[i].estadoPedido, estadoPedido, ESTADO_LEN);
			list[i].idCliente = idCliente;
			list[i].isEmpty = FALSE_P;
		}
		output = 0;
	}

	return output;
}

/*
 5) Procesar residuos:
Se imprimirán los pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. SI
Luego deberán ingresarse la cantidad de kilos de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que se recolectaron.
Por último, se marcará al pedido como “Completado”.
*/

int procesarResiduos(Pedido* list, int len)
{
	int output = -1;
	int idIngresado;
	int index;
	Pedido buffer;
	char response;
	float sumaKgTotal;

	if(list != NULL && len > 0)
	{
		printPedidosRecoleccion(list, len);

		if(utn_getNumero(&idIngresado, "\nSeleccione el id del pedido existente: ", ERROR_MSG_P, 1, QTY_PEDIDO, QTY_REINTENTOS_P) == 0)
		{
			index = findPedidoById(list, len, idIngresado);

			if(index != -1 && list[index].isEmpty == FALSE_P)
			{
				if(utn_getFloat(&buffer.kgHDPE, "\nCantidad de HDPE(Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0 &&
					utn_getFloat(&buffer.kgLDPE, "\nCantidad de LDPE(Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0 &&
				   utn_getFloat(&buffer.kgPP, "\nCantidad de PP(Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0)
				{
					sumaKgTotal = buffer.kgHDPE + buffer.kgLDPE + buffer.kgPP;
					if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
					  (response == 'Y' || response == 'y') &&
					  sumaKgTotal == list[index].totalKg)
					{
						list[index].kgHDPE = buffer.kgHDPE;
						list[index].kgLDPE = buffer.kgLDPE;
						list[index].kgPP = buffer.kgPP;
						strncpy(list[index].estadoPedido, COMPLETADO, ESTADO_LEN);
						printf("\nSus residuos han sido procesados");
					}
					else
					{
						printf("\nLa suma total de residuos no es correcta \nSus residuos no han sido procesados");
					}
				}
			}
			else
			{
				printf(ID_NOEXISTE);
			}
		}
		output = 0;
	}

	return output;
}


int findPedidoById(Pedido* list, int len, int id)
{
	int output = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE_P && list[i].id == id)
			{
				output = i;
				break;
			}
		}
	}

	return output;
}

int printPedidoRecoleccion(Pedido* pedido)
{
	int output = -1;

	if(pedido != NULL && pedido->isEmpty == FALSE_P)
	{
		printf("\n%d %12.2f %10.2f %11.2f %10.2f %14s %4d",pedido->id, pedido->kgHDPE, pedido->kgLDPE, pedido->kgPP, pedido->totalKg, pedido->estadoPedido, pedido->idCliente);
		output = 0;
	}

	return output;
}

int printPedidosRecoleccion(Pedido* list, int length)
{
	int output = -1;

	if(list != NULL && length > 0)
	{
		printf("\n%s %10s %10s %10s %10s %10s %10s", "ID_P", "KgHDPE", "KgLDPE", "KgPP", "TOTALKg", "ESTADO", "ID_C");
		for(int i = 0; i < length; i++)
		{
			printPedidoRecoleccion(&list[i]);
		}
		output = 0;
	}

	return output;
}

int hardcodearData_PedidoRecoleccion(Pedido* list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		addPedidoRecoleccion(list, len, 1, 0, 0, 0, 400, PENDIENTE, 1);
		addPedidoRecoleccion(list, len, 2, 0, 0, 0, 300, PENDIENTE, 2);
		addPedidoRecoleccion(list, len, 3, 0, 0, 0, 300, PENDIENTE, 3);
		addPedidoRecoleccion(list, len, 4, 0, 0, 0, 400, PENDIENTE, 4);
		addPedidoRecoleccion(list, len, 5, 0, 0, 0, 500, PENDIENTE, 5);
		addPedidoRecoleccion(list, len, 6, 0, 0, 0, 350, PENDIENTE, 6);
		printPedidosRecoleccion(list, len);
		output = 0;
	}

	return output;
}

/*
int alta_menu_Pedido(Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear pedido de recoleccion \n2-Cargar pedido de recoleccion \n3-Volver al menu principal", ERROR_MSG_P, 1, 3, QTY_REINTENTOS_P) == 0)
			{
				switch(option)
				{
					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData_PedidoRecoleccion(pedidoList, pedidoLen) == 0)
							{
								printf("\nDatos hardcodeados exitosamente");
							}
						}
						else
						{
							printf("\nNo puede volver a hardcodear los datos");
						}

						break;
					case 2:
						if(printClientes(clienteList, clienteLen) == 0 &&
						   uploadPedidoRecoleccion(pedidoList, QTY_PEDIDO, &id, clienteList, QTY_CLIENTE) != -1)
						{
							printf("\nSe ha cargado el pedido exitosamente");
						}
						else
						{
							printf("\nNo se ha podido cargar el pedido");
						}
						break;
				}
			}
		}while(option!= 3);
		output = 0;
	}

	return output;
}
*/

int alta_menu_Pedido(Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear pedido de recoleccion \n2-Cargar pedido de recoleccion \n3-Volver al menu principal", ERROR_MSG_P, 1, 3, QTY_REINTENTOS_P) == 0)
			{
				switch(option)
				{
					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData_PedidoRecoleccion(pedidoList, pedidoLen) == 0)
							{
								printf("\nDatos hardcodeados exitosamente");
							}
						}
						else
						{
							printf("\nNo puede volver a hardcodear los datos");
						}

						break;
					case 2:
						if(printClientes(clienteList, clienteLen) == 0 &&
						   uploadPedidoRecoleccion(pedidoList, QTY_PEDIDO, &id, clienteList, QTY_CLIENTE) != -1)
						{
							printf("\nSe ha cargado el pedido exitosamente");
						}
						else
						{
							printf("\nNo se ha podido cargar el pedido");
						}
						break;
				}
			}
		}while(option!= 3);
		output = 0;
	}

	return output;
}

int isPedidoListEmpty(Pedido* list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE_P)
			{
				output = 0;
				break;
			}
		}
	}

	return output;
}

/*


int removeCliente(Cliente* list, int len, int id)
{
	int output = -1;
	int index;
	char respuesta;

	if(list != NULL && len > 0)
	{
		printClientes(list, len);

		if(utn_getNumero(&id, "\nSeleccione el id del empleado a dar de baja: ", ERROR_MSG_CLIENTE, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findClienteById(list, len, id);

			if(index != -1 && list[index].isEmpty == FALSE_CLIENTE)
			{
				if(utn_getContinuar(&respuesta, CONTINUAR, ERROR_MSG_CLIENTE, QTY_REINTENTO) == 0 &&
				  (respuesta == 'Y' || respuesta == 'y'))
				{
					list[index].isEmpty = TRUE_CLIENTE;
					printf("\nCliente eliminado exitosamente\n");
					printClientes(list, len);
				}
				else
				{
					printf(CLIENTE_NOTREMOVED);
				}
			}
			else
			{
				printf(ID_NOEXISTE);
				printf(CLIENTE_NOTREMOVED);
			}
		}
		output = 0;
	}

	return output;
}

*/


