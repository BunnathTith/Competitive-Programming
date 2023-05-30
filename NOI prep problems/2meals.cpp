// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
int main() {
    ull n; cin >> n;
    ull arr[n];
    for (ull i = 0; i < n; ++i){
        cin >> arr[i];
    }

    ull fr_dp[n+1];
    ull sum = 0;
    fr_dp[0] = 0;
    for(ull i = 1; i <=n; ++i){
        sum += arr[i-1];
        fr_dp[i] = max(fr_dp[i-1], sum);
        sum = max(0ll, sum);
    }

    ull bk_dp[n+1];
    sum = 0;
    bk_dp[n] = 0;
    for (ull i = n-1; i >= 0; --i){
        sum += arr[i];
        bk_dp[i] = max(bk_dp[i+1], sum);
        sum = max(0ll, sum);
    }

    ull ans = INT_MIN;
    for (ull i = 0; i <=n; ++i){
        ans = max(ans, fr_dp[i] + bk_dp[i]);
    }
    cout << ans;
    /*cout << endl;
    for (int e: fr_dp) cout << e << " ";
    cout << endl;
    for (int e: bk_dp) cout << e << " ";*/
    return 0;
}
