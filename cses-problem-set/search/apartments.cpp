#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n), vec(m);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    sort(arr.begin(), arr.end());
    int ans = 0;
    int i = arr.size() - 1, j = vec.size() - 1;
    while (i >= 0 && j >= 0) {
        if (arr[i] <= vec[j] + k && arr[i] >= vec[j] - k) {
            ++ans;
            --i, --j;
        } else if (arr[i] > vec[j]) {
            --i;
        } else {
            --j;
        }
    }
    cout << ans << endl;
}