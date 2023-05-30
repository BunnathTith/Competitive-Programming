#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, v; cin >> n >> v;
    int dp [n][v+1];

    for (int i = 0; i < n; ++i){
        dp[i][0] = 0;
        fill(dp[i]+1, dp[i]+v+1, -1);
    }

    int mn_arr[n];
    for (int i = 0; i < n; ++i){
        cin >> mn_arr[i];
    }

    int up, fact;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < v+1; ++j){
            if (i == 0){
                if (j < mn_arr[i]){
                    dp[i][j] = -1;
                }
                else if (j == mn_arr[i]){
                    dp[i][j] = 1;
                }
                else{

                    if (dp[i][j-mn_arr[i]] != -1){
                        dp[i][j] = dp[i][j-mn_arr[i]]+1;
                    }
                }
            }
            else {
                if (j < mn_arr[i]){
                    dp[i][j] = max(-1, dp[i-1][j]);
                }
                else if (j == mn_arr[i]){
                    dp[i][j] = 1;
                }
                else {
                    if (dp[i][j-mn_arr[i]] != -1){
                        if (dp[i-1][j] != -1){
                            dp[i][j] = min(dp[i][j-mn_arr[i]]+1, dp[i-1][j]);
                        }
                        else {
                            dp[i][j] = dp[i][j-mn_arr[i]]+1;
                        }
                    }
                    else{
                        dp[i][j] = max(-1, dp[i-1][j]);
                    }
                }
            }
        }
    }

    /*for (int i = 0; i < n; ++i){
        for (int j = 0; j < v+1; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[n-1][v];

}
