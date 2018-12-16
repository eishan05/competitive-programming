#include <bits/stdc++.h>

using namespace std;

#define N 2000000

bool isPrime(int n){
	for(int i=2; i<=sqrt(n); i++) if(n%i==0) return false;

	return true;
}

int main(void){
	ofstream out;
	out.open("primes.txt");
	for(int i=2; i<=N; i++) if(isPrime(i)) out<<i<<"\n";
	out.close();
	return 0;
}