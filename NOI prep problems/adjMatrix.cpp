#include <bits/stdc++.h>
using namespace std;
int memo[51][51];

int main(){
    int n, e;
    cin >> n >> e;
    vector <int> arr[n];
    for (int i = 0; i < e; ++i){
        int ea, eb;
        cin >> ea >> eb;
        arr[ea-1].push_back(eb-1);
        arr[eb-1].push_back(ea-1);
    }


    int v_cnt = 0;
    for (vector <int> v: arr){
        for (int e: v){
            memo[v_cnt][e] = 1;
        }
        v_cnt++;
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << memo[i][j];
        }
        cout << endl;
    }
}
