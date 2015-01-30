/* 
 * File:   cliente.h
 * Author: ivo
 *
 * Created on January 27, 2015, 3:38 PM
 */

#ifndef CLIENTE_H
#define	CLIENTE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "DataManagement.h"

    typedef struct {
        unsigned short id_cliente;
        char nome[MEDIUM_STRING];
        unsigned short id_utilizador;
    } Cliente;
    
    typedef enum {
        ID_CLIENTE,
        NOME,
        ID_UTILIZADOR_CLIENTE
    } camposCliente;


#ifdef	__cplusplus
}
#endif

#endif	/* CLIENTE_H */

