#ifndef _ARGS_H_kFlmYm1tW9p5npzDr2opQJ9jM8
#define _ARGS_H_kFlmYm1tW9p5npzDr2opQJ9jM8

#include <stdbool.h>

struct percy_args {
    char* file_in;
    char* file_out;
};

/**
 * Interpreta la linea de comandos (argc, argv) llenando
 * args con defaults o la seleccion humana. Puede cortar
 * la ejecucion.
 */
void parse_args(int argc, char** argv, struct percy_args* args);

#endif
