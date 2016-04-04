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
    void dfs(TreeNode* root, vector<string>& ans, string cur)
    {
         cur.append(std::to_string(root->val));
        if(!root->left && !root->right)
        {
            ans.push_back(cur);
            return;
        }
        cur.append("->");
        if(root->left)
        {
            dfs(root->left,ans,cur);
        }
        if(root->right)
        {
            dfs(root->right,ans,cur);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root)
            return ret;
        string tmp;
        dfs(root,ret,tmp);
        return ret;
    }
};
