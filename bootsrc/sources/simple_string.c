
/* 
	Copyright (c) 2017-2018 Azeez Adewale <azeezadewale98@gmail.com"> 
	MIT License Copyright (c) 2017 simple 

*/

/* 
 * File:   simple.h
 * Author: thecarisma
 *
 * Created on July 10, 2017, 1:10 PM
 */


#include "../includes/simple.h"
/* Blocks */

SIMPLE_API String * simple_string_new_gc ( void *pState,const char *str )
{
	int x  ;
	x = strlen( str ) ;
	return simple_string_new2_gc(pState,str,x) ;
}

SIMPLE_API String * simple_string_new2_gc ( void *pState,const char *str,int nStrSize )
{
	String *string  ;
	int x  ;
	string = (struct String *) simple_state_malloc(pState,sizeof(struct String));
	if ( string == NULL ) {
		printf( SIMPLE_OOM ) ;
		exit(0);
	}
	string->cStr = (char *) simple_state_malloc(pState,nStrSize+1);
	if ( string->cStr  == NULL ) {
		printf( SIMPLE_OOM ) ;
		exit(0);
	}
	/* Copy String */
	for ( x = 0 ; x < nStrSize ; x++ ) {
		string->cStr[x] = str[x] ;
	}
	string->cStr[nStrSize] = '\0' ;
	string->nSize = nStrSize ;
	return string ;
}

SIMPLE_API String * simple_string_delete_gc ( void *pState,String *string )
{
	assert(string != NULL);
	simple_state_free(pState,string->cStr);
	string->cStr = NULL ;
	simple_state_free(pState,string);
	return NULL ;
}

SIMPLE_API int simple_string_size ( String *string )
{
	assert(string != NULL);
	return string->nSize ;
}

SIMPLE_API void simple_string_set_gc ( void *pState,String *string,const char *str )
{
	int x  ;
	assert(string != NULL);
	x = strlen( str ) ;
	simple_string_set2_gc(pState,string,str,x);
}

SIMPLE_API void simple_string_set2_gc ( void *pState,String *string,const char *str,int nStrSize )
{
	int x  ;
	assert(string != NULL);
	assert(string->cStr != NULL);
	simple_state_free(pState,string->cStr);
	string->cStr = (char *) simple_state_malloc(pState,nStrSize+1);
	if ( string->cStr  == NULL ) {
		printf( SIMPLE_OOM ) ;
		exit(0);
	}
	/* Copy String */
	for ( x = 0 ; x < nStrSize ; x++ ) {
		string->cStr[x] = str[x] ;
	}
	string->cStr[nStrSize] = '\0' ;
	string->nSize = nStrSize ;
}

SIMPLE_API void simple_string_add_gc ( void *pState,String *string,const char *str )
{
	int x  ;
	x = strlen( str ) ;
	simple_string_add2_gc(pState,string,str,x);
}

SIMPLE_API void simple_string_add2_gc ( void *pState,String *string,const char *str,int nStrSize )
{
	int x  ;
	int x2  ;
	char *cStr  ;
	assert(string != NULL);
	x2 = nStrSize+simple_string_size(string) ;
	cStr = string->cStr ;
	string->cStr = (char *) simple_state_malloc(pState,x2+1);
	if ( string->cStr  == NULL ) {
		printf( SIMPLE_OOM ) ;
		exit(0);
	}
	/* Copy String */
	for ( x = 0 ; x < simple_string_size(string) ; x++ ) {
		string->cStr[x] = cStr[x] ;
	}
	for ( x = 0 ; x < nStrSize ; x++ ) {
		string->cStr[x+simple_string_size(string)] = str[x] ;
	}
	string->cStr[x2] = '\0' ;
	string->nSize = x2 ;
	simple_state_free(pState,cStr);
}

SIMPLE_API void simple_string_print ( String *string )
{
	assert(string != NULL);
	printf( "%s \n",string->cStr ) ;
}

SIMPLE_API void simple_string_setfromint_gc ( void *pState,String *string,int x )
{
	char cStr[20]  ;
	assert(string != NULL);
	sprintf( cStr , "%d" , x ) ;
	simple_string_set_gc(pState,string,cStr);
}

SIMPLE_API char * simple_string_lower ( char *cStr )
{
    if( NOT_CASE_SENSITIVE ){
        unsigned int x  ;
        for ( x = 0 ; x < strlen(cStr) ; x++ ) {
            if ( isalpha(cStr[x]) ) {
                    cStr[x] = tolower( cStr[x] );
            }
        }
    }
    return cStr ;
}

SIMPLE_API char * simple_string_lower2 ( char *cStr,int nStrSize )
{
	int x  ;
	for ( x = 0 ; x < nStrSize ; x++ ) {
		if ( isalpha(cStr[x]) ) {
			cStr[x] = tolower( cStr[x] );
		}
	}
	return cStr ;
}

SIMPLE_API char * simple_string_upper ( char *cStr )
{
	unsigned int x  ;
	for ( x = 0 ; x < strlen(cStr) ; x++ ) {
		if ( isalpha(cStr[x]) ) {
			cStr[x] = toupper( cStr[x] );
		}
	}
	return cStr ;
}

SIMPLE_API char * simple_string_upper2 ( char *cStr,int nStrSize )
{
	int x  ;
	for ( x = 0 ; x < nStrSize ; x++ ) {
		if ( isalpha(cStr[x]) ) {
			cStr[x] = toupper( cStr[x] );
		}
	}
	return cStr ;
}

