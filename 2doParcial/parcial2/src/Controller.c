#include "Controller.h"


int controller_loadFromText(LinkedList* pArrayList, int (*pFunc)(FILE*, LinkedList*))
{
	int output = -1;
	FILE* pFile;
	char path[PATH_LEN];

	if(pArrayList != NULL && pFunc != NULL)
	{
		controller_enterFileName(path, PATH_LEN);
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			pFunc(pFile, pArrayList);
			output = 0;
			printf("Carga de datos en el archivo exitosa\n");
			fclose(pFile);
		}
		else if(ll_isEmpty(pArrayList) == 0)//tiene elementos
		{
			printf("Se realizó la carga de datos en el archivo en otra oportunidad\n");
			output = -2;
		}
		else
		{
			printf("No se puede abrir el archivo\n");
			output = -3;
		}
	}

    return output;
}


int controller_enterFileName(char* path, int len)
{
	int output = -1;

	if(path != NULL &&
	   len > 0 &&
	   utn_getString(path, "Ingrese el nombre del archivo que desea abrir: \n", ERROR_MSG, PATH_LEN, QTY_REINTENTO) == 0 &&
	   (strncmp(path, "books", PATH_LEN) == 0 || strncmp(path, "publishers", PATH_LEN) == 0))  //|| strncmp(path, "minotauro", PATH_LEN) == 0))
	{
		strncat(path, ".csv", PATH_LEN);
		output = 0;
	}

	return output;
}


int controller_sortBookByAutor(LinkedList* bookList, LinkedList* publisherList)
{
	int output = -1;

	if(bookList != NULL && ll_isEmpty(bookList) == 0)
	{
		printf(SORT_MSG);
		if(ll_sort(bookList, book_compareByAuthor, 1) == 0) // 1 = asc
		{
			controller_listBooks(bookList, publisherList);
			printf("\nOrdenamiento exitoso\n\n");
		}
		else
		{
			printf("No se ha podido realizar el ordenamiento\n");
		}
		output = 0;
	}

    return output;
}



int controller_listBooks(LinkedList* bookList, LinkedList* publisherList)
{
	int output = -1;
	eBook* pBook;
	int len;
	len = ll_len(bookList);
	if(bookList != NULL &&
	   publisherList != NULL &&
	   ll_isEmpty(bookList) == 0 &&
	   ll_isEmpty(publisherList) == 0)
	{
		printf("id - titulo - autor - precio - editorial\n");
		for(int i = 0; i < len; i++)
		{
			pBook = (eBook*) ll_get(bookList, i);
			book_printBook(publisherList, pBook);
		}
		output = 0;
	}

    return output;
}

int controller_saveMinotauroAsText(LinkedList* bookList, char* path)
{
	int output = -1;
	FILE* pFile = NULL;
	LinkedList* minotauroList;
	eBook* pBook;
	int len;
	int id;
	char titulo[TITLE_LEN];
	char autor[AUTHOR_LEN];
	float precio;
	int idEditorial;

	if(bookList != NULL && path != NULL && ll_isEmpty(bookList) == 0)
	{
		minotauroList = ll_filter(bookList, book_searchMinotauro);

		if(minotauroList != NULL)
		{
			len = ll_len(minotauroList);
			pFile = fopen(path, "w");

			if(pFile != NULL)
			{
				fprintf(pFile, "id,titulo,autor,precio\n");
				for(int i = 0; i < len; i++)
				{
					pBook = (eBook*) ll_get(minotauroList, i);
					if(book_getAllTheGets(pBook, &id, titulo, autor, &precio, &idEditorial) == 0)
					{
						fprintf(pFile,"%d,%s,%s,%.2f\n", id, titulo, autor, precio);
					}
				}
				printf(SAVE_DATA);
				output = 0;
			}
		}
	}
	fclose(pFile);
    return output;
}

int controller_exit(LinkedList* bookList, LinkedList* publisherList, char* continuar)
{
	int output = -1;

	if(bookList != NULL &&
	   publisherList != NULL &&
	   utn_getContinuar(continuar, "Desea salir del programa?", ERROR_MSG, QTY_REINTENTO) == 0)
	{
		if(ll_isEmpty(bookList) == 0 &&
		   ll_isEmpty(publisherList) == 0)
		{
			controller_deleteCleanList(bookList);
			controller_deleteCleanList(publisherList);
			//printf("\nHasta la próxima!\n");
		}
		output = 0;
	}

	return output;
}

int controller_deleteCleanList(LinkedList* list)
{
	int output = -1;

	if(list != NULL)
	{
		ll_clear(list);
		ll_deleteLinkedList(list);
		output = 0;
	}

	return output;
}
