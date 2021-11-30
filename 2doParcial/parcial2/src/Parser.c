#include "Parser.h"

int parser_BookFromText(FILE* pFile , LinkedList* pArrayList)
{
	int output = -1;
    char id[MAX_ID];
    char titulo[TITLE_LEN];
    char autor[AUTHOR_LEN];
    char precio[PRECIO_LEN];
    char idEditorial[MAX_ID];
	eBook* pBook = NULL;

	if(pFile != NULL && pArrayList != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial) == 5)
			{

				pBook = book_newParametrosTxt(id, titulo, autor, precio, idEditorial);
				//los tipos de datos reales
				if(pBook != NULL)
				{
					output = ll_add(pArrayList, pBook);
					//0 = ok
				}
				else
				{
					book_delete(pBook);
				}
			}
		}while(!feof(pFile));
	}

	fclose(pFile);
    return output;
}


int parser_PublisherFromText(FILE* pFile , LinkedList* pArrayList)
{
	int output = -1;
    char id[MAX_ID];
    char nombre[NAME_LEN];
	ePublisher* pPublisher = NULL;

	if(pFile != NULL && pArrayList != NULL)
	{
		fscanf(pFile, "%[^,],%[^\n]\n", id, nombre);
		do
		{
			if(fscanf(pFile, "%[^,],%[^\n]\n", id, nombre) == 2)
			{
				pPublisher = publisher_newParametrosTxt(id, nombre);
				//los tipos de datos reales
				if(pPublisher != NULL)
				{
					output = ll_add(pArrayList, pPublisher);
					//0 = ok
				}
				else
				{
					publisher_delete(pPublisher);
				}
			}
		}while(!feof(pFile));
	}

	fclose(pFile);
    return output;
}
