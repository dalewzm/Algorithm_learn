//更优雅的写法，每经过一个节点，就可以将要查询的值减去当前结点值，最后判断在叶子节点后，值是否为0
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root){
            return false;
        }
        if(!root->left && !root->right)
        {
            if(root->val == sum)
                return true;
            return false;
        }
        return hasPathSum(root->left,sum-root->val)|| hasPathSum(root->right,
                                                                sum-root->val);
    }
};
