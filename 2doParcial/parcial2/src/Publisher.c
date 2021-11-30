#include "Publisher.h"


ePublisher* publisher_new(void)
{
	return (ePublisher*)malloc(sizeof(ePublisher));
}


ePublisher* publisher_newParametrosTxt(char* idStr, char* nombre)
{
	ePublisher* this = NULL;

	if(idStr != NULL && nombre != NULL)
	{
		this = publisher_new();
		if(this != NULL)
		{
			if(publisher_setIdTxt(this, idStr) != 0 ||
				publisher_setNombre(this, nombre) != 0)
			{
				publisher_delete(this);
				this = NULL;
			}
		}
	}
	return this;
}


void publisher_delete(ePublisher* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int publisher_setIdTxt(ePublisher* this, char* id)
{
	int output = -1;

	if(this != NULL && id != NULL && isValidIntTxt(id) == 1)
	{
		this->id = atoi(id);
		output = 0;
	}

	return output;
}

/*
char* publisher_getIdTxt(ePublisher* this, int* flagError)
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
*/

int publisher_getId(ePublisher* this, int* id)
{
	int output = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id; //te trae el dato
		output = 0;
	}
	return output;
}


int publisher_setNombre(ePublisher* this, char* nombre)
{
	int output = -1;
	if(this != NULL && nombre != NULL && isValidString(nombre, NAME_LEN) == 1)
	{
		strncpy(this->nombre, nombre, NAME_LEN);
		output = 0;
	}
	return output;
}


int publisher_getNombre(ePublisher* this, char* nombre)
{
	int output = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, NAME_LEN);
		output = 0;
	}
	return output;
}


