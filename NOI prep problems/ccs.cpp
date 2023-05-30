#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull n, q; cin >> n >> q;
    set <ull> st;
    st.insert (-1);
    for (ull i = 0; i < q; ++i){
        string cmd;
        cin >> cmd;
        if (cmd == "SLEEP"){
            ull x; cin >> x;
            st.insert(x);
        }
        else if (cmd == "WAKE"){
            ull x; cin >> x;
            st.erase (x);
        }
        else if (cmd == "TRANSMIT"){
            ull x, y; cin >> x >> y;
            auto s_i = st.lower_bound(x);
            if (*s_i > y || s_i == st.end()) cout << "YES\n";
            else cout << "NO\n";
        }
    }

}
