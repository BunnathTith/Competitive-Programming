#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[200005];
    fill(arr, arr+200005, 0);
    for (int i = 0; i < n-1; ++i){
        int x;
        cin >> x;
        arr[x]++;
    }
    for (int i = 1; i <= n; ++i){
        cout << arr[i] << "\n";
    }


}
