#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m; cin >> n >> m;
    ll arr[n+1][m+1];
    ll h_pref[n+1][m+1];
    ll v_pref[n+1][m+1];
    for (ll i = 0; i <= n; ++i){
        for (ll j = 0; j <= m; ++j){
            if (i != 0 && j != 0){
                cin >> arr[i][j];
                h_pref[i][j] = h_pref[i][j-1] + arr[i][j];
                v_pref[i][j] = v_pref[i-1][j] + arr[i][j];
            }
            else {
                h_pref[i][j] = 0;
                v_pref[i][j] = 0;
            }
        }
    }

    ll h_min[n+1][m+1];
    ll v_min[n+1][m+1];
    for (ll i = 0; i <= n; ++i){
        for (ll j = 0; j <= m; ++j){
            if (i==0||j==0){
                h_min[i][j] = h_pref[i][j];
                v_min[i][j] = v_pref[i][j];
            }
            else{
                h_min[i][j] = min(h_min[i][j-1], h_pref[i][j]);
                v_min[i][j] = min(v_min[i-1][j], v_pref[i][j]);
            }
        }
    }

    /*for (auto e: h_pref[1]) cout << e << " ";
    cout << endl;
    for (auto e: h_min[1]) cout << e << " ";
    cout << endl;*/


    ll ans[n+1][m+1];
    for (ll i = 1; i <= n; ++i){
        for (ll j = 1; j <= m; ++j){
            ll lf, ri = LLONG_MIN;
            ll fix = h_pref[i][j];
            lf = fix - h_min[i][j-1];

            fix = h_pref[i][j-1];
            for (ll x = j; x <= m; ++x){
                ri = max(ri, h_pref[i][x]-fix);
            }

            //cout << lf << " " << ri << endl;
            ans[i][j] = max(lf, ri);
        }

    }

    for (ll j = 1; j <= m; ++j){
        for (ll i = 1; i <= n; ++i){
            ll tp = LLONG_MIN, dn = LLONG_MIN;
			ll fix = v_pref[i][j];
            tp = fix-v_min[i-1][j];
			fix = v_pref[i-1][j];
			for (ll x = i; x <= n; ++x){
				dn = max(dn, v_pref[x][j]-fix);
			}
            ans[i][j] += max(tp, dn);
            ans[i][j] -= arr[i][j];
        }
    }

    ll ansr = INT_MIN;
    for (ll i = 1; i <= n; ++i)
        for (ll j = 1; j <= m; ++j){
            ansr = max(ansr, ans[i][j]);
        }
    cout << ansr;
}
