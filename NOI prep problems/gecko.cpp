#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    int arr[h][w];
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            cin >> arr[i][j];
        }
    }

    int dp[h][w];
    for (int i = 0; i < w; ++i){
        dp[0][i] = arr[0][i];
    }
    for (int i = 1; i < h; ++i){
        for (int j = 0; j < w; ++j){
            int ab_lf, ab, ab_ri;
            ab = dp[i-1][j];
            if (j == w-1)  ab_ri = ab;
            else ab_ri = dp[i-1][j+1];
            if (j == 0) ab_lf = ab;
            else ab_lf = dp[i-1][j-1];
            //cout <<i<<j<< ": " << ab_lf << " " << ab << " " << ab_ri << "r: ";
            dp[i][j] = arr[i][j] + max(max(ab_lf, ab), ab_ri);
            //cout << dp[h][w] << endl;
        }

    }
    int ans = 0;
    for (int j = 0; j < w; ++j){
        ans = max(ans, dp[h-1][j]);
    }
    /*cout << endl;
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << ans;
}
