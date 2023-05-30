#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll memo[100005];
set <ll> st;

ll solve (ll i){
    if (st.find(i) == st.end()){
        if (memo[i] > 0) return memo[i];
        if (i == 0) memo[i] = 1;
        if (i == 1) memo[i] = memo[i-1] + 1;
        if (st.find(i-1) == st.end()) memo[i] += solve(i-1);
        if (st.find(i-2) == st.end()) memo[i] += solve (i-2);
    }
    else{
        memo[i] = 0;
    }
    return memo[i];
}

int main(){
    //memset(mem, -1, sizeof(mem));

    ll n, m; cin >> n >> m;
    ll arr[m];

    for (ll i = 0; i < m; ++i){
        ll x; cin >> x;
        st.insert(x-1);
    }
    fill (memo, memo+100005, 0);

    //for (ll e: dp) cout << e << " ";
    //cout << endl;
    cout << solve(n-1) % 1000000007;
}
