#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, k; cin >> n >> k;
    long a1[n], a2[n], dp[n][2];

    for (long i = 0; i < n; ++i) cin >> a1[i];
    for (long i = 0; i < n; ++i) cin >> a2[i];
    fill (dp[0], dp[0]+n, 0);
    fill (dp[1], dp[1]+n, 0);

    for (long i = 0; i < n; ++i) {
        if (i == 0){
            dp[i][0] = a1[i];
            dp[i][1] = a2[i];
        }
        else{
            dp[i][0] = max (dp[i-1][0], dp[i-1][0]-k) + a1[i];
            dp[i][1] = max (dp[i-1][1], dp[i-1][1]-k) + a2[i];
        }
    }
    cout << max(dp[n-1][0], dp[n-1][1]);
}
