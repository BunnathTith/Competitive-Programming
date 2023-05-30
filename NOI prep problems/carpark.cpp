#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main (){
    ll n, s;
    cin >> n >> s;

    vector <ll> zeroCnt;
    ll ans = n, cur = 0;

    bool flag = 0;
    for (ll i = 0; i < n; ++i) {
        ll e; cin >> e;
        if (e == 1) {
            if (flag == 0) {
                ans -= cur;
                flag = 1;
            }
            else zeroCnt.push_back(cur);
            cur = 0;
        }
        else cur++;
    }
    ans -= cur;

    sort (zeroCnt.begin(), zeroCnt.end(), greater<ll>());
    /*for (long e: zeroCnt){
        cout << e << " ";
    }*/
    //cout << endl;
    for (ll i = 0; i < zeroCnt.size(); ++i){
        if (s == 1) break;
        ans -= zeroCnt[i];
        s--;
    }
    cout << ans;
}
