#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    multiset<int> in;
    multiset<int> out;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        in.insert(a);
        out.insert(b);
    }
 
    int ans = 0;
    int curr = 0;
    while(!in.empty()) {
        int a = *in.begin();
        in.erase(in.begin());
        ++curr;
        int b = *out.begin();
        if (b < a) {
            --curr;
            out.erase(out.begin());
        }
        ans = max(curr, ans);
    }
    cout << ans << endl;
}