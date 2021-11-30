#include "Book.h"

//ARREGLAR --> COMENTAR LOS NO TXT

eBook* book_new(void)
{
	return (eBook*)malloc(sizeof(eBook));
}


eBook* book_newParametrosTxt(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eBook* this = NULL;

	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL)
	{
		this = book_new();
		if(this != NULL)
		{
			if(book_setIdTxt(this, idStr) != 0 ||
				book_setTitulo(this, tituloStr) != 0 ||
				book_setAutor(this, autorStr) != 0 ||
				book_setPrecioTxt(this, precioStr) != 0 ||
				book_setIdEditorialTxt(this, idEditorialStr) != 0)
			{
				book_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}


eBook* book_newParametros(int id, char* titulo, char* autor, float precio, int idEditorial)
{
	eBook* this = NULL;

	if(id >= 0 && titulo != NULL && autor != NULL && precio >= 0 && idEditorial >= 0)
	{
		this = book_new();
		if(this != NULL)
		{
			if(book_setId(this, id) != 0 ||
			   book_setTitulo(this, titulo) != 0 ||
			   book_setAutor(this, autor) != 0 ||
			   book_setPrecio(this, precio) != 0 ||
			   book_setIdEditorial(this, idEditorial) != 0)
			{
				book_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}

void book_delete(eBook* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////

int book_setId(eBook* this, int id)
{
	int output = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id; //te agrega el dato
		output = 0;
	}
	return output;
}


int book_getId(eBook* this, int* id)
{
	int output = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id; //te trae el dato
		output = 0;
	}

	return output;
}



//////////////////////////////ID TXT


int book_setIdTxt(eBook* this, char* id)
{
	int output = -1;

	if(this != NULL && id != NULL && isValidIntTxt(id) == 1)
	{
		this->id = atoi(id);
		output = 0;
	}

	return output;
}


char* book_getIdTxt(eBook* this, int* flagError)
{
	*flagError = -1;
	char* bufferId = NULL;

	if(this != NULL && flagError != NULL)
	{
		sprintf(bufferId, "%d", this->id);
		*flagError = 0;
	}
	return bufferId;
}


int isValidIntTxt(char* number)
{
	int retorno = 0;

	if(number != NULL && utn_esNumerica(number, sizeof(number)) != -1)
	{
		retorno = 1;
	}

	return retorno;
}


////////////////////////////////TITULO


int book_setTitulo(eBook* this, char* titulo)
{
	int output = -1;
	if(this != NULL && titulo != NULL && isValidString(titulo, TITLE_LEN) == 1)
	{
		strncpy(this->titulo, titulo, TITLE_LEN);
		output = 0;
	}
	return output;
}


int book_getTitulo(eBook* this, char* titulo)
{
	int output = -1;
	if(this != NULL && titulo != NULL)
	{
		strncpy(titulo, this->titulo, TITLE_LEN);
		output = 0;
	}
	return output;
}


//cambiada evaluar si fx bien
int isValidString(char* string, int len)
{
	int output = 0;

	if(string != NULL && validarNombre(string, len) == 1)
	{
		output = 1;
	}

	return output;
}


////////////////////////////AUTOR

int book_setAutor(eBook* this, char* autor)
{
	int output = -1;
	if(this != NULL && autor != NULL && isValidString(autor, AUTHOR_LEN) == 1)
	{
		strncpy(this->autor, autor, AUTHOR_LEN);
		output = 0;
	}
	return output;
}


int book_getAutor(eBook* this, char* autor)
{
	int output = -1;
	if(this != NULL && autor != NULL)
	{
		strncpy(autor, this->autor, AUTHOR_LEN);
		output = 0;
	}
	return output;
}



////////////////////////////PRECIO


int book_setPrecio(eBook* this, float precio)
{
	int output = -1;
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		output = 0;
	}
	return output;
}


int book_getPrecio(eBook* this, float* precio)
{
	int output = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		output = 0;
	}
	return output;
}


int book_setPrecioTxt(eBook* this, char* precioTxt)
{
	int output = -1;
	if(this != NULL && precioTxt != NULL && isValidFloatTxt(precioTxt, PRECIO_LEN) == 1)
	{
		this->precio = atof(precioTxt);
		output = 0;
	}
	return output;
}


char* book_getPrecioTxt(eBook* this, int* flagError)
{
	*flagError = -1;
	char* bufferPrecioTxt = NULL;

	if(this != NULL && flagError != NULL)
	{
		sprintf(bufferPrecioTxt,"%f", this->precio);
		*flagError = 0;
	}

	return bufferPrecioTxt;
}


int isValidFloatTxt(char* number, int len)
{
	int output = 0;

	if(number != NULL && utn_esFloat(number, len) == 1)
	{
		output = 1;
	}

	return output;
}

////////////////////////////ID EDITORIAL

int book_setIdEditorial(eBook* this, int id)
{
	int output = -1;

	if(this != NULL && id >= 0)
	{
		this->idEditorial = id; //te agrega el dato
		output = 0;
	}
	return output;
}


int book_getIdEditorial(eBook* this, int* id)
{
	int output = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idEditorial; //te trae el dato
		output = 0;
	}

	return output;
}



//////////////////////////////ID TXT


int book_setIdEditorialTxt(eBook* this, char* id)
{
	int output = -1;

	if(this != NULL && id != NULL && isValidIntTxt(id) == 1)
	{
		this->idEditorial = atoi(id);
		output = 0;
	}

	return output;
}


char* book_getIdEditorialTxt(eBook* this, int* flagError)
{
	*flagError = -1;
	char* bufferId = NULL;

	if(this != NULL && flagError != NULL)
	{
		sprintf(bufferId, "%d", this->idEditorial);
		*flagError = 0;
	}
	return bufferId;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
int employee_findId(LinkedList* pArrayListEmployee, int* id)
{
	int output = -1;
	int len;
	Employee* bufferEmployee;
	int bufferId;

	if(pArrayListEmployee != NULL && id != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for(int i = 0; i < len; i++)
		{
			bufferEmployee = (Employee*) ll_get(pArrayListEmployee, i); //unboxing
			employee_getId(bufferEmployee, &bufferId);
			if(bufferEmployee != NULL && bufferId == *id)
			{
				output = i;
				break;
			}
		}
	}
	return output;
}
*/


int book_getAllTheGets(eBook* pBook, int* id, char* titulo, char* autor, float* precio, int* idEditorial)
{
	int output = -1;

	if(pBook != NULL && id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL)
	{
		if(book_getId(pBook, id) == 0 &&
		   book_getTitulo(pBook, titulo) == 0 &&
		   book_getAutor(pBook, autor) == 0 &&
		   book_getPrecio(pBook, precio) == 0 &&
		   book_getIdEditorial(pBook, idEditorial) == 0)
		{
			output = 0;
		}
	}

	return output;
}


int book_printBook(LinkedList* publisherList, eBook* pBook)
{
	int output = -1;
	int id;
	char titulo[TITLE_LEN];
	char autor[AUTHOR_LEN];
	float precio;
	int idEditorial;
	char nombreEditorial[NAME_LEN];

	if(pBook != NULL &&
	   publisherList != NULL &&
	   book_getAllTheGets(pBook, &id, titulo, autor, &precio, &idEditorial) == 0 &&
	   book_getPublisherName(publisherList, pBook, idEditorial, nombreEditorial) == 0)
	{
		printf("%d - %s - %s - %.2f - %s\n", id, titulo, autor, precio, nombreEditorial);
		output = 0;
	}

	return output;
}

int book_getPublisherName(LinkedList* publisherList, eBook* pBook, int idEditorialBook, char* nombreEditorial)
{
	int output = -1;
	int publisherLen;
	ePublisher* pPublisher;
	int idPublisherEntity;

	if(pBook != NULL && idEditorialBook >= 0 && nombreEditorial != NULL)
	{
		publisherLen = ll_len(publisherList);
		for(int i = 0; i < publisherLen; i++)
		{
			pPublisher = ll_get(publisherList, i);
			publisher_getId(pPublisher, &idPublisherEntity);
			if(idEditorialBook == idPublisherEntity)
			{
				publisher_getNombre(pPublisher, nombreEditorial);
				output = 0;
			}
		}
	}
	return output;
}


int book_compareByAuthor(void* firstAuthor, void* secondAuthor)
{
	int output = -1;
	eBook* pFirstAuthor = (eBook*) firstAuthor;
	eBook* pSecondAuthor = (eBook*) secondAuthor;
	char firstAuthorChar[AUTHOR_LEN];
	char secondAuthorChar[AUTHOR_LEN];

	if (pFirstAuthor != NULL && pSecondAuthor != NULL)
	{
		book_getAutor(pFirstAuthor, firstAuthorChar);
		book_getAutor(pSecondAuthor, secondAuthorChar);
		output = strncmp(firstAuthorChar, secondAuthorChar, AUTHOR_LEN);
	}

	return output;
}


int book_searchMinotauro(void* book)
{
	int output = 0;
	eBook* pBook = (eBook*) book;
	int id;

	if(pBook != NULL &&
	   book_getIdEditorial(pBook, &id) == 0 &&
	   id == 4)
	{
		output = 1;
	}

	return output;
}

