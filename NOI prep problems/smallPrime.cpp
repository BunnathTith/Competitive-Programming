#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll prime [61];

vector<ll> priming (){
    for (ll i = 2; i*i <= 61; ++i){
        if (prime[i] == 0){
            for (ll j = 2; i*j <=65; ++j){
                prime [i*j] = 1;
            }
        }
    }
    vector <ll> pNum;
    for (ll i = 2; i < 61; ++i){
        if (prime[i] == 0){
            pNum.push_back(i);
        }
    }
    return pNum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector <ll> pNum = priming();
    ll n = pNum.size();

    ll  q, k;
    cin >> q >> k;

    for (ll i = 0; i < n; ++i){
        if (k<pNum[i]){
            n = i-1;
            break;
        }
    }

    for (ll tc = 0; tc < q; ++tc){
        ll lf, ri;
        cin >> lf >> ri;
        ll cnt = 0;
        //cout << lf << " " << ri << endl;
        for (ll ii = lf; ii <= ri; ++ii){
            //cout << i << ": ";
            ll i = ii;
            for (ll j = 0; j <= n; ++j){
                //if (i > pNum[j])cout << i << "%" << pNum[j] << "; ";
                while (i % pNum[j] == 0){
                    if (i < pNum[j]) break;
                    //cout << i << "%" << pNum[j] << "; ";
                    i = i/pNum[j];
                    //cout << i << " ";
                }
                //cout << endl;

            }
            if (i==1) cnt ++;
        }
        cout << to_string(cnt) + "\n";
    }
}
