#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string brac;
    cin >> n >> brac;
    vector <char> v;
    int flag = 0;
    if (n%2 == 1){
        flag = 1;
    }
    else {
        for (int i = 0; i < n; ++i){
            if (brac[i] == '('){
                v.push_back('(');
            }
            else if (brac[i] == ')'){
                if (v.size() == 0){
                    flag = 1;
                    break;
                }
                if (v.back() == '('){
                    v.pop_back();
                }
            }
            else if (brac[i] == '['){
                v.push_back('[');
            }
            else if (brac[i] == ']'){
                if (v.size() == 0){
                    flag = 1;
                    break;
                }
                if (v.back() == '['){
                    v.pop_back();
                }
            }
            else if (brac[i] == '{'){
                v.push_back('{');
            }
            else if (brac[i] == '}'){
                if (v.size() == 0){
                    flag = 1;
                    break;
                }
                if (v.back() == '{'){
                    v.pop_back();
                }
            }
        }
    }
    //cout << rou << " " << squ << " " << cur;
    if (flag == 1){
        cout << "Invalid";
    }
    else{
        if (v.size() == 0) cout << "Valid";
        else cout << "Invalid";
    }
}
