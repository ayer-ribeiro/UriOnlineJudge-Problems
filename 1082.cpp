/*
	Componentes conexos - URI Online Judge | 1082
	Autor: Ayer Ribeiro de Souza Netto
	Observações:
		-Componente conexo: Componentes conexos de um grafo 
		 são os subgrafos conexos deste grafo.
		-DFS
*/

#include <bits/stdc++.h>

using namespace std;
typedef vector<char> vc;

vc g[300];
int visitado[300];
int N;
int V,E;
vector<vector<char> > subs;
char maior;
void dfs(int a){
	visitado[a] = true;
	for(int i = 0 ;i < g[a].size();i++){
		int no = g[a][i];
		if(!visitado[no]){
			dfs(no);
		}
	}
}

void f(){
	bool acabou = false;
	subs.clear();
	int cont = 0;
	while(!acabou){
		for(int i = 'a'; i <= 'z'; i++){
			if(visitado[i] == 1) visitado[i]++;
		}
		for(int i = 'a'; i <= ('z'); i++){
			if(!visitado[i]){
				cont++;
				dfs(i);
				break;
			}
			if(i == 'z') acabou = true;
		}
		vector<char> temp;
		for(int i = 'a'; i < ('a' + V); i++){
			if(visitado[i] == 1){
				temp.push_back((char)i);
			}
		}
		if(!temp.empty())
			subs.push_back(temp);
	}
}


int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		
		maior = 'a';
		for(int k = 0; k < 300;k++) {
			g[k].clear();
			visitado[k] = 0;
			subs.clear();
		}
		cin >> V >> E;
		for(int j = 0 ; j < E ; j++){
			char n1,n2;
			cin >> n1 >> n2;
			if(n1 > maior) maior = n1;
			if(n2 > maior) maior = n2;
			g[((int)n1)].push_back(n2);
			g[((int)n2)].push_back(n1);
		}
		f();
		cout << "Case #" << i << ":" << endl;
		for(int k = 0; k < subs.size();k++){
			for(int j = 0; j < subs[k].size();j++){
				cout << subs[k][j] <<",";
			}
			cout << endl;
		}
		cout << subs.size() << " connected components" << endl;
		cout << endl;

	}
	return 0;
}