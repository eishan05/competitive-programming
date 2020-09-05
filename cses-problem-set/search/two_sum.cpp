#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    map<int, int> seen;
    int n, x;
    cin >> n >> x;
    pair<int, int> ans;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (seen.find(x - a) != seen.end()) {
            ans.first = seen[x - a] + 1;
            ans.second = i + 1;
            break; 
        }
        seen[a] = i;
    }
    if (ans.first == 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans.first << " " << ans.second << endl;
    }
}