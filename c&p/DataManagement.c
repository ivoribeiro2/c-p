#include "DataManagement.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*DataManagement API implementation */

//TODO Separate functions in diferent implementations
//TODO Convert functions to use Class

/* Cast functions */

//TODO Implement cast functions to all data types

/**
 * 
 * @param s - Memory adress of variable to make cast to char
 * @return 
 */
char *castString(void *s) {
    char *val = (char *) s;
    return val;
}

/**
 * 
 * @param i - Memory adress of variable to make cast to int
 * @return 
 */
int castInt(void *i) {
    return *(int*) i;
}

/**
 * 
 * @param sh - Memory adress of variable to make cast to short
 * @return 
 */
short castShort(void *sh) {
    return *(short*) sh;
}

/* End of Cast functions */

/* Get functions */

//TODO real necessary functions?

/**
 * 
 * @param f - Memory adress of variable to make cast to float
 * @return 
 */
float castFloat(void *f) {
    return *(float*) f;
}

/* Get value functions  */

/**
 * 
 * @param i - Memory adress of variable to make cast to int 
 * @param storage
 */
void getInt(void *i, void *storage) {
    int *val = (int *) i;
    int *s = (int*) storage;
    *s = *val;

};

/**
 * 
 * @param i - Memory adress of variable to make cast to int 
 * @param storage
 */
void getShort(void *sh, void *storage) {
    short *val = (short *) sh;
    short *s = (short*) storage;
    *s = *val;

};

/**
 * 
 * @param s
 * @param storage
 */
void getString(void *s, void *storage) {
    char *val = (char *) s;
    char *st = (char*) storage;
    *st = *val;
};

/**
 * 
 * @param f
 * @param storage
 */
void getFloat(void *f, void *storage) {
    float *val = (float *) f;
    float *s = (float*) storage;
    *s = *val;
};

/**
 * 
 * @param type type
 * @param reg
 * @param storage
 */
void get(DataType type, void *reg, void *storage) {
    if (type == STRING) {
        getString(reg, storage);
    } else if (type == INT) {
        getInt(reg, storage);
    } else if (type == SHORT) {
        getShort(reg, storage);
    } else if (type == FLOAT) {
        getFloat(reg, storage);
    }
}

/**
 * This method returns to a given pointer the value of a chosen atribute structure element;
 * @param *structElement-Pointer to the element structure;
 * @param *aux-Pointer to the aux structure;
 * @param atributeNumber-Atribute number inside of the structure;
 * @param *storage-Pointer to the variable where de atribute value is going to;
 * 
 */
void getAtributeValue(void * element, FieldAux *aux, const unsigned int atributeNumber, void * storage) {

    unsigned i;
    for (i = 0; i < atributeNumber; ++i) {
        element = element + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;
    if (type == STRUCT) {
    }
    get(type, element, storage);

};

/* END of Get functions */

/*Print Functions*/

/**
 * 
 * @param s
 */
void printString(const void *s) {
    puts(castString(s));
}

/**
 * 
 * @param s
 */
void printChar(const void *c) {
    puts(castString(c));
}

/**
 * 
 * @param i
 */
void printInt(const void * i) {
    printf("%d", castInt(i));
    puts("");
}

/**
 * 
 * @param sh
 */
void printShort(const void * sh) {
    printf("%hd", castShort(sh));
    puts("");
}

/**
 * 
 * @param ui
 */
void printUnsignedInt(const void * ui) {
    unsigned int *val = (unsigned int *) ui;
    printf("%ui", *val);
    puts("");
}

/**
 * 
 * @param f
 */
void printFloat(const void * f) {
    printf("%f", castFloat(f));
}

/*
 * @brief Imprime qualquer tipo de dados, recebe um tipo de dados e o valor a imprimir como parametros
 * @param type- tipo de dados do valor dado
 * @param *val- endereço de memoria do valor
 * Exemplo:
 * @code
 * int i = 1;
 * print(INT,&i);
 * @endcode
 */
void print(const DataType type, const void *const val) {

    if (type == STRING) {
        printString(val);
    } else if (type == INT) {
        printInt(val);
    } else if (type == SHORT) {
        printShort(val);
    } else if (type == UNSIGNED_INT) {
        printUnsignedInt(val);
    } else if (type == FLOAT) {
        printFloat(val);
    }
}

/*End of Print Functions*/

/*Compare functions*/

/**
 * 
 * @param string_one
 * @param string_two
 * @return 
 */
bool compareStrings(void *string_one, void *string_two) {
    string_one = castString(string_one);
    string_two = castString(string_two);
    if (strcmp(string_one, string_two) == 0) return true;
    else return false;
}

/**
 * 
 * @param type_one
 * @param value_one
 * @param type_two
 * @param value_two
 * @return 
 */
bool generalCompare(DataType type_one, void *value_one, DataType type_two, void *value_two, char *signal) {
    //TODO nao esta a fazer cast
    if (type_one == INT) {
        *(int*) value_one = castInt(value_one);
        //printf("%d", value_one);
    } else if (type_one == FLOAT) {
        *(float*) value_one = castFloat(value_one);
    } else if (type_one == SHORT) {
        *(short*) value_one = castShort(value_one);
    }
    if (type_two == INT) {
        *(int*) value_two = castInt(value_two);
    } else if (type_two == FLOAT) {
        *(float*) value_two = castFloat(value_two);
    } else if (type_two == SHORT) {
        *(short*) value_two = castShort(value_two);
    }

    char cmpSignal[2 + 1];
    strcpy(cmpSignal, "==");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if ((*(short*) value_one) == (*(short*) value_two)) return true;
        else return false;
    }
    strcpy(cmpSignal, ">");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one > *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, "<");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one < *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, ">=");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one >= *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, "<=");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one <= *(int*) value_two) return true;
        else return false;
    }
    strcpy(cmpSignal, "!=");
    if (compareStrings(signal, cmpSignal) == true) {
        //TODO nao fazer cast aqui
        if (*(int*) value_one != *(int*) value_two) return true;
        else return false;
    }




}

