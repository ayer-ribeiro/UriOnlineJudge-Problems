#include <bits/stdc++.h>


using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
int V, E, u, v, w;
vector<vii> AdjList;


int dij(int s, int d){
   // Dijkstra routine
  vi dist(V+1, INF); dist[s] = 0;                    // INF = 1B to avoid overflow
  priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));
                             // ^to sort the pairs by increasing distance from s
  while (!pq.empty()) {                                             // main loop
    ii front = pq.top(); pq.pop();     // greedy: pick shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d == dist[u])            // this check is important, see the explanation
      for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];                       // all outgoing edges from u
        if (dist[u] + v.second < dist[v.first]) {
          dist[v.first] = dist[u] + v.second;                 // relax operation
          pq.push(ii(dist[v.first], v.first));
  }   } }  // note: this variant can cause duplicate items in the priority queue

  return dist[d];
}


int main() {

  scanf("%d %d", &V, &E);
  while(V != 0 || E != 0){
    AdjList.clear();
    AdjList.assign(V+1, vii()); // assign blank vectors of pair<int, int>s to AdjList
    for (int i = 0; i < E; i++) {
      scanf("%d %d %d", &u, &v, &w);
      bool y = false;                              // directed graph
      for(int i = 0; i < AdjList[v].size(); i++){
        if(AdjList[v][i].first == u){
          AdjList[v][i].second = 0;
          y = true;
          break;
        }
      }
      if(y) AdjList[u].push_back(ii(v, 0));
      else AdjList[u].push_back(ii(v, w));
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
      int o, d;
      cin >> o >> d;
      int resul = dij(o,d);
      if(resul == INF) cout << "Nao e possivel entregar a carta" << endl;
      else cout << resul << endl;
    }
    cout << endl;
    scanf("%d %d", &V, &E);
  }
  return 0;
}
