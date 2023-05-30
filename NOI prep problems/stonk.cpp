#include <bits/stdc++.h>
using namespace std;

int main(){
    long n; cin >> n;
    long a[n], b[n];
    for (long i = 0; i < n; ++i) cin >> a[i];
    for (long i = 0; i < n; ++i) cin >> b[i];

    long last = b[n-1];
    for (long i = n-2; i > -1; --i){
        if (b[i] < last) b[i] = 0;
        else last = b[i];
    }

    long ans = 0;
    for (long i = 0; i < n; ++i){
        if (b[i] == 0) a[i+1] += a[i];
        else ans += a[i]*b[i];
    }
    cout << ans;
}