/**
 * 
 * @param varType
 * @param varValue
 * @param toCompareType
 * @param toCompareValue
 * @return 
 */
bool compare(DataType varType, void* varValue, DataType toCompareType, void * toCompareValue, char *signal) {
    unsigned int toReturn = false;
    if (varType == STRING && toCompareType == STRING) {
        toReturn = compareStrings(varValue, toCompareValue);
    } else {
        if (generalCompare(varType, varValue, toCompareType, toCompareValue, signal) == true) toReturn = true;
        else toReturn = false;
    }
    return toReturn;
}

/*End of Compare Functions*/

/*Search Functions*/

/**
 * 
 * @param field - field number of  the auxStruct 
 * @param searchValue - memory adress of the search value
 * @param list - Class data
 * @param aux - Memory adress of the auxiliary struct 
 * @param elementsNumber - number of data elements (number of registries)
 * @param structTypeSize - Size of the Class data type 
 * @param searchValueType - Type of the search value 
 * @param resultCounter - Memory adress of a unsigned int variable ,contains the number of registries found  ( query rows number )  
 * @return a pointer to an array with the keys founded , if 0 founded , return -1 in all array positions 
 */
int * search(const unsigned int field, void *searchValue, void * list, FieldAux *aux, const unsigned int elementsNumber, const unsigned int structTypeSize, DataType searchValueType, unsigned int *resultCounter, char *signal) {

    unsigned int i = 0, j = 0;
    *resultCounter = 0;
    void *reg;
    int atributeValue = NULL;

    static int resultKeys[MAX_RESULTS];
    for (i = 0; i < elementsNumber; i++) {
        reg = list + (structTypeSize * i);
        //TODO implementar a função elementMemoryAdress
        getAtributeValue(reg, aux, field, &atributeValue);
        DataType type = aux[field].type;
        unsigned int result = compare(type, &atributeValue, searchValueType, searchValue, signal);
        if (result == true) {
            resultKeys[*resultCounter] = i;
            (*resultCounter)++;
        }
    }
    for (j = *resultCounter; j < MAX_RESULTS; j++) {
        resultKeys[j] = NO_VALUE;
    }
    if (*resultCounter == 0) puts("No value found in search");
    return resultKeys;
};

//TODO search function to only one result

/**
 * Returns de first result founded
 * @param class
 * @param field
 * @param searchValue
 * @param searchValueType
 * @param resultCounter
 * @param signal
 * @return 
 */
