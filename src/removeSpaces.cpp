/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>

char removeSpaces(char *str) {
		int index = 0, pos = 0;
		if (str == NULL)
			return '\0';
		while (str[index] != '\0')  //Traverse through the string 
		{
			if (str[index] != ' ') //If the character is not space then add it to the string or else leave it
				str[pos++] = str[index];
			index++;
		}
		str[pos] = '\0'; //To make it valid string add '\0' at last after all characters are added
	
}