#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define forn(n) for(int in = 1; in <= n; ++ in)
#define fora(n) for(int ia = 0; ia < n; ++ ia)
#define forat(arr_name) for(auto at_e: arr_name) {cout << at_e << "\n";}

vector <int> stk;
int rgt = 0;
vector < pair<string, int>> syntax;

void command(string word, int num){

    if (word == "PUSH"){
        stk.push_back(num);
    }
    else if (word == "STORE"){
        if (stk.size()>0){
            rgt = stk.back();
            stk.pop_back();
        }
    }
    else if (word == "LOAD"){
        stk.push_back(rgt);
    }
    else if (word == "PLUS"){
        if (stk.size()>1){
            int f = stk.back();
            int s = stk[stk.size()-2];
            stk.pop_back();
            stk.pop_back();
            stk.push_back(f+s);
        }
    }
    else if (word == "TIMES"){
        if (stk.size()>1){
            int f = stk.back();
            int s = stk[stk.size()-2];
            stk.pop_back();
            stk.pop_back();
            stk.push_back(f*s);
        }
    }
    else if (word == "IFZERO"){
        if (stk.size()>0){
            int temp_back = stk.back();
            stk.pop_back();
            if (temp_back == 0){
                for (int i = num-1; i<syntax.size(); ++i){
                    command(syntax[i].first, syntax[i].second);
                }
            }
        }
    }

    cout << "   -> Stack update: ";
    for (int e: stk){
        cout << e << " ";
    }
    cout << endl;

}

void ifzero(int num){

}


int main (){
    int noc;
    cin >> noc;


    forn (noc){
        string cmd;
        int dg = 0;
        cin >> cmd;
        if (cmd == "PUSH" || cmd == "IFZERO"){
            cin >> dg;
        }
        syntax.push_back(make_pair(cmd, dg));

        command(cmd, dg);

        if (cmd == "DONE"){
            break;
        }

    }



    cout << stk.back();
    return 0;
}
