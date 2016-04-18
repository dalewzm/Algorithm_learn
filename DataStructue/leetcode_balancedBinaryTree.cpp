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
	int depth(TreeNode* root)
	{
		if (!root)
			return 0;
		int ld = depth(root->left);
		if(ld == -1)
		    return -1;
		int rd = depth(root->right);
		if (rd == -1 || ((ld - rd) > 1 || (ld-rd)<-1))
			return -1;
		return max(ld, rd) + 1;
	}
	bool isBalanced(TreeNode* root) {
		return depth(root)!=-1;
	}
};
