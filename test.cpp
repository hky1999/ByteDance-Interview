#include <iostream>
using namespace std;
#include <map>
#include <vector> 
#define LEN (100)
#define TARGET (8)
vector<int> res;

    void find(vector<int>& preOrder, vector<int>& inOrder){
        /*
        printf("res:");
        for(int i = 0;i<res.size();i++){
            printf("%d ",res[i]);
        }
        printf("\n");
        printf("pre:");
        for(int i = 0;i<preOrder.size();i++){
            printf("%d ",preOrder[i]);
        }
        printf("\n");
        printf("in:");
        for(int i = 0;i<inOrder.size();i++){
            printf("%d ",inOrder[i]);
        }
        printf("\n");*/
        if(preOrder.empty() || inOrder.empty() || preOrder.size() != inOrder.size()){
            return;
        }
        
        if(preOrder.size() == 1){
            res.push_back(preOrder[0]);
            return;
        }
        int root = preOrder[0];
        int rootPos;
        for(int i = 0;i<inOrder.size();i++){
            if(root == inOrder[i]){
                rootPos = i;
                break;
            }
        }
        //printf("Find root %d rootPos %d\n",root,rootPos);
        vector<int> leftInOrder(inOrder.begin(),inOrder.begin() + rootPos);
        vector<int> rightInOrder(inOrder.begin()+rootPos,inOrder.end());
        vector<int> leftPreOrder(preOrder.begin()+1,preOrder.begin() + rootPos +1);
        vector<int> rightPreOrder(preOrder.begin()+1+rootPos,preOrder.end());
        find(leftPreOrder,leftInOrder);
        find(rightPreOrder, rightInOrder);
        res.push_back(root);
    }
    
    vector<int> findOrder(vector<int>& preOrder, vector<int>& inOrder) {
        if(preOrder.empty() || inOrder.empty() || preOrder.size() != inOrder.size()){
            return res;
        }
        find(preOrder,inOrder);
        return res;
    }

int main(){
	vector<int> preOrder = {1,2,3};
	vector<int> InOrder = {2,1,3};
	findOrder(preOrder,InOrder);
	return 0;
}
