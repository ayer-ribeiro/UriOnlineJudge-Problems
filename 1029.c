#include <stdio.h>
int calls = -1;

int fib(int n){
	calls += 1;
	if (n == 0) return 0;
	if (n == 1)
		return 1;
	else
		return fib(n-1) + fib (n-2);
}

int main(){
	int i, j;
	int n;
	scanf("%d", &n);
	while(n){
		scanf("%d", &i);
		j = fib(i);
		printf("fib(%d) = %d calls = %d\n",i, calls, j);
		calls = -1;
		n--;
}
return 0;
}