int searchSingle(Class *class, const unsigned int field, void *searchValue, DataType searchValueType, unsigned int *resultCounter, char *signal) {
    int * search_result;
    search_result = search(field, searchValue, class->data, class->auxStruct, *(class->elements), class->StructTypeSize, searchValueType, resultCounter, signal);
    if (resultCounter != 0) {
        return (*(search_result + 0));
    } else {
        puts("Search Single: search value not found");
        return NO_VALUE;
    }
};


/*End of Search Functions*/

/*List Functions*/

/**
 * this method does a parsed list of a registry (one registry + given fields)
 * @param class - Class (Table)
 * @param key - number of Class data registry
 * @param fields - Memory adress of a int array of the chosen Class aux fields
 * @param fieldsNumber - Number of fields chosen
 */
void singleParsedList(Class *class, const unsigned int key, int *fields, unsigned fieldsNumber) {

    int keys[] = {key};
    parsedList(class, keys, 1, fields, fieldsNumber);
}

/**
 * This method list a field -> value of any Class data 
 * @param reg - Memory adress of some field 
 * @param aux - Memory adress of the auxiliary struct 
 * @param field - Aux field number
 */
void listRegistry(void * reg, FieldAux *aux, unsigned field) {
    unsigned i, j;
    for (i = 0; i < field; ++i) {
        reg = reg + aux[i].sizeBytes;
    }

    DataType type = aux[i].type;
    if (type != STRUCT) {
        if (aux[i].foreignKey == true) {
            unsigned int resultNumber;
            char signal[2 + 1];
            strcpy(signal, "==");
            int result = NO_VALUE;
            result = searchSingle(aux[i].parentClass, aux[i].parentPrimaryKey, reg, aux[i].type, &resultNumber, signal);
            //result = search(aux[i].parentPrimaryKey, reg, aux[i].parentClass->data, aux[i].parentClass->auxStruct, *(aux[i].parentClass->elements), aux[i].parentClass->StructTypeSize, aux[i].type, &resultNumber, signal);
            if (result != NO_VALUE) {
                int field[1];
                field[0] = aux[i].parentClass->aliasField;
                singleParsedList(aux[i].parentClass, result, field, 1);
            } else {
                FieldAux *parentAux;
                parentAux = aux[i].parentClass->auxStruct;
                printf("No value found on Parent class %s primary key field %s \n", aux[i].parentClass->name, parentAux[aux[i].parentPrimaryKey]);
            }
        } else if (aux[i].foreignKey != true) {
            if (reg != NULL) {
                print(type, reg);
            } else puts("No Value");
        }
        puts("");

    }
}


/*Function not implemented*/

/**
 * 
 * @param list
 * @param structTypeSize
 * @param elementNumber
 * @param storage
 */
void * elementMemoryAdress(void * list, const unsigned int structTypeSize, const unsigned int elementNumber) {
    return list + (structTypeSize * elementNumber);
}

/**
 * This method does a full (full elements(keys) + full atributes(fields)) list of a given Class data
 * 
 * @param list - Memory adress of some Class data struct
 * @param structTypeSize - Size of the struct type
 * @param listSize - Number of Class data registries
 * @param aux - Memory adress of some Class auxiliary struct
 * @param fieldsNumber - Number of auxiliary struct registries (Number of fields that table contains)
 */
void fullList(Class *class) {
    unsigned int i = 0, j = 0;
    FieldAux *aux = class->auxStruct;
    for (i = 0; i < *(class->elements); i++) {
        puts("---------------------------------------------");
        for (j = 0; j < class->fieldsNumber; j++) {

            if (aux[j].foreignKey != true) {
                printString(aux[j].alias);
            }
            listRegistry(elementMemoryAdress(class->data, class->StructTypeSize, i), aux, j);
        }
        puts("---------------------------------------------");
    }
}

/**
 * This method does a parsed (chosed elements(keys) + chosed atributes(fields)) list of a given Class data
 * @param list - Memory adress of some Class data struct
 * @param structTypeSize - Size of the struct type
 * @param aux - Memory adress of some Class auxiliary struct
 * @param elements - Memory adress of an array of int keys
 * @param elementsNumber  - Number of elements in the array gived 
 * @param fields - Memory adress of array of int fields 
 * @param fieldsNumber - Number of fields int the array gived 
 */
void parsedList(Class *class, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {
    unsigned int i = 0, j = 0;
    FieldAux *aux = class->auxStruct;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            if (aux[fields[j]].foreignKey != true) {
                printString(aux[fields[j]].alias);
            }
            listRegistry(elementMemoryAdress(class->data, class->StructTypeSize, elements[i]), aux, fields[j]);
        }
        //puts("---------------------------------------------");
    }
}

