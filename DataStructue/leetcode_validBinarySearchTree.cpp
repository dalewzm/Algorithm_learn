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
