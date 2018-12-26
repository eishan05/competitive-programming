#include <iostream>

using namespace std;

long long cycle_length(int n){
	int num = 1;
	while(n!=1){
		if(n%2==0) n = n/2;
		else n = 3*n+1;
		num++;
	}
	return num;
}

int main(void){
	int first, second;

	while(cin>>first>>second){
		long long maxm = -1;
		int start = min(first, second);
		int end = max(first, second);
		for(int i=start; i<=end; i++){
			long long num = cycle_length(i);
			maxm=max(maxm, num);
		}

		cout<<first<<" "<<second<<" "<<maxm<<endl;
	}
	
	return 0;
}