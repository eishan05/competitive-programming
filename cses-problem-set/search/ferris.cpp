#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    multiset<int> st(arr.begin(), arr.end());
    while(!st.empty()) {
        ++ans;
        int a = *st.begin();
        st.erase(st.begin());
        auto last = st.upper_bound(x - a);
        if (last != st.begin()) {
            st.erase(--last);
        }
    } 
    cout << ans << endl;
}