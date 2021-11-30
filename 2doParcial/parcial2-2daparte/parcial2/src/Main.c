#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Book.h"
#include "Publisher.h"
#include "Inputs.h"
#define EMPTY_LIST_ERROR "Error, lista vacía. Cargue los datos primero\n"
#define ALREADY_ENTERED_ERROR "Error, ya ha cargado los datos en el archivo\n"

int main()
{
    setbuf(stdout, NULL);
    int option = 0;
    int option1 = 0;
    int option2 = 0;
    char continuar;

   LinkedList* bookList = ll_newLinkedList();
   LinkedList* publisherList = ll_newLinkedList();


    do{
    	if(utn_getNumero(&option, "\nMenu: \n1.Cargar los datos de los libros \n2.Cargar los datos de las editoriales \n3.Ordenar autor de forma ascendente \n4.Imprimir lista de libros \n5.Listado de los libros de la editorial MINOTAURO \n6.Aplicar descuentos \n7. Salir\n", "Error, reingrese el dato\n", 1, 7, 5) == 0)
    	{
            switch(option)
            {
                case 1:
                	if(option1 == 0 &&
                	   controller_loadFromText(bookList, parser_BookFromText) == 0)
					{
						option1++;
					}
					else if(option1 > 0)
					{
						printf(ALREADY_ENTERED_ERROR);
					}
                    break;
                case 2:
                	if(option2 == 0 &&
                	   controller_loadFromText(publisherList, parser_PublisherFromText) == 0)
                	{
                		option2++;
                	}
                	else if(option2 > 0)
					{
						printf(ALREADY_ENTERED_ERROR);
					}
                	break;
                case 3:
                	if(ll_isEmpty(bookList) == 0 &&
                	   ll_isEmpty(publisherList) == 0)
                	{
                		controller_sortBookByAutor(bookList, publisherList);
                	}
                	else
					{
						printf(EMPTY_LIST_ERROR);
					}
                	break;
                case 4:
                	if(ll_isEmpty(bookList) == 0 &&
					   ll_isEmpty(publisherList) == 0)
					{
                		controller_listBooks(bookList, publisherList);
					}
					else
					{
						printf(EMPTY_LIST_ERROR);
					}
                	break;
                case 5:
                	if(ll_isEmpty(bookList) == 0 &&
					   ll_isEmpty(publisherList) == 0)
					{
                		controller_saveMinotauroAsText(bookList, "minotauro.csv");
					}
					else
					{
						printf(EMPTY_LIST_ERROR);
					}
                	break;
                case 6:
                	if(ll_isEmpty(bookList) == 0 &&
					   ll_isEmpty(publisherList) == 0)
					{
                		controller_saveDiscountAsText(bookList, "mapeado.csv");
					}
                	else
					{
						printf(EMPTY_LIST_ERROR);
					}
                	break;
                case 7:
                	controller_exit(bookList, publisherList, &continuar);
                	break;
            }
    	}
    }while((continuar == 'n' || continuar == 'N') || option != 7);

    return 0;
}

