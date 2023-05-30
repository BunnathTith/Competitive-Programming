#include <bits/stdc++.h>
using namespace std;

int main(){
    long long cnLst[] = {1000000, 500000, 100000, 50000, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1};
    long long n;
    cin >> n;

    long long cnt = 0;
    int i = 0;

    while (n>0){
        long long curr = n/cnLst[i];
        cnt +=curr;
        n = n-cnLst[i]*curr;
        i++;
    }
    cout << cnt;

}
