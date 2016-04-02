//BST 每个节点代表一个范围,在BST中找序号最大的节点就公共节点,满足一个节点在其左区间,另一个在其右区间即可
//根据节点的值，就可以判断查询节点和当前节点的位置关系
class Solution {
public:
    TreeNode* findLCA(TreeNode* root)
    {
        if(!root)
            return NULL;
        if(root->val<minv )
            return findLCA(root->right);
        if(root->val>maxv)
            return findLCA(root->left);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)
            return root;
        maxv = max(p->val, q->val);
        minv = min(p->val, q->val);
        return findLCA(root);
    }
    int maxv,minv;
};
