#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Book.h"
#include "Publisher.h"
#define CHAR_QTY 250


/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int parser_BookFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos los datos de las editoriales desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile
 * \param LinkedList* pArrayListEmployee
 * \return int
 *
 */
int parser_PublisherFromText(FILE* pFile , LinkedList* pArrayListEmployee);


#endif
