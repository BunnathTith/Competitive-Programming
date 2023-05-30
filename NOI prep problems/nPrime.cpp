#include <bits/stdc++.h>
using namespace std;

int prime [10000100];

int main(){
    prime[0] = 1, prime[1] = 1;
    for (int i = 2 ; i < 10000100; ++i){
        if (prime[i] == 1) continue;
        for (int j = 2; i*j < 10000100; ++j){
            prime[i*j] = 1;
        }
    }


    vector <int> prI;
    for (int i = 0; i < 10000100; ++i){
        if (prime[i] == 0){
            prI.push_back(i);
        }
    }
    int n;
    cin >> n;
    cout << prI[n-1];
}
