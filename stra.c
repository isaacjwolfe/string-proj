/*-------------------------------------------------------------------*/
/* stra.c                                                            */
/* Author: Isaac Wolfe                                               */
/* netid: iwolfe                                                     */
/*-------------------------------------------------------------------*/

#include <stddef.h>
#include <assert.h>
#include "str.h"

/*-------------------------------------------------------------------*/

size_t Str_getLength(const char s1[])
{
	size_t uLength = 0;
	assert(s1 != NULL);
	
	while (s1[uLength] != '\0')
		uLength++;
	return uLength;
}

char *Str_copy(char s1[], const char s2[])
{
	size_t i = 0;
	assert(s1 != NULL);
	assert(s2 != NULL);

	/* copy over items to s1 from s2 until '\0' is reached */
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}

	/* insert the terminating character at the end of s1 */
	s1[i] = '\0';
	return s1;
}

char *Str_concat(char s1[], const char s2[])
{
	size_t uLength = Str_getLength(s1);
	size_t i = 0;

	assert(s1 != NULL);
	assert(s2 != NULL);

	/* add items from s2 to the end of s1 until '\0' is recached */
	while (s2[i] != '\0')
	{
		s1[uLength] = s2[i];
		uLength++;
		i++;
	}

	/* insert the terminating character at the end of s1 */
	s1[uLength] = '\0';
	return s1;
}

int Str_compare(const char s1[], const char s2[])
{
	int i = 0;

	assert(s1 != NULL);
	assert(s2 != NULL);

	/* when the stirngs are equal and '\0' is reached, return 0 */
	while (s1[i] == s2[i]) 
	{
		if (s1[i] == '\0') return 0;
		i++;
	}

	/* return positive is s1 is greater than s2 
	and negative otherwise */
	if (s1[i] > s2[i]) return 1;
	else return -1;
}

char *Str_search(const char s1[], const char s2[]) 
{
	/* declare and define indexes to iterate through the haystack 
	and the needle, as well as a variable to store the start point
	of the needle when it is found */
	size_t uBigIndex, uLittleIndex, uNeedleStart, uInternalBigIndex;
	uBigIndex = 0; 
	uLittleIndex = 0;
	uNeedleStart = 0;
	uInternalBigIndex = 0;

	assert(s1 != NULL);
	assert(s2 != NULL);

	/* retuen the haystack if the needle has a lenght of 0 */
	if (Str_getLength(s2) == 0) return (char *)s1;

	/* iterate through the haystack until it reaches the end*/
	while (s1[uBigIndex] != '\0')
	{
		/* when a match is discovered... */
		if (s1[uBigIndex] == s2[uLittleIndex]) 
		{
			/* ... store the start of the match... */
			uNeedleStart = uBigIndex;

			/* ... and iterate through the needle and haystack to
			check for a complete match */
			while (s1[uInternalBigIndex] == s2[uLittleIndex])
			{
				uInternalBigIndex++;
				uLittleIndex++;

				/* return or break depending on how the match
				situation terminates */
				if ((s1[uInternalBigIndex] == '\0') && 
					(s2[uLittleIndex] != '\0')) 
					break;

				if ((s1[uInternalBigIndex] == '\0') && 
					(s2[uLittleIndex] == '\0'))
					return (char *)&s1[uNeedleStart];

				if (s2[uLittleIndex] == '\0') 
					return (char *)&s1[uNeedleStart];

			}
			/* if a complete match has not been found, 
			reset our variables */
			uLittleIndex = 0;
			uInternalBigIndex = uBigIndex;
		}
		/* iterate haystack indexes to continue traversal */
		uBigIndex++;
		uInternalBigIndex++;
	}
	return NULL;
}
