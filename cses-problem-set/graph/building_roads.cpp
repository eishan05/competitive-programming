#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> seen;
int n, m;

void dfs(int curr) {
    for (int next: graph[curr]) {
        if (!seen[next]) {
            seen[next] = true;
            dfs(next);
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    seen.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> cities;

    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            seen[i] = true;
            cities.push_back(i);
            dfs(i);
        }
    }

    cout << cities.size() - 1 << endl;
    for (int i = 1; i < cities.size(); ++i) {
        cout << cities[i] << " " << cities[i - 1] << endl;
    }

}