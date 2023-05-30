#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main (){
    ios_base::sync_with_stdio (0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    queue <int> qu;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        qu.push(x);
    }
    int new_arr[n];
    if (n%2 == 0){ //even

        int st = n/2;
        int tempoF = qu.front();
        qu.pop();
        new_arr[st] = tempoF;
        int cnt = 1;
        for (int k = 1; k < n-1; k++){
            int y = qu.front();
            qu.pop();
            if (k%2 == 1){
                new_arr[st-cnt] = y;
            }
            else {
                new_arr[st+cnt] = y;
                cnt++;
            }
        }
        int tempoL = qu.front();
        qu.pop();
        new_arr[0] = tempoL;
    }
    else{ //odd

        int st = (n-1)/2;
        int tempoF = qu.front();
        qu.pop();
        new_arr[st] = tempoF;
        int cnt = 1;
        for (int j = 1; j < n; j++){
            int y = qu.front();
            qu.pop();
            if (j%2 == 1){
                new_arr[st+cnt] = y;
            }
            else {
                new_arr[st-cnt] = y;
                cnt++;
            }
        }
    }
    for (int e: new_arr){
        cout << e << " ";
    }

}
