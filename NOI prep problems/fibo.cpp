#include <bits/stdc++.h>
using namespace std;



int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long f = 0;
    unsigned long long s = 1;
    unsigned long long n;
    cin >> n;

    if (n >= 2){
        cout << f << endl << s << endl;
        for (unsigned long long i = 2; i <=n; ++i){
            cout << (f+s)%998244353 << endl;
            unsigned long long temp_s = s;
            s = f+s%998244353;
            f = temp_s%998244353;
        }
    }
    else if (n == 1){
        cout << "0\n1";
    }
    else if (n == 0){
        cout << "0";
    }


}
