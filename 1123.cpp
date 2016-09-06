#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
    vector<vii> AdjList;
    int n, m, c, k, p, u, v;

    cin >> n >> m >> c >> k;
    while (n != 0 || m != 0 || c != 0 || k != 0) {
        
        AdjList.assign(n, vii()); // assign blank vectors of pair<int, int>s to AdjList
        vi rota;
        rota.resize(n);
        for (int i = 0; i < m; i++) {
            //scanf("%d %d %d", &u, &v, &w);
            cin >> u >> v >> p;
            AdjList[u].push_back(ii(v, p));                           
            AdjList[v].push_back(ii(u, p));
            if(u+1 == v) rota[u] = p;
            else if(u == v+1) rota[v] = p;
        }
        
        vii ate_rota;
        
        // Dijkstra routine
        vi dist(n, INF); dist[k] = 0;                    // INF = 1B to avoid overflow
        priority_queue< ii, vector<ii>, greater<ii> > pq;
        // ^to sort the pairs by increasing distance from s
        pq.push(ii(0, k));
        while (!pq.empty()) {                                             // main loop
            ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
            int d = front.first, u = front.second;
            if (d == dist[u])            // this check is important, see the explanation
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                    ii v = AdjList[u][j];                       // all outgoing edges from u
                    
                    if(v.first >= 0 && v.first < c){
                        ate_rota.push_back(ii(v.first,dist[u] + v.second));
                    }
    
                    else if (dist[u] + v.second < dist[v.first]) {
                        dist[v.first] = dist[u] + v.second;                 
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
        }  // note: this variant can cause duplicate items in the priority queue
    
        if(ate_rota.size() == 0){
            cout << dist[c-1] << endl;
        }else{
            int menor = INF;
            for(int i = 0; i<ate_rota.size(); i++){
                int d = ate_rota[i].second;
                for(int j = ate_rota[i].first; j < c-1; j++){
                    d += rota[j];
                }
                if( d < menor) menor = d;
            }
            
            cout << menor << endl;
        }
    
        cin >> n >> m >> c >> k;
    }
    return 0;
}
