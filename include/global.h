#ifndef       __GLOBAL_H__ 
#define       __GLOBAL_H__ 

#include <stdio.h>     /* printf, FILE, etc */  
#include <stdlib.h>    /* malloc etc */
#include <stdint.h>
#include <string.h>    /* memset, memcpy etc */ 
#include <time.h>      /* time related */
#include <errno.h>     /* `errno` global variable */ 

#define BAD_ARGS          -1 
#define BAD_ARGS_PTR      NULL 
#define SUCCESS           1 

/* 
Integer types having exactly the specified width
Source: http://www.nongnu.org/avr-libc/user-manual/group__avr__stdint.html

typedef signed   char           int8_t; 
typedef unsigned char           uint8_t; 
typedef signed   int            int16_t; 
typedef unsigned int            uint16_t; 
typedef signed   long int       int32_t; 
typedef unsigned long int       uint32_t; 
typedef signed   long long int  int64_t; 
typedef unsigned long long int  uint64_t; 
*/ 

void global_print(void);  

#endif 
