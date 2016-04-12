// 首先获得树高(只遍历一条路径)，得到叶子层节点数目上限
//
class Solution{
    public:
    int getHeight(TreeNode* root)//边的个数
    {
        if(!root)
            return  0;
        if(root->left)
            return getHeight(root->left)+1;
    }
    bool isExist(TreeNode* root, int pos,int level)
    {
        if(root)
        {
            if(level == 0)
                return true;
            if(pos & (1<<(level-1)))
            {
                return isExist(root->right, pos, level-1);
            }
            else{
                return isExist(root->left,  pos, level-1);
            }
        }
        return false;
    }
    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;
        h = getHeight(root);
        int low = 0, high = (1<<h);
        int mid ;
        int upp = 0;
        while(low < high-1){
            mid = low+(high-low)/2;
            if(isExist(root, mid, h)){
                low = mid;
                upp = mid;
            }
            else{
                high = mid;
            }
        }
        return (1<<h) + upp;
    }
    int h;
};
