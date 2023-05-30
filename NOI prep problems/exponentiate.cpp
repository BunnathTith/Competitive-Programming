    #include <bits/stdc++.h>
    #include <math.h>
    using namespace std;


long long mod(long long x, long long n, long long m) {
    long long v = 1;
    while (n > 0) { // let the current iteration be i (0-indexed)
        if (n & 1) v = (v * x) % m; // if i-th bit is 1, multiply x^(2^i)
        x = (x * x) % m; // calculate x^(2^(i+1)) for the next iteration
        n >>= 1;
    }
    return v;
}


    int main(){
        int t;
        cin >> t;
        for (int i = 0; i<t; ++i){
            long long a, b, m;
            cin >> a >> b >> m;
            long long x = mod (a, b, m);
            cout << x << endl;
        }
        return 0;
    }
