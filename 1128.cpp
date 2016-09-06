#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;

bool dfs(vector <int> v[], int ini){
    stack <int> s;
    vector <int> hist;
    s.push(ini);
    hist.push_back(ini);
    while(!s.empty()){
        int atual = s.top();
        s.pop();
        for(int i = 0; i < v[atual].size(); i++){
            if(find(hist.begin(), hist.end(), v[atual][i]) == hist.end()){
                s.push(v[atual][i]);
                hist.push_back(v[atual][i]);
            }
        }
    }
    return hist.size() == n;
}

int main(){
    cin >> n >> m;
    while (n != 0 || m != 0) {
        vector <int> v[2001];
        vector <int> c[2001];
        for(int i = 0; i<m; i++){
            int q,w,e;
            cin >> q >> w >> e;
            v[q].push_back(w);
            c[w].push_back(q);
            if(e == 2){
                v[w].push_back(q);
                c[q].push_back(w);
            }
        }
        int j = 0;
        bool um = dfs(v, 1);
    
        if(um){
            j = 1;
            if(!dfs(c, 1)){
                j = 0;
            }
        }
        cout << j << endl;
        cin >> n >> m;
    }
    return 0;
}
