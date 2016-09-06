#include <bits/stdc++.h>
using namespace std;

int main(){
	map<string, int> entrada;
	int n;
	cin >> n;
	for(int i = 0; i< n; i++){
		string a;
		cin >> a;
		entrada[a] = 1;
	}
	
	cout << "Falta(m) " << (151 - entrada.size()) << " pomekon(s)." << endl;

	return 0;

}
