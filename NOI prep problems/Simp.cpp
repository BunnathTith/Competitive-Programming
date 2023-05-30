#include <bits/stdc++.h>
using namespace std;

int quadrant(pair<int, int> a, pair<int, int> x){
    int diffX = a.first-x.first;
    int diffY = a.second-x.second;

    if (diffX < 0 && diffY > 0) return 1;
    else if (diffX > 0 && diffY > 0) return 2;
    else if (diffX > 0 && diffY < 0) return 3;
    else if (diffX < 0 && diffY < 0) return 4;
    else return 0;

}

bool diagCh (pair<int, int> a, pair<int, int> x){
    return (abs(a.first - x.first) == abs(a.second - x.second));
}

int main(){
    int n;
    cin >> n;
    string ans = "";
    vector <pair <int, int>> li;
    for (int i = 0; i < 3; ++i){
        int fi, se;
        cin >> fi >> se;
        li.push_back ({fi, se});
    }

    int qoB = quadrant(li[0], li[1]);
    int qoC = quadrant(li[0], li[2]);

    if (qoB == qoC){ // same quadrant
        if (diagCh(li[0], li[1]) && diagCh(li[0], li[2])){ //on diagonol
            ans = "NO";
        }
        else{
            ans = "YES";
        }
    }
    else {
        ans = "NO";
    }
    cout << ans;
}
