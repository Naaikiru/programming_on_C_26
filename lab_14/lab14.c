#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


jmp_buf env = {0};

void form(int n, int x, int y, int sum)
{
	if (n == 0)
    {
		longjmp(env, sum);
	}
	form(n - 1, y, x + y, sum + x); 
}

int main() 
{
    int n;
	printf(": ");
	scanf("%d", &n);

	int lol = setjmp(env);
	if (lol == 0)
    {
		form(n, 1, 1, 0);
	}
	else
    {
		printf("%d", lol);
	}
	return 0;
}