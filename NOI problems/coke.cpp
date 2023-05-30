#include <bits/stdc++.h>
using namespace std;

bool com (pair<long, long> fi, pair<long, long> se){
    return se.first*fi.second < fi.first*se.second;
}

int main(){
    long n, k; cin >> n >> k;
    pair<long, long> coke[n];
    for (long i = 0; i < n; ++i){ //caffene - allertnesss
        long fi; cin >> fi;
        coke[i].first = fi;
    }
    for (long i = 0; i < n; ++i){ //sugar - enjoyment
        long se; cin >> se;
        coke[i].second = se;
    }
    sort (coke, coke+n, com);

    /*cout << endl;
    for (auto e: coke) cout << e.first << " ";
    cout << endl;
    for (auto e: coke) cout << e.second << " ";
    cout << endl << endl;*/
    long bdr = 0;
    pair<long, long> dp[n][k+1];
    for (long i = 0; i < n; ++i){
        //cout << coke[i].first << ":\t";
        for (long j = 0; j <= k; ++j){
            if (i==0) bdr = 0;
            else bdr = dp[i-1][k].second;
            if (j <= coke[i].first + bdr-1 || dp[i-1][j].second+coke[i].first > k){
                if (i==0){
                    dp[i][j] = {0, 0}; //{e, a}
                }
                else{
                    dp[i][j].first = dp[i-1][j].first; //prev_enjoyn + prev_alert*curr_sugar
                    dp[i][j].second = dp[i-1][j].second; //pref_alert+curr_caffene
                }
            }
            else{
                if (i==0){
                    dp[i][j] = {0, coke[i].first};
                }
                else {
                    if (dp[i-1][j].first > dp[i-1][j-coke[i].first].first){
                        dp[i][j].first = dp[i-1][j].first + dp[i-1][j].second*coke[i].second;
                        dp[i][j].second = dp[i-1][j].second + coke[i].first;
                    }
                    else {
                        dp[i][j].first = dp[i-1][j-coke[i].first].first + dp[i-1][j-coke[i].first].second*coke[i].second;
                        dp[i][j].second = dp[i-1][j-coke[i].first].second + coke[i].first;
                    }
                }
            }
            //cout << dp[i][j].first <<","<<dp[i][j].second<< "\t";
        }
        //cout << endl;
    }

    /*for (auto e: coke){
        cout << e.first << " " << e.second << endl;
    }

    for (long i = 0; i < n; ++i){
        for (long j = 0; j <= k; ++j){
            cout << dp[i][j].first << " ";
        }
        cout << endl;
    }*/
    cout << dp[n-1][k].first;
}
