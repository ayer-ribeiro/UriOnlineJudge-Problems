/*
	Resgate em Queda Livre - URI Online Judge | 1552
	Autor: Ayer Ribeiro de Souza Netto
	Observações: Kruskal (Pesos tipo double)
*/
	
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii pessoas;

// Union-Find Disjoint Sets Library
// PS: This library code does not include the `union by rank' heuristic yet
// 1000 is just a rough number, adjustable by user
vi pset(1000), setSize(1000); int _numDisjointSets;
void initSet(int N) { setSize.assign(N, 1); _numDisjointSets = N;
pset.assign(N, 0); for (int i = 0; i < N; i++) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) {
  if (!isSameSet(i, j)) {
    _numDisjointSets--;
    setSize[findSet(j)] += setSize[findSet(i)];
    pset[findSet(i)] = findSet(j); } }
int numDisjointSets() { return _numDisjointSets; }
int sizeOfSet(int i) { return setSize[findSet(i)]; }


vector<vii> AdjList;
vi taken;                                  // global boolean flag to avoid cycle
priority_queue<ii> pq;            // priority queue to help choose shorter edges
vector< pair<double, ii> > EdgeList;

int V, E, u, v, w;

void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]){
			pq.push(ii(-v.second, -v.first));
		}
	}
}  // sort by (inc) weight then by (inc) id by using -ve sign to reverse order

double kruskal(int V){
	int E;
	E = EdgeList.size();
	sort(EdgeList.begin(), EdgeList.end());
	double mst_cost = 0; initSet(V);             // all V are disjoint sets initially
	for (int i = 0; i < E; i++) {                           // for each edge, O(E)
		pair<double, ii> front = EdgeList[i];
		if (!isSameSet(front.second.first, front.second.second)) {    // if no cycle
			mst_cost += front.first;                     // add the weight of e to MST
			unionSet(front.second.first, front.second.second);       // link endpoints
		}
	}
	return mst_cost;
}

double dist(int a, int b){
	return sqrt( pow (pessoas[a].first - pessoas[b].first , 2) + pow (pessoas[a].second - pessoas[b].second , 2));
}

void liga(int x){
	for(int i = 0; i < x-1 ;i++){
		for(int j = i+ 1; j< x; j++){
			double w = dist(i,j);
			EdgeList.push_back(make_pair(w, ii(i, j)));
			AdjList[i].push_back(ii(j, w));
			AdjList[j].push_back(ii(i, w));
		}
	}
}
int main() {
	int c;
	cin >> c;
	while(c--){
		int n;
		cin >> n;
		EdgeList.clear();
		pessoas.clear();
		AdjList.clear();

		V = n;
		while(n--){
			int x,y;
			cin >> x >> y;
			pessoas.push_back(ii(x,y));
		}
		AdjList.assign(V, vii());
		liga(V);
		double mst_cost = kruskal(V);

		printf("%.2lf\n", mst_cost/100.0f);
	}
	return 0;
}
