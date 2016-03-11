/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     bool isBalance(TreeNode* root,int &hei)
    {
        if(!root  ){
            hei = 0;
            return true;
        }
        int hl =0 ,hr =0;
        if(!isBalance(root->left, hl))
            return false;
        if(!isBalance(root->right, hr))
            return false;
        hei = max(hl,hr)+1;
        if(hl-hr<-1 || hl-hr>1)
        {
            return false;
        }
            
        return true;
    }
  
    bool isBalanced(TreeNode* root) {
        int h= 0;
        return isBalance(root,h);
    }
};
