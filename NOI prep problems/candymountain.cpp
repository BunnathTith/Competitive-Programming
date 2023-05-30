#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int seg[4*100005];

void printTree(int n){
    int sta = 0;
    for (int i = 0; i < 4*n; ++i){
        cout << seg[i] << " ";
        if (sta == i){
            cout << endl;
            sta = (sta+1)*2;
        }
    }
    cout << endl << endl;
}

void update (int nd, int tl, int tr, int pos, int val){
    if (tl == tr){
        seg[nd] = val;
        //return;
    }
    else{
        int tm = tl + (tr-tl)/2;
        if (pos <= tm) update(nd*2+1, tl, tm, pos, val);
        else update(nd*2+2, tm+1, tr, pos, val);
        seg[nd] = min(seg[nd*2+1], seg[nd*2+2]);
    }
}

int getRange(int nd, int tl, int tr, int lf, int ri){
    //int answer = INT_MIN;
    if (tl >= lf && tr <= ri) return seg[nd];
    if (tl > ri || tr < lf) return INT_MAX;
    int tm = tl + (tr-tl)/2;
    int lfCh = getRange(nd*2+1, tl, tm, lf, ri);
    int riCh = getRange(nd*2+2, tm+1, tr, lf, ri);
    return min(lfCh, riCh);
}


int kBehind(int arr[], int k_back, int ind){
    int ans = INT_MAX;
    for (int i  = max(0, ind-k_back); i < ind; ++i){
        ans = min (ans, arr[i]);
    }
    return ans;
}

int main(){
	int n,k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}

    int dp[n+1];
    //dp[0] = 0;
    //update(0, 0, n, 0, dp[0]);
    //cout << dp[0] << endl;
    for (int i = 1; i <= n; ++i){
        //int min_e = kBehind(dp, k, i);
        int min_e = getRange(0, 1, n, max(1, i-k) , i-1);
        dp[i] = max(min_e, arr[i-1]);
        //cout << dp[i] << " " << min_e << " " << arr[i] << endl;
        update(0, 0, n, i, dp[i]);
    }

    int ans = INT_MAX;
    for (int i = n-k+1; i <= n; ++i){
        ans = min(ans, dp[i]);
    }
    //printTree(n);
    //int ans = getRange(0, 0, n, n-k+1, n);
    cout << *min_element(dp+(n-k+1), dp+(n+1));
    //cout << *min_element(dp+(n-k), dp+n);
}
