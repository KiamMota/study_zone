#include <stdio.h>
#include <stdlib.h>

int f(int n)
{
		static int recursive_count = 0;
		if(n == 0) return n;
		if(n == 1) return n;
		
		recursive_count++;
		printf("recursive call to [%d]: %d\n", n, recursive_count);
		return f(n - 1) + f(n - 2);
}

int main(int argn, char* argv[])
{
		int n = 0;
		printf("resultado do que você quer:");
		scanf("%d", &n);
		int r = f(n);
		printf("result: %d\n", r);
}


