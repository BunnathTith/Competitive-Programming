#include <bits/stdc++.h>
using namespace std;

//typedef unsigned unsigned long long uint64_t;

int bs(vector <unsigned long long> arr, int l, int r, unsigned long long x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return 1;
        else if (arr[mid] > x) return bs(arr, l, mid - 1, x);
        else return bs(arr, mid + 1, r, x);
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long q;
    cin >> q;
    //vector <unsigned long long> cups;

    unsigned long long cups [];
    unsigned long long extas = 0;

    for (unsigned long long i = 0; i < q; ++i){
        int indi;
        unsigned long long x;
        cin >> indi;
        cin >> x;

        if (indi == 1){
            if (x < extas) {
                cout << "NO" << endl;
            }
            else {
                if (cups[x-extas] == 1) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
        else if (indi == 2){
            cups [x] = 1;
        }
        else if (indi == 3){
            extas += x;
        }

    }

    return 0;
}
