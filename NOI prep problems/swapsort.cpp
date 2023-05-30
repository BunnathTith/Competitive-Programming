#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define forn(n) for(int in = 1; in <= n; ++ in)
#define fora(n) for(int ia = 0; ia < n; ++ ia)
#define forat(arr_name) for(auto at_e: arr_name) {cout << at_e << " ";}


int main (){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int coin [n];
    bool sorted_coin[n];
    int unsort = n;
    fora (n){
        cin >> coin [ia];
        if (coin[ia] == ia+1){
            sorted_coin[ia] = 1;
            unsort--;
        }
        else sorted_coin[ia] = 0;
    }

    int q;
    cin >> q;
    int cnt = 0;
    fora (q){

        /*cout << "Coin order: " << endl;
        forat(coin);
        cout << endl << "Right order bool: " << endl;
        forat(sorted_coin);
        cout << endl << "Unsorted coins: " << unsort << endl <<endl;*/

        int l, r;
        cin >> l >> r;
        int old_status_left = sorted_coin[l-1], old_status_right = sorted_coin[r-1];
        swap (coin[l-1], coin[r-1]);
        //left:
        if (coin[l-1] == l){
            sorted_coin[l-1] = 1;
            unsort--;
        }
        else{
            sorted_coin[l-1] = 0;
            if (old_status_left != sorted_coin[l-1]){
                unsort++;
            }
        }
        //right:
        if (coin[r-1] == r){
            sorted_coin[r-1] = 1;
            unsort --;
        }
        else{
            sorted_coin[r-1] = 0;
            if(old_status_right != sorted_coin[r-1]){
                unsort++;
            }
        }
        if (unsort == 0){
            cnt++;
            //cout << "UPDATED COUNT!!" << endl;
        }
    }
    cout << cnt << endl;
    for (int e: coin){
        cout << e << " ";
    }

    return 0;
}

