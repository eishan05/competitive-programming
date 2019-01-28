#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 0x7fffffff

int main(){
  ll n, w;
  cin>>n>>w;
  vector<ll> weight(n+1);
  vector<ll> value(n+1);
  
  for(int i=1; i<=n; i++){
    cin>>weight[i]>>value[i];
  }
  vector<ll> knapsack(100001);
  for(int i=1; i<=100000; i++) knapsack[i] = INF;
  for(int i=1; i<=n; i++){
    for(int j=100000; j>=0; j--){
      if(value[i] <= j) 
      knapsack[j] = min(weight[i] + knapsack[j-value[i]], knapsack[j]);
      else break;
    }
  }
  ll ans =-1;
  for(int i=100000; i>=0; i--){ 
    if(knapsack[i]<=w){
      ans = i;
      break;
    }
  } 
  cout<<ans<<endl;
  return 0;
}
