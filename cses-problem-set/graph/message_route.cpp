#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> seen;
vector<int> ind;
int n, m;

void bfs() {
    queue<int> q;
    q.push(1);
    seen[1] = 1;
    ind[1] = 1;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next: graph[curr]) {
            if (seen[next] == 0) {
                seen[next] = curr;
                ind[next] = ind[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    seen.resize(n + 1);
    ind.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs();

    if (seen[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << ind[n] << endl;

    vector<int> path;

    int curr = n;
    while (curr != 1) {
        path.push_back(curr);
        curr = seen[curr];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    for (int i: path) {
        cout << i << " ";
    }
    cout << endl;

}