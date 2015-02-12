/* 
 * File:   Date.h
 * Author: ivo
 *
 * Created on February 11, 2015, 4:53 PM
 */

#ifndef DATE_H
#define	DATE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        unsigned short day;
        unsigned short month;
        unsigned short year;
    } Date;

#ifdef	__cplusplus
}
#endif

#endif	/* DATE_H */

