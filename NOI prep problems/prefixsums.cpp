    #include <iostream>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;


    int main(){
        //ios_base::sync_with_stdio(0);
        //cin.tie(0);
        //cout.tie(0);

        int n, q;
        scanf("%d %d", &n, &q);
        long a[n], prefA[n+1];

        for (int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
        }

        prefA[0] = 0;
        for (int k = 1; k <= n; ++k){
            prefA[k] = prefA[k-1] + a[k-1];
        }

        for (int j = 0; j < q; ++j){
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", (prefA[r]-prefA[l-1]));
        }
        return 0;
    }
