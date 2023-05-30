#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n, k; cin >> n >> k;

    queue <ll> arr;
    for (ll i = 0; i < n; ++i){
        ll x; cin >> x;
        arr.push(x);
    }

    ll total = 0;
    ll cont = 0;
    priority_queue <ll> lastK;

    for (ll i = 0; i < k; ++i){
        lastK.push(arr.front());
        arr.pop();
    }

    while (! lastK.empty()){
        ll tmp = lastK.top();
        lastK.pop();
        cont += tmp;
        total = max(total, cont);

        if (! arr.empty()){
            lastK.push(arr.front());
            arr.pop();
        }
    }
    cout << total;
}

