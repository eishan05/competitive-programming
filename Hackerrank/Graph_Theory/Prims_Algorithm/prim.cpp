#include <bits/stdc++.h>

using namespace std;

long long prims_algorithm(vector<unordered_map<int, int>>& graph, int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_set<int> seen;
    pq.push(make_pair(0, start));

    long long sum = 0;

    while(!pq.empty()){
        pair<int,int> curr_node = pq.top();
        pq.pop();
        int curr = curr_node.second;
        int weight = curr_node.first;
        if(seen.find(curr) != seen.end()) continue;
        sum += weight;
        for(auto it=graph[curr].begin(); it != graph[curr].end(); it++){
            int next = it->first;
            int w = it->second;
            pq.push(make_pair(w, next));
        }
        seen.insert(curr);
    }

    return sum;
}

int main(void){
    int n, m;
    cin>>n>>m;
    vector<unordered_map<int, int>> graph(n+1);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        
        auto instance1 = graph[a].find(b);
        if(instance1 == graph[a].end()) graph[a].insert(make_pair(b, c));
        else instance1->second = min(instance1->second, c);

        auto instance2 = graph[b].find(a);
        if(instance2 == graph[b].end()) graph[b].insert(make_pair(a, c));
        else instance2->second = min(instance2->second, c);
    }
    cout<<prims_algorithm(graph, 1);
    
    return 0;
}