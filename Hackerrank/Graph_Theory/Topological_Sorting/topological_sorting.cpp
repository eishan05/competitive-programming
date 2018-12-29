#include <bits/stdc++.h>

using namespace std;

vector<bool> discovered;
vector<bool> processed;
stack<int> st;
vector<int> sorted;
vector<int> paths;
vector<vector<int>> graph;
vector<int> cycle;

//Topological sorting by dfs
void dfs(int curr){
    discovered[curr] = true;
    for(int i=0; i<graph[curr].size(); i++){
        int next = graph[curr][i];
        if(!discovered[next]) dfs(next);
        else if(discovered[next] && !processed[next]) {
            cycle.push_back(next);
        }
    }
    processed[curr] = true;
    st.push(curr);
}

void stack_to_vector(){
    while(!st.empty()){
        sorted.push_back(st.top());
        st.pop();
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    graph.resize(n+1);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    discovered.resize(n+1);
    processed.resize(n+1);

    dfs(1);

    stack_to_vector();

    paths.resize(n+1);

    paths[1] = 1;

    for(int i=0; i<cycle.size(); i++) paths[cycle[i]] = -1;


    for(int i=0; i<sorted.size(); i++){
        int curr = sorted[i];
        for(int j=0; j<graph[curr].size(); j++){
            int next = graph[curr][j];
            if(paths[curr] == -1) paths[next] = -1;
            else if(paths[next] != -1) paths[next] += paths[curr];
            paths[next] = paths[next]%1000000000;
        }
    }    
    if(paths[n] == -1) cout<<"INFINITE PATHS";
    else cout<<paths[n]%1000000000;

}