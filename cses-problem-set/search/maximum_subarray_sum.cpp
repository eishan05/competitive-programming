#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long global = arr[0];
    long long local = arr[0];
    for (int i = 1; i < n; ++i) {
        local = max(local + arr[i], arr[i]);
        global = max(local, global);
    }
    cout << global << endl;
}