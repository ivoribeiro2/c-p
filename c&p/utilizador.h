/* 
 * File:   utilizador.h
 * Author: ivo
 *
 * Created on January 27, 2015, 4:00 PM
 */

#ifndef UTILIZADOR_H
#define	UTILIZADOR_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include "DataManagement.h"
    typedef struct {
        unsigned short id_utilizador;
        unsigned short id_tipo_utilizador;
        char username[SHORT_STRING];
        char password[SHORT_STRING];
    } Utilizador;

    enum CamposUtilizador {
        ID_UTILIZADOR,
        ID_TIPO_UTILIZADOR_UTILIZADOR,
        USERNAME,
        PASSWORD
    };


#ifdef	__cplusplus
}
#endif

#endif	/* UTILIZADOR_H */

