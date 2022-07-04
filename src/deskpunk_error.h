/**
 * @file deskpunk_error.h
 * @author Luccas Rocigno de Medeiros
 * @date 06/21/2022
 * @brief Header of the error handlers functions
 *
 * Here are the prototypes of the error handlers created for the Deskpunk
 * engine. Functions descriptions and examples can be found on the
 * documentation, doxygen comments are also available with the functions
 * definitions.
 */
#ifndef DESKPUNK_ERROR_H
#define DESKPUNK_ERROR_H

// Session of includes that are universally used by the error functions
#include <stdio.h>
#include <stdint.h>
#include <string_c.h>

void deskpunk_error_detect(uint8_t res);

#endif
