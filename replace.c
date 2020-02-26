/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Isaac Wolfe                                                */
/* netid: iwolfe                                                      */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
	const char *pcFrom, const char *pcTo)
{
	size_t uReplaceCount;
	const char *pcToTemp;
	const char *pcR;

	assert(pcLine != NULL);
	assert(pcFrom != NULL);
	assert(pcTo != NULL);

	/* define counter for number of replacements and save temp 
	   value of beginning of pcTo so it can be reset later */
	uReplaceCount = 0;
	pcToTemp = pcTo;

	/* if query string is empty, write out pcLine and return 0 */
	if ((Str_getLength(pcFrom)) == 0)
	{
		while (*pcLine != '\0')
		{
			putchar(*pcLine);
			pcLine++;
		}
		return 0;
	}

	/* traverse the text until it terminates... */
	while (*pcLine != '\0')
	{	

	/* ...check if there is remaining text to replace */
	pcR = Str_search(pcLine, pcFrom);	

	    /* write string out if there are no remaining 
	    query occurences */
		if (pcR == NULL)
		{
			while (*pcLine != '\0')
			{
				putchar(*pcLine);
				pcLine++;
			}
			break;
		}

		/* a query occurence remains, so increment counter */
		uReplaceCount++;

		/* continue to print as long as the query does not appear */
		while (pcR != pcLine)
		{
			putchar(*pcLine);
			pcLine++;
		}

		/* when it does, replace query text of pcFrom to pcTo */
		while (*pcTo != '\0')
		{
			putchar(*pcTo);
			pcTo++;
		}

		/* reset pcTo and increment pcLine so that it skips space
		   correlated to the text that needs to be replaced */
		pcTo = pcToTemp;
		pcLine += Str_getLength(pcFrom);
	}
	return uReplaceCount;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
	enum {MAX_LINE_SIZE = 4096};
	enum {PROPER_ARG_COUNT = 3};

	char acLine[MAX_LINE_SIZE];
	char *pcFrom;
	char *pcTo;
	size_t uReplaceCount = 0;

	if (argc != PROPER_ARG_COUNT)
	{
		fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
		return EXIT_FAILURE;
	}

	pcFrom = argv[1];
	pcTo = argv[2];

	while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL)
	{
		uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
	}

	fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
	return 0;
}
