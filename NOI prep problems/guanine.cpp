#include <bits/stdc++.h>
using namespace std;
string x = "";

void ADD_BACK (char ch){
    x = x+ch;
}

void ADD_FRONT (char ch){
    x = ch+x;
}

void SNIP_FRONT (int cut){
    int n = x.size() - cut;
    x = x.substr(cut+1, n);
}

void SNIP_BACK (int cut){
    x = x.substr(0, cut);
}


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        string cmd;
        cin >> cmd;
        if (cmd == "ADD_BACK"){
            char para;
            cin >> para;
            ADD_BACK(para);
        }
        else if (cmd == "ADD_FRONT"){
            char para;
            cin >> para;
            ADD_FRONT(para);
        }
        else if (cmd == "SNIP_BACK"){
            int para;
            cin >> para;
            SNIP_BACK(para);
        }
        else if (cmd == "SNIP_FRONT"){
            int para;
            cin >> para;
            SNIP_FRONT(para);
        }
        else if (cmd == "QUERY"){
            int para;
            cin >> para;
            cout << x[para] << endl;
        }
    }
}
