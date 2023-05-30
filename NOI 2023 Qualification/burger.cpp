#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> pll;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    long n; cin >> n;
    long x[n];
    long a[n], b[n];
    for (long i = 0; i < n; ++i) cin >> x[i];
    for (long i = 0; i < n; ++i) cin >> a[i];
    for (long i = 0; i < n; ++i) cin >> b[i];
    bool case1 = 1;
    for (long i = 0; i < n; ++i){
        if (a[i] != b[i]){
            case1 = 0;
            break;
        }
    }
    long minAtime = LONG_MAX;
    for (long i = 0; i < n; ++i){
        minAtime = min(minAtime, x[i]/a[i]);
    }
    if (!case1){
        long ans = 0;
        for (long j = 0; j < minAtime; ++j){
            long minBtime = LONG_MAX;
            for (long i = 0; i < n; ++i){
                minBtime = min(minBtime, (x[i]-a[i]*j)/b[i]);
            }
            ans = max(ans, j+minBtime);
        }
        cout << ans;
    }
    else{
        cout << minAtime;
    }

}
