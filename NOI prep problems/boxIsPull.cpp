#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int minTime = 0;
    for (int i = 0; i < t; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        minTime = abs(x1-x2) + abs(y1-y2);
        if (x1 != x2 && y1 != y2){
            minTime += 2;
        }
        cout << to_string(minTime) + "\n";
    }

}