SIMPLE_API char * simple_string_find_gc ( void *pState,char *string_one,char *cStr2 )
{
	return simple_string_find2_gc(pState,string_one,strlen(string_one),cStr2,strlen(cStr2)) ;
}

SIMPLE_API char * simple_string_find2_gc ( void *pState,char *string_one,int nStrSize1,char *cStr2,int nStrSize2 )
{
	int nPos,x  ;
	nPos = 0 ;
	if ( (nStrSize1 - nStrSize2) < 0 ) {
		return NULL ;
	}
	while ( nPos <= (nStrSize1 - nStrSize2) ) {
		x = 0 ;
		while ( (x < nStrSize2) && (string_one[nPos+x] == cStr2[x] ) ) {
			x++ ;
		}
		if ( x == nStrSize2 ) {
			return string_one+nPos ;
		}
		nPos++ ;
	}
	return NULL ;
}

SIMPLE_API char * simple_string_find3_gc ( void *pState,char *string_one,int nStrSize1,char *cStr2,int nStrSize2 )
{
	int nPos,x  ;
	char *cStr3  ;
	char *cStr4  ;
	char *pOutput  ;
	/* This block is not case sensitive and work on a copy from string_one and cStr2 */
	nPos = 0 ;
	if ( (nStrSize1 - nStrSize2) < 0 ) {
		return NULL ;
	}
	/* Copy Strings and convert to lower case */
	cStr3 = (char *) simple_state_malloc(pState,nStrSize1+1);
	cStr4 = (char *) simple_state_malloc(pState,nStrSize2+1);
	if ( (cStr3==NULL) || (cStr4==NULL) ) {
		printf( SIMPLE_OOM ) ;
		exit(0);
	}
	for ( x = 0 ; x <= nStrSize1 ; x++ ) {
		cStr3[x] = string_one[x] ;
	}
	for ( x = 0 ; x <= nStrSize2 ; x++ ) {
		cStr4[x] = cStr2[x] ;
	}
	simple_string_lower2(cStr3,nStrSize1);
	simple_string_lower2(cStr4,nStrSize2);
	pOutput = NULL ;
	while ( nPos <= (nStrSize1 - nStrSize2) ) {
		x = 0 ;
		while ( (x < nStrSize2) && (cStr3[nPos+x] == cStr4[x] ) ) {
			x++ ;
		}
		if ( x == nStrSize2 ) {
			pOutput = string_one+nPos ;
			break ;
		}
		nPos++ ;
	}
	/* Free Memory */
	simple_state_free(pState,cStr3);
	simple_state_free(pState,cStr4);
	return pOutput ;
}

void simple_string_test ( void )
{
	#define nMaxValue 10
	String *mystr[nMaxValue]  ;
	int x  ;
	String *string  ;
	for ( x = 0 ; x < nMaxValue ; x++ ) {
		mystr[x] = simple_string_new("Wow Really i like the c language so much");
		simple_string_print(mystr[x]);
	}
	for ( x = 0 ; x < nMaxValue ; x++ ) {
		mystr[x] = simple_string_delete(mystr[x]);
	}
	/* Test String Add */
	string = simple_string_new("Hello ");
	simple_string_add(string,"World");
	printf( "\nTest String Add , Output = %s\n",simple_string_get(string) ) ;
	simple_string_add(string," Welcome to the C programming language");
	printf( "\nTest String Add , Output = %s\n",simple_string_get(string) ) ;
	simple_string_delete(string);
	/* Test String to Lower */
	string = simple_string_new("Welcome to my StrinG");
	printf( "Test string to lower \n" ) ;
	printf( "%s\n",simple_string_tolower(string) ) ;
	simple_string_delete(string);
	getchar();
}
/* Blocks without state pointer */

SIMPLE_API String * simple_string_new2 ( const char *str,int nStrSize )
{
	return simple_string_new2_gc(NULL,str,nStrSize) ;
}

SIMPLE_API String * simple_string_new ( const char *str )
{
	return simple_string_new_gc(NULL,str) ;
}

SIMPLE_API void simple_string_add ( String *string,const char *str )
{
	simple_string_add_gc(NULL,string,str);
}

SIMPLE_API void simple_string_add2 ( String *string,const char *str,int nStrSize )
{
	simple_string_add2_gc(NULL,string,str,nStrSize);
}

SIMPLE_API void simple_string_set ( String *string,const char *str )
{
	simple_string_set_gc(NULL,string,str);
}

SIMPLE_API void simple_string_set2 ( String *string,const char *str,int nStrSize )
{
	simple_string_set2_gc(NULL,string,str,nStrSize);
}

SIMPLE_API char * simple_string_find ( char *string_one,char *cStr2 )
{
	return simple_string_find_gc(NULL,string_one,cStr2) ;
}

SIMPLE_API char * simple_string_find2 ( char *string_one,int nStrSize1,char *cStr2,int nStrSize2 )
{
	return simple_string_find2_gc(NULL,string_one,nStrSize1,cStr2,nStrSize2) ;
}

SIMPLE_API char * simple_string_find3 ( char *string_one,int nStrSize1,char *cStr2,int nStrSize2 )
{
	return simple_string_find3_gc(NULL,string_one,nStrSize1,cStr2,nStrSize2) ;
}

SIMPLE_API String * simple_string_delete ( String *string )
{
	return simple_string_delete_gc(NULL,string) ;
}

SIMPLE_API void simple_string_setfromint ( String *string,int x )
{
	simple_string_setfromint_gc(NULL,string,x);
}
