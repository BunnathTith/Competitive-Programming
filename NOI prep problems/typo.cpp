#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length();

    int flag = 1;
    vector <pair<string, string>> strCheck;

    for (int i = 0; i < n; ++i){
        if (a[i] != b[i]){
            if (a[i] == b[i+1] && a[i+1] == b[i]){
                flag = 1;
                break;
            }
            else{
                flag = 0;
                break;
            }
        }
    }

    if (flag == 0){
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}
