#ifndef BOOK_H_
#define BOOK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "LinkedList.h"
#include "Publisher.h"
#define ERROR_MSG "Error, reingrese el dato\n"
#define QTY_REINTENTO 5
#define MIN_ID 1
#define MAX_ID 3000
#define TITLE_LEN 120
#define AUTHOR_LEN 120
#define PRECIO_LEN 120

typedef struct
{
    int id;
    char titulo[TITLE_LEN];
    char autor[AUTHOR_LEN];
    float precio;
    int idEditorial;
}eBook;


/**
 * \brief Reserva espacio en memoria para un libro
 * \param void
 * \return eBook*
 *
 */
eBook* book_new(void);


/**
 *  \brief Valida los campos y los carga en una variable eBook(como cadena de caracteres)
 * \param char* idStr
 * \param char* tituloStr
 * \param char* autorStr
 * \param char* precioStr
 * \param char* idEditorialStr
 * \return eBook* this
 *
 */
eBook* book_newParametrosTxt(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);


/**
 *  \brief Valida los campos y los carga en una variable eBook
 * \param int id
 * \param char* titulo
 * \param char* autor
 * \param float precio
 * \param int idEditorial
 * \return eBook* this
 *
 */
eBook* book_newParametros(int id, char* titulo, char* autor, float precio, int idEditorial);


/**
 *  \brief Libera el espacio reservado en memoria para un libro
 * \param eBook* this
 * \return void
 *
 */
void book_delete(eBook* this);


/**
 * \brief Carga el id en el campo del libro
 * \param this eBook*
 * \param id int
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setId(eBook* this, int id);


/**
 * \brief Obtiene el id del libro
 * \param this eBook*
 * \param id int*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getId(eBook* this, int* id);


/**
 * \brief Carga el id en el campo del libro (tratado como texto) y valida que el dato sea correcto
 * \param this Employee*
 * \param id char*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setIdTxt(eBook* this, char* id);


/**
 * \brief Obtiene el id del libro (tratado como texto)
 * \param this eBook*
 * \param flagError int*
 * \return int [-1] ERROR, [id] EXITO - retorna el id si funciona correctamente
 *
 */
char* book_getIdTxt(eBook* this, int* flagError);


/**
 * \brief Verifica que la cadena sea solo numeros
 * \param integer char* Puntero al id
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int isValidIntTxt(char* integer);


/**
 * \brief Carga un titulo en el campo titulo del libro
 * \param eBook* this
 * \param char* titulo
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setTitulo(eBook* this, char* titulo);


/**
 * \brief Obtiene el titulo del libro
 * \param eBook* this
 * \param char* titulo
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getTitulo(eBook* this, char* titulo);


/**
 * \brief Verifica la cadena
 * \param name char* Puntero al nombre
 * \return int[-1] ERROR, [0] EXITO
 *
 */
int isValidString(char* string, int len);


/**
 * \brief Carga el autor en el campo del libro
 * \param eBook* this
 * \param char* autor
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setAutor(eBook* this, char* autor);


/**
 * \brief Obtiene el autor del libro
 * \param eBook* this
 * \param char* autor
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getAutor(eBook* this, char* autor);


/**
 * \brief Carga el precio en el campo precio del libro
 * \param eBook* this
 * \param float* precio
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setPrecio(eBook* this, float precio);


/**
 * \brief Obtiene el precio del libro
 * \param eBook* this
 * \param float* precio
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getPrecio(eBook* this, float* precio);


/**
 * \brief Carga un precio en el campo precio del libro (modo texto)
 * \param eBook* this
 * \param char* precioTxt
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setPrecioTxt(eBook* this, char* precioTxt);


/**
 * \brief Obtiene el precio del libro
 * \param eBook* this
 * \param int* flagError
 * \return int [-1] ERROR, [0] EXITO
 *
 */
char* book_getPrecioTxt(eBook* this, int* flagError);

/**
 * \brief Valida que la cadena haya recibido un float
 * \param char* number
 * \param int len
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int isValidFloatTxt(char* number, int len);


/**
 * \brief Carga un id de editorial en el campo idEditorial del libro
 * \param eBook* this
 * \param int id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setIdEditorial(eBook* this, int id);


/**
 * \brief Obtiene el id de la editorial del libro
 * \param eBook* this
 * \param int* id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getIdEditorial(eBook* this, int* id);


/**
 * \brief Carga un id de editorial en el campo idEditorial del libro (modo texto)
 * \param eBook* this
 * \param char* id
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_setIdEditorialTxt(eBook* this, char* id);


/**
 * \brief Obtiene el id de la editorial del libro (modo texto)
 * \param eBook* this
 * \param int* flagError
 * \return int [-1] ERROR, [0] EXITO
 *
 */
char* book_getIdEditorialTxt(eBook* this, int* flagError);


/**
 * \brief Obtiene todos los campos del libro
 * \param eBook* this
 * \param int* id
 * \param char* autor
 * \param char* titulo
 * \param float* precio
 * \param int* idEditorial
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getAllTheGets(eBook* pBook, int* id, char* titulo, char* autor, float* precio, int* idEditorial);


/**
 * \brief Imprime un libro con el nombre de la editorial
 * \param eBook* pBook
 * \param LinkedList* publisherList
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_printBook(LinkedList* publisherList, eBook* pBook);


/**
 * \brief Obtiene el nombre de la editorial del libro
 * \param eBook* this
 * \param char* autor
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_getPublisherName(LinkedList* publisherList, eBook* pBook, int idEditorialBook, char* nombreEditorial);


/**
 * \brief Compara dos autores
 * \param void* firstAuthor
 * \param void* secondAuthor
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_compareByAuthor(void* firstAuthor, void* secondAuthor);


/**
 * \brief Busca los libros con editorial Minotauro
 * \param void* book
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int book_searchMinotauro(void* book);

void book_deleteAll(LinkedList* bookList);

int book_applyDiscount(void* book);

float book_calculateDiscount(float price, int discount);

#endif
