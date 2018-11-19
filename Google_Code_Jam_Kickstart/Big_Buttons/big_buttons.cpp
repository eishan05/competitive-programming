#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;


//only handles y>=0
long long power(int x, int y) 
{ 
    long long temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 

int main()
{
   int t;
   cin>>t;
   int index = 1;
   while(t--){
       int n, p;
       cin>>n>>p;
       string s;
       unordered_set<string> set;
       long long num = 0;
       vector<string> vec(p);
       for(int i=0; i<p; i++){
           cin>>vec[i];
       }
       sort(vec.begin(), vec.end());
       for(int i=0; i<p; i++){
           int j;
           for(j=1; j<=vec[i].length(); j++){
               string str = vec[i].substr(0, j);
               if(set.find(str) != set.end()) break;
           }
           if(j>vec[i].length()){
               num+= power(2, n - vec[i].length());
           }
           set.insert(vec[i]);
       }
       cout<<"Case #"<<index<<": "<<max(power(2, n) - num, (long long) 0)<<endl;
       index++;
   }
   return 0;
}