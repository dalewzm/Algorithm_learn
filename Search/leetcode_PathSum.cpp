//深搜遍历每条路径
class Solution {
public:
    void dfs(TreeNode* root, int &cur, int sum, bool &find)
    {
        if(!root->left && !root->right)
        {
            cur += root->val;
            if(cur == sum)
              {
                  find = true;
                  return;
              }
             cur-=root->val;
            return;
        }
        cur+= root->val;
        
        if(root->left)
        {
            dfs(root->left,cur,sum,find);
        }
        if(find)
          return;
        if(root->right)
        {
            dfs(root->right,cur,sum,find);
        }
        cur-= root->val;
         
    }
    bool hasPathSum(TreeNode* root, int sum) {
         bool find = false;
         int cur = 0;
         if(!root)
            return false;
         dfs(root,cur,sum,find);
         if(find)
            return true;
         return false;
    }
};
