/* 
 * File:   producao.h
 * Author: ivo
 *
 * Created on January 27, 2015, 3:54 PM
 */

#ifndef PRODUCAO_H
#define	PRODUCAO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "DataManagement.h"

    typedef struct {
        unsigned short id_producao;
        unsigned short id_linha_encomenda;
        float quantidade;
    } Producao;

    typedef enum {
        ID_PRODUCAO,
        ID_LINHA_ENCOMENDA_PRODUCAO,
        ID_QUANTIDADE_PRODUCAO
    } camposProducao;


#ifdef	__cplusplus
}
#endif

#endif	/* PRODUCAO_H */

