 #include <bits/stdc++.h>
using namespace std;

int main (){
    int child, color;
    cin >> child >> color;
    int cl_arr[color];
    int maxCl = INT_MIN;
    for (int i = 0; i < color; ++i){
        cin >> cl_arr[i];
        maxCl = max(maxCl, cl_arr[i]);
    }

    int lf = 0, ri = maxCl;
    while (lf <= ri){
        int mid = lf + (ri-lf)/2;

        int huh = 0;
        for (int i = 0; i < color; ++i){
            int k = (cl_arr[i]+mid-1)/mid;
            huh += k;
            //cout << huh << "        ";
        }
        //cout << endl;

        if (huh<=child) ri = mid-1;
        else lf = mid+1;
    }
    cout << lf;

}
