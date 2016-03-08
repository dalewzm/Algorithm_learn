#include<iostream>
#include<string>
#include<vector>
using namespace std;


 struct TreeNode {
        int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    bool isSym(TreeNode *lc, TreeNode *rc)
    {
        if(lc==NULL && rc==NULL)
            return true;
        if(lc==NULL || rc == NULL)
            return false;
        if(lc->val != rc->val)
            return false;
        return isSym(lc->left, rc->right) && isSym(lc->right, rc->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        return isSym(root->left, root->right);
    }
};

