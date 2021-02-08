#include <iostream>
using namespace std;
#include <map>
#include <vector> 
#define LEN (100)
#define TARGET (8)

int main() {
    //int a;
    //cin >> a
    map<int,int> mymap;
    mymap[1] = 1;
    mymap[0] = 1;
    mymap[1] = 2;
    printf("map0 :%d\n",mymap[0]);
    printf("map1 :%d\n",mymap[1]);
    vector<int> a;
    a.push_back(1);
    printf("vector first:%d\n",a[0]);
    int num[LEN] = {1, 2, 3, 3, 4, 4, 4, 7,8, 10, 12};
    int start = 0;
    int end =11;
    int l = start;
    int r = end-1;
    int target = TARGET;
    int cnt = 0;
    while(l<r){
        if(num[l] + num[r] < target){
            l++;
        }
        else if(num[l] + num[r] > target){
            r--;
        }
        else{
            int cur = r;
            while(cur > l && num[l] + num[cur] == target){
                printf("fine pari [%d]%d [%d]%d\n",l,num[l],cur,num[cur]);
                cnt++;
                cur--;
            }
            l++;
        }
    }
    cout << cnt << endl;
    return 0;
}
