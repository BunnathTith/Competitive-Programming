#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    int pot[n];
    for (int i = 0; i < n; ++ i){
        cin >> pot[i];
    }
    sort(pot, pot+n, greater<int>());
    int sum = 0;
    for (int i = 0; i < d; ++i){
        sum += pot[i];
    }
    cout << sum;
}
