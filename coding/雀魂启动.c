#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> a) {
    // 三个或者四个，先按其中三个是刻子（三连顺子也就是三个刻子）
    for(int i = 1; i <= 9; ++i)
        if(a[i] >= 3) {
            a[i] -= 3;
            if(dfs(a)) return true;
            a[i] += 3;
        }
    // 一个或者两个只能是顺子
    for(int i = 1; i <= 7; ++i)
        while(a[i] >= 1) {
            --a[i]; --a[i + 1]; --a[i + 2];
        }
    for(int i = 1; i <= 9; ++i)
        if(a[i] != 0)
            return false;
    return true;
}

bool canWin(vector<int> a) {
    for(int i = 1; i <= 9; ++i) {
        if (a[i] < 2) continue;
        a[i] -= 2;    // 当雀头
        if(dfs(a))
            return true;
        a[i] += 2;
    }
    return false;
}

int main(){
    vector<int> cnt(10, 0);
    for(int i = 0; i < 13; ++i) {
        int t;
        cin >> t;
        ++cnt[t];
    }
    bool found = false;
    for(int i = 1; i <= 9; ++i) {
        if(cnt[i] == 4) continue;
        ++cnt[i];
        if(canWin(cnt)) {
            cout << i << ' ';
            found = true;
        }
        --cnt[i];
    }
    if(!found)
        cout << '0' << endl;
}
