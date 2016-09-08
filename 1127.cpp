#include <bits/stdc++.h>
#define MAX 200000
#define INF 999999
#define PI M_PI
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

bool isSubStr(string a, string b){
	return(a.find(b) != string::npos);
}

//vector<string> teclado;
map <string,int> teclado;
int main(){
    teclado["Cb"] = 12;
	teclado["C"] = 1;
	teclado["C#"] = 2;
	teclado["Db"] = 2;
	teclado["D"] = 3;
	teclado["D#"] = 4;
	teclado["Eb"] = 4;
	teclado["E"] = 5;
	teclado["E#"] = 6;
	teclado["Fb"] = 5;
	teclado["F"] = 6;
	teclado["F#"] = 7;
	teclado["Gb"] = 7;
	teclado["G"] = 8;
	teclado["G#"] = 9;
	teclado["Ab"] = 9;
	teclado["A"] = 10;
	teclado["A#"] = 11;
	teclado["Bb"] = 11;
	teclado["B"] = 12;
	teclado["B#"] = 1;

	int t,m;
	/*

	Entrada:
	16 4
	D G A B C D G G G C D E F# G C C
	G G C D
	12 2
	C C# D D# E F F# G G# A A# B
	C D
	12 2
	C Db D Eb E F Gb G Ab A Bb B
	C D
	4 3
	C E G Bb
	D F# A
	0 0

	Saída:
	S
	N
	N
	S

	*/

	cin >> m >> t;
	while(m!=0 || t!=0){
		vector<string> musica;
		vector<string> plagio;
		while(m--){
			string temp;
			cin >> temp;
			musica.push_back(temp);
		}
		while(t--){
			string temp;
			cin >> temp;
			plagio.push_back(temp);
		}
		string musicaDist;
		string plagioDist;
		for(int i = 1; i < musica.size();i++){
			int dist = teclado[musica[i]] - teclado[musica[i-1]];
			if(dist < 0) dist += 12;
			char temp = dist + '0';
			musicaDist.push_back(temp);
		}


		for(int i = 1; i < plagio.size();i++){
			int dist = teclado[plagio[i]] - teclado[plagio[i-1]];

			if(dist < 0) dist += 12;
			char temp = dist + '0';
			plagioDist.push_back(temp);
		}
		if(isSubStr(musicaDist,plagioDist)){
			cout << "S" << endl;
		}else{
			cout << "N" << endl;
		}

		cin >> m >> t;
	}

    return 0;
}
