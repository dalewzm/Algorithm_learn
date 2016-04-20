//解法一：存在bug(如果节点值也用long long储存，此方法就不行了)
//BST的每个节点代表一个取值区间
//看当前结点的值是否在当前区间，如果不在，则错误
class Solution {
public:
       bool isValid(TreeNode* root, long long int low,  long long int  upp)
    {
        if(!root)
            return true;
        if(root->val <=low || root->val >= upp)
            return false;
        return isValid(root->left, low,  root->val)
        && isValid(root->right, root->val, upp);
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        long long int min = 1;
        return isValid(root->left, min<<63, root->val) && isValid(root->right, root->val,0x8fffffff);
        
    }
};

//解法二
//BST中序遍历就是排序输出
//通过中序遍历，判断前一个数是否小于当前的数，如果不小于则出错
class Solution {
public:
    bool isValid(TreeNode* root, TreeNode* &prev)
    {
        if(!root) return true;
        if(!isValid(root->left,prev))  return false;
        if(prev && prev->val >= root->val)
            return false;
        prev = root;
        return isValid(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isValid(root,prev);
    }
};
