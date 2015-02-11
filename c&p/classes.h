/* 
 * File:   classes.h
 * Author: joao
 *
 * Created on February 10, 2015, 12:32 PM
 */

#ifndef CLASSES_H
#define	CLASSES_H

#ifdef	__cplusplus
extern "C" {
#endif

 typedef struct {
        Class * tipoUtilizadorClass;
        Class * utilizadorClass;
        Class * clienteClass;
        Class * unidadeClass;
        Class * ingredienteClass;
        Class * produtoFinalClass;
        Class * linhaProdutoFinalClass;
        Class * encomendaClass;
        Class * linhaEncomendaClass;
        Class * producaoClass;
    } Classes;


#ifdef	__cplusplus
}
#endif

#endif	/* CLASSES_H */

