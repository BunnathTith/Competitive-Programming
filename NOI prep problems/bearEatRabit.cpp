#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long arr[n];
    long long ans = 0;
    long long prefArr[n];
    long long max1 = LLONG_MIN;
    long long noEat = 0;

    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        noEat = max(arr[i], max1); //maximum if eat only 1
    }
    sort(arr, arr+n);

    for (int i = 0; i < n; ++i){
        if (i<=1){
            prefArr[i] = max(noEat, arr[i]);
        }
        else if (i == 2){
            long long adding = max(arr[i] + prefArr[i-2], arr[i]);
            prefArr[i] = max(adding, noEat);
        }
        else {
            long long added = max(prefArr[i-2], prefArr[i-3]);
            long long noAdd = max(prefArr[i-2]-arr[i-2], prefArr[i-3]-arr[i-3]);
            long long adding = max(added, noAdd);
            prefArr[i] = max(arr[i] + adding, noEat);
        }
        ans = max(ans, prefArr[i]);
    }

    cout << ans;

}
