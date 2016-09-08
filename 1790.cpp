/*
	Resgate em Queda Livre - URI Online Judge | 1790
	Autor: Ayer Ribeiro de Souza Netto
	Observações: DFS
*/

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> g[100];
vector<int> dfsStack;

int c,p;
bool jaPassou[50];

vector< pair<int,int> > caminhosLoop;

bool existe( pair<int,int> a ){
	for (int i =0; i< caminhosLoop.size(); i++){
		if( (a.first == caminhosLoop[i].first) && ((a.second == caminhosLoop[i].second)) ){
			return true;
		}
	}
	for (int i =0; i< caminhosLoop.size(); i++){
		if( (a.first == caminhosLoop[i].second) && ((a.second == caminhosLoop[i].first)) ){
			return true;
		}
	}
	return false;
}


bool jaTemNaPilha( int a ){
	for(int i = 0; i < dfsStack.size(); i++){
		if( a == dfsStack[i]) return true;
	}
	return false;
}

void adicionaCaminhos(int a, int b){
	pair<int,int> aux;
	aux = make_pair(a,b);
	
	if(!existe(aux)){
		caminhosLoop.push_back(aux);
	}

	int i = dfsStack.size() - 1;
	while(dfsStack[i] != b){
		aux = make_pair(dfsStack[i], dfsStack[i-1]);
		if(!existe(aux)){
			caminhosLoop.push_back(aux);
		}
		i--;
	}
}

bool anterior(int a){
	if(a == dfsStack[dfsStack.size() - 2]){
		return true;
	}
	return false;

}

void dfs( int atual ){
	dfsStack.push_back(atual);
	jaPassou[atual] = true;

	for(int i = 0;i < g[atual].size() ;i++){
		if( !jaPassou[ g[atual][i] ] ){
			dfs(g[atual][i]);
		}else if(jaTemNaPilha( g[atual][i])){
			if(!anterior(g[atual][i])){
				adicionaCaminhos(atual,g[atual][i]);
			}
		}
	}
	dfsStack.erase(dfsStack.begin() + dfsStack.size() - 1);
}



int main(){
	while(scanf("%d %d",&c,&p) != EOF){
		caminhosLoop.clear();
		dfsStack.clear();
		for(int i = 0; i <= c ;i++){
			jaPassou[i] = false;
			g[i].clear();
		}
		for(int i =0; i<p; i++){
			int c1,c2;
			cin >> c1 >> c2;
			g[c1].push_back(c2);
			g[c2].push_back(c1);
		}
		dfs(1);

		cout << p -caminhosLoop.size() << endl;
	}
}