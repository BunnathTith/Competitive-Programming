#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<>());
    int ans = 0;
    for (int i = k-1; i < n; i+=k){

        ans = max(ans, ans + arr[i]);
        //cout << arr[i] << " ";
    }
    cout << ans;
}
