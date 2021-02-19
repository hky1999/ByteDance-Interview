## Coding

参考：

https://github.com/lewiscrow/WorkHardAndFindJob/blob/master/%E5%A4%8D%E4%B9%A0/%E9%9D%A2%E8%AF%95/%E6%89%8B%E6%92%95%E5%AD%97%E8%8A%82%E8%B7%B3%E5%8A%A8%E9%9D%A2%E8%AF%95%E6%97%B6%E5%87%BA%E7%8E%B0%E8%BF%87%E7%9A%84%E7%AE%97%E6%B3%95%E9%A2%98.md

https://www.nowcoder.com/discuss/428158

### 数组中的逆序数对

```C++
class Solution {

    private:
    long long M = 1000000007;
    
    long long mergeCnt(vector<int> &data, unsigned int lo, unsigned int hi) {
        unsigned int mi = (lo + hi) >> 1;
        long long cnt = 0;
        unsigned int i = 0, j = 0, k = lo;
        vector<int> front(data.begin() + lo, data.begin() + mi + 1);
        vector<int> rear(data.begin() + mi + 1, data.begin() + hi + 1);
        while (i < front.size() && j < rear.size()) {
            if (front[i] <= rear[j]) data[k++] = front[i++];
            else {
                data[k++] = rear[j++];
                cnt += front.size() - i;
            }
        }
        while (i < front.size()) data[k++] = front[i++];
        while (j < rear.size()) data[k++] = rear[j++];
        return cnt % M;
    }
    
    long long mergeSortCnt(vector<int> &data, unsigned int lo, unsigned int hi) {
        if (lo >= hi) return 0;
        unsigned int mi = (lo + hi) >> 1;
        long long left = mergeSortCnt(data, lo, mi);
        long long right = mergeSortCnt(data, mi + 1, hi);
        return (left + right + mergeCnt(data, lo, hi)) % M;
    }
    
    public:
    long long InversePairs(vector<int> data) {
        vector<int> _data(data);
        return mergeSortCnt(_data, 0, _data.size() - 1);
    }
};
```

**最长不含重复字符的子字符串**

请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。    

​     示例 1:    

​     输入: "abcabcbb"    

​     输出: 3     

​     解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

```java
双指针+哈希表 时间复杂度O(N) 空间复杂度O(1):字符的 ASCII 码范围为 0 ~ 127 ，
哈希表 dicdic 最多使用 O(128) = O(1)大小的额外空间。
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> dic = new HashMap<>();
        int i = -1, res = 0;
        for(int j = 0; j < s.length(); j++) {
            if(dic.containsKey(s.charAt(j)))
                i = Math.max(i, dic.get(s.charAt(j))); // 更新左指针 i
            dic.put(s.charAt(j), j); // 哈希表记录
            res = Math.max(res, j - i); // 更新结果
        }
        return res;
    }
}
```

### 两数之和

### 股票问题：

```c
//不限制次数：
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
 
//有一天冷却期
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
 
//有服务费
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
解释：相当于买入股票的价格升高了。
在第一个式子里减也是一样的，相当于卖出股票的价格减小了。
 
//2次买卖
原始的动态转移方程，没有可化简的地方
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])

//空间复杂度为1的动态规划
stock = 0,cash = -prices[0]
stock = max(stock,cash-prices[i])
cash = max(cash,stock+prices[i])
```



### 一个有序数组，从随机一位截断，把前段放在后边，如 4 5 6 7 1 2 3求中位数 

​     用[排序]()解决，问了下一般[排序]()[算法]()的复杂度，O(nlogn)   

​     扫一遍，找出分界点，O(n)   

​     提示我还有更快的方法，那肯定只有   二分   了，想了好久mid的判断条件后写了个解法，给面试官叙述了一遍跑样例的过程。

### 快排

```java

public void quickSort(int[] arr,int L,int R){
    if (arr.length == 0) return;
    int i = L;
    int j = R;
    int key = arr[(i + j)/2];
    while (i <= j){
        while (arr[i] < key)
            i++;
        while (arr[j] > key)
            j--;
        if (i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    //上面一个while保证了第一趟排序支点的左边比支点小，支点的右边比支点大了。
    //“左边”再做排序，直到左边剩下一个数(递归出口)
    if (L < j)
        quickSort(arr,L,j);
    //“右边”再做排序，直到右边剩下一个数(递归出口)
    if(i < R)
        quickSort(arr,i,R);
}

 public void quickSort(long[] array, int begin, int end){
        if (begin>=end)
            return;
        int b = begin;
        int e = end;
        long sentry = array[begin];
        while(begin<end){
            while (begin<end && array[end]>sentry) --end;
            array[begin] = array[end];
            while (begin<end && array[begin]<=sentry) ++begin;
            array[end] = array[begin];
        }
        array[begin] = sentry;
 
        quickSort(array, b, begin-1);
        quickSort(array, begin+1, e);
    }
```

### 最长有效括号   ( ) ) ( ( ( ) ) 

#### 1、用栈模拟，01标记，然后寻找最长的为1的子序列

#### 2、动态规划

