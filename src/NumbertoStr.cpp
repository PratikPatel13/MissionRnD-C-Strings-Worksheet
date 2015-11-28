/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void number_to_str(float number, char *str, int afterdecimal);
void inttostr(int number, char *str);
int power(int base, int pow);

void number_to_str(float number, char *str, int afterdecimal){
	int int_part, dec_part, start, end, index = 0;
	char temp;
	float float_part;
	if (number < 0)  // If number is less than 0 then add '-' to the string and make the number positive
	{
		number = number * -1;
		str[index++] = '-';
	}
	int_part = number;  
	float_part = number - int_part;
	start = index;

	//Convert the int part of number to string
	while (int_part != 0)
	{
		str[index++] = (int_part % 10) + '0';
		int_part /= 10;
	}
	end = index - 1;
	while (start < end)   // Reverse the int part as using modulus 34 will be stored in string as 43
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	/*If there is decimal part then add '.' to the string and then convert the floating part to integer by multiplying 
	  it with 10 to the power of afterdecimal
	  Ex : 0.345 to get 2 floating point precision multiply it by 10**2 = 100. 0.345 * 100 = 34 which is afterdecimal value
	  */
	if (afterdecimal > 0)
	{
		str[index++] = '.';
		dec_part = power(10, afterdecimal) * float_part;
		start = index;
		while (dec_part != 0)
		{
			str[index++] = (dec_part % 10) + '0';
			dec_part /= 10;
		}
		end = index - 1;
		while (start < end)
		{
			temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start++;
			end--;
		}

	}
	str[index] = '\0';
}


int power(int base, int pow)
{
	int res = 1;
	while (pow > 0)
	{
		res *= base;
		pow--;
	}
	return res;
}
