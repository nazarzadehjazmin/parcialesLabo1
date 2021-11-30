#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "Publisher.h"
#include "Book.h"
#include "LinkedList.h"
#include "Parser.h"
#define CONTINUE_MSG "\nDesea continuar?"
#define SAVE_DATA "Datos guardados exitosamente\n"
#define EDIT_SUCCESS "Empleado editado exitosamente\n"
#define EDIT_ERROR "El empleado no ha sido editado\n"
#define SORT_MSG "\nRealizando el ordenamiento. Aguarde un instante...\n"
#define PATH_LEN 200

/** \brief Carga los datos desde el archivo data.csv (modo texto).
 *
 * \param pArrayList LinkedList*
 * \param int (*pFunc)(FILE*, LinkedList*)
 * \return int [<0] ERROR, [0] EXITO
 *
 */
int controller_loadFromText(LinkedList* pArrayList, int (*pFunc)(FILE*, LinkedList*));


/** \brief Pide al usuario por consola el nombre del archivo que desea ingresar y lo concatena con ".csv"
 *
 * \param path char*
 * \param len int
 * \return int [<0] ERROR, [0] EXITO
 *
 */
int controller_enterFileName(char* path, int len);


/** \brief Ordenar libros por autor
 *
 * \param bookList LinkedList*
 * \param publisherList LinkedList*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int controller_sortBookByAutor(LinkedList* bookList, LinkedList* publisherList);


/** \brief Listar libros
 *
 * \param bookList LinkedList*
 * \param publisherList LinkedList*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int controller_listBooks(LinkedList* bookList, LinkedList* publisherList);


/** \brief Guarda los datos de libros de editorial Minotauro en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param bookList LinkedList*
 * \return int [-1] ERROR, [0] EXITO
 *
 */
int controller_saveMinotauroAsText(LinkedList* bookList, char* path);


/** \brief Pregunta si desea salir del programa. En caso de que asi sea, borra la lista de memoria y la libera
 *
 * \param pArrayList LinkedList*
 * \param int (*pFunc)(FILE*, LinkedList*)
 * \return int [<0] ERROR, [0] EXITO
 *
 */
int controller_exit(LinkedList* bookList, LinkedList* publisherList, char* continuar);


int controller_saveDiscountAsText(LinkedList* bookList, char* path);


#endif
