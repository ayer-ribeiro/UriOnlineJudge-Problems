#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int peso(int n, vector <int> chegada){
	int i, j, p;
	for(i = 0; i<chegada.size(); i++){
		if (n == chegada[i]) return i;
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		vector <int>largada, chegada;
		largada.assign(n, 0);
		chegada.assign(n, 0);
		int j, i = 0;
		while(i < n){
			scanf("%d", &largada[i]);
			i++;					
		}
		i = 0;
		while(i < n){
			scanf("%d", &chegada[i]);
			i++;					
		}
		int temp, soma =0;
		for(i =0; i<n; i++){
			for(j=i; j<n; j++){
				if(peso(largada[j], chegada) < peso(largada[i], chegada)){
					temp = largada[i];
					largada[i] = largada[j];
					largada[j] = temp;
					soma++;
					//continue;			
				}			
			}
		} 		
		cout << soma << endl;
		
	}
	return 0;
}
