#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct img{
    ll sz;
    ll val;
};

bool comp (img fi, img se){
    return fi.val < se.val;
}

int main(){
    ll n, m; cin >> n >> m;

    img pic[n];
    for (ll i = 0; i < n; ++i) cin >> pic[i].sz >> pic[i].val;
    sort (pic, pic+n, comp);

    ll frame [m];
    for (ll i = 0; i < m; ++i) cin >> frame[i];
    sort (frame, frame+m);

    cout << endl;
    for (img e: pic) cout << e.sz << " ";
    cout << endl;
    for (img e: pic) cout << e.val << " ";
    cout << endl;

    for (ll e: frame) cout << e << " ";
    return 0;
}
