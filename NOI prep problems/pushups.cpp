#include <bits/stdc++.h>
using namespace std;
long multiple[1001000]; // store integer n of size t


void multiUpdate(int u){
    for (int i = 2; i <= u; i++){
        for (int j = i; j <= u; j += i){
            multiple[j] += i;
        }
    }

}


int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fill(multiple, multiple+1001000, 1);
    multiple[0] = 0;
    int t;
    cin >> t;
    long n[t];
    long maxN = 0;
    for (int i = 0; i < t; ++i){
        cin >> n[i];
        maxN = max(maxN, n[i]);
    }

    multiUpdate(maxN+1); //update prime[] until n
    long maxToI [maxN+1];
    maxToI[0] = multiple[0];
    for (int i = 1; i <= maxN; ++i){
        maxToI[i] = max(maxToI[i-1], multiple[i]);
    }

    for (int i = 0; i < t; ++i){
        cout << to_string(maxToI[n[i]]) + "\n";
    }



    //for (int i = 0; i < t; ++i){
        //multipleFind(n); //find the
    //}


}
