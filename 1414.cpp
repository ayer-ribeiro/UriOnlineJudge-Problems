#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int t, n;

int main(){
	cin >> t >> n;
	while(t != 0){
		string time;
		int pontos = 0;
		for(int i = 0; i<t; i++){
			int p;
			cin >> time >> p;
			pontos += p;
		}
		cout << (3*n - pontos) << endl;

		cin >> t >> n;
	}


	return 0;
}
