/* 
 * File:   unidade.h
 * Author: ivo
 *
 * Created on January 27, 2015, 3:41 PM
 */

#ifndef UNIDADE_H
#define	UNIDADE_H

#ifdef	__cplusplus
extern "C" {
#endif
    #include "DataManagement.h"

    typedef struct {
        unsigned short id_unidade;
        char descricao[SHORT_STRING];
    } Unidade;
    
    typedef enum {
        ID_UNIDADE,
        DESCRICAO_UNIDADE,
    } camposUnidade;





#ifdef	__cplusplus
}
#endif

#endif	/* UNIDADE_H */

