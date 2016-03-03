class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
         if(root!=NULL){
             TreeNode* originL = root->left;
              root->left = invertTree(root->right);
              root->right = invertTree(originL);
         }   
         return root;
    }
};
