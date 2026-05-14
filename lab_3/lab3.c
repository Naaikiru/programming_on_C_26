#include <stdio.h>

int main() 
{
	char str[81];
    scanf("%80s", str);

	for (int c = 0; str[c] != '\0'; c++)
	{
		if (str[c] == 'a')
		{
			str[c] = 'A';
		}
		else if (str[c] == 'b')
		{
			str[c] = 'B';
		}
		else if (str[c] == '!')
		{
			str[c] = '?';
		}
	}
	printf("%s", str);
    return 0;
}