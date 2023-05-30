#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

vector <ll> arr;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int curLen;
ll curr;
void filling(int j) {
    arr.push_back(prime[j]);
    curLen = arr.size();
    for (int i = 0; i < curLen; ++i){
        curr = arr[i];
        while (curr < 1e18){
            curr *= ll(prime[j]);
            arr.push_back(curr);
        }
    }
}

int main(){
    int q, k; cin >> q >> k;
    arr.push_back(1ll);
    for (int i = 1; i <=60; ++i){
        curr = prime[0];
        arr.push_back(curr);
        curr *= 2ll;
    }
    int goTill = upper_bound(prime, prime+17, k) - prime - 1;
    for (int i = 0; i <= goTill; ++i){
        filling(i);
    }

    set<ll> st(arr.begin(),arr.end());
    arr.clear();
    vector<ll> a_arr(st.begin(), st.end());
    st.clear();
    sort (a_arr.begin(), a_arr.end());

    ll l, r;
    for (int i = 0; i < q; ++i){
        cin >> l >> r;
        cout << to_string((upper_bound(a_arr.begin(), a_arr.end(), r) - a_arr.begin()) - (lower_bound(a_arr.begin(), a_arr.end(), l) - a_arr.begin()))+"\n";
    }

}
