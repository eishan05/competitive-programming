#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
  int n, w;
  cin>>n>>w;
  vector<ll> weight(n);
  vector<ll> value(n);
  for(int i=0; i<n; i++){
    cin>>weight[i];
    cin>>value[i];
  }
  vector<vector<ll>> knapsack(n+1, vector<ll>(w+1));
  for(int i=1; i<=n; i++){
    for(int j=1; j<=w; j++){
      knapsack[i][j] = knapsack[i-1][j];
      if(weight[i-1] <= j){
        knapsack[i][j] = max(value[i-1] + knapsack[i-1][j-weight[i-1]], knapsack[i][j]);
      }
    }
  }

  cout<<knapsack[n][w]<<endl;
  return 0;
}
