// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << " " << endl;
    for (int i = 1; i <= n; ++i){
        string sp(n-i, ' ');
        string st(i-1, '*');
        cout << sp << st << '*' << st << endl;
    }

    for (int i = n-2; i >= 0; --i){
        string sp(n-i-1 , ' ');
        string st(i, '*');
        cout << sp << st << '*' << st << endl;
    }

    return 0;
}
