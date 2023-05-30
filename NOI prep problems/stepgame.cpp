#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n; cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; ++i){
        cin >> arr[i];
    }

    ll dp[n];
    ll sum = 0;
    for (ll i = 0; i < n; ++i){
        if (i == 0){
            dp[i] = arr[i];
        }
        else{
            dp[i] = min(dp[i-1] + arr[i],arr[i]);
        }
    }
    for (ll e: dp){
        cout << e << " ";
    }
    cout << endl;
    cout << *min_element(dp, dp+n);
}
