#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string strin;
    cin >> strin;
    int arr[n];
    for (int i = 0; i < n; ++i){
        if (strin[i] == 'M'){
            arr[i] = -2;
        }
        else{
            arr[i] = int(strin[i]) - 48;
        }
    }

    int dp[n];
    for (int i = 0; i < n; ++i){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    }

    for (int e: dp){
        cout << e << " ";
    }
    cout << endl;
    cout << *max_element(dp, dp+n);
}
