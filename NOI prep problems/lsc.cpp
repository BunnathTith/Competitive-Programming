#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string fi, se;
    cin >> fi >> se;
    int n_f = fi.length();
    int n_s = se.length();
    /*vector <vector <int>> dp_arr;
    vector <int> firstRow;
    for (int i = 0; i < n_f+1; ++i){
        firstRow.push_back(0);
    }
    dp_arr.push_back(firstRow);
    for (int j = 0; j < n_s; ++j){
        vector <int> f_tem;
        f_tem.push_back (0);
        for (int i = 0; i < n_f; ++i){
            f_tem.push_back(0);
        }
        dp_arr.push_back(f_tem);
    }*/



    int dp_arr[n_s + 1][n_f + 1];
    for (int i = 0; i<=n_s; ++i){
        for (int j = 0; j<=n_f; ++j){
            if (i == 0 || j == 0){
                dp_arr[i][j] = 0;
            }
            else if (fi[i-1] == se[j-1]){
                dp_arr[i][j] = dp_arr[i-1][j-1]+1;
            }
            else{
                dp_arr[i][j] = max(dp_arr[i-1][j], dp_arr[i][j-1]);
            }
        }
    }
    /*
    cout << endl;
    for (int i = 0; i < n_s+1; ++i){
        for (int j = 0; j < n_f+1; ++j){
            cout << dp_arr[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << dp_arr[n_s][n_f];

    return 0;
}
