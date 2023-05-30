#include <bits/stdc++.h>
#include <map>
using namespace std;

//bool comp(int& fi, int& se){
    //return fi.first<se.second;
//}

int main (){
    long n;
    cin >> n;
    vector <pair<long, long>> arr;
    map <long, long> mp;
    for (long i = 0; i < n; ++i){
        long coord, breed;
        cin >> coord >> breed;
        arr.push_back({coord, breed}); // arr[].first -> coord, arr[].second -> breed
        mp[breed] = coord;
    }

    sort (arr.begin(), arr.end());

    /*cout << endl;
    for (auto e: arr){
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;*/

    long breedNum = mp.size();
    long curr_breed_num = 0;

    long minPay = LONG_MAX;

    long lastJ = 0;
    map <long, long> checking;
    for (long i = 0; i < n; ++i){
        long j;
        for (j = lastJ; j < n; ++j){
            checking[arr[j].second] = 1;
            curr_breed_num = checking.size();
            //cout << "Current Breed Number: " << curr_breed_num << endl;
            if (arr[i].second == arr[j].second && i != j){
                break;
            }

            if (curr_breed_num == breedNum){
                minPay = min(minPay, arr[j].first-arr[i].first);
                //cout << arr[j].first << " " << arr[i].first << endl << endl;
                break;
            }
        }
        if (j == n-1) break;
        lastJ = j;
        checking.erase(arr[i].second);
    }
    cout << minPay;
}
