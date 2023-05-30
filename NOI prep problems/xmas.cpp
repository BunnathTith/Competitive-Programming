#include <bits/stdc++.h>


using namespace std;


int main (){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
        arr[i] -= 1;
    }
    int co_arr[n];



    int swaped[n];
    fill (swaped, swaped+n, 0);

    for (int i = 0; i < n; ++i){
        co_arr[arr[i]] = i;
    }

    for (int e: co_arr){
        cout << e+1 << endl;
    }


}
