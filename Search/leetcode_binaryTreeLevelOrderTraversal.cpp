//递归版本，类似IDA 思想
class Solution {
public:
    bool findLevel(TreeNode* root,vector<int>& nums,int tar,int level)
    {
        if(!root)
            return false;
        if(tar == level)
        {
            nums.push_back( root->val);
            return true;
        }
        bool leftFind = findLevel(root->left, nums, tar,level+1);
        bool rightFind = findLevel(root->right,nums,tar,level+1);
        return leftFind || rightFind;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > ret;
        if(!root)
            return  ret;
        int cnt = 1;
        vector<int> levelNum;
        while(findLevel(root, levelNum, cnt, 1)){
            ret.push_back( levelNum);
            levelNum.clear();
            cnt++;
        }
    }
};

//非递归版本，宽搜
typedef struct levelNode{
    levelNode(TreeNode* t,int l):node(t),level(l){}
    TreeNode* node;
    int level;
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<levelNode> nodeQueue;
        levelNode tmp(root,0);
        levelNode cur(root,0);
        nodeQueue.push(tmp);
        vector<int> levelVector;
        while(!nodeQueue.empty()){
            tmp = nodeQueue.front();
            nodeQueue.pop();
            if(tmp.level+1 > ret.size())
            {
                ret.push_back( levelVector);
            }
            ret[tmp.level].push_back(tmp.node->val);
            if(tmp.node->left)
            {
                cur.node = tmp.node->left;
                cur.level = tmp.level +1;
                nodeQueue.push(cur);
            }
            if(tmp.node->right)
            {
                cur.node = tmp.node->right;
                cur.level = tmp.level +1;
                nodeQueue.push(cur);
            }
        }
        return ret;
    }
};
