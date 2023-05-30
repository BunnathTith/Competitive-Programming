#include <bits/stdc++.h>
using namespace std;

int main (){
    int score;
    cin >> score;

    if (score > 90) cout << "A*";
    else if (score > 74) cout << "A";
    else if (score > 59) cout << "B";
    else if (score > 49) cout << "C";
    else if (score > 34) cout << "D";
    else if (score > 19) cout << "E";
    else cout << "U";
}

/*A*: 91 and above
A: 75 to 90
B: 60 to 74
C: 50 to 59
D: 35 to 49
E: 20 to 34
U: Below 20*/
