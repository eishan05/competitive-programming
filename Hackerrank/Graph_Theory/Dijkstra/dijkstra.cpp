#include <bits/stdc++.h>

using namespace std;

void print_vector_to_console(vector<long long>& index, int s){
    for(int i=1; i<index.size(); i++){
        if(i==s) continue;
        cout<<index[i]<<" ";
    }
    cout<<"\n";
}

void shortestReach(int n, vector<vector<int>>& edges, int s) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> seen(n+1);
    vector<long long> index(n+1, -1);
    vector<unordered_map<int, int>> graph(n+1);     //Since there can be multiple edges between two nodes, I am using a vector of maps to represent the graph
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        auto instance1 = graph[u].find(v);
        if(instance1 == graph[u].end()) graph[u].insert(make_pair(v, w));
        else instance1->second = min(instance1->second, w);

        auto instance2 = graph[v].find(u);
        if(instance2 == graph[v].end()) graph[v].insert(make_pair(u,w));
        else instance2->second = min(instance2->second, w);
    }
    pair<int, int> start = make_pair(0, s);
    index[s] = 0;
    pq.push(start);
    while(!pq.empty()){
        pair<int, int> curr_edge = pq.top();
        pq.pop();
        int curr = curr_edge.second;
        if(seen[curr]) continue;
        for(auto it = graph[curr].begin(); it != graph[curr].end(); it++){
            int next = it->first;
            int weight = it->second;
            if(index[next] == -1) {
                index[next] = index[curr] + weight;
            }
            else {
                index[next] = min(index[next], index[curr] + weight);
            }
            pq.push(make_pair(index[next], next));
        }
        seen[curr] = true;
    }
    print_vector_to_console(index, s);
}

int main()
{
     ios_base::sync_with_stdio(false);
     int t;
     cin>>t;
     while(t--){
         int n, m;
         cin>>n>>m;
         vector<vector<int>> edges(m);
         for(int i=0; i<m; i++){
             edges[i].resize(3);
             cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
         }
         int start;
         cin>>start;
         shortestReach(n, edges, start);
     }
    return 0;
}

