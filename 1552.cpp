#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

double dist(ii p, ii q){
    return sqrt(pow(p.first - q.first, 2) + pow(p.second - q.second, 2));
}

vi pset(1000), setSize(1000); int _numDisjointSets;

void initSet(int N) { setSize.assign(N, 1); _numDisjointSets = N;
    pset.assign(N, 0);
    for (int i = 0; i < N; i++)
        pset[i] = i;
}

int findSet(int i) {
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
        _numDisjointSets--;
        setSize[findSet(j)] += setSize[findSet(i)];
        pset[findSet(i)] = findSet(j);
    }
}

int numDisjointSets() {
    return _numDisjointSets;
}

int sizeOfSet(int i) {
    return setSize[findSet(i)];
}

int main(){
    int c;
    cin >> c;
    while (c--) {
        vector < pair<double, ii> > EdgeList;
        int n, x, y;
        cin >> n;
        vii posicoes;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            posicoes.push_back(ii(x, y));
        }
        int e = 0;
        for(int i = 0; i< posicoes.size(); i++){
            for(int j = i + 1; j < posicoes.size(); j++){
                double d;
                d = dist(posicoes[i], posicoes[j]);
                EdgeList.push_back(make_pair(d, ii(i, j)));
                e++;
            }
        }
        sort(EdgeList.begin(), EdgeList.end());
        
        double mst_cost = 0;
        initSet(n);
        for(int i = 0; i < e; i++){
            pair<double, ii> front = EdgeList[i];
            if(!isSameSet(front.second.first, front.second.second)){
                mst_cost += front.first;
                unionSet(front.second.first, front.second.second);
            }
        }
        printf("%.2lf\n", mst_cost/100.0);
    }
}
