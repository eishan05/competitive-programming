#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_set<int> x;
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i=0; i<k; i++) {
    string s;
    int num;
    cin >> s;
    if (s == "CLICK") {
      cin >> num;
      if (x.find(num) != x.end()) {
        x.erase(num);
      } else {
        x.insert(num);
      }
    } else if (s == "CLOSEALL") {
      x.clear();
    }
    cout << x.size() << endl;
  }
}
