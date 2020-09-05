#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> color;
bool bad = false;
int n, m;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next: graph[curr]) {
            if (color[next] == 0) {
                color[next] = color[curr] == 1 ? 2 : 1;
                q.push(next);
            } else if (color[next] == color[curr]) {
                bad = true;
                return;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    color.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            bfs(i);
        }
    }

    if (bad) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << color[i] << " ";
    }
    cout << endl;

}