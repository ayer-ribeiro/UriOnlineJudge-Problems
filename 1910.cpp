#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
#define MAX 100000
#define MIN 1

int o, d, k;
vi proibidos;

vi poss(int a){ //Existe possibilidade de gerar resultados repetidos? Como por exemplo se a = 2, a - 1 = a/2
    vi resul;
    if((a + 1 <= MAX) && (a + 1 >= MIN)) resul.push_back(a+1);
    if((a - 1 <= MAX) && (a - 1 >= MIN)) resul.push_back(a-1);
    if((2*a <= MAX) && (a*2 >= MIN)) resul.push_back(a*2);
    if((3*a <= MAX) && (a*3 >= MIN)) resul.push_back(a*3);
    if(a%2 == 0) resul.push_back(a/2);
    return resul;
}

int bfs(){
    int total = -1;
    queue <int> q;
    int hist[100001];
    for(int i = 0; i<= 100000; i++) hist[i] = 0;
    for(int i = 0; i < proibidos.size(); i++) hist[proibidos[i]] = 1;
  
    q.push(o);
    hist[o] = 1;
    vi custo;
    custo.assign(100001,0);
    
    while(!q.empty()){
        int atual = q.front();
        q.pop();
        
        if(atual == d) {
            total = custo[atual];
            break;
        }
        
        vi possibilidades = poss(atual);
        for(int i = 0; i < possibilidades.size(); i++){
            if (!hist[possibilidades[i]]){
                custo[possibilidades[i]] = 1 + custo[atual];
                q.push(possibilidades[i]);
                hist[possibilidades[i]] = 1;
            }
        }
        
    }
    
    return total;
}


int main(){
    cin >> o >> d >> k;
    while(o != 0 || d != 0 || k != 0){
        proibidos.clear();
        
        for(int i = 0; i<k; i++){
            int aux;
            cin >> aux;
            proibidos.push_back(aux);
        }
        int resp = bfs();
        cout << resp << endl;
        cin >> o >> d >> k;
    }
    
    return 0;
}