/**
 * This method does a full list (all the fields) of a Class data registry 
 * @param class - Memory Adress of some Class (table)
 * @param key - Key number of the Class data registry that will be listed 
 */
void singleList(Class *class, const unsigned int key) {

    int keys[] = {key};
    int fields[class->fieldsNumber];
    unsigned int i;
    for (i = 0; i < class->fieldsNumber; i++) {
        fields[i] = i;
    }
    parsedList(class, keys, 1, fields, class->fieldsNumber);
}

/*End of list Functions*/

/*Read Functions*/

/**
 * 
 * @param field
 * @param maxSize
 */
void readString(void * field, const unsigned int maxSize) {
    scanf("%[^\n]s", castString(field));
    while (getchar() != '\n');

};

/**
 * 
 * @param field
 */
void readInt(void * field) {
    scanf("%d", field);
    while (getchar() != '\n');
};

/**
 * 
 * @param field
 */
void readShort(void * field) {
    scanf("%hd", field);
    while (getchar() != '\n');
};

/**
 * 
 * @param field
 */
void readFloat(void * field) {
    scanf("%f", field);
    while (getchar() != '\n');
};

/**
 * 
 * @param field
 */
void readChar(void * field) {
    scanf("%c", field);
    while (getchar() != '\n');
}

/**
 * 
 * @param type
 * @param field
 * @param maxSize
 */
void read(DataType type, void * field, const unsigned int maxSize) {
    if (type == STRING) {
        readString(field, maxSize);
    } else if (type == INT) {
        readInt(field);
    } else if (type == SHORT) {
        readShort(field);
    } else if (type == FLOAT) {
        readFloat(field);
    }
}

bool foreignKeyRead(FieldAux *aux, const unsigned short field) {

    printString(aux[field].parentClass->name);
    puts("1-List / 2-New");
    unsigned int op;
    readInt(&op);
    if (op == 1) {
        puts("");
        puts("__________________________________________________________________________");
        puts("__________________________________________________________________________");
        fullList(aux[field].parentClass);
        puts("__________________________________________________________________________");
        puts("__________________________________________________________________________");
        puts("");
    } else if (op == 2) {
        fullRead(aux[field].parentClass, CREATE, *(aux[field].parentClass->elements));
    }
    return op;
}
//TODO setField

void setField(DataType fieldType, void * field, void *value) {
    if (fieldType == SHORT) {
        * (short*) field = (short*) value;
    }
    if (fieldType == INT) {
        * (int*) field = (int*) value;
    }
}

/**
 * This method read a registy of a given Class data
 * @param rtype request type ( not implemented )
 * @param reg the Class data registry
 * @param aux Memory adress of some Class auxiliary struct
 * @param field field number of the Class Aux struct  
 */

void readRegistry(Class *class, RequestType rtype, void * reg, unsigned field) {
    unsigned i, j;
    unsigned short op;
    FieldAux * aux = class->auxStruct;
    for (i = 0; i < field; ++i) {
        reg = reg + aux[i].sizeBytes;
    }
    DataType type = aux[i].type;

    //IF the request type is CREATE and the field is auto incremental will not request user data and set automat number (last reg number + step)
    if (rtype == CREATE && aux[i].autoIncrement == true) {
        unsigned short step;
        step = (*(class->elements) + aux[i].step);
        setField(type, reg, &step);
    } else {
        if (aux[i].type != STRUCT) {
            if (aux[i].foreignKey == true) {
                op = foreignKeyRead(aux, i);
            }
            //SE não for chave estrangeira ou se for chave estrangeira e ter sido escolhida opção de listagem 
            if (op == 0 || op == 1) {
                if (aux[i].required == true) {
                    do {
                        printString(aux[i].alias);
                        read(type, reg, aux[i].maxSize);
                        puts("");
                    } while (reg == NULL);

                } else {
                    printString(aux[i].alias);
                    read(type, reg, aux[i].maxSize);
                    puts("");
                }
            } else if (op == 2) {
                unsigned short lastReg = *(aux[field].parentClass->elements) + 1;
                setField(type, reg, &lastReg);
            }
        }
    }
}

