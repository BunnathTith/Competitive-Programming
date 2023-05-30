#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef tuple <int, int, int> tiii;

int main(){
    int n; cin >> n;
    vector <pair<int, pair<bool, int>>> event; //time, start or end?, index;
    int ans [n];
    for (int i = 0; i < n; ++i){
        int s, e; cin >> s >> e;
        event.push_back({s, {1, i}});
        event.push_back({e+1, {0, i}});
    }

    sort (event.begin(), event.end());
    int room = 1;
    stack <int> rtRoom;
    for (auto const e: event){
        if (e.second.first){
            if (rtRoom.empty()){
                rtRoom.push(room);
                room ++;
            }
            ans[e.second.second] = rtRoom.top();
            rtRoom.pop();
        }
        else{
            rtRoom.push(ans[e.second.second]);
        }
    }
    cout << room-1 << endl;
    for (int e: ans) cout << e << " ";

}
