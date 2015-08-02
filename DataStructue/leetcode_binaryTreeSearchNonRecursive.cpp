struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution2{
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> q;
        TreeNode* cur;
        
        if(root == NULL)
            return ans;
        q.push(root);
        
        while(!q.empty())
        {
            cur = q.top();
            q.pop();
            ans.push_back(cur->val);
            if(cur->right)
                q.push(cur->right);
            if(cur->left)
                q.push(cur->left);
            
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        stack<int> res;
        stack<TreeNode*> q;
        TreeNode* curr;
        q.push(root);
        while(!q.empty()){
            curr = q.top();
            q.pop();
            res.push(curr->val);
            if(curr->left)
                q.push(curr->left);
            if(curr->left)
                q.push(curr->right);
        }
        while(!res.empty())
        {
            ans.push_back(res.top());
            res.pop();
        }
        return ans;
    }
};
