#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Custom object for an edge
struct edge{
    int u;
    int v;
    int wt;
    bool operator < (const edge& e2) const {
        if(wt < e2.wt) return true;
    else if (wt == e2.wt){
        return (u+v) < (e2.u + e2.v); //this is to break the tie when two edges have equal weights. This is not usually done, but is asked for in the problem
    }
        else return false;
    }
};

//Union find data structure
int find(vector<int>& set, int x){
    if(set[x] == -1) return x;
    set[x] = find(set, set[x]);
    return set[x];
}
void unionE(vector<int>& set, int a, int b){
    set[find(set, a)] = find(set, b);
}

long long kruskal(vector<edge>& edges. int n){
    //First step of kruskal is to sort all edges w.r.t to their weights (ascending)
    sort(edges.begin(), edges.end());

    //itialize union-find data structure
    vector<int> set(n+1);
    fill(set.begin(), set.end(), -1);

    long long sum = 0;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;
        if(find(set, u) != find(set, v)){
            unionE(set, u, v);
            sum+= wt;
        }
    }

    return sum;
}

int main(void){
    int n, m;
    cin>>n>>m;
    vector<edge> edges(m);
    for(int i=0; i<m; i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].wt;
    }      
    cout<<kruskal(edges, n);

    return 0;
}