/**
 This method does a parsed (chosed elements(keys) + chosed atributes(fields)) read of a given Class data
 * @param rtype
 * @param structTypeSize - Size of the struct type
 * @param list - Memory adress of some Class data struct
 * @param aux - Memory adress of some Class auxiliary struct
 * @param elements - Memory adress of an array of int keys
 * @param elementsNumber  - Number of elements in the array gived 
 * @param fields - Memory adress of array of int fields 
 * @param fieldsNumber - Number of fields int the array gived 
 * 
 * 
 */
void parsedRead(Class *class, RequestType rtype, int *elements, unsigned elementsNumber, int *fields, unsigned fieldsNumber) {

    unsigned int i = 0, j = 0;
    for (i = 0; i < elementsNumber; i++) {
        for (j = 0; j < fieldsNumber; j++) {
            readRegistry(class, rtype, elementMemoryAdress(class->data, class->StructTypeSize, elements[i]), fields[j]);
        }
        puts("---------------------------------------------");
    }

}

void singleParsedRead(Class *class, RequestType rtype, const unsigned int element, int *fields, unsigned fieldsNumber) {
    int elements[] = {element};
    parsedRead(class, rtype, elements, 1, fields, fieldsNumber);
}

/**
 * 
 * @param rType
 * @param structTypeSize
 * @param list
 * @param element
 * @param aux
 * @param fieldsNumber
 */
void fullRead(Class * class, RequestType rType, const unsigned short element) {
    unsigned int j = 0;
    for (j = 0; j < class->fieldsNumber; j++) {
        readRegistry(class, rType, elementMemoryAdress(class->data, class->StructTypeSize, element), j);
    }
    puts("---------------------------------------------");
}

/*End of read Functions*/

/**
 * This method checks if already exists a given value in a Class data (table) atribute (field) 
 * @param field
 * @param searchValue
 * @param list
 * @param aux
 * @param elementsNumber
 * @param structTypeSize
 * @param searchValueType
 * @return 
 */
bool checkUniqueField(const unsigned int field, void *searchValue, void * list, FieldAux *aux, const unsigned int elementsNumber, const unsigned int structTypeSize, DataType searchValueType) {
    if (aux[field].unique) {
        unsigned int resultCounter;
        char signal[2 + 1];
        strcpy(signal, "==");
        search(field, searchValue, list, aux, elementsNumber, structTypeSize, searchValueType, &resultCounter, signal);
        if (resultCounter == 0) return false;
        else return true;

    } else {
        puts("Field isn't unique");
    }
}

/**
 * 
 * @param structTypeSize
 * @param list
 * @param contador
 * @param aux
 * @param fieldsNumber
 */
void create(Class *class) {
    fullRead(class, CREATE, (*class->elements));
    (*class->elements)++;

}

void update() {
};

void delete() {
};



/*Function not implemented*/

/**
 * 
 * @param vet
 * @param chave
 * @param Tam
 * @return 
 */
int PesquisaBinaria(int vet[], int chave, int Tam) {
    int inf = 0; //Limite inferior      (o primeiro elemento do vetor em C é zero          )
    int sup = Tam - 1; //Limite superior    (termina em um número a menos 0 à 9 são 10 numeros )
    int meio;
    while (inf <= sup) {
        meio = (inf + sup) / 2;
        if (chave == vet[meio])
            return meio;
        else if (chave < vet[meio])
            sup = meio - 1;
        else
            inf = meio + 1;
    }
    return -1; // não encontrado
}

/*Function not implemented*/



void removeKey(Class *class, const unsigned short key) {
    unsigned short i;
    for (i = key; i < (*class->elements) - 1; i++) {
        memcpy(elementMemoryAdress(class->data, class->StructTypeSize, i), elementMemoryAdress(class->data, class->StructTypeSize, i + 1), class->StructTypeSize);
    }
    (*class->elements)--;
}

/**
 * This function randomize a chosed quantity of numbers , of a given array
 * @param array - Memory adress of a int array , 
 * @param n , quantity of numbers that will be returned 
 * @param limit - array limit
 * @return  an memory adress of an array of requested number of randomized integers
 */
int * randomize(int *array, size_t n, int limit) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n; i++) {
            srand(time(0));
            size_t j = i + rand() / (RAND_MAX / (limit - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
    return array;
}

time_t getUnixTime() {
    time_t clk = time(NULL);
    return clk;
}

void convertDate(time_t *unixTime) {
    printf("%s", ctime(unixTime));

};




