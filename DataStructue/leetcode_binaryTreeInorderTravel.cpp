//rt 初始化为根节点
//rt 一直往左走，走不下去就到了最左，可以print
//如果走不下去，弹出栈顶的根节点，并更新为右儿子
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> frames;
        TreeNode *rt = root;
        while( rt || !frames.empty()){
            if(rt){
                frames.push(rt);
                rt = rt->left;
                continue;
            }
            rt = frames.top();
            frames.pop();
            ret.push_back(rt->val);
            rt = rt->right;
        }
        return ret;
    }
};
