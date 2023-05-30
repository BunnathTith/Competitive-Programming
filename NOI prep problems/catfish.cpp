#include <bits/stdc++.h>
using namespace std;

int main (){
    long n, p;
    cin >> n >> p;
    long catPow[n];
    for (long i = 0; i < n; ++i){
        cin >> catPow[i];
    }

    long lastJ = 0;
    long sum = 0;
    long maxCat = 0;
    for (long i = 0; i < n; ++i){
        if (lastJ == n) break;
        long j=0;
        if (sum < p){
            for (j = lastJ; j < n; ++j){
                if (sum + catPow[j]<p){
                    sum += catPow[j];
                    maxCat = max(maxCat, j-i+1);
                    //cout << "Jay " << sum << endl;
                }
                else break;
            }
        }
        sum -= catPow[i];
        //cout << "I   " << sum << endl;
        lastJ = max(j, i);


    }


    cout << maxCat;

}

