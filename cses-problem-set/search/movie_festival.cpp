#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
 
    int ans = 1;
    int end = arr[0].second;
    for (int i = 1; i < n; ++i) {
        if (end <= arr[i].first) {
            ++ans;
            end = arr[i].second;
        }
    }
    cout << ans << endl;
}