/*
	Resgate em Queda Livre - URI Online Judge | 1552
	Autor: Ayer Ribeiro de Souza Netto
	Observações: Prim (Pesos tipo double)

*/

#include <bits/stdc++.h>
#define MAX 200000

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,double> id;
typedef pair<double,int> di;
typedef vector<int> vi;
typedef vector< ii > vii;
typedef vector< ii > vii;
typedef vector< id > vid;
typedef vector< di > vdi;

vector<pair<double,double> > pessoas;
vid g[MAX + 1];
bool visitado[MAX+1];
int n,c;


//Não sei porque funciona, mas funciona, pode confiar
double prim(int s){
	double cost = 0;
	priority_queue< di, vdi, greater<di> > pq;

	for(int i = 0; i <=n ;i++) visitado[i] = false;

	for(int i = 0; i< g[s].size(); i++){
		pq.push(di(g[s][i].second,g[s][i].first));
		visitado[s] = true;
	}
	while(!pq.empty()){
		di aux = pq.top();
		pq.pop();
		int d;
		double w;
		w = aux.first;
		d = aux.second;

		if(!visitado[d]){
			cost += w;
			visitado[d] = true;
			for(int i = 0;i < g[d].size(); i++){
				if(!visitado[g[d][i].first])
					pq.push(di(g[d][i].second,g[d][i].first));
			}
		}
	}
	return cost;
}


double euclidianDist(int i, int j){
    return sqrt( pow(pessoas[i].first - pessoas[j].first, 2)  +  
    	pow(pessoas[i].second - pessoas[j].second,2));
}

int main(){
    cin >> c;
    while(c--){
        cin >> n;
        pessoas.clear();
        for(int i = 0 ; i <= n; i++) g[i].clear();

        for(int i = 0; i < n ;i++){
            double x,y;
            cin >> x >> y;
            pessoas.push_back(make_pair(x,y));
        }
        for(int i = 0 ;i < pessoas.size() - 1;i++){
            for(int j = i+1; j < pessoas.size(); j++){
                double dist;
                dist = euclidianDist(i,j);
                g[i].push_back(id(j,dist));
                g[j].push_back(id(i,dist));
            }
        }
        double resp;
        resp = prim(0);
        printf("%.2lf\n",resp/100.0);
    }
    return 0;
}