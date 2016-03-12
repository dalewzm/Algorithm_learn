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
     TreeNode* arrayToBST(vector<int>&nums,int st,int ed)
    {
        if(ed -st < 0)//ed is out bound
            return NULL;
        if(ed -st == 0)
        {
            TreeNode *cur = new TreeNode(nums[st]);
            return cur;
        }
        int mid = 0;
        if((ed -st) & 1 )
        {
            mid = (ed-st+1)/2 + st;
        }
        else{
            mid = (ed-st)/2 + st;
        }

        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = arrayToBST(nums, st, mid-1);
        cur->right = arrayToBST(nums, mid+1, ed);
        
        return cur;
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return arrayToBST(nums, 0, nums.size()-1);
        
        
    }
};
