#include <bits/stdc++.h>
using namespace std;

int main(){
    long cn, wi; cin >> cn >> wi;

    pair<long, long> p[cn];
    for (long i = 0; i < cn; ++i){
        long w, v;
        cin >> w >> v;
        p[i].first = w, p[i].second = v;
    }

    long dp[cn][wi+1];
    for (long i = 0; i < cn; ++i){
        for (long j = 0; j < wi+1; ++j){
            if (j == 0){
                dp[i][j] = 0;
                continue;
            }

            if (i == 0){
                if (j < p[i].first){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = p[i].second;
                }
            }
            else{
                if (j < p[i].first){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i].first]+p[i].second);
                }
            }
        }
    }
    cout << dp[cn-1][wi];

}
