#include <bits/stdc++.h>
#include <list>
using namespace std;

void a_cmd(list<int> li){ //front is top, back is bottom
    int top = li.front();
    li.pop_front();
    li.push_back(top);
}
void b_cmd(list<int> li){
    int top = li.front();
    li.pop_front();
    int s_top = li.front();
    li.pop_front();
    li.push_front(top);
    li.push_back(s_top);
}

void printLi (list<int> li){
    for (int e: li){
        cout << e << " ";
    }
    cout << endl;
}

int main (){
    int n, k;
    string cmd;
    cin >> n >> k >> cmd;
    list<int> card;
    for (int i = 0; i < n; ++i){
        card.push_back(i);
    }
    int ind = 0;
    while (cmd[ind] != '.'){
        if (cmd[ind] == 'A'){
            int top = card.front();
            card.pop_front();
            card.push_back(top);
        }
        else if (cmd[ind] == 'B'){
            int top = card.front();
            card.pop_front();
            int s_top = card.front();
            card.pop_front();
            card.push_front(top);
            card.push_back(s_top);
        }
        ind++;
        //printLi(card);
    }
    //cout << card[k-1] << " " << card[k] << " " << card[k+1];

    list<int>::iterator it = card.begin();
    advance(it, k-1);
    cout << *it << " ";
    advance(it, 1);
    cout << *it << " ";
    advance(it, 1);
    cout << *it;



}
