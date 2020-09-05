#include<bits/stdc++.h>

using namespace std;

vector<string> grid;
vector<vector<bool>> seen;
map<pair<int, int>, pair<int, int>> ind;
pair<int, int> s, e;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
map<pair<int, int>, char> path_map = {{{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}};
int n, m;
bool found = false;

bool inside(pair<int, int> p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

void dfs(pair<int, int> curr) {
    queue<pair<int, int>> q;
    s = curr;
    q.push(curr);
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (pair<int, int> d: dir) {
            pair<int, int> next = {curr.first + d.first, curr.second + d.second};
            if (inside(next) && (grid[next.first][next.second] == '.' && !seen[next.first][next.second])) {
                seen[next.first][next.second] = true;
                ind[next] = curr;
                q.push(next);
            }
            if (inside(next) && grid[next.first][next.second] == 'B') {
                e = next;
                ind[next] = curr;
                found = true;
                return;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    seen.resize(n, vector<bool>(m));
    int ans = 0;
    bool flag = false;
    string path = "";
    for (int i = 0; i < n && !flag; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                dfs({i, j});
                flag = true;
                break;
            }
        }
    }

    if (found) {
        cout << "YES" << endl;
        while (e != s) {
            pair<int, int> parent = ind[e];
            path.push_back(path_map[{e.first - parent.first, e.second - parent.second}]);
            e = parent;
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
        
    } else {
        cout << "NO" << endl;
    }

}