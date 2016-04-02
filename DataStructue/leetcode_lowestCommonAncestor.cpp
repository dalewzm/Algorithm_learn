//递归寻找
// 程序无bug前提是 p，q一定存在一个公共祖先
// 如果根为空，或者根与某个节点相等，就返回根
// 如果左右子树都没找到，返回空
// 如果两个子树都找到了一个值，那么当前就是最小公共祖先
// 如果有一个子树找到了，就返回子树找到的值
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root ==p || root == q)
            return root;
        TreeNode* leftFind = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightFind = lowestCommonAncestor(root->right, p, q);
        if(! leftFind )
        {
            if(!rightFind)
                return NULL;
            return rightFind;
        }
        if(!rightFind)
        {
            return leftFind;
        }
        return root;
    }
};
