/* 
 * File:   DataManagement.h
 * Author: ivo
 *
 * Created on 24 de Novembro de 2014, 18:15
 */

#ifndef DATAMANAGEMENT_H
#define	DATAMANAGEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "Date.h" 

    typedef int bool;
#define true 1
#define false 0

    typedef unsigned short TypeSize;
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define INT_SIZE sizeof(int)
#define SHORT_SIZE sizeof(short)
#define UNSIGNED_SHORT_SIZE sizeof(unsigned short)
#define UNSIGNED_INT_SIZE sizeof(unsigned int)
#define BOOL_SIZE sizeof(bool)
#define DATE_SIZE sizeof(Date)

#define NO_VALUE -1

#define SHORT_STRING 28
#define MEDIUM_STRING 80
#define LONG_STRING 260 

#define MAX_RESULTS 50

    /*
     * Data Types
     */
    typedef enum {
        INT,
        SHORT,
        UNSIGNED,
        STRING,
        CHAR,
        VOID,
        FLOAT,
        UNSIGNED_SHORT,
        UNSIGNED_INT,
        STRUCT,
        BOOL,
        DATE
    } DataType;

    /*
     * Type of request ( functionality not implemented )
     */
    typedef enum {
        CREATE,
        UPDATE,
        LIST,
        DELETE
    } RequestType;

    /*
     * @atribute name - Class name ( name of the table )
     * @atribute primaryKeyField - Number of primary key field
     * @atribute data - memory adress of the struct that contains all the class registries   
     * @atribute StructTypeSize - Bytes size of the data struct type
     * @atribute auxStruct - Memory adress of the struct that contains all the fields information
     * @atribute elements - Memory adress  of the variable that contains the actual number of data struct registries ( table registries number )
     * @atribute aliasField - Number of the auxStruct field that is going to be displayed if a foreign key requested
     */
    typedef struct {
        char name[20];
        unsigned short primaryKeyField;
        void *data;
        unsigned int StructTypeSize;
        void *auxStruct;
        unsigned short *elements;
        unsigned int fieldsNumber;
        unsigned int aliasField;
        char fileName[SHORT_STRING];
    } Class;

    /*
     *@atribute fieldName- Name of the field ( table field )
     *@atribute alias - Name that is going to be displayed on lists 
     *@atribute  type - Field data type
     *@atribute required - If the field is required or if can be leaved in white
     *@atribute unique - If the field can have replications( functionality not implemented ) 
     *@atribute autoIncrement - If the field is auto incremental 
     *@atribute primaryKey - If the field is a primary key of the table
     *@atribute foreignKey - If the field is a foreign key and have relation with other table
     *@atribute parentClass -Memory adress of the Class (table) that is related too
     *@atribute parentPrimaryKey - Number of the primary key field that is going to be relationated
     *@atribute step - Number of step if the field is auto incremental ex: step 1: 1,2,3,4 ; step 2 :1,3,5,7 ;
     *@atribute sizeBytes - Bytes size of the field type
     *@atribute minSize - Minimum size of the field ( functionality not implemented )
     *@atribute maxSize - Maximum size of the field ( functionality not implemented )   
     *@atribute substruct - Memory adress of the Class (case this field is a struct ) ( functionality not implemented )
     */
    typedef struct {
        char fieldName[MEDIUM_STRING];
        char alias[MEDIUM_STRING];
        DataType type;
        bool required;
        bool unique;
        bool autoIncrement;
        bool primaryKey;
        bool foreignKey;
        Class *parentClass;
        unsigned short parentPrimaryKey;
        unsigned int step;
        TypeSize sizeBytes;
        unsigned int minSize;
        unsigned int maxSize;
        void *substructClass;
        bool date;
    } FieldAux;

    /*
     *Interface implementation ( not completed )
     */

    typedef struct {
        void (*listRegistry)(void *, FieldAux *, unsigned);
        void (*fullList)(void *, const unsigned short, const unsigned int, FieldAux *, const unsigned int);
        void (*parsedList)(void *, const unsigned short, FieldAux *, int *, unsigned, int *, unsigned);
    } List;

    typedef struct {
        void(*fullRead)(RequestType, const unsigned short, void *, const unsigned int, FieldAux *, const unsigned int);
        void(*parsedRead)(RequestType, void *, FieldAux *, int *, unsigned, int *, unsigned);
        void(*readRegistry)(RequestType, void *, FieldAux *, unsigned);

    } Read;

    typedef struct {
        void (*create)(const unsigned short stuctTypeSize, void * list, int *contador, FieldAux *aux, const unsigned int fieldsNumber);
        Read read;
        void (*update)();
        void (*delete)();
        List list;
    } crud;

    //Print interface
    void printString(const void *s);
    void printInt(const void *i);
    void printUnsignedInt(const void * ui);
    void printFloat(const void * f);
    void print(const DataType type, const void *const val);

    //List interface
    //void listRegistry(void * reg, FieldAux *aux, unsigned field);
    //void fullList(void *list, const unsigned short stuctTypeSize, const unsigned int listSize, FieldAux *aux, const unsigned int fieldsNumber);
    //void parsedList(void *list, const unsigned short stuctTypeSize, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber);

    //Create interface
    //void create(const unsigned short stuctTypeSize, void * list, int *contador, FieldAux *aux, const unsigned int fieldsNumber);

    //Read interface
    //void read();
    //void parsedRead(RequestType rtype, const unsigned short stuctTypeSize, void *list, FieldAux *aux, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber);
    //void fullRead(RequestType rType, const unsigned short stuctTypeSize, void * list, const unsigned int element, FieldAux *aux, const unsigned int fieldsNumber);

    //Update interface
    void update();

    //Delete interface
    void delete();






#ifdef	__cplusplus
}
#endif

#endif	/* DATAMANAGEMENT_H */

