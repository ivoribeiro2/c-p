/* 
 * File:   linha_encomenda.h
 * Author: ivo
 *
 * Created on January 27, 2015, 4:32 PM
 */

#ifndef LINHA_ENCOMENDA_H
#define	LINHA_ENCOMENDA_H

#ifdef	__cplusplus
extern "C" {
#endif



#include "DataManagement.h"

    typedef struct {
        unsigned short id_linha_encomenda;
        unsigned short id_encomenda;
        unsigned short id_produto_final;
        unsigned short quantidade;
    } LinhaEncomenda;
    
    typedef enum {
        ID_LINHA_ENCOMENDA,
        ID_ENCOMENDA_LINHA_ENCOMENDA,
        ID_PRODUTO_FINAL_LINHA_ENCOMENDA,
        QUANTIDADE_LINHA_ENCOMENDA,
    } camposLinhaEncomenda;



#ifdef	__cplusplus
}
#endif

#endif	/* LINHA_ENCOMENDA_H */

