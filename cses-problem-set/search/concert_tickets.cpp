#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    multiset<int> st(h.begin(), h.end());
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        auto it = st.upper_bound(a);
        if (it == st.begin()) {
            cout << -1 << endl;
            continue;
        }
        cout << *(--it) << endl;
        st.erase(it);
    }
}