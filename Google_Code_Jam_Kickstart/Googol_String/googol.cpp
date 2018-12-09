#include <bits/stdc++.h>

using namespace std;

bool check(long long num, long long next_num){
	if(num == next_num/2) return false;
	else if(num < next_num/2) return check(num, next_num/2);
	else return !check(next_num - num - 1, next_num/2);
}

int solve(long long num){
	long long next_num = 0;
	while(next_num <= num) next_num = 2*next_num + 1;
	if(check(num, next_num)) return 1;
	else return 0;
}

int main(void){
	ifstream in;
	ofstream out;
	in.open("B-large-practice.in");
	out.open("out-large.txt");
	int t;
	in>>t;
	int index = 1;
	while(t--){
		long long num;
		in>>num;
		num--;
		out<<"Case #"<<index<<": "<<solve(num)<<endl;
		index++;
	}
	in.close();
	out.close();
}