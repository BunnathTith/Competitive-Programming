#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    unsigned long long cnt = 0;
    for (int i = 63; i >=0; --i){
        unsigned long long domi = 1ULL <<i;

        if (n < domi){
            continue;
        }
        else{
            unsigned long long devi = n/domi;
            cnt += devi;
            n = n-domi*devi;
        }
    }
    cout << cnt;

}
