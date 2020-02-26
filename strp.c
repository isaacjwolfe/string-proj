/*-------------------------------------------------------------------*/
/* strp.c                                                            */
/* Author: Isaac Wolfe                                               */
/* netid: iwolfe                                                     */
/*-------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include "str.h"

/*-------------------------------------------------------------------*/

size_t Str_getLength(const char *s1)
{
	const char *pcEnd;
	assert(s1 != NULL);
	pcEnd = s1;
	while (*pcEnd != '\0')
		pcEnd++;
	return (size_t)(pcEnd - s1);
}

char *Str_copy(char *s1, const char *s2)
{
	char *temp;

	assert(s1 != NULL);
	assert(s2 != NULL);

	temp = s1;

	/* copy over items to s1 from s2 until '\0' is reached */
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++; 
	}

	/* insert the terminating character at the end of s1 */
	*s1 = '\0';
	return temp;
}

char *Str_concat(char *s1, const char *s2)
{
	char *temp;
	size_t uLength;

	assert(s1 != NULL);
	assert(s2 != NULL);

	/* save temp of beginning and add length of s2 to s1*/
	temp = s1;
	uLength = Str_getLength(s1);
	s1 += uLength;

	/* add items from s2 to the end of s1 until '\0' is recached */
	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}

	/* insert the terminating character at the end of s1 */
	*s1 = '\0';
	return temp;
}

int Str_compare(const char *s1, const char *s2)
{
	assert(s1 != NULL);
	assert(s2 != NULL);

	/* when the strings are equal and '\0' is reached, return 0 */
	while (*s1 == *s2) 
	{
		if (*s1 == '\0') return 0;
		s1++;
		s2++;
	}

	/* return positive if s1 is greater than s2 
	and negative otherwise */
	if (*s1 > *s2) return 1;
	else return -1;
}

char *Str_search(const char *s1, const char *s2) 
{
	/* declare and define indexes to iterate through the 
	haystack and the needle, as well as a variable to store the 
	start point of the needle when it is found */
	const char *uInternalBigIndex, *uLittleIndex, *uNeedleStart;
	uInternalBigIndex = s1;
	uLittleIndex = s2;
	
	assert(s1 != NULL);
	assert(s2 != NULL);

	/* return the haystack if the needle has a length of 0 */
	if (Str_getLength(s2) == 0) return (char *)s1;

	/* iterate through the haystack until it reaches the end */
	while (*s1 != '\0')
	{
		/* when a match is discovered... */
		if (*s1 == *uLittleIndex) 
		{
			/* ... store the start of the match... */
			uNeedleStart = s1;

			/* ... and iterate through the needle and haystack to
			check for a complete match */
			while (*uInternalBigIndex == *uLittleIndex)
			{
				uLittleIndex++;
				uInternalBigIndex++;
				
				/* return or break depending on how the match
				situation terminates */
				if ((*uInternalBigIndex == '\0') && 
					(*uLittleIndex != '\0')) 
					break;

				if ((*uInternalBigIndex == '\0') && 
					(*uLittleIndex == '\0'))
					return (char *)uNeedleStart;

				if (*uLittleIndex == '\0') 
					return (char *)uNeedleStart;

			}
			/* if a complete match has not been found, 
			reset our variables */
			uInternalBigIndex = s1;
			uLittleIndex = s2;
		}
		/* iterate haystack indexes to continue traversal */
		s1++;
		uInternalBigIndex++;
	}
	return NULL;
}
