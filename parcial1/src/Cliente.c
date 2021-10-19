#include "Cliente.h"

static int generateNewId(void);

static int generateNewId(void)
{
	static int id = 6;
	id++;
	return  id;
}

int initCliente(Cliente* list, int len)
{
	int output = -1;

	if (list != NULL && len > 0)
	{
	  for (int i = 0; i < len; i++)
		{
		  list[i].isEmpty = TRUE;
		}
	  output = 0;
	}
	return output;
}

int findEmptyIndex(Cliente *list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				output = i;
				break;
			}
		}
	}

	return output;
}

int uploadCliente(Cliente *list, int len, int *id)
{
	int output = -1;
	Cliente buffer;

	if(list != NULL && len > 0 && findEmptyIndex(list, len) != -1)
	{
		if(utn_getNombre(buffer.nombreEmpresa, "\nNombre de la empresa: ", ERROR_MSG, NOMBREEMPRESA_LEN, QTY_REINTENTO) == 0 &&
		   utn_getCuit(buffer.cuit, "\nCUIT: ", ERROR_MSG, CUIT_LEN, QTY_REINTENTO) == 0 &&
		   //utn_getAlfanumerico("\nDireccion: ", ERROR_MSG, buffer.direccion, DIRECCION_LEN, QTY_REINTENTO) == 0 &&
		   utn_getDireccion(buffer.direccion, "\nDireccion - Calle: ", "\nAltura", ERROR_MSG, ERROR_ALTURA) == 0 &&
		   utn_getNombre(buffer.localidad, "\nLocalidad: ", ERROR_MSG, LOCALIDAD_LEN, QTY_REINTENTO) == 0
		   )
		{
			buffer.id = generateNewId();

			if(addCliente(list, len, buffer.id, buffer.nombreEmpresa, buffer.cuit, buffer.direccion, buffer.localidad) == 0)
			{
				output = 0;
			}
		}
	}

	return output;
}

int addCliente(Cliente* list, int len, int id, char nombreEmpresa[], char cuit[], char direccion[], char localidad[])
{
	int output = -1;
	int i;
	//int auxContador = 0;

	if(list != NULL && len > 0 && id > 0 && nombreEmpresa != NULL && cuit != NULL && direccion != NULL && localidad != NULL)
	{
		i = findEmptyIndex(list, len);
		list[i].id = id;
		strncpy(list[i].nombreEmpresa, nombreEmpresa, NOMBREEMPRESA_LEN);
		strncpy(list[i].cuit, cuit, CUIT_LEN);
		strncpy(list[i].direccion, direccion, DIRECCION_LEN);
		strncpy(list[i].localidad, localidad, LOCALIDAD_LEN);
		list[i].isEmpty = FALSE;

/*
		auxContador = list[i].contadorPedido;
		auxContador++;
		list[i].contadorPedido = auxContador;*/

		output = 0;
	}

	return output;
}


int findClienteById(Cliente* list, int len, int id)
{
	int output = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				output = i;
				break;
			}
		}
	}

	return output;
}

int printCliente(Cliente* cliente)
{
	int output = -1;

	if(cliente != NULL && cliente->isEmpty == FALSE)
	{
		//printf("\n%4d %20s %15s %20s %15s %10d",cliente->id, cliente->nombreEmpresa, cliente->cuit, cliente->direccion, cliente->localidad, cliente->contadorPedido);
		printf("\n%4d %20s %15s %20s %15s",cliente->id, cliente->nombreEmpresa, cliente->cuit, cliente->direccion, cliente->localidad);
		output = 0;
	}

	return output;
}

int printClientes(Cliente* list, int length)
{
	int output = -1;

	if(list != NULL && length > 0)
	{
		printf("\n%4s %20s %10s %25s %15s", "ID", "NOMBRE EMPRESA", "CUIT", "DIRECCION", "LOCALIDAD");
		for(int i = 0; i < length; i++)
		{
			printCliente(&list[i]);
		}
		output = 0;
	}

	return output;
}

int hardcodearData(Cliente* list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		addCliente(list, len, 1, "Arcor", "99992122111", "Av Callao 1790", "La Plata");
		addCliente(list, len, 2, "Toyota", "33992122144", "Santamarina 200", "CABA");
		addCliente(list, len, 3, "MercadoLibre", "45549921221", "Lavalle 1200", "Ezeiza");
		addCliente(list, len, 4, "Samsung", "51359921221", "Av Junin 900", "Junin");
		addCliente(list, len, 5, "Nestle", "73279921221", "Av Campana 1700", "Campana");
		addCliente(list, len, 6, "Sony", "82389921221", "Av Ostende 300", "Ostende");

		output = 0;
	}

	return output;
}

int alta_menu(Cliente* list, int len)
{
	int output = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(list != NULL && len > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear clientes \n2-Cargar cliente \n3-Volver al menu principal", ERROR_MSG, 1, 3, QTY_REINTENTO) == 0)
			{
				switch(option)
				{
					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData(list, len) == 0)
							{
								printClientes(list, len);
							}
						}
						else
						{
							printf("\nNo puede volver a harcodear los datos");
						}

						break;
					case 2:
						if(uploadCliente(list, len, &id) == 0 &&
						   printClientes(list, len) == 0)
						{
							printf("\nCliente cargado exitosamente");
						}
						else
						{
							printf("\nNo se ha podido cargar el cliente");
						}
						break;
				}
			}
		}while(option!= 3);
		output = 0;
	}

	return output;
}

int isClienteListEmpty(Cliente *list, int len)
{
	int output = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				output = 0;
				break;
			}
		}
	}

	return output;
}

int ModificarCliente(Cliente* list, int len)
{
	int output = -1;
	int idIngresado;
	int index;
	int option;
	Cliente buffer;
	char response;

	if(list != NULL && len > 0)
	{
		printClientes(list, len);

		if(utn_getNumero(&idIngresado, "\nSeleccione el id del cliente a modificar: ", ERROR_MSG, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findClienteById(list, len, idIngresado);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				do
				{
					if(utn_getNumero(&option, "\nQue desea modificar? \n1-Direccion \n2-Localidad \n5-Volver al menu principal", ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
					{
						switch(option)
						{
							case 1:
								if(utn_getDireccion(buffer.direccion, "\nNueva direccion: ", "\nNueva altura: ", ERROR_MSG, ERROR_ALTURA) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{

										strncpy(list[index].direccion, buffer.direccion, CUIT_LEN);
										printf("\nLa direccion ha sido modificada exitosamente");
									}
									else
									{
										printf("\nLa direccion no ha sido modificada");
									}
								}
								break;
							case 2:
								if(utn_getNombre(buffer.localidad, "\nNueva localidad: ", ERROR_MSG, LOCALIDAD_LEN, QTY_REINTENTO) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{
										strncpy(list[index].localidad, buffer.localidad, LOCALIDAD_LEN);
										printf("\nLa localidad ha sido modificada exitosamente");
									}
									else
									{
										printf("\nLa localidad no ha sido modificada");
									}
								}
								break;
						}
					}
				}while(option != 5);
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

int removeCliente(Cliente* list, int len, int id)
{
	int output = -1;
	int index;
	char respuesta;

	if(list != NULL && len > 0)
	{
		printClientes(list, len);

		if(utn_getNumero(&id, "\nSeleccione el id del empleado a dar de baja: ", ERROR_MSG, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findClienteById(list, len, id);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				if(utn_getContinuar(&respuesta, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
				  (respuesta == 'Y' || respuesta == 'y'))
				{
					list[index].isEmpty = TRUE;
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


