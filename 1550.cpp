#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define MAX 10000
#define MIN 1
int x, y;

int reverse(int x) {
    int rev = 0;
    while(x != 0){
        rev = rev*10 + x%10;
        x = x/10;
    }
    return rev;
}

vi poss(int a){
    vi resul;
    if((a + 1 < MAX) && (a + 1 >= MIN)) resul.push_back(a+1);
    int rev = reverse(a);
    if((rev >= MIN) && (rev < MAX)) resul.push_back(rev);
    
    return resul; 
}

int bfs(){
    int total = -1;
    queue <int> q;
    int hist[MAX];
    for(int i = 0; i< MAX; i++) hist[i] = 0;
    
    q.push(x);
    hist[x] = 1;
    vi custo;
    custo.assign(MAX,0);
    
    while(!q.empty()){
        int atual = q.front();
        q.pop();
        
        if(atual == y) {
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
    int n;
    cin >> n;
    while(n--){
        cin >> x >> y;
        int out = bfs();
        cout << out << endl;
    }
    return 0;
}
