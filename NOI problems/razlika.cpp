#include <bits/stdc++.h>
using namespace std;
long long seg[4*1000005];

void build (long long arr[], long long nd, long long tl, long long tr){
    if (tl == tr){
        seg[nd] = arr[tl];
        return;
    }
    long long tm = (tl+tr)/2;
    build (arr, nd*2+1, tl, tm);
    build (arr, nd*2+2, tm+1, tr);
    seg[nd] = min(seg[nd*2+1], seg[nd*2+2]);
}

long long getRange (long long nd, long long tl, long long tr, long long lf, long long ri){
    if (tl >= lf && ri >= tr) return seg[nd];
    //if (tl == l && r == tr) return seg[v];
    if (tr < lf || tl > ri) return LLONG_MAX;

    long long tm = (tr+tl)/2;
    long long leftChild = getRange(nd*2+1, tl, tm, lf, ri);
    long long rightChild = getRange(nd*2+2, tm+1, tr, lf, ri);
    return min(leftChild, rightChild);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long  n, k;
    cin >> n >> k;
    long long arr [n];
    for (long long i = 0; i < n; ++i){
        cin >> arr[i];
    }
    sort (arr, arr+n);
    long long w_sz = n-k;

    long long diff_arr[n-1];
    for (long long i = 0; i < n-1; ++i){
        diff_arr[i] = arr[i+1] - arr[i];
    }
    build (diff_arr, 0, 0, n-2);

    /*for (long long i = 0; i < n-1; ++i){
        cout << diffArr
    }
    for (long long e: diffArr){
        cout << e << " ";
    }*/

    long long big_m;
    long long small_m;
    long long theMin = LLONG_MAX;

    for (long long i = 0; i <= k; ++i){
        big_m = arr[w_sz-1+i] - arr[i];
        small_m = getRange(0, 0, n-2, i, w_sz-2+i);
        theMin = min(theMin, big_m+small_m);
    }
    cout << theMin;

}
