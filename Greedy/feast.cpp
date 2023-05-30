#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main (){
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (ll i = 0; i < n; ++i) cin >> arr[i];

    //__________Srink to pos/neg arr_______
    vector<pair<ll, ll>> f_arr;
    ll cur = arr[0];
    ll positive_n = 0;
    ll position = 0;
    for (ll i = 1; i < n; ++i){
        if (arr[i] < 0){
            if (cur < 0) cur += arr[i];
            else{
                f_arr.push_back({cur, position});
                cur = arr[i];
                position++;
            }
        }
        else{
            if (cur > 0) cur += arr[i];
            else{
                f_arr.push_back({cur, position});
                cur = arr[i];
                positive_n++;
                position++;
            }
        }
    }
    f_arr.push_back({cur, position});
    if (cur > 0) positive_n ++;

    //____________________________________
    vector <pair<ll, ll>> s_arr (f_arr);
    vector <bool> visit(n, 0);
    sort (s_arr.begin(), s_arr.end(), greater<pair<ll, ll>>());

    //for (auto e: s_arr) cout << e.first << " ";

    ll ans = 0;
    ll new_n = f_arr.size();
    if (k < positive_n){ //leftover pos_n
        for (ll i = 0; i < k; ++i){
            ans += s_arr[i].first;
            visit[s_arr[i].second] = 1;
        }
        /*for (bool e: visit) cout << e << "  ";
        cout << endl;
        cout << "First ans: " << ans << endl;*/

        vector <ll> toAdd;
        ll now = 0;
        bool flag = 0;
        for (ll i = 0; i < new_n; ++i){
            if (!visit[i]){
                if (f_arr[i].first < 0){
                    if (flag == 0) now = 0;
                    toAdd.push_back(now);
                    now += f_arr[i].first;
                }
                else now += f_arr[i].first;
            }
            else {
                now = 0;
                flag = 1;
            }
        }

        now = 0;
        flag = 0;
        ll ind = toAdd.size()-1;
        for (ll i = new_n-1; i > -1; --i){
            if (!visit[i]){
                if (f_arr[i].first < 0){
                    if (flag == 0) now = 0;
                    toAdd[ind] += now;
                    ind --;
                    now += f_arr[i].first;
                }
                else now += f_arr[i].first;
            }
            else{
                now = 0;
                flag = 1;
            }
        }
        /*for (auto e: toAdd) cout << e << " ";
        cout << endl;*/

        ll maxA = 0;
        ind = 0;
        for (ll i = 0; i < new_n; ++i){
            if (visit[i]){
                ans += maxA;
                //cout << maxA << " ";
                maxA = 0;
            }
            else{
                if (f_arr[i].first < 0){
                    maxA = max(maxA, toAdd[ind]);
                    ind++;
                }
            }
        }
        //cout << endl << "2nd ans: " << ans << endl;
    }
    else{
        ll i = 0;
        while (s_arr[i].first>0){
            ans += s_arr[i].first;
            i++;
        }
    }
    cout << endl << ans;

}
