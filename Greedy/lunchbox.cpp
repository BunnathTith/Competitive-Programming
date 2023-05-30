#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define forn(n) for(int in = 1; in <= n; ++ in)
#define fora(n) for(int ia = 0; ia < n; ++ ia)
#define forat(arr_name) for(auto at_e: arr_name) {cout << at_e << "\n";}

int main (){
    int n, m;
    cin >> n >> m;
    vector <int> arr;
    forn (m){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int cnt = 0;
    for (int e: arr){
        if (n-e < 0){
            break;
        }
        n = n-e;
        cnt++;
    }
    cout << cnt;
}
