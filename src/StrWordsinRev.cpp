/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void revers(char *s, int start, int end);
/*
	To reverse the string first reverse each word of the string and then reverse the string obtained to get the reverse words
	Ex: String = "Hello Pratik Patel"
		Reverse words are = "olleH kitarP letaP"
		Reversing the above string gives result = "Patel Pratik Hello"
*/

void str_words_in_rev(char *input, int len){
	int start = 0, end, i = 0;
	while (i <= len)
	{
		if (input[i] == ' ' || input[i] == '\0'){
			end = i - 1;
			revers(input, start, end);
			start = i + 1;
		}

		i++;
	}
	revers(input, 0, len - 1);
	
}

void revers(char *s, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}