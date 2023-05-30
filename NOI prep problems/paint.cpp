#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    int ks[n];

    int sum = 0;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; ++i){
        cin >> ks[i];
    }
    sort (ks, ks+n, greater <int>());
    for (int i = 0; i < n; ++i){

        sum += ks[i]*i;
    }

    /*cout << endl;
    for (int e: ks) cout << e << " ";
    cout << endl;
    for (int i = 0; i < n; ++i) cout << ks[i]*i << " ";
    cout << endl;*/

    cout << sum;
}
