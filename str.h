/*-------------------------------------------------------------------*/
/* str.h.                                                            */
/* Author: Isaac Wolfe                                               */
/* netid: iwolfe                                                     */
/*-------------------------------------------------------------------*/

#include <stddef.h>
#include <assert.h>

/*-------------------------------------------------------------------*/

#ifndef STR_INCLUDED
#define STR_INCLUDED

/* returns the length in size_t of s1 */
size_t Str_getLength(const char *s1);

/* copies the strinf s2 to the stirnf s1 and returns s1 */
char *Str_copy(char *s1, const char *s2);

/* attaches the string s2 to the end of the string s1 
   and returns s1 */
char *Str_concat(char *s1, const char *s2);

/* uses lexagraphic computation to compare s1 and s2 and 
   return an int:
   0 is returned if they are equal
   1 is returned is s1 is greater than s2
   -1 is returned if s1 is less than s2 */
int Str_compare(const char *s1, const char *s2);

/* searches through the string s1 for the string s2
   and returns the address where s2 begins if it is
   present, otherwise returning NULL */
char *Str_search(const char *s1, const char *s2);

#endif
