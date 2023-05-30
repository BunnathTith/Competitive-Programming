#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int chuCnt = 0;
    for (int i = 0; i < n; ++i){
        string chu;
        cin >> chu;
        if (chu == "chugga"){
            chuCnt++;
        }
    }
    if (chuCnt%2) cout << "choo CHOO";
    else cout << "CHOO choo";
}
