#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i){
        if (i%a == 0 || i%b == 0){
            if (i%a == 0) cout << "Fizz";
            if (i%b == 0) cout << "Buzz";
            cout << endl;
        }
        else cout << i << endl;
    }
}
