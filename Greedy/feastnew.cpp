#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct merging{
    vector <ll> sub_arr;
    ll sum = 0;
    ll cms;
};

ll cms (vector <ll> arr){
    ll n = arr.size();
    ll last = arr[0];
    ll minAns = last;

        for (ll i = 1; i < n; ++i){
            if (last + arr[i] < 0){
                last += arr[i];
                minAns = min (minAns, last);
            }
            else{
                last = 0;
            }
        }


    return minAns;
}


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
                position++;
                positive_n++;
                cur = arr[i];
            }
        }
        else{
            if (cur > 0) cur += arr[i];
            else{
                f_arr.push_back({cur, position});
                position++;
                if (f_arr.size() == 1) {
                    f_arr.pop_back();
                    position--;
                }
                cur = arr[i];
            }
        }
    }
    if (cur > 0){
        f_arr.push_back({cur, position});
        if (cur > 0) positive_n ++;
    }

    //____________________________________
    ll nn = f_arr.size();
    vector <pair<ll, ll>> s_arr (f_arr);
    vector <bool> visit(nn, 0);
    sort (s_arr.begin(), s_arr.end(), greater<pair<ll, ll>>());

    //for (auto e: s_arr) cout << e.first << " ";

    ll ans = 0;
    if (k < positive_n){ //leftover pos_n
        for (ll i = 0; i < k; ++i){
            ans += s_arr[i].first;
            //visit.push(s_arr[i].second);
            visit[s_arr[i].second] = 1;
        }

        //for (auto e: f_arr) cout << e.first << " ";
        //cout << endl;
        /*for (auto e: visit) cout << e << "  ";
        cout << endl << endl;*/

        vector<merging> pa_arr;
        merging inter;
        for (ll i = 0; i < nn; ++i){
            if (!visit[i]){
                inter.sub_arr.push_back(f_arr[i].first);
                inter.sum += f_arr[i].first;
            }
            else{
                pa_arr.push_back(inter);
                inter.sub_arr.clear();
                inter.sum = 0;
            }
        }
        pa_arr.push_back(inter);

        //mid
        for (ll i = 1; i < pa_arr.size()-1; ++i){
            pa_arr[i].cms = cms(pa_arr[i].sub_arr);
            if (pa_arr[i].sum - pa_arr[i].cms > 0) ans += (pa_arr[i].sum - pa_arr[i].cms);
        }
        //front
        ll curMax = 0;
        ll summing = 0;
        for (ll i = pa_arr.front().sub_arr.size()-1; i > -1; --i){
            summing += pa_arr.front().sub_arr[i];
            curMax = max(curMax, summing);
        }
        ans += curMax;
        //back
        curMax = 0;
        summing = 0;
        for (ll i = 0; i < pa_arr.back().sub_arr.size(); ++i){
            summing += pa_arr.back().sub_arr[i];
            curMax = max(curMax, summing);
        }
        ans += curMax;

        /*for (auto e: pa_arr){
            cout << "Array: ";
            for (auto ee: e.sub_arr) cout << ee << " ";
            cout << endl << e.sum << endl << e.cms << endl << endl;
        }*/
    }
    else{
        ll i = 0;
        while (s_arr[i].first>0){
            ans += s_arr[i].first;
            i++;
        }
    }
    cout << ans;

}
