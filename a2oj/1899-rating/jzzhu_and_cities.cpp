#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[100005];
bool train[100005];
bool seen[100005];
long long dist[100005];
const long long INF = 1LL << 60;
int n, m, k;

int main() {
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
    }

    dist[0] = 0;

    for (int i = 0; i < k; ++i) {
        int v;
        long long c;
        cin >> v >> c;
        --v;
        train[v] = true;
        dist[v] = min(dist[v], c);
    }

    priority_queue<pair<long long, int>> pq;

    for (int i = 0; i < n; ++i) {
        if (dist[i] != INF) {
            pq.push({-dist[i], i});
        }
    }

    while (!pq.empty()) {
        pair<long long, int> n = pq.top();
        pq.pop();
        int curr = n.second;
        long long d = -n.first;
        if (dist[curr] != d) {
            continue;
        }
        for (int i = 0; i < adj[curr].size(); ++i) {
            int next = adj[curr][i].first;
            long long next_dist = d + adj[curr][i].second;
            if (next_dist <= dist[next] && train[next]) {
                train[next] = false;
            }
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({-dist[next], next});
            }
        }
    }

    int ans = k;
    for (int i = 0; i < n; ++i) {
        ans -= train[i];
    }

    cout << ans << endl;
}