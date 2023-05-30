#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

int main(){
    long n; cin >> n;
    long arr[n];
    for (long i = 0; i < n; ++i){
        long fi, se; cin >> fi >> se;
        arr[i] = fi*se;
    }
    cout << *max_element(arr, arr+n);

}
