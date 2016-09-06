#include <bits/stdc++.h>
using namespace std;

int eq[61];
int di[61];

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < 61; i++){
			eq[i] = 0;
			di[i] = 0;
		}
		for(int i = 0; i<n; i++){
			int t;
			char p;
			cin >> t >> p;
			if(p == 'D') di[t]++;
			if(p == 'E') eq[t]++;
		}
		int c = 0;
		for(int i = 30; i< 61; i++){
			if(di[i] <= eq[i]) c += di[i];
			else c+= eq[i];
		}
		cout << c << endl;
	}
	return 0;
}
