#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k; cin >> n >> k;
    ll arr[n+2], dp[n+2];
    deque <int>sliding;
    set <ll> st;

    for (ll i = 1; i <= n; ++i) cin >> arr[i];

    arr[0] = 0;
    arr[n+1] = 0;
    dp[0] = 0;
    sliding.push_back(0);
    //st.insert(dp[0]);

    for (ll i = 1; i < n+2; ++i){ //check i-k to i-1 //sliding is 1 behind
        dp[i] = dp[sliding.front()] + arr[i];
        while (!sliding.empty() && dp[sliding.back()] >= dp[i]) sliding.pop_back();
        sliding.push_back(i);
        if (i >= k){
            if (i-k == sliding.front()) sliding.pop_front();
        }
    }

    cout << dp[n+1];
}
