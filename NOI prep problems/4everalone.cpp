#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
    ull n, k; cin >> n >> k;
    /*map <ull, ull> mp;
    for (ull i = 0; i < k; ++i){
        ull fi, se;
        cin >> fi >> se;
        if (fi != se){
            mp[fi] = 1;
            mp[se] = 1;
        }
    }*/
    set <ull> st;
    for (ull i = 0; i < k; ++i){
        ull fi, se; cin >> fi >> se;
        if (fi != se){
            st.insert(fi);
            st.insert(se);
        }
    }

    cout << n-st.size();
}
