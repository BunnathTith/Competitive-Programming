#include <bits/stdc++.h>
using namespace std;

struct mod {
    long long lev;
    long long cplx;

};

class comp{
public:
    bool operator()(mod fi, mod se){
        if (fi.lev == se.lev) return fi.cplx < se.cplx;
        return fi.lev < se.lev;
    }
};

typedef pair<long long, long long> pLL;

int main(){
    long long n; cin >> n;
    priority_queue <pLL, vector<pLL>, greater<pLL>> bot;
    for (long long i = 0; i < n; ++i){
        pLL curr;
        cin >> curr.first >> curr.second;
        bot.push(curr);
    }

    long long time = 0;
    while (!bot.empty()){
        pLL fi = bot.top(); bot.pop();
        pLL se;
        if (!bot.empty()) se = bot.top();
        else break;

        if (fi.first == se.first){
            pLL toAdd;
            toAdd.first = se.first + 1;
            toAdd.second = fi.second+se.second;

            bot.pop();
            bot.push (toAdd);
            cout << toAdd.first << " " << toAdd.second << " " << bot.size() << endl;

            time += fi.second+se.second;
        }
    }
    cout << endl << time;

}
