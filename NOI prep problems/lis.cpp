#include <bits/stdc++.h>
using namespace std;


int main() {
    long n; cin >> n;
    long arr[n];
    vector <long> lis;
    long mAns = 0;

    for (long i = 0; i < n; ++i){
        cin >> arr[i];
    }

    lis.push_back(arr[0]);
    for (long i = 1; i < n; ++i){
        if (arr[i] > lis.back()){
            lis.push_back(arr[i]);
            mAns = max(mAns, long(lis.size()));
        }
        else{
             long sz = lis.size();
             long pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
             lis[pos] = arr[i];

        }
    }
    cout << mAns;
}
