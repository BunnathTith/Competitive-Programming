#include <bits/stdc++.h>
using namespace std;

struct sub{
    int phy;
    int bio;
};

bool comp (sub fi, sub se){
    return fi.phy-fi.bio > se.phy-se.bio;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    sub arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i].phy;
    for (int i = 0; i < n; ++i) cin >> arr[i].bio;
    sort (arr, arr+n, comp);

    int ans = 0;
    for (int i = 0; i < a; ++i) ans += arr[i].phy;
    for (int i = a; i < n; ++i) ans += arr[i].bio;
    cout << ans;
}
