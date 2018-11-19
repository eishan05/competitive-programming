#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
  ifstream in;
  in.open("B-large.in");
  ofstream out;
  out.open("out.txt");
  int t;
  in>>t;
  int index = 1;
   while(t--){
     int n;
     in>>n;
     string s;
     in>>s;
     int sum = 0;
     for(int i=0; i< n/2 + n%2; i++){
          sum += (int)s[i] - 48;
      }
      int max_substring = sum;
      for(int i=n/2 + n%2; i<n; i++){
          sum += (int)s[i] - (int) s[i - n/2 - n%2];
          max_substring = max(max_substring, sum);
      }
      out<<"Case #"<<index<<": "<<max_substring<<endl;
      index++;
   }
  return 0;
}