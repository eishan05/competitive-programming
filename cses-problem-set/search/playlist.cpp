#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    set<int> s;
    int maxm = 1;
    int last = 0;
    s.insert(arr[0]);
    for (int i = 1; i < n; ++i) {
        while (s.find(arr[i]) != s.end()) {
            s.erase(arr[last]);
            ++last;
        }
        s.insert(arr[i]);
        maxm = max(maxm, (int) s.size());
    }
    cout << maxm << endl;
}