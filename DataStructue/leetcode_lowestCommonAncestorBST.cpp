//BST 每个节点代表一个范围,在BST中找序号最大的节点就公共节点,满足一个节点在其左区间,另一个在其右区间即可
class Solution {
public:
    TreeNode* lowest(TreeNode* root, int low, int high, int p,int q)
    {
        int val = root->val;    
        if(p<=val){
            if(q<val)
               return lowest(root->left, low, val,p,q);
            else
               return root;
        }
        else{
              return lowest(root->right, val, high,p,q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(!p)
            return q;
        if(!q)
            return p;
        if(q->val < p->val)
            return lowest(root,(signed)0x80000000 ,0x7ffffff,q->val,p->val );
        return lowest(root,(signed)0x80000000 ,0x7ffffff,p->val,q->val );
    }
};
