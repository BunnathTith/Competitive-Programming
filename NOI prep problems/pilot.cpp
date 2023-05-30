#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, q; cin >> n >> q;
    ll ls_arr[n], p_arr[q];
    bool inc = 1;
    for (ll i = 0; i < n; ++i){
        cin >> ls_arr[i];
        if (i > 0){
            if (ls_arr[i] < ls_arr[i-1]) inc = 0;
        }
    }
    for (ll i = 0; i < q; ++i) cin >> p_arr[i];

    if (!inc){
        ll ans = 0;
        ll last = 0;
        for (ll i = 0; i < q; ++i){
            for (ll j = n-1; j > -1; --j){
                if (ls_arr[j] <= p_arr[i]){
                    last ++;
                    ans += last;
                }
                else{
                    last = 0;
                }

            }
            cout << ans << "\n";
            ans = 0;
            last = 0;
            //cout << endl;
        }
    }
    else{
        for (ll i = 0; i < q; ++i){
            ll ind = (upper_bound(ls_arr, ls_arr+n, p_arr[i]) - ls_arr);
            //cout << ind;
            if (ind % 2ll == 0) cout << (ind/2ll)*(ind+1ll) << "\n";
            else cout << ((ind)/2ll)*(ind+1ll)+ind/2ll+1ll << "\n";
        }
    }

}
