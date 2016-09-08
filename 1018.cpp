#include <bits/stdc++.h>
#define MAX 200000
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;


int main(){
	int r;
	int n;
	cin >> n;
	r = n;
	int n100, n50, n20, n10, n5, n2 ,n1;
	n100 = n50 = n20 = n10 = n5 = n2 = n1 = 0;
	while(n >= 100){

		n100++;
		n-= 100;
	}
	while(n >= 50){
		n50++;
		n-= 50;
	}
	while(n >= 20){
		n20++;
		n-= 20;
	}
	while(n >= 10){
		n10++;
		n-= 10;
	}
	while(n >= 5){
		n5++;
		n-= 5;
	}
	while(n >= 2){
		n2++;
		n-= 2;
	}
	while(n >= 1){
		n1++;
		n-= 1;
	}
	cout << r << endl;
	cout << n100 << " nota(s) de R$ 100,00" << endl;
	cout << n50 << " nota(s) de R$ 50,00" << endl;
	cout << n20 << " nota(s) de R$ 20,00" << endl;
	cout << n10 << " nota(s) de R$ 10,00" << endl;
	cout << n5 << " nota(s) de R$ 5,00" << endl;
	cout << n2 << " nota(s) de R$ 2,00" << endl;
	cout << n1 << " nota(s) de R$ 1,00" << endl;

	return 0;
}
