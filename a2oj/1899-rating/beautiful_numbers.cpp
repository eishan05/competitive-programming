#include <bits/stdc++.h>

using namespace std;

#define p 1000000007

typedef long long ll;

long long power(long long x, long long y) {
    long long res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res%p;
}
 
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
 
long long modInverse(long long b)
{
    long long x, y; // used in extended GCD algorithm
    long long g = gcdExtended(b, p, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%p + p) % p;
}
 
// a/b
long long mod_divide(long long a, long long b) {
   a = a % p;
   long long inv = modInverse(b);
   return (inv * a) % p;
}
 
// a*b
long long mulmod(long long a, long long b) {
   long long res = 0;
   a = a % p;
   while (b > 0) {
      if (b % 2 == 1) {
         res = (res + a) % p;
      }
      a = (a*2)%p;
      b /= 2;
   }
   return res%p;
}
 
long long choose(long long n, long long b) {
   long long ans = 1;
   long long fact = 1;
   for (long long i = 0; i < b; ++i) {
      ans = mulmod(ans, n - i);;
      fact = mulmod(fact, i + 1);
   }
   return mod_divide(ans, fact);
}


int a, b, n;

bool is_good(int num) {
    while (num > 0) {
        if (num % 10 != a && num % 10 != b) {
            return false;
        }
        num = num / 10;
    }
    return true;
}

int main() {
    cin >> a >> b >> n;
    ll choose = 1;
    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (is_good(a*i + (n - i)*b)) {
            ans = (ans + choose) % p;
        }
        choose = mod_divide(mulmod(choose, (n - i)), (i + 1));
    }
    cout << ans << endl;
}