```c
if s[i] == ')' && s[i-1] == '(' // ......()
    dp[i] = dp[i-2] + 2
if s[i] == ')' && s[i-1] == ')' // ......))
	if  s[i -dp[i - 1] - 1] == '('
		dp[i] = ap[i-1] + dp[i-dp[i-1]-2]+ 2
```

#### 3、栈

保持栈底元素为**当前已经遍历过的元素中最后一个没有被匹配的右括号的下标**

对于'(' ，将下标放入栈中

对于')' ，先弹出栈顶元素表示匹配了当前右括号

​	如果栈为空，说明当前右括号为没有被匹配的右括号，将其下标放入栈中

​	如果不为空，当前右括号的下标减去栈顶元素即为 **以该右括号为结尾的最长有效括号的长度**

需要注意的是，如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，这样就不满足提及的「最后一个没有被匹配的右括号的下标」，为了保持统一，我们在一开始的时候往栈中放入一个值为 -1−1 的元素。

#### 4、双计数器 left right

从左到右遍历字符串，对于遇到的每个（，增加left，遇到的每个），增加right，当二者相等时记录有效字符串长度，当right比left大时，二者同时变为0；

从右到左遍历字符串，对于遇到的每个（，增加left，遇到的每个），增加right，当二者相等时记录有效字符串长度，当left比right大时，二者同时变为0；

### 每k个反转链表

```c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *l,*r,*rr,*connect = NULL;
        ListNode *start = NULL;
        l = r =  head;
        while(1){
            int i;
            rr = r;
            for(i = 0;i<k && r!=NULL;i++) r = r ->next;
            if(r==NULL && i<k){
                break;
            }
            if(start == NULL){
                start = reverseK(l,k);
            }
            else{ 
                connect->next = reverseK(l,k);
            }
            connect = l;
            l = r;
        }
        connect->next = rr;
        return start;
    }

    ListNode* reverseK(ListNode* head,int k){
        ListNode *p,*q;
        int i;
        p = head->next;
        for(i = 0;i<k-1 && p!=NULL;i++){
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};
```

### 合并两个有序数组

从后往前

### 合并K个升序链表

```c++
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

```

### 缺失的第一个正数

```c++
class Solution {
public:
    void printNum(vector<int>& nums,int l){
        for(int i = 0;i<l;i++){
            printf("%d ",nums[i]);
        }
        printf("\n");
        return;
    }

    int firstMissingPositive(vector<int>& nums) {
        int i;
        int length = nums.size();
        for(i = 0;i<length;i++){
            while(nums[i] >= 1 && nums[i] <= length && nums[nums[i] - 1] != nums[i]){
                printf("i=%d,swich %d with %d:::",i,nums[i],nums[nums[i] - 1]);
                int tmp = nums[nums[i] - 1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
                printNum(nums,length);
            }
        }

        for(i = 0;i<length;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return length+1;
    }
};
```

### 二叉树右视图

```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        queue<TreeNode *> q;
        int i;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.back()->val);
            int n = q.size();
            for(i = 0;i<n;i++){
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
        }
        return res;
    }
};
```

### 反转链表

```java
public ListNode reverseList(ListNode l1) {
    ListNode pre = null;
    ListNode next = null;
    while(l1 != null) {
        next = l1.next;
        l1.next = pre;
        pre = l1;
        l1 = next;
    }
    return pre;
}

```

### 二叉搜索树与双向链表

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

```c++
class Solution {
private:
    TreeNode* treeNode = NULL;
    void myConvert(TreeNode* pRootofTree){
        if(pRootofTree == NULL){
            return;
        }
        else{
            myConvert(pRootofTree->left);
            pRootofTree->left = treeNode;
            if(treeNode){
                treeNode->right = pRootofTree;
            }
            treeNode = pRootofTree;
            myConvert(pRootofTree->right);
        }
    }   
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        myConvert(pRootOfTree);
        if(treeNode==NULL){
            return NULL;
        }
        else{
            while(treeNode->left){
                treeNode = treeNode->left;
            }
            return treeNode;
        }
    }
};


class Solution {
private:
    TreeNode* leftLast = NULL;
    
public:
    
    TreeNode* Convert(TreeNode* root)
    {
       if(root == NULL){
           return NULL; 
       }
       if(root->left == NULL && root->right == NULL){
           leftLast = root;
           return root;
       }
        TreeNode* left = Convert(root->left);
        if(left!=NULL){
            leftLast->right = root;
            root->left = leftLast;
        }
        leftLast = root;
        TreeNode* right = Convert(root->right);
        if(right!=NULL){
            right->left = root;
            root->right = right;
        }
        return left!=NULL ? left : root;
    }
};

中序遍历即可。只需要记录一个pre指针即可。
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
         
        convertHelper(pRootOfTree, pre);
         
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
     
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    {
        if(cur == nullptr) return;
        convertHelper(cur ->left, pre);
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;
        convertHelper(cur ->right, pre);  
    }
};
```

### 三数之和

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};
```

### 最小割算法

https://blog.csdn.net/mmm_jsw/article/details/83787395

###  “马”在棋盘上的概率

### 求平方根

### 找出重复元素

### 最小编辑距离

### 求两个班成绩的最小差值

### 猜数字

