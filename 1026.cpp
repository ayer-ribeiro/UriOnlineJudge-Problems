#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	
	unsigned long long a,b;
	unsigned long long x;
	while(scanf("%llu %llu",&a,&b) != EOF){
		x = 0;
		for(int i =0;i<32;i++){
			x = x | ((a&(1<<i))^(b&(1<<i)));
		}
		printf("%llu\n",x);
		


	}
	return 0;
}
