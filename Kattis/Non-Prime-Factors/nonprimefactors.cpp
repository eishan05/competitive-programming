#include <stdio.h>
#include <unordered_set>
#include <vector>

using namespace std;

#define N 2000000

int main(void){
    unordered_set<int> primes;
    for(int i=2; i<=N/2; i++){
        primes.insert(i);
    }
    for(int i=2; i<=N/4 + 1; i++){
        if(primes.find(i) == primes.end()) continue;
        int j=2;
        while(i*j<=N){
            if(primes.find(i*j) != primes.end()) primes.erase(i*j);
            j++;
        }
    }
    
   vector<int> nums(2000001, 1);
   for(int i=2; i<=N; i++){
       if(primes.find(i) != primes.end()) continue;
       int j = 1;
       while(i*j <= N){
           nums[i*j]++;
           j++;
       }
   }
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++){
       int a;
       scanf("%d", &a);
       printf("%d\n", nums[a]);
   }
}