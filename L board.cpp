#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define forn(n) for(int in = 1; in <= n; ++ in)
#define fora(n) for(int ia = 0; ia < n; ++ ia)
#define forat(arr_name) for(auto at_e: arr_name) {cout << *at_e << " ";}

ll largest(ll arr[], int mid, int side){
    ll highest = -9223372036854775800;
    if (mid == side){
        highest = arr[mid];
    }
    else if (mid < side){
        for (int g = mid; g <= side; ++g){
            int toAdd;
            if (g == 0){
                toAdd = 0;
            }
            else{
                toAdd = arr[mid-1];
            }
            if (arr[g] - toAdd >highest){
                highest = arr[g] - toAdd;
            }
        }
    }
    else{
        for (int g = mid-1; g >= side; --g){
            if (arr[mid] - arr[g] > highest){
                highest = arr[mid] - arr[g];
            }
        }
    }
    return highest;
}


int main (){
    //freopen("100x100Ans103973609722.txt", "r", stdin);

    int n, m; //y, x;
    cin >> n >> m;

    ll o_arr[n][m];
    for (int height_e = 0; height_e < n; ++height_e){
        for(int width_e = 0; width_e < m; ++width_e){
            cin >> o_arr[height_e][width_e];
        }
    }

    ll hor_pref_arr[m][n];
    for(int width_e = 0; width_e < m; ++width_e){
        hor_pref_arr[width_e][0] = o_arr[0][width_e];
        if (n>1){
            for (int height_e = 1; height_e < n; ++height_e){
                hor_pref_arr[width_e][height_e] = hor_pref_arr[width_e][height_e-1] + o_arr[height_e][width_e];
            }
        }
    }


    ll ver_pref_arr[n][m];
    for (int height_e = 0; height_e < n; ++height_e){
        ver_pref_arr[height_e][0] = o_arr[height_e][0];
        if (m>1){
            for(int width_e = 1; width_e < m; ++width_e){
                ver_pref_arr[height_e][width_e] = ver_pref_arr[height_e][width_e-1] + o_arr[height_e][width_e];
            }
        }
    }



    ll ans(-9223372036854775800);
    for (int y_grd = 0; y_grd < n; ++y_grd){
        for (int x_grd = 0; x_grd < m; ++x_grd){
            ll ans_x_right = largest (ver_pref_arr[y_grd], x_grd, m-1);
            ll ans_x_left = largest (ver_pref_arr[y_grd], x_grd, 0);
            ll ans_x = max(ans_x_right, ans_x_left);

            ll ans_y_down = largest(hor_pref_arr[x_grd], y_grd, n-1);
            ll ans_y_up = largest(hor_pref_arr[x_grd], y_grd, 0);
            ll ans_y = max(ans_y_down, ans_y_up);

            cout << "\n Corner: " << o_arr[y_grd][x_grd] << "\n Max_x: " << ans_x << "\n Max_y: " << ans_y <<endl;
            if (ans_x + ans_y - o_arr[y_grd][x_grd] > ans){
                ans = ans_x + ans_y - o_arr[y_grd][x_grd];
                //cout << "\nNew ans: " << ans;
                //cout << "[" << y_grd << "]" << "[" << x_grd << "]";
                //cout << "\n Corner: " << o_arr[y_grd][x_grd] << "\n Max_x: " << ans_x << "\n Max_y: " << ans_y <<endl;
            }

        }
    }
    cout << "\n"<<ans;



    /* Print prefix sum arrays
    cout << "Vertical: \n";
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            cout << ver_pref_arr[a][b] << " ";
        }
        cout << endl;
    }

    cout << "\n\nHorizontal: \n";
    for(int a = 0; a < m; a++){
        for(int b = 0; b < n; b++){
            cout << hor_pref_arr[a][b] << " ";
        }
        cout << endl;
    }*/

    return 0;
}
