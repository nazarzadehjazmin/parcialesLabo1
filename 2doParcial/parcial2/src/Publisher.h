#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "LinkedList.h"
#include "Book.h"
#define ERROR_MSG "Error, reingrese el dato\n"
#define QTY_REINTENTO 5
#define MIN_ID 1
#define MAX_ID 3000
#define NAME_LEN 120

typedef struct
{
    int id;
    char nombre[NAME_LEN];
}ePublisher;


/**
 * \brief Reserva espacio en memoria para una editorial
 * \param void
 * \return ePublisher*
 *
 */
ePublisher* publisher_new(void);


/**
 *  \brief Valida los campos y los carga en una variable ePublisher(como cadena de caracteres)
 * \param char* idStr
 * \param char* nombre
 * \return ePublisher* this
 *
 */
ePublisher* publisher_newParametrosTxt(char* idStr, char* nombre);


/**
 *  \brief Libera el espacio reservado en memoria para una editorial
 * \param ePublisher* this
 * \return void
 *
 */
void publisher_delete(ePublisher* this);


/**
 * \brief Carga el id en el campo de la editorial (tratado como texto) y valida que el dato sea correcto
 * \param this ePublisher*
 * \param char* id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int publisher_setIdTxt(ePublisher* this, char* id);


/**
 * \brief Obtiene el id de la editorial
 * \param this eBook*
 * \param id int*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int publisher_getId(ePublisher* this, int* id);

/**
 * \brief Obtiene el nombre de la editorial
 * \param this ePublisher*
 * \param nombre char*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int publisher_getNombre(ePublisher* this, char* nombre);

/**
 * \brief Carga un nombre en el campo nombre de la editorial. Valida que el dato sea correcto
 * \param this ePublisher*
 * \param nombre char*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int publisher_setNombre(ePublisher* this, char* nombre);


#endif
