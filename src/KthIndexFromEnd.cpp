/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include <stdio.h>
int strlength(char *str);
char KthIndexFromEnd(char *str, int K) {
	int len, fromStart;
	if (str == NULL)
		return '\0';
	len = strlength(str);
	if (len < 1 || K < 0  || K > len) 
		return '\0';
	fromStart = len - (K + 1); // Calculate position of string from start
	return str[fromStart];
}

// Find the length of the string
int strlength(char *str)
{
	int len = -1;
	while (str[++len] != '\0');
	return len ;
}