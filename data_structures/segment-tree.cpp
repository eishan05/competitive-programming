#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll arr[100010];
ll segtree[200020];                            //segtree is twice the length of array

void build_tree (int n);                         //Method to build tree
void update_tree (int index, int value, int n);  //Update the index of the array
ll get_min (int left, int right, int n);       //Query the min value in range [L, R)
int left (int index);                            //get left child
int right (int index);                           //get right child
int parent (int index);                          //get parent

int main(){

  ios::sync_with_stdio(0);  //Fast I/O
  cin.tie(0);

  int n, m;

  cin >> n >> m;

  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  build_tree(n);

  for(int i=0; i<m; i++){
    char c;
    int index;
    int value;
    cin >> c >> index >> value;
    if (c == 'Q') cout << get_min (index, value+1, n) << endl;
    else update_tree (index, value, n);
  }
}

int left (int index){
  return index << 1;
}

int right (int index){
  return (index << 1) + 1;
}

int parent (int index) {
  return index >> 1;
}

void build_tree (int n){
  for(int i=n; i<2*n; i++){
    segtree[i] = arr[i-n];
  }
  for(int i=n-1; i>=1; i--){
    segtree[i] = min (segtree[left(i)], segtree[right(i)]);
  }
}

void update_tree (int index, int value, int n){
  index += n;
  segtree[index] = value;
  while(index > 1){
    index = parent(index);
    segtree[index] = min (segtree[left(index)], segtree[right(index)]);
  }
}

ll get_min (int left, int right, int n){
  left += n;
  right += n;
  ll minm = LONG_MAX;
  while (left < right){
    if (left%2){
      minm = min (minm, segtree[left]);
      left++;
    }
    if (right%2){
      right--;
      minm = min(minm, segtree[right]);
    }
    left = parent(left); right = parent(right);
  }
  return minm;
}


