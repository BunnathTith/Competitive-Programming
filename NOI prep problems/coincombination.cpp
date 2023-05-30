#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, v; cin >> n >> v;
    int coins[n];
    for (int i = 0; i < n; ++i) cin >> coins[i];

    int dp[n][v+1];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= v; ++j){
            if (i == 0){
                if (j == 0) dp[i][j] = 1;
                else if(j < coins[i]) dp[i][j] = 0;
                else dp[i][j] = dp[i][j-coins[i]];
            }
            else{
                if (j == 0) dp[i][j] = 1;
                else if (j < coins[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = (dp[i-1][j]%13371337 + dp[i][j-coins[i]]%13371337)%13371337;
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[n-1][v];
}
