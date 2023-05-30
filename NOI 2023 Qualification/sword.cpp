#include <bits/stdc++.h>
using namespace std;

int main(){
    long n; cin >> n;
    pair<long, long> a[n];
    long b[n];
    for (long i = 0; i < n; ++i){
        long fi, se; cin >> fi >> se;
        a[i] = {fi,se};
        b[i] = se;
    }
    sort(a, a+n);

    long lastB = a[n-1].second;
    long ans = 1;
    for (long i = n-2; i > -1; --i){
        if (a[i].second > lastB){
            lastB = a[i].second;
            ans++;
        }
    }
    cout << ans;

}
