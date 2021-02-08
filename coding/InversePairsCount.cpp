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

class Solution {
private:
   bool isBalanced = true;
    
public:
    int dfs(TreeNode *pRoot){
        if(pRoot == NULL){
            return 0;
        }
        int left = dfs(pRoot->left);
        int right = dfs(pRoot->right);
        if(abs(left-right) > 1){
            isBalanced = false;
        }
        return right > left ? right+1:left+1;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL){
            return true;
        }
        dfs(pRoot);
        return isBalanced;
    }
};
