#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int> a) {
    // ���������ĸ����Ȱ����������ǿ��ӣ�����˳��Ҳ�����������ӣ�
    for(int i = 1; i <= 9; ++i)
        if(a[i] >= 3) {
            a[i] -= 3;
            if(dfs(a)) return true;
            a[i] += 3;
        }
    // һ����������ֻ����˳��
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
        a[i] -= 2;    // ��ȸͷ
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
