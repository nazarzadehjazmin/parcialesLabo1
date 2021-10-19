#include "Informe.h"


int informe_imprimirLocalidadPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int contadorPendientes = 0;
	int localidad;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		if(utn_getNumero(&localidad, "Ingrese la localidad que desea listar:", "Localidad ingresada invalida.", 1, 100, QTY_REINTENTO) == 0)
		{
			for(int i = 0; i < clienteLen; i++)
			{
				if(clienteList[i].idLocalidad ==localidad)
				{
					clienteList[i].idLocalidad = localidad;
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
				printf("\nEn la localidad %d quedan pendientes %d pedidos.", localidad, contadorPendientes);
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

					printf("\n%4d %20s %15s %20s %15d %6d", clienteList[i].id, clienteList[i].nombreEmpresa, clienteList[i].cuit, clienteList[i].direccion, clienteList[i].idLocalidad, contadorPendientes);
					contadorPendientes = 0;
					//imprimirClientesConPendientes(pedidoList, pedidoLen, contadorPendientes);
				}
				else
				{

					printf("\n%4d %20s %15s %20s %15d %6d ", clienteList[i].id, clienteList[i].nombreEmpresa, clienteList[i].cuit, clienteList[i].direccion, clienteList[i].idLocalidad, 0);
				}

			}
		}
		output = 0;
	}
	return output;
}


int informe_imprimirPedidosPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output =-1;
	int flagPrimerPendiente=0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		printf("\n%10s %25s %15s", "CUIT", "DIRECCION", "TOTAL DE KG");
		for(int i = 0; i < clienteLen; i++)
		{
			if(clienteList[i].isEmpty == 0)
			{
				for(int j = 0; j < pedidoLen; j++)
				{
					if((clienteList[i].id == pedidoList[j].idCliente) && (strncasecmp(pedidoList[j].estadoPedido, PENDIENTE, ESTADO_LEN) == 0))
					{
						flagPrimerPendiente=1;
						printf("\n%15s %20s %15.2f",  clienteList[i].cuit, clienteList[i]. direccion, pedidoList[j].totalKg);
					}
				}

			}
		}
		if(flagPrimerPendiente==1)
		{
		output = 0;
		}
		else
		{
			printf("\nNo hay pedidos pendientes para mostrar.");
			output=-1;
		}
	}
	return output;
}



int informe_imprimirPedidosProcesados(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int flagPrimerProcesado=0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		for(int i = 0; i < clienteLen; i++)
		{
			if(clienteList[i].isEmpty==FALSE)
			{
				for(int j = -1; j < pedidoLen; j++)
				{
					if((clienteList[i].id==pedidoList[j].idCliente) && (strncasecmp(pedidoList[j].estadoPedido, COMPLETADO, ESTADO_LEN) == 0))
					{
						if((flagPrimerProcesado==0))
						{
							printf("\n%10s %25s %15s %15s %15s", "CUIT", "DIRECCION", "HDPE", "LDPE", "PP");
							printf("\n%15s %20s %15.2f %15.2f %15.2f",  clienteList[i].cuit, clienteList[i].direccion, pedidoList[j].kgHDPE, pedidoList[j].kgLDPE, pedidoList[j].kgPP);
							flagPrimerProcesado=1;
						}
						else
						{
							printf("\n%15s %20s %15.2f %15.2f %15.2f",  clienteList[i].cuit, clienteList[i].direccion, pedidoList[j].kgHDPE, pedidoList[j].kgLDPE, pedidoList[j].kgPP);
						}
					}
				}
			}
		}
		if(flagPrimerProcesado==0)
		{
			printf("\nNo hay pedidos procesados para mostrar.");
			output =-1;
		}
		else
		{
			output = 0;
		}
	}
	return output;
}


int informe_imprimirMaximo(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
	int contadorPendientes = 0;
	int flag = 0;
	int maximo;
	int clienteMasPedido;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
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
				if(contadorPendientes > maximo || flag == 0)
				{
					clienteMasPedido = clienteList[i].id;
					maximo = contadorPendientes;
					flag = 1;
				}
				contadorPendientes = 0;
			}

		}
			printf("\nEl usuario con mas pedidos es el ID:%4d", clienteMasPedido);
		output = 0;
	}
	return output;
}


int informe_imprimirClientesConMasCompletos(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int output = -1;
		int contadorPendientes = 0;
		int flag = 0;
		int maximo;
		int clienteMasPedido;

		if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
		{
			for(int i = 0; i < clienteLen; i++)
			{
				if(clienteList[i].isEmpty == FALSE)
				{
					for(int j = 0; j < pedidoLen; j++)
					{
						if(clienteList[i].id == pedidoList[j].idCliente && strncasecmp(pedidoList[j].estadoPedido, COMPLETADO, ESTADO_LEN) == 0)
						{
							contadorPendientes++;
						}
					}
					if(contadorPendientes > maximo || flag == 0)
					{
						clienteMasPedido = clienteList[i].id;
						maximo = contadorPendientes;
						flag = 1;
					}
					contadorPendientes = 0;
				}

			}
				printf("\nEl usuario con mas pedidos es el ID:%4d", clienteMasPedido);
			output = 0;
		}
		return output;
}
