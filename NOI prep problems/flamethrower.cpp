#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int iCnt = 0;
    int arr[n], prefK[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        if (i == 0) {
            prefK[i] = arr[i];
        }
        else if (i < k){
            prefK[i] = arr[i] + prefK[i-1];
        }
        else {
            prefK[i] = arr[i] + prefK[i-1] - arr[iCnt];
            iCnt++;
        }
    }
    int maxA = 0;
    for (int i = 0; i < n; ++i){
        maxA = max(maxA, prefK[i]);
    }
    cout << maxA;


    return 0;
}
