/* 
 * File:   linha_produto_final.h
 * Author: ivo
 *
 * Created on January 28, 2015, 12:45 AM
 */

#ifndef LINHA_PRODUTO_FINAL_H
#define	LINHA_PRODUTO_FINAL_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "DataManagement.h"

    typedef struct {
        unsigned short id_linha_produto_final;
        unsigned short id_produto_final;
        unsigned short id_ingrediente;
        unsigned short id_unidade;
        float quantidade;
    } LinhaProdutoFinal;

    typedef enum {
        ID_LINHA_PRODUTO_FINAL,
        ID_PRODUTO_FINAL_LINHA_PRODUTO_FINAL,
        ID_INGREDIENTE_LINHA_PRODUTO_FINAL,
        ID_UNIDADE_LINHA_PRODUTO_FINAL,
        QUANTIDADE_LINHA_PRODUTO_FINAL
    } camposLinhaProdutoFinal;

#ifdef	__cplusplus
}
#endif

#endif	/* LINHA_PRODUTO_FINAL_H */

