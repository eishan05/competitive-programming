#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void output_vector_to_console(vector<int>& index, int start){
    for(int i=1; i<index.size(); i++){
        if(i==start) continue;
        cout<<index[i]<<" ";
    }
    cout<<endl;
}

void bfs(vector< vector<int> >& graph, int start){
    int n = graph.size();
    vector<int> index(n);
    queue<int> q;
    fill(index.begin(), index.end(), -1);
    index[start] = 0;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<graph[curr].size(); i++){
            int next = graph[curr][i];
            if(index[next]!=-1) continue;
            index[next] = 6 + index[curr];
            q.push(next);
        }
    }
    output_vector_to_console(index, start);
}

int main(void){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector< vector<int> > graph(n+1);
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int start;
        cin>>start;
        bfs(graph, start);
    }
}