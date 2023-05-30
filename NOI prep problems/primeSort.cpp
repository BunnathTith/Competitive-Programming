#include <bits/stdc++.h>
using namespace std;

int priming[1000005];
vector <int> prime;

void seive(){
    priming[0] = 1;
    priming[1] = 1;
    for (int i = 2; i*i <= 1000005; ++i){
        if (priming[i] == 0) {
            for (int j = i*i; j <= 1000005; j += i){
                priming[j] = 1;
            }
        }
    }
    int ind = 0;
    for (int i = 0; i <= 1000005; ++i){
        if (priming[i] == 0){
            prime.push_back(i);
        }
    }
}




int main(){
    seive();
    for (int e: prime){
        cout << e << " ";
    }

    long n; cin >> n;
    pair <long, string> arr[n];
    for (long i = 0; i < n; ++i){
        long x;
        cin >> x;
        //string strX= factorConvert (x);
        //arr[i] = {x, strX};
    }
}

