/* 
 * File:   ingrediente.h
 * Author: ivo
 *
 * Created on January 27, 2015, 3:38 PM
 */

#ifndef INGREDIENTE_H
#define	INGREDIENTE_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "DataManagement.h"

    typedef struct {
        unsigned short id_ingrediente;
        char descricao[SHORT_STRING];
    } Ingrediente;
    
    typedef enum {
        ID_INGREDIENTE,
        DESCRICAO_INGREDIENTE,
    } camposIngrediente;



#ifdef	__cplusplus
}
#endif

#endif	/* INGREDIENTE_H */

