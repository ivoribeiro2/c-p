/* 
 * File:   menu.h
 * Author: joao
 *
 * Created on February 10, 2015, 5:10 PM
 */

#ifndef MENU_H
#define	MENU_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    void gestaoClientesEncomendas(Classes *classes, unsigned short idCliente);
    void relatorios(Classes *classes);
    void gestaoGestores(Classes *classes);
    void gestaoClientes(Class *clienteClass, Classes *classes);
    void gestaoIngredientes(Class *ingredientesClass, Classes *classes);
    void gestaoUtilizadores(Class *utilizadorClass, Classes *classes);
    void gestaoUnidades(Class *unidadesClass, Classes *classes);
    void gestaoTipoUtilizadores(Class *tipoUtilizadorClass, Classes *classes);
    void gestaoEncomenda(Class *encomendaClass, Classes *classes);
    void gestaoProducao(Class *producaoClass, Classes *classes);
    void gestaoProdutoFinal(Class *produtoFinalClass, Classes *classes);
    void gestaoLinhaEncomenda(Class *linhaEncomendaClass, Classes *classes);
    void gestaoLinhaProducaoFinal(Class *linhaProdutoFinalClass, Classes *classes);
    void gestaoAdmin(Classes *classes);
    void menuLogin(Classes *classes)
    
#ifdef	__cplusplus
}
#endif

#endif	/* MENU_H */
