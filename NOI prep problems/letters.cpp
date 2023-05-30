#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int indexConv (char let){
    int cur = int(let);
    if (cur >= 65 && cur <=90) cur += 32;
    if (cur >= 97 && cur <=122) return cur-96;
    return -1;
}

int main(){
    string jumbo; cin >> jumbo;
    ull n = jumbo.size();

    pair <ull, ull> dp[27];
    for (int i = 0; i < 27; ++i){
        if (i == 0) dp[i] = {1,1};
        else dp[i] = {0, 0};
    }

    for (ull i = 0; i < n; ++i){
        int dp_ind = indexConv(jumbo[i]);
        if (dp_ind == -1) continue;

        if (dp[dp_ind-1].first != 0){
            if (dp[dp_ind].first != 0){ //mid seq
                dp[dp_ind].second ++;
                dp[dp_ind].first += dp[dp_ind-1].second;
            }
            else{ //continue the seq
                dp[dp_ind].second ++;
                dp[dp_ind].first = dp[dp_ind-1].first * dp[dp_ind].second;
            }
        }
    }
    cout << dp[26].first;
}
