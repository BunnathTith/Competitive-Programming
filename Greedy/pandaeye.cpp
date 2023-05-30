#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main (){
    ll n; cin >> n;

    vector <pair<ll, ll>> gd;
    for (ll i = 0; i < n; ++i){
        ll s, e;
        cin >> s >> e;
        gd.push_back({s, e});
    }
    sort (gd.begin(), gd.end());

    //repetitive removal
    vector <pair<ll, ll>> rp_rm;
    for (ll i = 0; i < n; ++i){
        if (i == 0){
            rp_rm.push_back(gd[i]);
        }
        else{
            if (gd[i].first != rp_rm.back().first){
                rp_rm.push_back(gd[i]);
            }
        }
    }
    /*(for (auto e: rp_rm){
        cout << e.first << " " << e.second << endl;
    }*/

    //counting;
    ll cnt = 1;
    ll lastE = rp_rm[0].second;
    for (ll i = 1; i < rp_rm.size(); ++i){
        if (lastE <= rp_rm[i].first){
            cnt ++;
            lastE = rp_rm[i].second;
            continue;
        }
        if (lastE > rp_rm[i].second){
            lastE = rp_rm[i].second;
        }
    }
    cout << cnt;
}
