#include <bits/stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin>>n>>k;
  vector<int> arr(n);
  vector<int> dp(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  if(k>=n){
    cout<<abs(arr[n-1] - arr[0])<<endl;
    return 0;
  }
  for(int i=1; i<k; i++){
    dp[i] = abs(arr[i] - arr[0]);
    for(int j=1; j<i; j++){
      dp[i] = min(abs(arr[i] - arr[j]) + dp[j], dp[i]);
    }
  }

  for(int i=k; i<n; i++){
    dp[i] = abs(arr[i] - arr[i-k]) + dp[i-k];
    for(int j=i-k+1; j<i; j++){
      dp[i] = min(abs(arr[i] - arr[j]) + dp[j], dp[i]);
    }
  }
  cout<<dp[n-1]<<endl;
  return 0;
}
