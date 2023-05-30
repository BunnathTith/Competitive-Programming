#include <bits/stdc++.h>
using namespace std;
typedef pair <long, long> pll;

bool comp (pll fi, pll se){
    return fi.second-fi.first > se.second-se.first;
}

int main(){
    long n, k; cin >> n >> k;
    pair <long, long> arr[n];
    priority_queue <long> toAdd;
    long pts = 0;

    for (long i = 0; i < n; ++i) cin >> arr[i].first;
    for (long i = 0; i < n; ++i) cin >> arr[i].second;
    sort (arr, arr+n);

    for (long i = 0; i < n; ++i){
        if (arr[i].first <= pts) toAdd.push(arr[i].second);
        else{
            while (arr[i].first > pts){
                if (!toAdd.empty()){
                    //cout << pts << " -> ";
                    pts += toAdd.top(); toAdd.pop();
                    //cout << pts << endl;
                    k--;
                    if (k == 0) break;
                }
                else break;
            }
            if (arr[i].first <= pts) toAdd.push(arr[i].second);
            else k = 0;
        }
        if (k == 0) break;
    }
    while (k--) pts += toAdd.top(); toAdd.pop();
    cout << pts;
}
