#include <bits/stdc++.h>
using namespace std;

int main(){
    long n, l, t; cin >> n >> l >> t;

    long arr[n+2];
    arr[0] = 0;
    bool link = 1;
    for (long i = 1; i <= n; ++i) cin >> arr[i];
    arr[n+1] = l;
    sort (arr, arr+n+1);



    long lastTU = 0, ans = 0;

    for (long i = 1; i <= n+1; ++i){
        if (arr[i] - lastTU > t){
            if (lastTU == arr[i-1]){
                link = 0;
                break;
            }
            else{
                if (arr[i] - arr[i-1] > t){
                    link = 0;
                    break;
                }
                lastTU = arr[i-1];
                ans++;
            }
        }
    }
    if (l-lastTU > t) ans ++;

    if (link == 0) cout << -1;
    else cout << ans;

}
