#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#define EMPTY_LIST "\nNo hay clientes en la lista. \nIngrese a la opcion 1 para dar de alta, luego, reingrese la opcion seleccionada\n"

int main(void) {
	setbuf(stdout, NULL);
	Cliente clienteList[QTY_CLIENTE];
	int menuOption;
	int id = 0;

	if(initCliente(clienteList, QTY_CLIENTE) == 0)
	{
		do
		{
			if(utn_getNumero(&menuOption, "\n\nMenu principal:\n1-Alta cliente \n2-Modificar cliente \n3-Baja cliente \n4-Informar \n5-Salir\n", ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
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
							printf(EMPTY_LIST);
						}

						break;
					case 3:
						if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0)
						{
							removeCliente(clienteList, QTY_CLIENTE, id);
						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
					case 4:

						 if(isClienteListEmpty(clienteList, QTY_CLIENTE) == 0)
						{

						}
						else
						{
							printf(EMPTY_LIST);
						}
						break;
				}
			}
		}while(menuOption != 5);
	}


	return EXIT_SUCCESS;
}
