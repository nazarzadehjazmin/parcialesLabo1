#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"

#define QTY_PEDIDO 1000
#define PENDIENTE 1
#define COMPLETADO 0

typedef struct
{
	 int id;
	 char localidad[];
	 float totalKgHDPE;
	 float totalKgLDPE;
	 float totalKgPP;
	 float totalKgResiduos;
	 int estadoPedido;
	 int idCliente;
	 int isEmpty;
} Pedido;


#endif
