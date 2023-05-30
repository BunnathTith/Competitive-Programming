#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long m = 1000000009;
    long long arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    long long ans = 1;
    for (int i = 0; i < 5; ++i){
        ans *= arr[i]%m;
        ans = ans%m;
    }
    cout << ans;
}
