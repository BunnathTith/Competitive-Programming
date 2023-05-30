#include <bits/stdc++.h>
using namespace std;

#define forn(n) for(int in = 1; in <= n; ++ in)
#define fora(n) for(int ia = 0; ia < n; ++ ia)
#define forat(arr_name) for(auto at_e: arr_name) {cout << at_e << "\n";}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int a_arr[a], b_arr[b], c_arr[c], d_arr[d];
    fora(a){
        cin >> a_arr[ia];
    }
    fora(b){
        cin >> b_arr[ia];
    }
    fora(c){
        cin >> c_arr[ia];
    }
    fora(d){
        cin >> d_arr[ia];
    }
    //cout << endl;

    pair<int, pair<int, int>> ab_arr[a*b];
    int k = 0;
    for (int iia = 0; iia < a; ++iia){
        for (int iib = 0; iib < b; ++iib){
            ab_arr[k].first = a_arr[iia]+b_arr[iib];
            ab_arr[k].second.first = iia;
            ab_arr[k].second.second = iib;
            k++;
            //cout << k << ":     ";
            //cout << ab_arr[k].first << "    " << ab_arr[k].second.first << "    " << ab_arr[k].second.second << endl;
        }
    }
    sort (ab_arr, ab_arr+(a*b));
    int ab_pos_lb = a*b; //include 0   // if ab_pos_lb == a*b: there's no non-negative numeber in the array
    int ab_neg_ub = a*b-1;
    for (int i = 0; i < a*b; ++i){
        if (ab_arr[i].first >= 0){
            ab_pos_lb = i;
            ab_neg_ub = i-1; // if ab_neg_ub == -1: there's no negative number in the array
            break;
        }
    }

    //cout << endl;

    pair<int, pair<int, int>> cd_arr[c*d];
    int l = 0;
    for (int iic = 0; iic < c; ++iic){
        for (int iid = 0; iid < d; ++iid){
            cd_arr[l].first = c_arr[iic]+d_arr[iid];
            cd_arr[l].second.first = iic;
            cd_arr[l].second.second = iid;
            l++;
            //cout << l << ":     ";
            //cout << cd_arr[l].first << "    " << cd_arr[l].second.first << "    " << cd_arr[l].second.second << endl;
        }
    }
    sort (cd_arr, cd_arr+(c*d));
    reverse (cd_arr, cd_arr+(c*d));

    int cd_pos_ub = c*d-1;
    int cd_neg_lb = c*d;
    for (int i = 0; i < c*d; ++i){
        if (cd_arr[i].first < 0){
            cd_pos_ub = i-1;
            cd_neg_lb = i;
            break;
        }
    }

    /*cout << endl;
    int flag = 0;
    for (pair<int, pair<int, int>> e: ab_arr){
        if (e.first >= 0 && flag == 0){
            cout << endl << ab_neg_ub << " " << ab_pos_lb << endl;
            flag = 1;
        }
        cout << e.first << "    ";
    }
    cout << endl << endl;
    flag = 0;
    for (pair<int, pair<int, int>> e: cd_arr){
        if (e.first < 0 && flag == 0){
            cout << endl << cd_pos_ub << " " << cd_neg_lb << endl;
            flag = 1;
        }
        cout << e.first << "    ";
    }*/

    //cout << "\n\ncd_pos and ab_neg: \n";
    int ind[4];
    int firstFlag = 0;
    for (int i = 0; i <= cd_pos_ub; ++i){//cd_pos (0->cd_pos_ub)
        if (firstFlag == 1) break;
        for (int j = 0; j <= ab_neg_ub; ++j){//ab_neg (0->ab_neg_ub)
            //cout << cd_arr[i].first+ab_arr[j].first << " ";
            if (cd_arr[i].first+ab_arr[j].first == 0){
                ind[0] = ab_arr[j].second.first;
                ind[1] = ab_arr[j].second.second;
                ind[2] = cd_arr[i].second.first;
                ind[3] = cd_arr[i].second.second;
                firstFlag = 1;
                break;
            }
            else if (cd_arr[i].first+ab_arr[j].first <0){
                break;
            }
        }
    }

    //cout << endl << "ab_pos and cd_neg: \n";
    for (int i = ab_pos_lb; i < a*b-1; ++i){//ab_pos (ab_pos_lb->a*b-1)
        if (firstFlag == 1) break;
        for (int j = cd_neg_lb; j < c*d-1; ++j){//cd_neg (cd_neg_lb->c*d-1)
            //cout << ab_arr[i].first+cd_arr[j].first << " ";
            if (ab_arr[i].first+cd_arr[j].first == 0){
                ind[0] = ab_arr[i].second.first;
                ind[1] = ab_arr[i].second.second;
                ind[2] = cd_arr[j].second.first;
                ind[3] = cd_arr[j].second.second;
                firstFlag = 1;
                break;
            }
            else if (ab_arr[i].first+cd_arr[j].first <0){
                break;
            }
        }
        if (firstFlag == 1) break;
    }



    //cout << endl << sum;

    cout << a_arr[ind[0]] << " " << b_arr[ind[1]] << " " << c_arr[ind[2]] << " " << d_arr[ind[3]];
}
