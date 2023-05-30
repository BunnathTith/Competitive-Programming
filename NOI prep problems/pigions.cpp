#include <bits/stdc++.h>
using namespace std;

int main (){
    int n, m; cin >> n >> m;

    int pi = 0;
    bool flag = 0;
    for (int i = 0; i < m; ++i){
        string cmd; cin >> cmd;
        if (cmd == "LAND"){
            pi ++;
        }
        else if (cmd == "LEAVE"){
            pi --;
        }
        else{
            pi = 0;
        }
        if (pi > n){
            flag = 1;
            //break;
        }
    }

    if (flag == 0) cout << "PLAN ACCEPTED";
    else cout << "PLAN REJECTED";
}
