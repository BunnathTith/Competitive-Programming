#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    priority_queue <ll> lf;
    priority_queue <ll, vector <ll>, greater<ll>> ri;
    ll lf_n, ri_n;
    ll n; cin >> n;

    for (ll i = 0; i < n; ++i){
        lf_n = lf.size();
        ri_n = ri.size();
        string cmd; cin >> cmd;
        if (cmd == "PUSH"){
            ll x; cin >> x;
            if (lf_n+ri_n < 2 ){ //base case
                if (lf_n == 0 && ri_n == 0)lf.push(x);
                else if (lf_n == 1 && ri_n == 0){
                    if (x > lf.top()) ri.push(x);
                    else{
                        ri.push(lf.top());
                        lf.pop();
                        lf.push(x);
                    }
                }
                else if (lf_n == 0 && ri_n == 1){
                    if (x < ri.top()) ri.push(x);
                    else{
                        lf.push(ri.top());
                        ri.pop();
                        ri.push(x);
                    }
                }
            }
            else {               //main case
                if (lf_n == ri_n){      //case 1
                    if (x<ri.top()) lf.push(x);
                    else ri.push(x);
                }
                else if (lf_n > ri_n){
                    if (x > lf.top()) ri.push(x);
                    else{
                        ri.push(lf.top());
                        lf.pop();
                        lf.push(x);
                    }
                }
                else{
                    if (x < ri.top()) lf.push(x);
                    else{
                        lf.push(ri.top());
                        ri.pop();
                        ri.push(x);
                    }
                }
            }
        }
        else if (cmd == "POP"){
            if (lf_n >= ri_n) lf.pop();
            else ri.pop();
        }
    }
    priority_queue <ll, vector <ll>, greater<ll>> lf_order;
    while (!lf.empty()){
        lf_order.push(lf.top());
        lf.pop();
    }

    while (!lf_order.empty()){
        cout << lf_order.top() << " ";
        lf_order.pop();
    }
    while (!ri.empty()){
        cout << ri.top() << " ";
        ri.pop();
    }

    return 0;
}
