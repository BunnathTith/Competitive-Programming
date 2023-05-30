#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main (){
    ll n, r; cin >> n >> r;
    n = n-1; r = r-1;
    ll bg = max(n-r, r), sm = min(n-r, r), ans = 1, sd = 1;
    for (ll i = bg+1; i <= n; ++i) ans *= i;
    for (ll i = 2; i <= sm; ++i) sd *= i;
    cout << ans / sd;

}
