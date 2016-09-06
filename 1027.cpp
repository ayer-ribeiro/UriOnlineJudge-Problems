#include <bits/stdc++.h>

using namespace std;

vector <int> posicoes[66000];

bool compCurva(const pair<int,int> &a,const pair<int,int> &b){
       return a.first < b.first;
}

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < 66000; i++){
			posicoes[i].clear();
		}
		int maior=-33000, menor = 33000;

		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			posicoes[y+33000].push_back(x);
			if(y > maior) maior = y;
			if(y < menor) menor = y;
		}

		menor += 33000;
		maior += 33000;

		for(int i = menor; i< maior; i++){
			sort(posicoes[i].begin(), posicoes[i].end());
		}

		int a, cont = 0;

		for (a = menor - 1; a <= maior; a++){
			if(posicoes[a-1].empty() && posicoes[a+1].empty()) continue;
			if(posicoes[a-1].empty() && !posicoes[a+1].empty()){
				if(cont == 0) cont = 1;
				continue;
			}
			if(!posicoes[a-1].empty() && posicoes[a+1].empty()){
				if(cont == 0) cont = 1;
				continue;
			}
			
			vector <int> up = posicoes[a-1];
			vector <int> down = posicoes[a+1];

			vector <pair <int, int> > curva;
			vector <pair <int, int> > curva2;

			for(int i = 0; i<up.size(); i++){
				curva.push_back(make_pair(up[i], 1));
			}

			for(int i = 0; i<down.size(); i++){
				curva.push_back(make_pair(down[i], -1));
				curva2.push_back(make_pair(down[i], -1));
			}

			for(int i = 0; i<up.size(); i++){
				curva2.push_back(make_pair(up[i], 1));
			}

			sort(curva.begin(), curva.end(), compCurva);
			sort(curva2.begin(), curva2.end(), compCurva);

			int sum = 1;
			int current = curva[0].first;
			int pos = curva[0].second;

			for(int i = 1; i<curva.size(); i++){
				if((curva[i].first > current) && (curva[i].second != pos)){
					current = curva[i].first;
					pos = curva[i].second;
					sum++;
				}
			}

			if(sum > cont) cont = sum;

			sum = 1;
			current = curva2[0].first;
			pos = curva2[0].second;

			for(int i = 1; i<curva2.size(); i++){
				if((curva2[i].first > current) && (curva2[i].second != pos)){
					current = curva2[i].first;
					pos = curva2[i].second;
					sum++;
				}
			}
			if(sum > cont) cont = sum;
		}
		cout << cont << endl;
	}
}
