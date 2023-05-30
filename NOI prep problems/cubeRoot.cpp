#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unordered_map <long long, long long> cbrt;

    for (long long i = 0; i <1000005; ++i){
        cbrt [i*i*i] = i;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i){
        long long num;
        cin >> num;
        cout << cbrt[num] << endl;
    }

}
