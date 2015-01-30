/* 
 * File:   produto_final.h
 * Author: ivo
 *
 * Created on January 27, 2015, 4:19 PM
 */

#ifndef PRODUTO_FINAL_H
#define	PRODUTO_FINAL_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "DataManagement.h"

    typedef struct {
        unsigned short id_produto_final;
        char descricao[MEDIUM_STRING];
    } ProdutoFinal;

    typedef enum {
        ID_PRODUTO_FINAL,
        DESCRICAO_PRODUTO_FINAL,
    } camposProdutoFinal;



#ifdef	__cplusplus
}
#endif

#endif	/* PRODUTO_FINAL_H */

